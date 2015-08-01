/*******************************************************************************
* File Name: QuadDec_Rear.h
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the QuadDec_Rear
*  component.
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

#if !defined(CY_TCPWM_QuadDec_Rear_H)
#define CY_TCPWM_QuadDec_Rear_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} QuadDec_Rear_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  QuadDec_Rear_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define QuadDec_Rear_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define QuadDec_Rear_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define QuadDec_Rear_CONFIG                         (3lu)

/* Quad Mode */
/* Parameters */
#define QuadDec_Rear_QUAD_ENCODING_MODES            (2lu)

/* Signal modes */
#define QuadDec_Rear_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define QuadDec_Rear_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define QuadDec_Rear_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define QuadDec_Rear_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define QuadDec_Rear_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define QuadDec_Rear_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define QuadDec_Rear_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define QuadDec_Rear_TC_RUN_MODE                    (0lu)
#define QuadDec_Rear_TC_COUNTER_MODE                (0lu)
#define QuadDec_Rear_TC_COMP_CAP_MODE               (2lu)
#define QuadDec_Rear_TC_PRESCALER                   (0lu)

/* Signal modes */
#define QuadDec_Rear_TC_RELOAD_SIGNAL_MODE          (0lu)
#define QuadDec_Rear_TC_COUNT_SIGNAL_MODE           (3lu)
#define QuadDec_Rear_TC_START_SIGNAL_MODE           (0lu)
#define QuadDec_Rear_TC_STOP_SIGNAL_MODE            (0lu)
#define QuadDec_Rear_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define QuadDec_Rear_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define QuadDec_Rear_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define QuadDec_Rear_TC_START_SIGNAL_PRESENT        (0lu)
#define QuadDec_Rear_TC_STOP_SIGNAL_PRESENT         (0lu)
#define QuadDec_Rear_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QuadDec_Rear_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define QuadDec_Rear_PWM_KILL_EVENT                 (0lu)
#define QuadDec_Rear_PWM_STOP_EVENT                 (0lu)
#define QuadDec_Rear_PWM_MODE                       (4lu)
#define QuadDec_Rear_PWM_OUT_N_INVERT               (0lu)
#define QuadDec_Rear_PWM_OUT_INVERT                 (0lu)
#define QuadDec_Rear_PWM_ALIGN                      (0lu)
#define QuadDec_Rear_PWM_RUN_MODE                   (0lu)
#define QuadDec_Rear_PWM_DEAD_TIME_CYCLE            (0lu)
#define QuadDec_Rear_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define QuadDec_Rear_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define QuadDec_Rear_PWM_COUNT_SIGNAL_MODE          (3lu)
#define QuadDec_Rear_PWM_START_SIGNAL_MODE          (0lu)
#define QuadDec_Rear_PWM_STOP_SIGNAL_MODE           (0lu)
#define QuadDec_Rear_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define QuadDec_Rear_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define QuadDec_Rear_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define QuadDec_Rear_PWM_START_SIGNAL_PRESENT       (0lu)
#define QuadDec_Rear_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define QuadDec_Rear_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QuadDec_Rear_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define QuadDec_Rear_TC_PERIOD_VALUE                (65535lu)
#define QuadDec_Rear_TC_COMPARE_VALUE               (65535lu)
#define QuadDec_Rear_TC_COMPARE_BUF_VALUE           (65535lu)
#define QuadDec_Rear_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define QuadDec_Rear_PWM_PERIOD_VALUE               (65535lu)
#define QuadDec_Rear_PWM_PERIOD_BUF_VALUE           (65535lu)
#define QuadDec_Rear_PWM_PERIOD_SWAP                (0lu)
#define QuadDec_Rear_PWM_COMPARE_VALUE              (65535lu)
#define QuadDec_Rear_PWM_COMPARE_BUF_VALUE          (65535lu)
#define QuadDec_Rear_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QuadDec_Rear__LEFT 0
#define QuadDec_Rear__RIGHT 1
#define QuadDec_Rear__CENTER 2
#define QuadDec_Rear__ASYMMETRIC 3

#define QuadDec_Rear__X1 0
#define QuadDec_Rear__X2 1
#define QuadDec_Rear__X4 2

