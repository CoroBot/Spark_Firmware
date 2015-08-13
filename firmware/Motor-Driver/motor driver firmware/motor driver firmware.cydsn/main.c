/* ========================================
 *
 * Copyright Coroware, Inc. 2015
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Coroware, Inc.
 *
 * ========================================
*/
#include <project.h>
#include <cobs.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <serial_comms.h>
#include <motor_control.h>

// Defines
#define true 1
#define false 0
#define SYSTEM_DATA_LENGTH 2
#define COBS_FRAME_OVERHEAD 5
#define CRC_LENGTH 4
#define MIN_FRAME_LENGTH 5
#define MAX_FRAME_LENGTH 64

#define TARGET_FRONT_MOTOR 1
#define TARGET_REAR_MOTOR 2
#define TARGET_BOTH_MOTOR 3

#define TARGET_OFFSET 0
#define SETGET_OFFSET 1
#define OPTION_OFFSET 2
#define DATA_OFFSET 3

// Global Variables
uint16 front_current;
uint16 rear_current;

uint16 front_encoder;
uint16 rear_encoder;

uint16 front_speed = 0;
uint16 rear_speed = 0;

uint8 front_direction = 0;
uint8 rear_direction = 0;

// Function Declarations
void hw_init();
void updateMotors();
void handleFrames(void);
void handle_Frame(uint8_t *frame, unsigned int length);
//void encode_and_send(uint16 fmotorcur, uint16 rmotorcur, uint16 fmotorenc, uint16 rmotorenc);
void encode_and_send(uint16 tosend);
void int16_to_be(unsigned char *target, uint16_t num);
void read_current_and_encoder();
void frontmotor(uint8_t* frame);
void rearmotor(uint8_t* frame);
void get_frontmotor(uint8_t* frame);
void set_frontmotor(uint8_t* frame);
void get_rearmotor(uint8_t* frame);
void set_rearmotor(uint8_t* frame);

// Program begins here
int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    hw_init();
    
    for(;;)
    {
        handleFrames();                         //deal with any relevant incoming frames
        
        updateMotors(); //Does this really need to be called every main? or only when something changes? (in sets)
        
        read_current_and_encoder();             //read the adc values and the quadrature encoder values
        CyDelayUs(100);                         //this delay is just to prevent it form dropping too many frames
    }
}

//start the relevant components
void hw_init() {
    PWM_Front_Start();
    PWM_Rear_Start();
    QuadDec_Front_Start();
    QuadDec_Rear_Start();
    QuadDec_Front_TriggerCommand(QuadDec_Front_MASK, QuadDec_Front_CMD_RELOAD);
    QuadDec_Rear_TriggerCommand(QuadDec_Rear_MASK, QuadDec_Rear_CMD_RELOAD);
    UART_Start();
    Motor_Current_ADC_Start();

}

//Apply the current global values to the corresponding hardware modules
void updateMotors() {
    Front_Dir_Write(front_direction);       //write the front directional control register
    Rear_Dir_Write(rear_direction);         //write the rear directional control register
    PWM_Front_WriteCompare(front_speed);    //set the speed of the front wheel
    PWM_Rear_WriteCompare(rear_speed);      //set the speed of the rear wheel
}

void read_current_and_encoder()
{
    Motor_Current_ADC_StartConvert();
    int hold_front_current = Motor_Current_ADC_GetResult16(0);
    int hold_rear_current = Motor_Current_ADC_GetResult16(1);
    if(hold_front_current <=0)
    {
        front_current = 0;
    }
    else
    {
        front_current = hold_front_current;
    }
    if(hold_rear_current <=0)
    {
        rear_current = 0;
    }
    else
    {
        rear_current = hold_rear_current;
    }
    front_encoder = QuadDec_Front_ReadCounter();
    rear_encoder = QuadDec_Rear_ReadCounter();
}

void int16_to_be(unsigned char *target, uint16_t num) {
    target[0] = (num>>8) & 0xFF;
    target[1] = num & 0xFF;
}

