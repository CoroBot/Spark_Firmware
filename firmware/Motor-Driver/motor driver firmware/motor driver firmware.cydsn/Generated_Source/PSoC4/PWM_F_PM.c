/*******************************************************************************
* File Name: PWM_F_PM.c
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

#include "PWM_F.h"

static PWM_F_BACKUP_STRUCT PWM_F_backup;


/*******************************************************************************
* Function Name: PWM_F_SaveConfig
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
void PWM_F_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_F_Sleep
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
void PWM_F_Sleep(void)
{
    if(0u != (PWM_F_BLOCK_CONTROL_REG & PWM_F_MASK))
    {
        PWM_F_backup.enableState = 1u;
    }
    else
    {
        PWM_F_backup.enableState = 0u;
    }

    PWM_F_Stop();
    PWM_F_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_F_RestoreConfig
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
void PWM_F_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_F_Wakeup
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
void PWM_F_Wakeup(void)
{
    PWM_F_RestoreConfig();

    if(0u != PWM_F_backup.enableState)
    {
        PWM_F_Enable();
    }
}


/* [] END OF FILE */
