/*******************************************************************************
* File Name: Rear_Dir_PM.c
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

#include "Rear_Dir.h"

/* Check for removal by optimization */
#if !defined(Rear_Dir_Sync_ctrl_reg__REMOVED)

static Rear_Dir_BACKUP_STRUCT  Rear_Dir_backup = {0u};

    
/*******************************************************************************
* Function Name: Rear_Dir_SaveConfig
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
void Rear_Dir_SaveConfig(void) 
{
    Rear_Dir_backup.controlState = Rear_Dir_Control;
}


/*******************************************************************************
* Function Name: Rear_Dir_RestoreConfig
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
void Rear_Dir_RestoreConfig(void) 
{
     Rear_Dir_Control = Rear_Dir_backup.controlState;
}


/*******************************************************************************
* Function Name: Rear_Dir_Sleep
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
void Rear_Dir_Sleep(void) 
{
    Rear_Dir_SaveConfig();
}


/*******************************************************************************
* Function Name: Rear_Dir_Wakeup
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
void Rear_Dir_Wakeup(void)  
{
    Rear_Dir_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
