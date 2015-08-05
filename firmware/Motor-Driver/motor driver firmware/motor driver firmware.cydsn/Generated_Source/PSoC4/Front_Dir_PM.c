/*******************************************************************************
* File Name: Front_Dir_PM.c
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

#include "Front_Dir.h"

/* Check for removal by optimization */
#if !defined(Front_Dir_Sync_ctrl_reg__REMOVED)

static Front_Dir_BACKUP_STRUCT  Front_Dir_backup = {0u};

    
/*******************************************************************************
* Function Name: Front_Dir_SaveConfig
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
void Front_Dir_SaveConfig(void) 
{
    Front_Dir_backup.controlState = Front_Dir_Control;
}


/*******************************************************************************
* Function Name: Front_Dir_RestoreConfig
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
void Front_Dir_RestoreConfig(void) 
{
     Front_Dir_Control = Front_Dir_backup.controlState;
}


/*******************************************************************************
* Function Name: Front_Dir_Sleep
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
void Front_Dir_Sleep(void) 
{
    Front_Dir_SaveConfig();
}


/*******************************************************************************
* Function Name: Front_Dir_Wakeup
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
void Front_Dir_Wakeup(void)  
{
    Front_Dir_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