/*void encode_and_send(uint16 fmotorcur, uint16 rmotorcur, uint16 fmotorenc, uint16 rmotorenc) {
    unsigned char data[SYSTEM_DATA_LENGTH+CRC_LENGTH];
    unsigned char outdat[SYSTEM_DATA_LENGTH + COBS_FRAME_OVERHEAD];
    uint32_t checksum;

    //Serialize data into buffer - all integers are represented in big endian (network) order
    int16_to_be(&data[0], fmotorcur);
    int16_to_be(&data[2], rmotorcur);
    int16_to_be(&data[4], fmotorenc);
    int16_to_be(&data[6], rmotorenc);
    
    //generate and append the checksum
    checksum = Crc32_ComputeBuf(0,data,SYSTEM_DATA_LENGTH);
    uint32toNO(checksum, &data[8]);
    
    //encode and fire off the frame
    encode_cobs(data,SYSTEM_DATA_LENGTH+CRC_LENGTH,outdat);

    UART_UartPutChar('\0');
    unsigned int i;
    for(i = 0; i<sizeof(outdat);i++)
    {
        UART_UartPutChar(outdat[i]);
    }
    UART_UartPutChar('\0');
}*/

void encode_and_send(uint16 tosend) {
    unsigned char data[SYSTEM_DATA_LENGTH+CRC_LENGTH];
    unsigned char outdat[SYSTEM_DATA_LENGTH + COBS_FRAME_OVERHEAD];
    uint32_t checksum;

    //Serialize data into buffer - all integers are represented in big endian (network) order
    int16_to_be(&data[0], tosend);
    
    //generate and append the checksum
    checksum = Crc32_ComputeBuf(0,data,SYSTEM_DATA_LENGTH);
    uint32toNO(checksum, &data[2]);
    
    //encode and fire off the frame
    encode_cobs(data,SYSTEM_DATA_LENGTH+CRC_LENGTH,outdat);

    UART_UartPutChar('\0');
    unsigned int i;
    for(i = 0; i<sizeof(outdat);i++)
    {
        UART_UartPutChar(outdat[i]);
    }
    UART_UartPutChar('\0');
}

void handleFrames(void) {
	static int offset = 0;
	static uint8_t inframe[MAX_FRAME_LENGTH];
	static uint8_t decoded[MAX_FRAME_LENGTH];
	
	int32_t inbyte;
	
	while (1) {
		inbyte = UART_UartGetByte();
		if (inbyte >0xFF) { // Out of bytes for now. Wait for another go-round.
			return; 
		}
		// Zeroes are frame delimeters. If the byte is not a zero, it's part of the data.
		// If so, add it to the input buffer - with boundary checking to avoid buffer overruns.
		if (inbyte != 0) {
			if (offset == (MAX_FRAME_LENGTH - 1)) { // Frame too long - dump.
				offset = 0;
				continue; // Jump back to start of loop
			}
			inframe[offset] = inbyte;
			offset++;
			continue; // Jump back to start of loop
		}
		// At this point we know that inbyte == 0
		
		if (offset < MIN_FRAME_LENGTH) { // Frame too short - dump 
			offset = 0;
			continue;
		}
		break; // Have a full frame - time to do something sane with it.
	}
	int rv = decode_cobs(inframe, offset, decoded);
	if (rv < 0) { // If the decoder blew up, we have a bad frame. Drop it on the floor
		offset = 0;
		return;
	}
	uint32_t cmp_crc32 = NO_to_uint32(&decoded[rv-CRC_LENGTH]);
	uint32_t crc32 = Crc32_ComputeBuf(0, decoded, rv-CRC_LENGTH);
	if (crc32 != cmp_crc32) { // Bad CRC32 - dump frame
		offset = 0;
		return;
	}
	offset = 0;
	handle_Frame(decoded, rv); // Good frame - Process result
}

