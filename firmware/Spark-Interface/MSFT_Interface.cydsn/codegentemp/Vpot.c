/*******************************************************************************
* File Name: Vpot.c  
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
#include "Vpot.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Vpot__PORT == 15 && ((Vpot__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Vpot_Write
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
void Vpot_Write(uint8 value) 
{
    uint8 staticBits = (Vpot_DR & (uint8)(~Vpot_MASK));
    Vpot_DR = staticBits | ((uint8)(value << Vpot_SHIFT) & Vpot_MASK);
}


/*******************************************************************************
* Function Name: Vpot_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Vpot_DM_STRONG     Strong Drive 
*  Vpot_DM_OD_HI      Open Drain, Drives High 
*  Vpot_DM_OD_LO      Open Drain, Drives Low 
*  Vpot_DM_RES_UP     Resistive Pull Up 
*  Vpot_DM_RES_DWN    Resistive Pull Down 
*  Vpot_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Vpot_DM_DIG_HIZ    High Impedance Digital 
*  Vpot_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Vpot_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Vpot_0, mode);
}


/*******************************************************************************
* Function Name: Vpot_Read
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
*  Macro Vpot_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Vpot_Read(void) 
{
    return (Vpot_PS & Vpot_MASK) >> Vpot_SHIFT;
}


/*******************************************************************************
* Function Name: Vpot_ReadDataReg
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
uint8 Vpot_ReadDataReg(void) 
{
    return (Vpot_DR & Vpot_MASK) >> Vpot_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Vpot_INTSTAT) 

    /*******************************************************************************
    * Function Name: Vpot_ClearInterrupt
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
    uint8 Vpot_ClearInterrupt(void) 
    {
        return (Vpot_INTSTAT & Vpot_MASK) >> Vpot_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
