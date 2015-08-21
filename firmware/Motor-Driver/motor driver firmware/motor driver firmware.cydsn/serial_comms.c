/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

// Includes
#include <project.h>
#include <serial_comms.h>
#include <cobs.h>
#include <motor_control.h>

// Functions begin here
void int16_to_be(unsigned char *target, uint16_t num) {
    target[0] = (num>>8) & 0xFF;
    target[1] = num & 0xFF;
}

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
		if (inbyte == UART_UART_RX_UNDERFLOW) { // Out of bytes for now. Wait for another go-round.
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
    if(frame[TARGET_OFFSET] == TARGET_RESERVED)
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

/* [] END OF FILE */
