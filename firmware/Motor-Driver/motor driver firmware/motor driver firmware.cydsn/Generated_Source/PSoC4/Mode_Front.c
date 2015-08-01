/*******************************************************************************
* File Name: Mode_Front.c  
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
#include "Mode_Front.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Mode_Front_PC =   (Mode_Front_PC & \
                                (uint32)(~(uint32)(Mode_Front_DRIVE_MODE_IND_MASK << (Mode_Front_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Mode_Front_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Mode_Front_Write
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
void Mode_Front_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Mode_Front_DR & (uint8)(~Mode_Front_MASK));
    drVal = (drVal | ((uint8)(value << Mode_Front_SHIFT) & Mode_Front_MASK));
    Mode_Front_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Mode_Front_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Mode_Front_DM_STRONG     Strong Drive 
*  Mode_Front_DM_OD_HI      Open Drain, Drives High 
*  Mode_Front_DM_OD_LO      Open Drain, Drives Low 
*  Mode_Front_DM_RES_UP     Resistive Pull Up 
*  Mode_Front_DM_RES_DWN    Resistive Pull Down 
*  Mode_Front_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Mode_Front_DM_DIG_HIZ    High Impedance Digital 
*  Mode_Front_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Mode_Front_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Mode_Front__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Mode_Front_Read
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
*  Macro Mode_Front_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Mode_Front_Read(void) 
{
    return (uint8)((Mode_Front_PS & Mode_Front_MASK) >> Mode_Front_SHIFT);
}


/*******************************************************************************
* Function Name: Mode_Front_ReadDataReg
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
uint8 Mode_Front_ReadDataReg(void) 
{
    return (uint8)((Mode_Front_DR & Mode_Front_MASK) >> Mode_Front_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Mode_Front_INTSTAT) 

    /*******************************************************************************
    * Function Name: Mode_Front_ClearInterrupt
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
    uint8 Mode_Front_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Mode_Front_INTSTAT & Mode_Front_MASK);
		Mode_Front_INTSTAT = maskedStatus;
        return maskedStatus >> Mode_Front_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
