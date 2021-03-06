/*******************************************************************************
* File Name: cursense2.c  
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
#include "cursense2.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        cursense2_PC =   (cursense2_PC & \
                                (uint32)(~(uint32)(cursense2_DRIVE_MODE_IND_MASK << (cursense2_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (cursense2_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: cursense2_Write
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
void cursense2_Write(uint8 value) 
{
    uint8 drVal = (uint8)(cursense2_DR & (uint8)(~cursense2_MASK));
    drVal = (drVal | ((uint8)(value << cursense2_SHIFT) & cursense2_MASK));
    cursense2_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: cursense2_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  cursense2_DM_STRONG     Strong Drive 
*  cursense2_DM_OD_HI      Open Drain, Drives High 
*  cursense2_DM_OD_LO      Open Drain, Drives Low 
*  cursense2_DM_RES_UP     Resistive Pull Up 
*  cursense2_DM_RES_DWN    Resistive Pull Down 
*  cursense2_DM_RES_UPDWN  Resistive Pull Up/Down 
*  cursense2_DM_DIG_HIZ    High Impedance Digital 
*  cursense2_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void cursense2_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(cursense2__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: cursense2_Read
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
*  Macro cursense2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 cursense2_Read(void) 
{
    return (uint8)((cursense2_PS & cursense2_MASK) >> cursense2_SHIFT);
}


/*******************************************************************************
* Function Name: cursense2_ReadDataReg
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
uint8 cursense2_ReadDataReg(void) 
{
    return (uint8)((cursense2_DR & cursense2_MASK) >> cursense2_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(cursense2_INTSTAT) 

    /*******************************************************************************
    * Function Name: cursense2_ClearInterrupt
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
    uint8 cursense2_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(cursense2_INTSTAT & cursense2_MASK);
		cursense2_INTSTAT = maskedStatus;
        return maskedStatus >> cursense2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
