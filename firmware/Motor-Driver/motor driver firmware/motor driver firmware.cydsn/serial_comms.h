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

// Protect header from multiple inclusion
#ifndef __INCLUDED_SERIALCOMMS
#define __INCLUDED_SERIALCOMMS 1

// Includes
#include <project.h>

// Defines
#define SYSTEM_DATA_LENGTH 2
#define COBS_FRAME_OVERHEAD 5
#define CRC_LENGTH 4
#define MIN_FRAME_LENGTH 5
#define MAX_FRAME_LENGTH 64

#define TARGET_RESERVED 0
#define TARGET_FRONT_MOTOR 1
#define TARGET_REAR_MOTOR 2
#define TARGET_BOTH_MOTOR 3

    
// Global Variables

// Function Prototypes
void handleFrames(void);
void handle_Frame(uint8_t *frame, unsigned int length);
//void encode_and_send(uint16 fmotorcur, uint16 rmotorcur, uint16 fmotorenc, uint16 rmotorenc);
void encode_and_send(uint16 tosend);
void int16_to_be(unsigned char *target, uint16_t num);

    
#endif    
/* [] END OF FILE */
