/*******************************************************************************
* File Name: Motor_Current_ADC_intClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Motor_Current_ADC_intClock_H)
#define CY_CLOCK_Motor_Current_ADC_intClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Motor_Current_ADC_intClock_StartEx(uint32 alignClkDiv);
#define Motor_Current_ADC_intClock_Start() \
    Motor_Current_ADC_intClock_StartEx(Motor_Current_ADC_intClock__PA_DIV_ID)

#else

void Motor_Current_ADC_intClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Motor_Current_ADC_intClock_Stop(void);

void Motor_Current_ADC_intClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Motor_Current_ADC_intClock_GetDividerRegister(void);
uint8  Motor_Current_ADC_intClock_GetFractionalDividerRegister(void);

#define Motor_Current_ADC_intClock_Enable()                         Motor_Current_ADC_intClock_Start()
#define Motor_Current_ADC_intClock_Disable()                        Motor_Current_ADC_intClock_Stop()
#define Motor_Current_ADC_intClock_SetDividerRegister(clkDivider, reset)  \
    Motor_Current_ADC_intClock_SetFractionalDividerRegister((clkDivider), 0u)
#define Motor_Current_ADC_intClock_SetDivider(clkDivider)           Motor_Current_ADC_intClock_SetDividerRegister((clkDivider), 1u)
#define Motor_Current_ADC_intClock_SetDividerValue(clkDivider)      Motor_Current_ADC_intClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Motor_Current_ADC_intClock_DIV_ID     Motor_Current_ADC_intClock__DIV_ID

#define Motor_Current_ADC_intClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Motor_Current_ADC_intClock_CTRL_REG   (*(reg32 *)Motor_Current_ADC_intClock__CTRL_REGISTER)
#define Motor_Current_ADC_intClock_DIV_REG    (*(reg32 *)Motor_Current_ADC_intClock__DIV_REGISTER)

#define Motor_Current_ADC_intClock_CMD_DIV_SHIFT          (0u)
#define Motor_Current_ADC_intClock_CMD_PA_DIV_SHIFT       (8u)
#define Motor_Current_ADC_intClock_CMD_DISABLE_SHIFT      (30u)
#define Motor_Current_ADC_intClock_CMD_ENABLE_SHIFT       (31u)

#define Motor_Current_ADC_intClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Motor_Current_ADC_intClock_CMD_DISABLE_SHIFT))
#define Motor_Current_ADC_intClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Motor_Current_ADC_intClock_CMD_ENABLE_SHIFT))

#define Motor_Current_ADC_intClock_DIV_FRAC_MASK  (0x000000F8u)
#define Motor_Current_ADC_intClock_DIV_FRAC_SHIFT (3u)
#define Motor_Current_ADC_intClock_DIV_INT_MASK   (0xFFFFFF00u)
#define Motor_Current_ADC_intClock_DIV_INT_SHIFT  (8u)

#else 

#define Motor_Current_ADC_intClock_DIV_REG        (*(reg32 *)Motor_Current_ADC_intClock__REGISTER)
#define Motor_Current_ADC_intClock_ENABLE_REG     Motor_Current_ADC_intClock_DIV_REG
#define Motor_Current_ADC_intClock_DIV_FRAC_MASK  Motor_Current_ADC_intClock__FRAC_MASK
#define Motor_Current_ADC_intClock_DIV_FRAC_SHIFT (16u)
#define Motor_Current_ADC_intClock_DIV_INT_MASK   Motor_Current_ADC_intClock__DIVIDER_MASK
#define Motor_Current_ADC_intClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Motor_Current_ADC_intClock_H) */

/* [] END OF FILE */