#define QuadDec_Rear__PWM 4
#define QuadDec_Rear__PWM_DT 5
#define QuadDec_Rear__PWM_PR 6

#define QuadDec_Rear__INVERSE 1
#define QuadDec_Rear__DIRECT 0

#define QuadDec_Rear__CAPTURE 2
#define QuadDec_Rear__COMPARE 0

#define QuadDec_Rear__TRIG_LEVEL 3
#define QuadDec_Rear__TRIG_RISING 0
#define QuadDec_Rear__TRIG_FALLING 1
#define QuadDec_Rear__TRIG_BOTH 2

#define QuadDec_Rear__INTR_MASK_TC 1
#define QuadDec_Rear__INTR_MASK_CC_MATCH 2
#define QuadDec_Rear__INTR_MASK_NONE 0
#define QuadDec_Rear__INTR_MASK_TC_CC 3

#define QuadDec_Rear__UNCONFIG 8
#define QuadDec_Rear__TIMER 1
#define QuadDec_Rear__QUAD 3
#define QuadDec_Rear__PWM_SEL 7

#define QuadDec_Rear__COUNT_UP 0
#define QuadDec_Rear__COUNT_DOWN 1
#define QuadDec_Rear__COUNT_UPDOWN0 2
#define QuadDec_Rear__COUNT_UPDOWN1 3


/* Prescaler */
#define QuadDec_Rear_PRESCALE_DIVBY1                ((uint32)(0u << QuadDec_Rear_PRESCALER_SHIFT))
#define QuadDec_Rear_PRESCALE_DIVBY2                ((uint32)(1u << QuadDec_Rear_PRESCALER_SHIFT))
#define QuadDec_Rear_PRESCALE_DIVBY4                ((uint32)(2u << QuadDec_Rear_PRESCALER_SHIFT))
#define QuadDec_Rear_PRESCALE_DIVBY8                ((uint32)(3u << QuadDec_Rear_PRESCALER_SHIFT))
#define QuadDec_Rear_PRESCALE_DIVBY16               ((uint32)(4u << QuadDec_Rear_PRESCALER_SHIFT))
#define QuadDec_Rear_PRESCALE_DIVBY32               ((uint32)(5u << QuadDec_Rear_PRESCALER_SHIFT))
#define QuadDec_Rear_PRESCALE_DIVBY64               ((uint32)(6u << QuadDec_Rear_PRESCALER_SHIFT))
#define QuadDec_Rear_PRESCALE_DIVBY128              ((uint32)(7u << QuadDec_Rear_PRESCALER_SHIFT))

/* TCPWM set modes */
#define QuadDec_Rear_MODE_TIMER_COMPARE             ((uint32)(QuadDec_Rear__COMPARE         <<  \
                                                                  QuadDec_Rear_MODE_SHIFT))
#define QuadDec_Rear_MODE_TIMER_CAPTURE             ((uint32)(QuadDec_Rear__CAPTURE         <<  \
                                                                  QuadDec_Rear_MODE_SHIFT))
#define QuadDec_Rear_MODE_QUAD                      ((uint32)(QuadDec_Rear__QUAD            <<  \
                                                                  QuadDec_Rear_MODE_SHIFT))
#define QuadDec_Rear_MODE_PWM                       ((uint32)(QuadDec_Rear__PWM             <<  \
                                                                  QuadDec_Rear_MODE_SHIFT))
#define QuadDec_Rear_MODE_PWM_DT                    ((uint32)(QuadDec_Rear__PWM_DT          <<  \
                                                                  QuadDec_Rear_MODE_SHIFT))
#define QuadDec_Rear_MODE_PWM_PR                    ((uint32)(QuadDec_Rear__PWM_PR          <<  \
                                                                  QuadDec_Rear_MODE_SHIFT))

/* Quad Modes */
#define QuadDec_Rear_MODE_X1                        ((uint32)(QuadDec_Rear__X1              <<  \
                                                                  QuadDec_Rear_QUAD_MODE_SHIFT))
#define QuadDec_Rear_MODE_X2                        ((uint32)(QuadDec_Rear__X2              <<  \
                                                                  QuadDec_Rear_QUAD_MODE_SHIFT))
#define QuadDec_Rear_MODE_X4                        ((uint32)(QuadDec_Rear__X4              <<  \
                                                                  QuadDec_Rear_QUAD_MODE_SHIFT))

