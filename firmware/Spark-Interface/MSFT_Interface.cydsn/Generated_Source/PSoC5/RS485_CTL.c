/*******************************************************************************
* File Name: RS485_CTL.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "RS485_CTL.h"

#if !defined(RS485_CTL_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: RS485_CTL_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 RS485_CTL_Read(void) 
{ 
    return RS485_CTL_Status;
}


/*******************************************************************************
* Function Name: RS485_CTL_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RS485_CTL_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    RS485_CTL_Status_Aux_Ctrl |= RS485_CTL_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: RS485_CTL_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RS485_CTL_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    RS485_CTL_Status_Aux_Ctrl &= (uint8)(~RS485_CTL_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: RS485_CTL_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void RS485_CTL_WriteMask(uint8 mask) 
{
    #if(RS485_CTL_INPUTS < 8u)
    	mask &= ((uint8)(1u << RS485_CTL_INPUTS) - 1u);
	#endif /* End RS485_CTL_INPUTS < 8u */
    RS485_CTL_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: RS485_CTL_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 RS485_CTL_ReadMask(void) 
{
    return RS485_CTL_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
