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

uint16 fcur;
uint16 rcur;
uint16 fenc;
uint16 renc;

void handleFrames(void);
void handle_Frame(uint8_t *frame, unsigned int length);
void encode_and_send(uint16 fmotorcur, uint16 rmotorcur, uint16 fmotorenc, uint16 rmotorenc);
unsigned char* sixteen_bit_shift(uint16 in);
void read_current_and_encoder();

uint8 dir = 0;
uint16 speedf = 0;
uint16 speedr = 0;


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
        /*unsigned char in[] = {'1','2','3'};
        unsigned char out[sizeof(in)+5];
        unsigned char check[4];
        unsigned char todec[sizeof(in)+4];
        uint32_t checksum;
        checksum = Crc32_ComputeBuf(0,in,sizeof(in));
        check[0] = (checksum>>24) & 0xFF;
        check[1] = (checksum>>16) & 0xFF;
        check[2] = (checksum>>8) & 0xFF;
        check[3] = checksum & 0XFF;
        unsigned int i = 0;
        for(i=0; i < sizeof(in); i++)
        {
            todec[i] = in[i];
        }
        int j;
        for(j = 0;j<4;j++)
        {
            todec[j+sizeof(in)] = check[j];
        }
        encode_cobs(todec,sizeof(todec),out);
        //encode_cobs(in,sizeof(in),out);
        UART_UartPutChar('\0');
        UART_UartPutString((char*)out);
        UART_UartPutChar('\0');
        CyDelay(20);*/
        
        /*
        char out[16];
        int in;
        in = QuadDec_1_ReadCounter();
        sprintf(out, "%d", in);
        UART_UartPutString(out);
        UART_UartPutChar('\n');*/
        
        handleFrames();
        DIR_CONTROL_Write(dir);
        PWM_F_WriteCompare(speedf);
        PWM_R_WriteCompare(speedr);
        CyDelayUs(100);
    }
}

void read_currenct_and_encoder()
{
    ADC_StartConvert();
    CyDelayUs(10);
    fcur = ADC_GetResult16(0);
    rcur = ADC_GetResult16(1);
    fenc = QuadDec_1_ReadCounter();
    renc = QuadDec_2_ReadCounter();
}

unsigned char* sixteen_bit_shift(uint16 in)
{
    static unsigned char out[2];
    out[0] = (in>>8) & 0xFF;
    out[1] = in & 0xFF;
    return out;
}

void encode_and_send(uint16 fmotorcur, uint16 rmotorcur, uint16 fmotorenc, uint16 rmotorenc)
{
    unsigned char data[8];
    unsigned char outdat[sizeof(data)+5];
    unsigned char check[4];
    unsigned char toenc[sizeof(data)+4];
    uint32_t checksum;
    //convert the data into bytes
    memcpy(data, sixteen_bit_shift(fmotorcur),2);
    memcpy(data+2, sixteen_bit_shift(rmotorcur),2);
    memcpy(data+4, sixteen_bit_shift(fmotorenc),2);
    memcpy(data+6, sixteen_bit_shift(rmotorenc),2);
    //add that data to the array to be encode
    memcpy(toenc, data, sizeof(data));
    //generate and append the checksum
    checksum = Crc32_ComputeBuf(0,data,sizeof(data));
    check[0] = (checksum>>24) & 0xFF;
    check[1] = (checksum>>16) & 0xFF;
    check[2] = (checksum>>8) & 0xFF;
    check[3] = checksum & 0XFF;
    memcpy(toenc+sizeof(data), check, sizeof(check));
    //encode and fire off the frame
    encode_cobs(toenc,sizeof(toenc),outdat);
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
		if (inbyte == UART_UART_RX_UNDERFLOW) { // Out of bytes for now. Wait for another go-round.
			return; 
		}
		// Zeroes are frame delimeters. If the byte is not a zero, it's probably part of the data.
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
	if (rv < 0) { // If the decoder blew up, we have a bad frame. floor.
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

void handle_Frame(uint8_t *frame, unsigned int length)
{
    switch(frame[0]){
        case 10:
            read_currenct_and_encoder();
            encode_and_send(fcur,rcur,fenc,renc);
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
        speedf = (frame[1] << 8) +frame[2];
        speedr = (frame[3] << 8) +frame[4];
    }
}

/* [] END OF FILE */