/* Counter modes */
#define QuadDec_Rear_COUNT_UP                       ((uint32)(QuadDec_Rear__COUNT_UP        <<  \
                                                                  QuadDec_Rear_UPDOWN_SHIFT))
#define QuadDec_Rear_COUNT_DOWN                     ((uint32)(QuadDec_Rear__COUNT_DOWN      <<  \
                                                                  QuadDec_Rear_UPDOWN_SHIFT))
#define QuadDec_Rear_COUNT_UPDOWN0                  ((uint32)(QuadDec_Rear__COUNT_UPDOWN0   <<  \
                                                                  QuadDec_Rear_UPDOWN_SHIFT))
#define QuadDec_Rear_COUNT_UPDOWN1                  ((uint32)(QuadDec_Rear__COUNT_UPDOWN1   <<  \
                                                                  QuadDec_Rear_UPDOWN_SHIFT))

/* PWM output invert */
#define QuadDec_Rear_INVERT_LINE                    ((uint32)(QuadDec_Rear__INVERSE         <<  \
                                                                  QuadDec_Rear_INV_OUT_SHIFT))
#define QuadDec_Rear_INVERT_LINE_N                  ((uint32)(QuadDec_Rear__INVERSE         <<  \
                                                                  QuadDec_Rear_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define QuadDec_Rear_TRIG_RISING                    ((uint32)QuadDec_Rear__TRIG_RISING)
#define QuadDec_Rear_TRIG_FALLING                   ((uint32)QuadDec_Rear__TRIG_FALLING)
#define QuadDec_Rear_TRIG_BOTH                      ((uint32)QuadDec_Rear__TRIG_BOTH)
#define QuadDec_Rear_TRIG_LEVEL                     ((uint32)QuadDec_Rear__TRIG_LEVEL)

/* Interrupt mask */
#define QuadDec_Rear_INTR_MASK_TC                   ((uint32)QuadDec_Rear__INTR_MASK_TC)
#define QuadDec_Rear_INTR_MASK_CC_MATCH             ((uint32)QuadDec_Rear__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define QuadDec_Rear_CC_MATCH_SET                   (0x00u)
#define QuadDec_Rear_CC_MATCH_CLEAR                 (0x01u)
#define QuadDec_Rear_CC_MATCH_INVERT                (0x02u)
#define QuadDec_Rear_CC_MATCH_NO_CHANGE             (0x03u)
#define QuadDec_Rear_OVERLOW_SET                    (0x00u)
#define QuadDec_Rear_OVERLOW_CLEAR                  (0x04u)
#define QuadDec_Rear_OVERLOW_INVERT                 (0x08u)
#define QuadDec_Rear_OVERLOW_NO_CHANGE              (0x0Cu)
#define QuadDec_Rear_UNDERFLOW_SET                  (0x00u)
#define QuadDec_Rear_UNDERFLOW_CLEAR                (0x10u)
#define QuadDec_Rear_UNDERFLOW_INVERT               (0x20u)
#define QuadDec_Rear_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define QuadDec_Rear_PWM_MODE_LEFT                  (QuadDec_Rear_CC_MATCH_CLEAR        |   \
                                                         QuadDec_Rear_OVERLOW_SET           |   \
                                                         QuadDec_Rear_UNDERFLOW_NO_CHANGE)
#define QuadDec_Rear_PWM_MODE_RIGHT                 (QuadDec_Rear_CC_MATCH_SET          |   \
                                                         QuadDec_Rear_OVERLOW_NO_CHANGE     |   \
                                                         QuadDec_Rear_UNDERFLOW_CLEAR)
#define QuadDec_Rear_PWM_MODE_ASYM                  (QuadDec_Rear_CC_MATCH_INVERT       |   \
                                                         QuadDec_Rear_OVERLOW_SET           |   \
                                                         QuadDec_Rear_UNDERFLOW_CLEAR)