void handle_Frame(uint8_t *frame, unsigned int length)
{
    if(frame[0] == 0)
    {
        //something not universe breaking maybe?
        return;
    }
    else if(frame[TARGET_OFFSET] == TARGET_FRONT_MOTOR)//going to front motor //TARGET_FRONT_MOTOR = 1
    {
        frontmotor(frame);
    }
    else if(frame[TARGET_OFFSET] == TARGET_REAR_MOTOR)//going to rear motor //TARGET_REAR_MOTOR = 2
    {
        rearmotor(frame);
    }
    else if(frame[TARGET_OFFSET] == TARGET_BOTH_MOTOR)//going to both motors //TARGET_BOTH_MOTOR = 3
    {
        frontmotor(frame);
        rearmotor(frame);
    }
}

//this function handles all the commands for the front motor.
void frontmotor(uint8_t *frame)
{
    if(frame[1] == 0)//okay we know we need to get something
    {
        get_frontmotor(frame);
    }
    else if(frame[1] == 1)//we need to set something instead
    {
        set_frontmotor(frame);
    }
}

//handles getting all the data from the front motor
void get_frontmotor(uint8_t* frame)
{
    switch(frame[2])
    {
        case 0: //get motor direction
            encode_and_send(front_direction);
            break;
        case 1://get motor speed
            encode_and_send(front_speed);
            break;
        case 2://get encoder counter
            encode_and_send(front_encoder);
            break;
        case 3://get current data
            encode_and_send(front_current);
            break;
        case 4://get mode pin
            encode_and_send(Mode_Front_Read());
            break;
        case 5://get power pin
            encode_and_send(Power_Front_Read());
            break;
    }
}

//handles setting values for the front motor
void set_frontmotor(uint8_t* frame)
{
    switch(frame[2])
    {
        case 0: //set motor direction
            //front_direction = frame[3];
            front_direction = NO_to_int16(&frame[3]);
            break;
        case 1://set motor speed
            front_speed = (frame[3] << 8) +frame[4];
            break;
        case 2://set encoder counter
            QuadDec_Front_WriteCounter((frame[3] << 8) +frame[4]);
            break;
        case 3://set current data -- not possible, remove?
            break;
        case 4://set mode pin
            Mode_Front_Write(frame[3]);
            break;
        case 5://set power pin
            Power_Front_Write(frame[3]);
            break;
    }
}

//this function handles all of the commands for the rear motor.
void rearmotor(uint8_t *frame)
{
    if(frame[1] == 0)//okay we know we need to get something
    {
        get_rearmotor(frame);
    }
    else if(frame[1] == 1)//we need to set something instead
    {
        set_rearmotor(frame);
    }
}

//handles getting values form the rear motor
void get_rearmotor(uint8_t* frame)
{
    switch(frame[2])
    {
        case 0: //get motor direction
            encode_and_send(rear_direction);
            break;
        case 1://get motor speed
            encode_and_send(rear_speed);
            break;
        case 2://get encoder counter
            encode_and_send(rear_encoder);
            break;
        case 3://get current data
            encode_and_send(rear_current);
            break;
        case 4://get mode pin
            encode_and_send(Mode_Rear_Read());
            break;
        case 5://get power pin
            encode_and_send(Power_Rear_Read());
            break;
    }
}

//handles setting all the values for the rear motor
void set_rearmotor(uint8_t* frame)
{
    switch(frame[2])
    {
        case 0: //set motor direction
            rear_direction = frame[3];
            break;
        case 1://set motor speed
            rear_speed = (frame[3] << 8) +frame[4];
            break;
        case 2://set encoder counter
            QuadDec_Rear_WriteCounter((frame[3] << 8) +frame[4]);
            break;
        case 3://set current data -- not possible, remove?
            break;
        case 4://set mode pin
            Mode_Rear_Write(frame[3]);
            break;
        case 5://set power pin
            Power_Rear_Write(frame[3]);
            break;
    }
}


/* [] END OF FILE */
