/*******************************************************************************
* File Name: TxReg_PM.c
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

#include "TxReg.h"

/* Check for removal by optimization */
#if !defined(TxReg_Sync_ctrl_reg__REMOVED)

static TxReg_BACKUP_STRUCT  TxReg_backup = {0u};

    
/*******************************************************************************
* Function Name: TxReg_SaveConfig
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
void TxReg_SaveConfig(void) 
{
    TxReg_backup.controlState = TxReg_Control;
}


/*******************************************************************************
* Function Name: TxReg_RestoreConfig
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
void TxReg_RestoreConfig(void) 
{
     TxReg_Control = TxReg_backup.controlState;
}


/*******************************************************************************
* Function Name: TxReg_Sleep
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
void TxReg_Sleep(void) 
{
    TxReg_SaveConfig();
}


/*******************************************************************************
* Function Name: TxReg_Wakeup
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
void TxReg_Wakeup(void)  
{
    TxReg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