#if (QuadDec_Rear_CY_TCPWM_V2)
    #if(QuadDec_Rear_CY_TCPWM_4000)
        #define QuadDec_Rear_PWM_MODE_CENTER                (QuadDec_Rear_CC_MATCH_INVERT       |   \
                                                                 QuadDec_Rear_OVERLOW_NO_CHANGE     |   \
                                                                 QuadDec_Rear_UNDERFLOW_CLEAR)
    #else
        #define QuadDec_Rear_PWM_MODE_CENTER                (QuadDec_Rear_CC_MATCH_INVERT       |   \
                                                                 QuadDec_Rear_OVERLOW_SET           |   \
                                                                 QuadDec_Rear_UNDERFLOW_CLEAR)
    #endif /* (QuadDec_Rear_CY_TCPWM_4000) */
#else
    #define QuadDec_Rear_PWM_MODE_CENTER                (QuadDec_Rear_CC_MATCH_INVERT       |   \
                                                             QuadDec_Rear_OVERLOW_NO_CHANGE     |   \
                                                             QuadDec_Rear_UNDERFLOW_CLEAR)
#endif /* (QuadDec_Rear_CY_TCPWM_NEW) */

/* Command operations without condition */
#define QuadDec_Rear_CMD_CAPTURE                    (0u)
#define QuadDec_Rear_CMD_RELOAD                     (8u)
#define QuadDec_Rear_CMD_STOP                       (16u)
#define QuadDec_Rear_CMD_START                      (24u)

/* Status */
#define QuadDec_Rear_STATUS_DOWN                    (1u)
#define QuadDec_Rear_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   QuadDec_Rear_Init(void);
void   QuadDec_Rear_Enable(void);
void   QuadDec_Rear_Start(void);
void   QuadDec_Rear_Stop(void);

void   QuadDec_Rear_SetMode(uint32 mode);
void   QuadDec_Rear_SetCounterMode(uint32 counterMode);
void   QuadDec_Rear_SetPWMMode(uint32 modeMask);
void   QuadDec_Rear_SetQDMode(uint32 qdMode);

void   QuadDec_Rear_SetPrescaler(uint32 prescaler);
void   QuadDec_Rear_TriggerCommand(uint32 mask, uint32 command);
void   QuadDec_Rear_SetOneShot(uint32 oneShotEnable);
uint32 QuadDec_Rear_ReadStatus(void);

void   QuadDec_Rear_SetPWMSyncKill(uint32 syncKillEnable);
void   QuadDec_Rear_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   QuadDec_Rear_SetPWMDeadTime(uint32 deadTime);
void   QuadDec_Rear_SetPWMInvert(uint32 mask);

void   QuadDec_Rear_SetInterruptMode(uint32 interruptMask);
uint32 QuadDec_Rear_GetInterruptSourceMasked(void);
uint32 QuadDec_Rear_GetInterruptSource(void);
void   QuadDec_Rear_ClearInterrupt(uint32 interruptMask);
void   QuadDec_Rear_SetInterrupt(uint32 interruptMask);

void   QuadDec_Rear_WriteCounter(uint32 count);
uint32 QuadDec_Rear_ReadCounter(void);

uint32 QuadDec_Rear_ReadCapture(void);
uint32 QuadDec_Rear_ReadCaptureBuf(void);

void   QuadDec_Rear_WritePeriod(uint32 period);
uint32 QuadDec_Rear_ReadPeriod(void);
void   QuadDec_Rear_WritePeriodBuf(uint32 periodBuf);
uint32 QuadDec_Rear_ReadPeriodBuf(void);

void   QuadDec_Rear_WriteCompare(uint32 compare);
uint32 QuadDec_Rear_ReadCompare(void);
void   QuadDec_Rear_WriteCompareBuf(uint32 compareBuf);
uint32 QuadDec_Rear_ReadCompareBuf(void);

void   QuadDec_Rear_SetPeriodSwap(uint32 swapEnable);
void   QuadDec_Rear_SetCompareSwap(uint32 swapEnable);

void   QuadDec_Rear_SetCaptureMode(uint32 triggerMode);
void   QuadDec_Rear_SetReloadMode(uint32 triggerMode);
void   QuadDec_Rear_SetStartMode(uint32 triggerMode);
void   QuadDec_Rear_SetStopMode(uint32 triggerMode);
void   QuadDec_Rear_SetCountMode(uint32 triggerMode);

