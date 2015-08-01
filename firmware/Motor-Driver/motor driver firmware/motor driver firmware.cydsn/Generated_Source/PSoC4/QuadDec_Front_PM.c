/*******************************************************************************
* File Name: QuadDec_Front_PM.c
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

#include "QuadDec_Front.h"

static QuadDec_Front_BACKUP_STRUCT QuadDec_Front_backup;


/*******************************************************************************
* Function Name: QuadDec_Front_SaveConfig
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
void QuadDec_Front_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec_Front_Sleep
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
void QuadDec_Front_Sleep(void)
{
    if(0u != (QuadDec_Front_BLOCK_CONTROL_REG & QuadDec_Front_MASK))
    {
        QuadDec_Front_backup.enableState = 1u;
    }
    else
    {
        QuadDec_Front_backup.enableState = 0u;
    }

    QuadDec_Front_Stop();
    QuadDec_Front_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec_Front_RestoreConfig
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
void QuadDec_Front_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec_Front_Wakeup
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
void QuadDec_Front_Wakeup(void)
{
    QuadDec_Front_RestoreConfig();

    if(0u != QuadDec_Front_backup.enableState)
    {
        QuadDec_Front_Enable();
    }
}


/* [] END OF FILE */
