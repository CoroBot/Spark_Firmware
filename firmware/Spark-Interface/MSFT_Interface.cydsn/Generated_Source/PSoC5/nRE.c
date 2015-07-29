/*******************************************************************************
* File Name: nRE.c  
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
#include "nRE.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 nRE__PORT == 15 && ((nRE__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: nRE_Write
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
void nRE_Write(uint8 value) 
{
    uint8 staticBits = (nRE_DR & (uint8)(~nRE_MASK));
    nRE_DR = staticBits | ((uint8)(value << nRE_SHIFT) & nRE_MASK);
}


/*******************************************************************************
* Function Name: nRE_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  nRE_DM_STRONG     Strong Drive 
*  nRE_DM_OD_HI      Open Drain, Drives High 
*  nRE_DM_OD_LO      Open Drain, Drives Low 
*  nRE_DM_RES_UP     Resistive Pull Up 
*  nRE_DM_RES_DWN    Resistive Pull Down 
*  nRE_DM_RES_UPDWN  Resistive Pull Up/Down 
*  nRE_DM_DIG_HIZ    High Impedance Digital 
*  nRE_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void nRE_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(nRE_0, mode);
}


/*******************************************************************************
* Function Name: nRE_Read
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
*  Macro nRE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 nRE_Read(void) 
{
    return (nRE_PS & nRE_MASK) >> nRE_SHIFT;
}


/*******************************************************************************
* Function Name: nRE_ReadDataReg
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
uint8 nRE_ReadDataReg(void) 
{
    return (nRE_DR & nRE_MASK) >> nRE_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(nRE_INTSTAT) 

    /*******************************************************************************
    * Function Name: nRE_ClearInterrupt
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
    uint8 nRE_ClearInterrupt(void) 
    {
        return (nRE_INTSTAT & nRE_MASK) >> nRE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