void   QuadDec_Rear_SaveConfig(void);
void   QuadDec_Rear_RestoreConfig(void);
void   QuadDec_Rear_Sleep(void);
void   QuadDec_Rear_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define QuadDec_Rear_BLOCK_CONTROL_REG              (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QuadDec_Rear_BLOCK_CONTROL_PTR              ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QuadDec_Rear_COMMAND_REG                    (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QuadDec_Rear_COMMAND_PTR                    ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QuadDec_Rear_INTRRUPT_CAUSE_REG             (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QuadDec_Rear_INTRRUPT_CAUSE_PTR             ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QuadDec_Rear_CONTROL_REG                    (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__CTRL )
#define QuadDec_Rear_CONTROL_PTR                    ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__CTRL )
#define QuadDec_Rear_STATUS_REG                     (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__STATUS )
#define QuadDec_Rear_STATUS_PTR                     ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__STATUS )
#define QuadDec_Rear_COUNTER_REG                    (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__COUNTER )
#define QuadDec_Rear_COUNTER_PTR                    ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__COUNTER )
#define QuadDec_Rear_COMP_CAP_REG                   (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__CC )
#define QuadDec_Rear_COMP_CAP_PTR                   ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__CC )
#define QuadDec_Rear_COMP_CAP_BUF_REG               (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__CC_BUFF )
#define QuadDec_Rear_COMP_CAP_BUF_PTR               ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__CC_BUFF )
#define QuadDec_Rear_PERIOD_REG                     (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__PERIOD )
#define QuadDec_Rear_PERIOD_PTR                     ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__PERIOD )
#define QuadDec_Rear_PERIOD_BUF_REG                 (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QuadDec_Rear_PERIOD_BUF_PTR                 ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QuadDec_Rear_TRIG_CONTROL0_REG              (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QuadDec_Rear_TRIG_CONTROL0_PTR              ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QuadDec_Rear_TRIG_CONTROL1_REG              (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QuadDec_Rear_TRIG_CONTROL1_PTR              ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QuadDec_Rear_TRIG_CONTROL2_REG              (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QuadDec_Rear_TRIG_CONTROL2_PTR              ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QuadDec_Rear_INTERRUPT_REQ_REG              (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__INTR )
#define QuadDec_Rear_INTERRUPT_REQ_PTR              ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__INTR )
#define QuadDec_Rear_INTERRUPT_SET_REG              (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__INTR_SET )
#define QuadDec_Rear_INTERRUPT_SET_PTR              ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__INTR_SET )
#define QuadDec_Rear_INTERRUPT_MASK_REG             (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__INTR_MASK )
#define QuadDec_Rear_INTERRUPT_MASK_PTR             ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__INTR_MASK )
#define QuadDec_Rear_INTERRUPT_MASKED_REG           (*(reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__INTR_MASKED )
#define QuadDec_Rear_INTERRUPT_MASKED_PTR           ( (reg32 *) QuadDec_Rear_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define QuadDec_Rear_MASK                           ((uint32)QuadDec_Rear_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define QuadDec_Rear_RELOAD_CC_SHIFT                (0u)
#define QuadDec_Rear_RELOAD_PERIOD_SHIFT            (1u)
#define QuadDec_Rear_PWM_SYNC_KILL_SHIFT            (2u)
#define QuadDec_Rear_PWM_STOP_KILL_SHIFT            (3u)
#define QuadDec_Rear_PRESCALER_SHIFT                (8u)
#define QuadDec_Rear_UPDOWN_SHIFT                   (16u)
#define QuadDec_Rear_ONESHOT_SHIFT                  (18u)
#define QuadDec_Rear_QUAD_MODE_SHIFT                (20u)
#define QuadDec_Rear_INV_OUT_SHIFT                  (20u)
#define QuadDec_Rear_INV_COMPL_OUT_SHIFT            (21u)
#define QuadDec_Rear_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define QuadDec_Rear_RELOAD_CC_MASK                 ((uint32)(QuadDec_Rear_1BIT_MASK        <<  \
                                                                            QuadDec_Rear_RELOAD_CC_SHIFT))
#define QuadDec_Rear_RELOAD_PERIOD_MASK             ((uint32)(QuadDec_Rear_1BIT_MASK        <<  \
                                                                            QuadDec_Rear_RELOAD_PERIOD_SHIFT))
#define QuadDec_Rear_PWM_SYNC_KILL_MASK             ((uint32)(QuadDec_Rear_1BIT_MASK        <<  \
                                                                            QuadDec_Rear_PWM_SYNC_KILL_SHIFT))
