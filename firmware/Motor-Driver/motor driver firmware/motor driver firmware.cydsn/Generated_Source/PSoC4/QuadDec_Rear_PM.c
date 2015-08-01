/*******************************************************************************
* File Name: QuadDec_Rear_PM.c
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

#include "QuadDec_Rear.h"

static QuadDec_Rear_BACKUP_STRUCT QuadDec_Rear_backup;


/*******************************************************************************
* Function Name: QuadDec_Rear_SaveConfig
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
void QuadDec_Rear_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec_Rear_Sleep
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
void QuadDec_Rear_Sleep(void)
{
    if(0u != (QuadDec_Rear_BLOCK_CONTROL_REG & QuadDec_Rear_MASK))
    {
        QuadDec_Rear_backup.enableState = 1u;
    }
    else
    {
        QuadDec_Rear_backup.enableState = 0u;
    }

    QuadDec_Rear_Stop();
    QuadDec_Rear_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec_Rear_RestoreConfig
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
void QuadDec_Rear_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec_Rear_Wakeup
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
void QuadDec_Rear_Wakeup(void)
{
    QuadDec_Rear_RestoreConfig();

    if(0u != QuadDec_Rear_backup.enableState)
    {
        QuadDec_Rear_Enable();
    }
}


/* [] END OF FILE */
