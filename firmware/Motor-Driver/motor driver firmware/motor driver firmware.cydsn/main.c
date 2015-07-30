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

#define true 1
#define false 0
#define SYSTEM_DATA_LENGTH 8
#define COBS_FRAME_OVERHEAD 5
#define CRC_LENGTH 4

// Global Variables
uint16 front_current;
uint16 rear_current;

uint16 front_encoder;
uint16 rear_encoder;

uint16 front_speed = 0;
uint16 rear_speed = 0;

uint8 dir = 0;

// Function Declarations
void handleFrames(void);
void handle_Frame(uint8_t *frame, unsigned int length);
void encode_and_send(uint16 fmotorcur, uint16 rmotorcur, uint16 fmotorenc, uint16 rmotorenc);
void int16_to_be(unsigned char *target, uint16_t num);
void read_current_and_encoder();

// Program begins here
int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    PWM_F_Start();
    PWM_R_Start();
    QuadDec_1_Start();
    QuadDec_2_Start();
    QuadDec_1_TriggerCommand(QuadDec_1_MASK, QuadDec_1_CMD_RELOAD);
    QuadDec_2_TriggerCommand(QuadDec_2_MASK, QuadDec_2_CMD_RELOAD);
    UART_Start();
    ADC_Start();

    for(;;)
    {
        handleFrames();
        DIR_CONTROL_Write(dir);
        PWM_F_WriteCompare(front_speed);
        PWM_R_WriteCompare(rear_speed);
        CyDelayUs(100);
    }
}

void read_current_and_encoder()
{
    ADC_StartConvert();
    CyDelayUs(10);
    front_current = ADC_GetResult16(0);
    rear_current = ADC_GetResult16(1);
    front_encoder = QuadDec_1_ReadCounter();
    rear_encoder = QuadDec_2_ReadCounter();
}

void int16_to_be(unsigned char *target, uint16_t num) {
    target[0] = (num>>8) & 0xFF;
    target[1] = num & 0xFF;
}

void encode_and_send(uint16 fmotorcur, uint16 rmotorcur, uint16 fmotorenc, uint16 rmotorenc) {
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
}

void handleFrames(void) {
	static int offset = 0;
	static uint8_t inframe[64];
	static uint8_t decoded[64];
	
	int32_t inbyte;
	
	while (1) {
		inbyte = UART_UartGetByte();
		if (inbyte >255) { // Out of bytes for now. Wait for another go-round.
			return; 
		}
		// Zeroes are frame delimeters. If the byte is not a zero, it's part of the data.
		// If so, add it to the input buffer - with boundary checking to avoid buffer overruns.
		if (inbyte != 0) {
			if (offset == 63) { // Frame too long - dump.
				offset = 0;
				continue; // Jump back to start of loop
			}
			inframe[offset] = inbyte;
			offset++;
			continue; // Jump back to start of loop
		}
		// At this point we know that inbyte == 0
		
		if (offset < 5) { // Frame too short - dump
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
	uint32_t cmp_crc32 = NO_to_uint32(&decoded[rv-4]);
	uint32_t crc32 = Crc32_ComputeBuf(0, decoded, rv-4);
	if (crc32 != cmp_crc32) { // Bad CRC32 - dump frame
		offset = 0;
		return;
	}
	offset = 0;
	handle_Frame(decoded, rv); // Good frame - Process result
}

void handle_Frame(uint8_t *frame, unsigned int length) {
    switch(frame[0]){
        case 10:
            read_current_and_encoder();
            encode_and_send(front_current,rear_current,front_encoder,rear_encoder);
            return;
        case 11:
            QuadDec_1_WriteCounter(32768);
            return;
        case 12:
            QuadDec_2_WriteCounter(32768);
            return;
        case 13:
            Mode1_Write(!Mode1_Read());
            return;
        case 14:
            Mode2_Write(!Mode2_Read());
            return;
        case 15:
            Power1_Write(!Power1_Read());
            return;
        case 16:
            Power2_Write(!Power2_Read());
            return;
        default:
            break;
            
    } 
    if(length >8)
    {
        dir = frame[0]-1;
        front_speed = (frame[1] << 8) +frame[2];
        rear_speed = (frame[3] << 8) +frame[4];
    }
}

/* [] END OF FILE */
