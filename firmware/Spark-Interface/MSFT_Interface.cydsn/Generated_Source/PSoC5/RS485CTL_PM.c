/*******************************************************************************
* File Name: RS485CTL_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "RS485CTL.h"

/* Check for removal by optimization */
#if !defined(RS485CTL_Sync_ctrl_reg__REMOVED)

static RS485CTL_BACKUP_STRUCT  RS485CTL_backup = {0u};

    
/*******************************************************************************
* Function Name: RS485CTL_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void RS485CTL_SaveConfig(void) 
{
    RS485CTL_backup.controlState = RS485CTL_Control;
}


/*******************************************************************************
* Function Name: RS485CTL_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void RS485CTL_RestoreConfig(void) 
{
     RS485CTL_Control = RS485CTL_backup.controlState;
}


/*******************************************************************************
* Function Name: RS485CTL_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void RS485CTL_Sleep(void) 
{
    RS485CTL_SaveConfig();
}


/*******************************************************************************
* Function Name: RS485CTL_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void RS485CTL_Wakeup(void)  
{
    RS485CTL_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
