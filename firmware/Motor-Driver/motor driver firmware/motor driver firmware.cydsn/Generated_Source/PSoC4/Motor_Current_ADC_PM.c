/*******************************************************************************
* File Name: Motor_Current_ADC_PM.c
* Version 2.10
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

#include "Motor_Current_ADC.h"


/***************************************
* Local data allocation
***************************************/

static Motor_Current_ADC_BACKUP_STRUCT  Motor_Current_ADC_backup =
{
    Motor_Current_ADC_DISABLED
};


/*******************************************************************************
* Function Name: Motor_Current_ADC_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Motor_Current_ADC_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Motor_Current_ADC_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Motor_Current_ADC_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Motor_Current_ADC_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Motor_Current_ADC_backup - modified.
*
*******************************************************************************/
void Motor_Current_ADC_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    Motor_Current_ADC_SAR_DFT_CTRL_REG |= Motor_Current_ADC_ADFT_OVERRIDE;
    if((Motor_Current_ADC_SAR_CTRL_REG  & Motor_Current_ADC_ENABLE) != 0u)
    {
        if((Motor_Current_ADC_SAR_SAMPLE_CTRL_REG & Motor_Current_ADC_CONTINUOUS_EN) != 0u)
        {
            Motor_Current_ADC_backup.enableState = Motor_Current_ADC_ENABLED | Motor_Current_ADC_STARTED;
        }
        else
        {
            Motor_Current_ADC_backup.enableState = Motor_Current_ADC_ENABLED;
        }
        Motor_Current_ADC_StopConvert();
        Motor_Current_ADC_Stop();
        
        /* Disable the SAR internal pump before entering the chip low power mode */
        if((Motor_Current_ADC_SAR_CTRL_REG & Motor_Current_ADC_BOOSTPUMP_EN) != 0u)
        {
            Motor_Current_ADC_SAR_CTRL_REG &= (uint32)~Motor_Current_ADC_BOOSTPUMP_EN;
            Motor_Current_ADC_backup.enableState |= Motor_Current_ADC_BOOSTPUMP_ENABLED;
        }
    }
    else
    {
        Motor_Current_ADC_backup.enableState = Motor_Current_ADC_DISABLED;
    }
}


/*******************************************************************************
* Function Name: Motor_Current_ADC_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers.
*  This should be called just after awaking from sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Motor_Current_ADC_backup - used.
*
*******************************************************************************/
void Motor_Current_ADC_Wakeup(void)
{
    Motor_Current_ADC_SAR_DFT_CTRL_REG &= (uint32)~Motor_Current_ADC_ADFT_OVERRIDE;
    if(Motor_Current_ADC_backup.enableState != Motor_Current_ADC_DISABLED)
    {
        /* Enable the SAR internal pump  */
        if((Motor_Current_ADC_backup.enableState & Motor_Current_ADC_BOOSTPUMP_ENABLED) != 0u)
        {
            Motor_Current_ADC_SAR_CTRL_REG |= Motor_Current_ADC_BOOSTPUMP_EN;
        }
        Motor_Current_ADC_Enable();
        if((Motor_Current_ADC_backup.enableState & Motor_Current_ADC_STARTED) != 0u)
        {
            Motor_Current_ADC_StartConvert();
        }
    }
}
/* [] END OF FILE */
