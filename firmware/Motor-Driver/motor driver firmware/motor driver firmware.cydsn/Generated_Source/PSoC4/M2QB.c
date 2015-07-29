/*******************************************************************************
* File Name: M2QB.c  
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
#include "M2QB.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        M2QB_PC =   (M2QB_PC & \
                                (uint32)(~(uint32)(M2QB_DRIVE_MODE_IND_MASK << (M2QB_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (M2QB_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: M2QB_Write
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
void M2QB_Write(uint8 value) 
{
    uint8 drVal = (uint8)(M2QB_DR & (uint8)(~M2QB_MASK));
    drVal = (drVal | ((uint8)(value << M2QB_SHIFT) & M2QB_MASK));
    M2QB_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: M2QB_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  M2QB_DM_STRONG     Strong Drive 
*  M2QB_DM_OD_HI      Open Drain, Drives High 
*  M2QB_DM_OD_LO      Open Drain, Drives Low 
*  M2QB_DM_RES_UP     Resistive Pull Up 
*  M2QB_DM_RES_DWN    Resistive Pull Down 
*  M2QB_DM_RES_UPDWN  Resistive Pull Up/Down 
*  M2QB_DM_DIG_HIZ    High Impedance Digital 
*  M2QB_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void M2QB_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(M2QB__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: M2QB_Read
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
*  Macro M2QB_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 M2QB_Read(void) 
{
    return (uint8)((M2QB_PS & M2QB_MASK) >> M2QB_SHIFT);
}


/*******************************************************************************
* Function Name: M2QB_ReadDataReg
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
uint8 M2QB_ReadDataReg(void) 
{
    return (uint8)((M2QB_DR & M2QB_MASK) >> M2QB_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(M2QB_INTSTAT) 

    /*******************************************************************************
    * Function Name: M2QB_ClearInterrupt
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
    uint8 M2QB_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(M2QB_INTSTAT & M2QB_MASK);
		M2QB_INTSTAT = maskedStatus;
        return maskedStatus >> M2QB_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
