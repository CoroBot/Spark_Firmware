/*******************************************************************************
* File Name: Power_Front.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Power_Front.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Power_Front_PC =   (Power_Front_PC & \
                                (uint32)(~(uint32)(Power_Front_DRIVE_MODE_IND_MASK << (Power_Front_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Power_Front_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Power_Front_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Power_Front_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Power_Front_DR & (uint8)(~Power_Front_MASK));
    drVal = (drVal | ((uint8)(value << Power_Front_SHIFT) & Power_Front_MASK));
    Power_Front_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Power_Front_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Power_Front_DM_STRONG     Strong Drive 
*  Power_Front_DM_OD_HI      Open Drain, Drives High 
*  Power_Front_DM_OD_LO      Open Drain, Drives Low 
*  Power_Front_DM_RES_UP     Resistive Pull Up 
*  Power_Front_DM_RES_DWN    Resistive Pull Down 
*  Power_Front_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Power_Front_DM_DIG_HIZ    High Impedance Digital 
*  Power_Front_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Power_Front_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Power_Front__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Power_Front_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Power_Front_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Power_Front_Read(void) 
{
    return (uint8)((Power_Front_PS & Power_Front_MASK) >> Power_Front_SHIFT);
}


/*******************************************************************************
* Function Name: Power_Front_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Power_Front_ReadDataReg(void) 
{
    return (uint8)((Power_Front_DR & Power_Front_MASK) >> Power_Front_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Power_Front_INTSTAT) 

    /*******************************************************************************
    * Function Name: Power_Front_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Power_Front_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Power_Front_INTSTAT & Power_Front_MASK);
		Power_Front_INTSTAT = maskedStatus;
        return maskedStatus >> Power_Front_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
