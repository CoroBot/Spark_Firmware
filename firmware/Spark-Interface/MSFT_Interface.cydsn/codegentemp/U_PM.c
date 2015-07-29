/*******************************************************************************
* File Name: U_PM.c
* Version 2.50
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "U.h"


/***************************************
* Local data allocation
***************************************/

static U_BACKUP_STRUCT  U_backup =
{
    /* enableState - disabled */
    0u,
};



/*******************************************************************************
* Function Name: U_SaveConfig
********************************************************************************
*
* Summary:
*  This function saves the component nonretention control register.
*  Does not save the FIFO which is a set of nonretention registers.
*  This function is called by the U_Sleep() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  U_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void U_SaveConfig(void)
{
    #if(U_CONTROL_REG_REMOVED == 0u)
        U_backup.cr = U_CONTROL_REG;
    #endif /* End U_CONTROL_REG_REMOVED */
}


/*******************************************************************************
* Function Name: U_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the nonretention control register except FIFO.
*  Does not restore the FIFO which is a set of nonretention registers.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  U_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
* Notes:
*  If this function is called without calling U_SaveConfig() 
*  first, the data loaded may be incorrect.
*
*******************************************************************************/
void U_RestoreConfig(void)
{
    #if(U_CONTROL_REG_REMOVED == 0u)
        U_CONTROL_REG = U_backup.cr;
    #endif /* End U_CONTROL_REG_REMOVED */
}


/*******************************************************************************
* Function Name: U_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for sleep. 
*  The U_Sleep() API saves the current component state. Then it
*  calls the U_Stop() function and calls 
*  U_SaveConfig() to save the hardware configuration.
*  Call the U_Sleep() function before calling the CyPmSleep() 
*  or the CyPmHibernate() function. 
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  U_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void U_Sleep(void)
{
    #if(U_RX_ENABLED || U_HD_ENABLED)
        if((U_RXSTATUS_ACTL_REG  & U_INT_ENABLE) != 0u)
        {
            U_backup.enableState = 1u;
        }
        else
        {
            U_backup.enableState = 0u;
        }
    #else
        if((U_TXSTATUS_ACTL_REG  & U_INT_ENABLE) !=0u)
        {
            U_backup.enableState = 1u;
        }
        else
        {
            U_backup.enableState = 0u;
        }
    #endif /* End U_RX_ENABLED || U_HD_ENABLED*/

    U_Stop();
    U_SaveConfig();
}


/*******************************************************************************
* Function Name: U_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when 
*  U_Sleep() was called. The U_Wakeup() function
*  calls the U_RestoreConfig() function to restore the 
*  configuration. If the component was enabled before the 
*  U_Sleep() function was called, the U_Wakeup()
*  function will also re-enable the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  U_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void U_Wakeup(void)
{
    U_RestoreConfig();
    #if( (U_RX_ENABLED) || (U_HD_ENABLED) )
        U_ClearRxBuffer();
    #endif /* End (U_RX_ENABLED) || (U_HD_ENABLED) */
    #if(U_TX_ENABLED || U_HD_ENABLED)
        U_ClearTxBuffer();
    #endif /* End U_TX_ENABLED || U_HD_ENABLED */

    if(U_backup.enableState != 0u)
    {
        U_Enable();
    }
}


/* [] END OF FILE */
