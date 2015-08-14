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
#include <motor_control.h>
#include <serial_comms.h>
#include <cobs.h>

// Global Variables
uint16 front_current;
uint16 rear_current;

uint16 front_encoder;
uint16 rear_encoder;

uint16 front_speed = 0;
uint16 rear_speed = 0;

uint8 front_direction = 0;
uint8 rear_direction = 0;


// Functions begin here

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

//this function handles all the commands for the front motor.
void frontmotor(uint8_t *frame)
{
    if(frame[SETGET_OFFSET] == GET)//okay we know we need to get something
    {
        get_frontmotor(frame);
    }
    else if(frame[SETGET_OFFSET] == SET)//we need to set something instead
    {
        set_frontmotor(frame);
    }
}

//handles getting all the data from the front motor
void get_frontmotor(uint8_t* frame)
{
    switch(frame[OPTION_OFFSET])
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
    switch(frame[OPTION_OFFSET])
    {
        case 0: //set motor direction
            front_direction = frame[DATA_OFFSET];
            //front_direction = NO_to_int16(&frame[DATA_OFFSET]);
            break;
        case 1://set motor speed
            //front_speed = (frame[3] << 8) +frame[4];
            front_speed = NO_to_int16(&frame[DATA_OFFSET]);
            break;
        case 2://set encoder counter
            QuadDec_Front_WriteCounter(NO_to_int16(&frame[3]));
            //QuadDec_Front_WriteCounter((frame[3] << 8) +frame[4]);
            break;
        case 3://set current data -- not possible, remove?
            break;
        case 4://set mode pin
            Mode_Front_Write(frame[DATA_OFFSET]);
            break;
        case 5://set power pin
            Power_Front_Write(frame[DATA_OFFSET]);
            break;
    }
}

//this function handles all of the commands for the rear motor.
void rearmotor(uint8_t *frame)
{
    if(frame[SETGET_OFFSET] == GET)//okay we know we need to get something
    {
        get_rearmotor(frame);
    }
    else if(frame[SETGET_OFFSET] == SET)//we need to set something instead
    {
        set_rearmotor(frame);
    }
}

//handles getting values form the rear motor
void get_rearmotor(uint8_t* frame)
{
    switch(frame[OPTION_OFFSET])
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
    switch(frame[OPTION_OFFSET])
    {
        case 0: //set motor direction
            rear_direction = frame[DATA_OFFSET];
            break;
        case 1://set motor speed
            rear_speed = NO_to_int16(&frame[DATA_OFFSET]);
            break;
        case 2://set encoder counter
            QuadDec_Rear_WriteCounter(NO_to_int16(&frame[DATA_OFFSET]));
            break;
        case 3://set current data -- not possible, remove?
            break;
        case 4://set mode pin
            Mode_Rear_Write(frame[DATA_OFFSET]);
            break;
        case 5://set power pin
            Power_Rear_Write(frame[DATA_OFFSET]);
            break;
    }
}


/* [] END OF FILE */