#define QuadDec_Rear_PWM_STOP_KILL_MASK             ((uint32)(QuadDec_Rear_1BIT_MASK        <<  \
                                                                            QuadDec_Rear_PWM_STOP_KILL_SHIFT))
#define QuadDec_Rear_PRESCALER_MASK                 ((uint32)(QuadDec_Rear_8BIT_MASK        <<  \
                                                                            QuadDec_Rear_PRESCALER_SHIFT))
#define QuadDec_Rear_UPDOWN_MASK                    ((uint32)(QuadDec_Rear_2BIT_MASK        <<  \
                                                                            QuadDec_Rear_UPDOWN_SHIFT))
#define QuadDec_Rear_ONESHOT_MASK                   ((uint32)(QuadDec_Rear_1BIT_MASK        <<  \
                                                                            QuadDec_Rear_ONESHOT_SHIFT))
#define QuadDec_Rear_QUAD_MODE_MASK                 ((uint32)(QuadDec_Rear_3BIT_MASK        <<  \
                                                                            QuadDec_Rear_QUAD_MODE_SHIFT))
#define QuadDec_Rear_INV_OUT_MASK                   ((uint32)(QuadDec_Rear_2BIT_MASK        <<  \
                                                                            QuadDec_Rear_INV_OUT_SHIFT))
#define QuadDec_Rear_MODE_MASK                      ((uint32)(QuadDec_Rear_3BIT_MASK        <<  \
                                                                            QuadDec_Rear_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define QuadDec_Rear_CAPTURE_SHIFT                  (0u)
#define QuadDec_Rear_COUNT_SHIFT                    (2u)
#define QuadDec_Rear_RELOAD_SHIFT                   (4u)
#define QuadDec_Rear_STOP_SHIFT                     (6u)
#define QuadDec_Rear_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define QuadDec_Rear_CAPTURE_MASK                   ((uint32)(QuadDec_Rear_2BIT_MASK        <<  \
                                                                  QuadDec_Rear_CAPTURE_SHIFT))
#define QuadDec_Rear_COUNT_MASK                     ((uint32)(QuadDec_Rear_2BIT_MASK        <<  \
                                                                  QuadDec_Rear_COUNT_SHIFT))
#define QuadDec_Rear_RELOAD_MASK                    ((uint32)(QuadDec_Rear_2BIT_MASK        <<  \
                                                                  QuadDec_Rear_RELOAD_SHIFT))
#define QuadDec_Rear_STOP_MASK                      ((uint32)(QuadDec_Rear_2BIT_MASK        <<  \
                                                                  QuadDec_Rear_STOP_SHIFT))
#define QuadDec_Rear_START_MASK                     ((uint32)(QuadDec_Rear_2BIT_MASK        <<  \
                                                                  QuadDec_Rear_START_SHIFT))

/* MASK */
#define QuadDec_Rear_1BIT_MASK                      ((uint32)0x01u)
#define QuadDec_Rear_2BIT_MASK                      ((uint32)0x03u)
#define QuadDec_Rear_3BIT_MASK                      ((uint32)0x07u)
#define QuadDec_Rear_6BIT_MASK                      ((uint32)0x3Fu)
#define QuadDec_Rear_8BIT_MASK                      ((uint32)0xFFu)
#define QuadDec_Rear_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define QuadDec_Rear_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define QuadDec_Rear_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(QuadDec_Rear_QUAD_ENCODING_MODES     << QuadDec_Rear_QUAD_MODE_SHIFT))       |\
         ((uint32)(QuadDec_Rear_CONFIG                  << QuadDec_Rear_MODE_SHIFT)))

#define QuadDec_Rear_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(QuadDec_Rear_PWM_STOP_EVENT          << QuadDec_Rear_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(QuadDec_Rear_PWM_OUT_INVERT          << QuadDec_Rear_INV_OUT_SHIFT))         |\
         ((uint32)(QuadDec_Rear_PWM_OUT_N_INVERT        << QuadDec_Rear_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(QuadDec_Rear_PWM_MODE                << QuadDec_Rear_MODE_SHIFT)))

#define QuadDec_Rear_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(QuadDec_Rear_PWM_RUN_MODE         << QuadDec_Rear_ONESHOT_SHIFT))
            
