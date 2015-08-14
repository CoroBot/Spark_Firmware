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
#ifndef __INCLUDED_MOTORCONTROL
#define __INCLUDED_MOTORCONTROL 1

// Includes
#include <project.h>

// Defines
#define TARGET_OFFSET 0
#define SETGET_OFFSET 1
#define OPTION_OFFSET 2
#define DATA_OFFSET 3

#define GET 0
#define SET 1


// Function Prototypes 
void updateMotors();
void read_current_and_encoder();
void frontmotor(uint8_t* frame);
void rearmotor(uint8_t* frame);
void get_frontmotor(uint8_t* frame);
void set_frontmotor(uint8_t* frame);
void get_rearmotor(uint8_t* frame);
void set_rearmotor(uint8_t* frame);    

    
#endif    
/* [] END OF FILE */
