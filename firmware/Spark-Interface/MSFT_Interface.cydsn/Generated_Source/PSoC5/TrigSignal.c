/*******************************************************************************
* File Name: TrigSignal.c  
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
#include "TrigSignal.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 TrigSignal__PORT == 15 && ((TrigSignal__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: TrigSignal_Write
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
void TrigSignal_Write(uint8 value) 
{
    uint8 staticBits = (TrigSignal_DR & (uint8)(~TrigSignal_MASK));
    TrigSignal_DR = staticBits | ((uint8)(value << TrigSignal_SHIFT) & TrigSignal_MASK);
}


/*******************************************************************************
* Function Name: TrigSignal_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  TrigSignal_DM_STRONG     Strong Drive 
*  TrigSignal_DM_OD_HI      Open Drain, Drives High 
*  TrigSignal_DM_OD_LO      Open Drain, Drives Low 
*  TrigSignal_DM_RES_UP     Resistive Pull Up 
*  TrigSignal_DM_RES_DWN    Resistive Pull Down 
*  TrigSignal_DM_RES_UPDWN  Resistive Pull Up/Down 
*  TrigSignal_DM_DIG_HIZ    High Impedance Digital 
*  TrigSignal_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void TrigSignal_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(TrigSignal_0, mode);
}


/*******************************************************************************
* Function Name: TrigSignal_Read
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
*  Macro TrigSignal_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TrigSignal_Read(void) 
{
    return (TrigSignal_PS & TrigSignal_MASK) >> TrigSignal_SHIFT;
}


/*******************************************************************************
* Function Name: TrigSignal_ReadDataReg
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
uint8 TrigSignal_ReadDataReg(void) 
{
    return (TrigSignal_DR & TrigSignal_MASK) >> TrigSignal_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TrigSignal_INTSTAT) 

    /*******************************************************************************
    * Function Name: TrigSignal_ClearInterrupt
    ********************************************************************************
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
    uint8 TrigSignal_ClearInterrupt(void) 
    {
        return (TrigSignal_INTSTAT & TrigSignal_MASK) >> TrigSignal_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
