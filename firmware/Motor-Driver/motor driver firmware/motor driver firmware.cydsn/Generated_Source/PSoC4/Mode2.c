/*******************************************************************************
* File Name: Mode2.c  
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
#include "Mode2.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Mode2_PC =   (Mode2_PC & \
                                (uint32)(~(uint32)(Mode2_DRIVE_MODE_IND_MASK << (Mode2_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Mode2_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Mode2_Write
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
void Mode2_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Mode2_DR & (uint8)(~Mode2_MASK));
    drVal = (drVal | ((uint8)(value << Mode2_SHIFT) & Mode2_MASK));
    Mode2_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Mode2_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Mode2_DM_STRONG     Strong Drive 
*  Mode2_DM_OD_HI      Open Drain, Drives High 
*  Mode2_DM_OD_LO      Open Drain, Drives Low 
*  Mode2_DM_RES_UP     Resistive Pull Up 
*  Mode2_DM_RES_DWN    Resistive Pull Down 
*  Mode2_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Mode2_DM_DIG_HIZ    High Impedance Digital 
*  Mode2_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Mode2_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Mode2__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Mode2_Read
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
*  Macro Mode2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Mode2_Read(void) 
{
    return (uint8)((Mode2_PS & Mode2_MASK) >> Mode2_SHIFT);
}


/*******************************************************************************
* Function Name: Mode2_ReadDataReg
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
uint8 Mode2_ReadDataReg(void) 
{
    return (uint8)((Mode2_DR & Mode2_MASK) >> Mode2_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Mode2_INTSTAT) 

    /*******************************************************************************
    * Function Name: Mode2_ClearInterrupt
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
    uint8 Mode2_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Mode2_INTSTAT & Mode2_MASK);
		Mode2_INTSTAT = maskedStatus;
        return maskedStatus >> Mode2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