#define QuadDec_Rear_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(QuadDec_Rear_PWM_ALIGN            << QuadDec_Rear_UPDOWN_SHIFT))

#define QuadDec_Rear_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(QuadDec_Rear_PWM_KILL_EVENT      << QuadDec_Rear_PWM_SYNC_KILL_SHIFT))

#define QuadDec_Rear_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(QuadDec_Rear_PWM_DEAD_TIME_CYCLE  << QuadDec_Rear_PRESCALER_SHIFT))

#define QuadDec_Rear_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(QuadDec_Rear_PWM_PRESCALER        << QuadDec_Rear_PRESCALER_SHIFT))

#define QuadDec_Rear_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(QuadDec_Rear_TC_PRESCALER            << QuadDec_Rear_PRESCALER_SHIFT))       |\
         ((uint32)(QuadDec_Rear_TC_COUNTER_MODE         << QuadDec_Rear_UPDOWN_SHIFT))          |\
         ((uint32)(QuadDec_Rear_TC_RUN_MODE             << QuadDec_Rear_ONESHOT_SHIFT))         |\
         ((uint32)(QuadDec_Rear_TC_COMP_CAP_MODE        << QuadDec_Rear_MODE_SHIFT)))
        
#define QuadDec_Rear_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(QuadDec_Rear_QUAD_PHIA_SIGNAL_MODE   << QuadDec_Rear_COUNT_SHIFT))           |\
         ((uint32)(QuadDec_Rear_QUAD_INDEX_SIGNAL_MODE  << QuadDec_Rear_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec_Rear_QUAD_STOP_SIGNAL_MODE   << QuadDec_Rear_STOP_SHIFT))            |\
         ((uint32)(QuadDec_Rear_QUAD_PHIB_SIGNAL_MODE   << QuadDec_Rear_START_SHIFT)))

#define QuadDec_Rear_PWM_SIGNALS_MODES                                                              \
        (((uint32)(QuadDec_Rear_PWM_SWITCH_SIGNAL_MODE  << QuadDec_Rear_CAPTURE_SHIFT))         |\
         ((uint32)(QuadDec_Rear_PWM_COUNT_SIGNAL_MODE   << QuadDec_Rear_COUNT_SHIFT))           |\
         ((uint32)(QuadDec_Rear_PWM_RELOAD_SIGNAL_MODE  << QuadDec_Rear_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec_Rear_PWM_STOP_SIGNAL_MODE    << QuadDec_Rear_STOP_SHIFT))            |\
         ((uint32)(QuadDec_Rear_PWM_START_SIGNAL_MODE   << QuadDec_Rear_START_SHIFT)))

#define QuadDec_Rear_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(QuadDec_Rear_TC_CAPTURE_SIGNAL_MODE  << QuadDec_Rear_CAPTURE_SHIFT))         |\
         ((uint32)(QuadDec_Rear_TC_COUNT_SIGNAL_MODE    << QuadDec_Rear_COUNT_SHIFT))           |\
         ((uint32)(QuadDec_Rear_TC_RELOAD_SIGNAL_MODE   << QuadDec_Rear_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec_Rear_TC_STOP_SIGNAL_MODE     << QuadDec_Rear_STOP_SHIFT))            |\
         ((uint32)(QuadDec_Rear_TC_START_SIGNAL_MODE    << QuadDec_Rear_START_SHIFT)))
        
#define QuadDec_Rear_TIMER_UPDOWN_CNT_USED                                                          \
                ((QuadDec_Rear__COUNT_UPDOWN0 == QuadDec_Rear_TC_COUNTER_MODE)                  ||\
                 (QuadDec_Rear__COUNT_UPDOWN1 == QuadDec_Rear_TC_COUNTER_MODE))

#define QuadDec_Rear_PWM_UPDOWN_CNT_USED                                                            \
                ((QuadDec_Rear__CENTER == QuadDec_Rear_PWM_ALIGN)                               ||\
                 (QuadDec_Rear__ASYMMETRIC == QuadDec_Rear_PWM_ALIGN))               
        
#define QuadDec_Rear_PWM_PR_INIT_VALUE              (1u)
#define QuadDec_Rear_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_QuadDec_Rear_H */

/* [] END OF FILE */
