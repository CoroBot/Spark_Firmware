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

// Function Declarations
void hw_init();


// Program begins here
int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    hw_init();
    
    for(;;)
    {
        handleFrames();                         //deal with any relevant incoming frames
        
        updateMotors(); 
        
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

/* [] END OF FILE */
