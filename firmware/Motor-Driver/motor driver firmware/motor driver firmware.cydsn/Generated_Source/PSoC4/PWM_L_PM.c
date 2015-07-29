/*******************************************************************************
* File Name: PWM_L_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_L.h"

static PWM_L_BACKUP_STRUCT PWM_L_backup;


/*******************************************************************************
* Function Name: PWM_L_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_L_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_L_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_L_Sleep(void)
{
    if(0u != (PWM_L_BLOCK_CONTROL_REG & PWM_L_MASK))
    {
        PWM_L_backup.enableState = 1u;
    }
    else
    {
        PWM_L_backup.enableState = 0u;
    }

    PWM_L_Stop();
    PWM_L_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_L_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_L_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_L_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_L_Wakeup(void)
{
    PWM_L_RestoreConfig();

    if(0u != PWM_L_backup.enableState)
    {
        PWM_L_Enable();
    }
}


/* [] END OF FILE */
