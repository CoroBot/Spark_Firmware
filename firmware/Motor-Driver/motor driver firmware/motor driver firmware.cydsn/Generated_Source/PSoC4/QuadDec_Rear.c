/*******************************************************************************
* File Name: QuadDec_Rear.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the QuadDec_Rear
*  component
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

uint8 QuadDec_Rear_initVar = 0u;


/*******************************************************************************
* Function Name: QuadDec_Rear_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default QuadDec_Rear configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (QuadDec_Rear__QUAD == QuadDec_Rear_CONFIG)
        QuadDec_Rear_CONTROL_REG = QuadDec_Rear_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        QuadDec_Rear_TRIG_CONTROL1_REG  = QuadDec_Rear_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        QuadDec_Rear_SetInterruptMode(QuadDec_Rear_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        QuadDec_Rear_SetCounterMode(QuadDec_Rear_COUNT_DOWN);
        QuadDec_Rear_WritePeriod(QuadDec_Rear_QUAD_PERIOD_INIT_VALUE);
        QuadDec_Rear_WriteCounter(QuadDec_Rear_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (QuadDec_Rear__QUAD == QuadDec_Rear_CONFIG) */

    #if (QuadDec_Rear__TIMER == QuadDec_Rear_CONFIG)
        QuadDec_Rear_CONTROL_REG = QuadDec_Rear_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        QuadDec_Rear_TRIG_CONTROL1_REG  = QuadDec_Rear_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        QuadDec_Rear_SetInterruptMode(QuadDec_Rear_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        QuadDec_Rear_WritePeriod(QuadDec_Rear_TC_PERIOD_VALUE );

        #if (QuadDec_Rear__COMPARE == QuadDec_Rear_TC_COMP_CAP_MODE)
            QuadDec_Rear_WriteCompare(QuadDec_Rear_TC_COMPARE_VALUE);

            #if (1u == QuadDec_Rear_TC_COMPARE_SWAP)
                QuadDec_Rear_SetCompareSwap(1u);
                QuadDec_Rear_WriteCompareBuf(QuadDec_Rear_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == QuadDec_Rear_TC_COMPARE_SWAP) */
        #endif  /* (QuadDec_Rear__COMPARE == QuadDec_Rear_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (QuadDec_Rear_CY_TCPWM_V2 && QuadDec_Rear_TIMER_UPDOWN_CNT_USED && !QuadDec_Rear_CY_TCPWM_4000)
            QuadDec_Rear_WriteCounter(1u);
        #elif(QuadDec_Rear__COUNT_DOWN == QuadDec_Rear_TC_COUNTER_MODE)
            QuadDec_Rear_WriteCounter(QuadDec_Rear_TC_PERIOD_VALUE);
        #else
            QuadDec_Rear_WriteCounter(0u);
        #endif /* (QuadDec_Rear_CY_TCPWM_V2 && QuadDec_Rear_TIMER_UPDOWN_CNT_USED && !QuadDec_Rear_CY_TCPWM_4000) */
    #endif  /* (QuadDec_Rear__TIMER == QuadDec_Rear_CONFIG) */

    #if (QuadDec_Rear__PWM_SEL == QuadDec_Rear_CONFIG)
        QuadDec_Rear_CONTROL_REG = QuadDec_Rear_CTRL_PWM_BASE_CONFIG;

        #if (QuadDec_Rear__PWM_PR == QuadDec_Rear_PWM_MODE)
            QuadDec_Rear_CONTROL_REG |= QuadDec_Rear_CTRL_PWM_RUN_MODE;
            QuadDec_Rear_WriteCounter(QuadDec_Rear_PWM_PR_INIT_VALUE);
        #else
            QuadDec_Rear_CONTROL_REG |= QuadDec_Rear_CTRL_PWM_ALIGN | QuadDec_Rear_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (QuadDec_Rear_CY_TCPWM_V2 && QuadDec_Rear_PWM_UPDOWN_CNT_USED && !QuadDec_Rear_CY_TCPWM_4000)
                QuadDec_Rear_WriteCounter(1u);
            #elif (QuadDec_Rear__RIGHT == QuadDec_Rear_PWM_ALIGN)
                QuadDec_Rear_WriteCounter(QuadDec_Rear_PWM_PERIOD_VALUE);
            #else 
                QuadDec_Rear_WriteCounter(0u);
            #endif  /* (QuadDec_Rear_CY_TCPWM_V2 && QuadDec_Rear_PWM_UPDOWN_CNT_USED && !QuadDec_Rear_CY_TCPWM_4000) */
        #endif  /* (QuadDec_Rear__PWM_PR == QuadDec_Rear_PWM_MODE) */

        #if (QuadDec_Rear__PWM_DT == QuadDec_Rear_PWM_MODE)
            QuadDec_Rear_CONTROL_REG |= QuadDec_Rear_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (QuadDec_Rear__PWM_DT == QuadDec_Rear_PWM_MODE) */

        #if (QuadDec_Rear__PWM == QuadDec_Rear_PWM_MODE)
            QuadDec_Rear_CONTROL_REG |= QuadDec_Rear_CTRL_PWM_PRESCALER;
        #endif  /* (QuadDec_Rear__PWM == QuadDec_Rear_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        QuadDec_Rear_TRIG_CONTROL1_REG  = QuadDec_Rear_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        QuadDec_Rear_SetInterruptMode(QuadDec_Rear_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (QuadDec_Rear__PWM_PR == QuadDec_Rear_PWM_MODE)
            QuadDec_Rear_TRIG_CONTROL2_REG =
                    (QuadDec_Rear_CC_MATCH_NO_CHANGE    |
                    QuadDec_Rear_OVERLOW_NO_CHANGE      |
                    QuadDec_Rear_UNDERFLOW_NO_CHANGE);
        #else
            #if (QuadDec_Rear__LEFT == QuadDec_Rear_PWM_ALIGN)
                QuadDec_Rear_TRIG_CONTROL2_REG = QuadDec_Rear_PWM_MODE_LEFT;
            #endif  /* ( QuadDec_Rear_PWM_LEFT == QuadDec_Rear_PWM_ALIGN) */

            #if (QuadDec_Rear__RIGHT == QuadDec_Rear_PWM_ALIGN)
                QuadDec_Rear_TRIG_CONTROL2_REG = QuadDec_Rear_PWM_MODE_RIGHT;
            #endif  /* ( QuadDec_Rear_PWM_RIGHT == QuadDec_Rear_PWM_ALIGN) */

            #if (QuadDec_Rear__CENTER == QuadDec_Rear_PWM_ALIGN)
                QuadDec_Rear_TRIG_CONTROL2_REG = QuadDec_Rear_PWM_MODE_CENTER;
            #endif  /* ( QuadDec_Rear_PWM_CENTER == QuadDec_Rear_PWM_ALIGN) */

            #if (QuadDec_Rear__ASYMMETRIC == QuadDec_Rear_PWM_ALIGN)
                QuadDec_Rear_TRIG_CONTROL2_REG = QuadDec_Rear_PWM_MODE_ASYM;
            #endif  /* (QuadDec_Rear__ASYMMETRIC == QuadDec_Rear_PWM_ALIGN) */
        #endif  /* (QuadDec_Rear__PWM_PR == QuadDec_Rear_PWM_MODE) */

        /* Set other values from customizer */
        QuadDec_Rear_WritePeriod(QuadDec_Rear_PWM_PERIOD_VALUE );
        QuadDec_Rear_WriteCompare(QuadDec_Rear_PWM_COMPARE_VALUE);

        #if (1u == QuadDec_Rear_PWM_COMPARE_SWAP)
            QuadDec_Rear_SetCompareSwap(1u);
            QuadDec_Rear_WriteCompareBuf(QuadDec_Rear_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == QuadDec_Rear_PWM_COMPARE_SWAP) */

        #if (1u == QuadDec_Rear_PWM_PERIOD_SWAP)
            QuadDec_Rear_SetPeriodSwap(1u);
            QuadDec_Rear_WritePeriodBuf(QuadDec_Rear_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == QuadDec_Rear_PWM_PERIOD_SWAP) */
    #endif  /* (QuadDec_Rear__PWM_SEL == QuadDec_Rear_CONFIG) */
    
}


/*******************************************************************************
* Function Name: QuadDec_Rear_Enable
********************************************************************************
*
* Summary:
*  Enables the QuadDec_Rear.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    QuadDec_Rear_BLOCK_CONTROL_REG |= QuadDec_Rear_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (QuadDec_Rear__PWM_SEL == QuadDec_Rear_CONFIG)
        #if (0u == QuadDec_Rear_PWM_START_SIGNAL_PRESENT)
            QuadDec_Rear_TriggerCommand(QuadDec_Rear_MASK, QuadDec_Rear_CMD_START);
        #endif /* (0u == QuadDec_Rear_PWM_START_SIGNAL_PRESENT) */
    #endif /* (QuadDec_Rear__PWM_SEL == QuadDec_Rear_CONFIG) */

    #if (QuadDec_Rear__TIMER == QuadDec_Rear_CONFIG)
        #if (0u == QuadDec_Rear_TC_START_SIGNAL_PRESENT)
            QuadDec_Rear_TriggerCommand(QuadDec_Rear_MASK, QuadDec_Rear_CMD_START);
        #endif /* (0u == QuadDec_Rear_TC_START_SIGNAL_PRESENT) */
    #endif /* (QuadDec_Rear__TIMER == QuadDec_Rear_CONFIG) */
}


/*******************************************************************************
* Function Name: QuadDec_Rear_Start
********************************************************************************
*
* Summary:
*  Initializes the QuadDec_Rear with default customizer
*  values when called the first time and enables the QuadDec_Rear.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  QuadDec_Rear_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time QuadDec_Rear_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the QuadDec_Rear_Start() routine.
*
*******************************************************************************/
void QuadDec_Rear_Start(void)
{
    if (0u == QuadDec_Rear_initVar)
    {
        QuadDec_Rear_Init();
        QuadDec_Rear_initVar = 1u;
    }

    QuadDec_Rear_Enable();
}


/*******************************************************************************
* Function Name: QuadDec_Rear_Stop
********************************************************************************
*
* Summary:
*  Disables the QuadDec_Rear.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_BLOCK_CONTROL_REG &= (uint32)~QuadDec_Rear_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the QuadDec_Rear. This function is used when
*  configured as a generic QuadDec_Rear and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the QuadDec_Rear to operate in
*   Values:
*   - QuadDec_Rear_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - QuadDec_Rear_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - QuadDec_Rear_MODE_QUAD - Quadrature decoder
*         - QuadDec_Rear_MODE_PWM - PWM
*         - QuadDec_Rear_MODE_PWM_DT - PWM with dead time
*         - QuadDec_Rear_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_CONTROL_REG &= (uint32)~QuadDec_Rear_MODE_MASK;
    QuadDec_Rear_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - QuadDec_Rear_MODE_X1 - Counts on phi 1 rising
*         - QuadDec_Rear_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - QuadDec_Rear_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_CONTROL_REG &= (uint32)~QuadDec_Rear_QUAD_MODE_MASK;
    QuadDec_Rear_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - QuadDec_Rear_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - QuadDec_Rear_PRESCALE_DIVBY2    - Divide by 2
*         - QuadDec_Rear_PRESCALE_DIVBY4    - Divide by 4
*         - QuadDec_Rear_PRESCALE_DIVBY8    - Divide by 8
*         - QuadDec_Rear_PRESCALE_DIVBY16   - Divide by 16
*         - QuadDec_Rear_PRESCALE_DIVBY32   - Divide by 32
*         - QuadDec_Rear_PRESCALE_DIVBY64   - Divide by 64
*         - QuadDec_Rear_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_CONTROL_REG &= (uint32)~QuadDec_Rear_PRESCALER_MASK;
    QuadDec_Rear_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the QuadDec_Rear runs
*  continuously or stops when terminal count is reached.  By default the
*  QuadDec_Rear operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_CONTROL_REG &= (uint32)~QuadDec_Rear_ONESHOT_MASK;
    QuadDec_Rear_CONTROL_REG |= ((uint32)((oneShotEnable & QuadDec_Rear_1BIT_MASK) <<
                                                               QuadDec_Rear_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetPWMMode(uint32 modeMask)
{
    QuadDec_Rear_TRIG_CONTROL2_REG = (modeMask & QuadDec_Rear_6BIT_MASK);
}



/*******************************************************************************
* Function Name: QuadDec_Rear_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_CONTROL_REG &= (uint32)~QuadDec_Rear_PWM_SYNC_KILL_MASK;
    QuadDec_Rear_CONTROL_REG |= ((uint32)((syncKillEnable & QuadDec_Rear_1BIT_MASK)  <<
                                               QuadDec_Rear_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_CONTROL_REG &= (uint32)~QuadDec_Rear_PWM_STOP_KILL_MASK;
    QuadDec_Rear_CONTROL_REG |= ((uint32)((stopOnKillEnable & QuadDec_Rear_1BIT_MASK)  <<
                                                         QuadDec_Rear_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_CONTROL_REG &= (uint32)~QuadDec_Rear_PRESCALER_MASK;
    QuadDec_Rear_CONTROL_REG |= ((uint32)((deadTime & QuadDec_Rear_8BIT_MASK) <<
                                                          QuadDec_Rear_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - QuadDec_Rear_INVERT_LINE   - Inverts the line output
*         - QuadDec_Rear_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_CONTROL_REG &= (uint32)~QuadDec_Rear_INV_OUT_MASK;
    QuadDec_Rear_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: QuadDec_Rear_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_WriteCounter(uint32 count)
{
    QuadDec_Rear_COUNTER_REG = (count & QuadDec_Rear_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 QuadDec_Rear_ReadCounter(void)
{
    return (QuadDec_Rear_COUNTER_REG & QuadDec_Rear_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - QuadDec_Rear_COUNT_UP       - Counts up
*     - QuadDec_Rear_COUNT_DOWN     - Counts down
*     - QuadDec_Rear_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - QuadDec_Rear_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_CONTROL_REG &= (uint32)~QuadDec_Rear_UPDOWN_MASK;
    QuadDec_Rear_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_WritePeriod(uint32 period)
{
    QuadDec_Rear_PERIOD_REG = (period & QuadDec_Rear_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 QuadDec_Rear_ReadPeriod(void)
{
    return (QuadDec_Rear_PERIOD_REG & QuadDec_Rear_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_CONTROL_REG &= (uint32)~QuadDec_Rear_RELOAD_CC_MASK;
    QuadDec_Rear_CONTROL_REG |= (swapEnable & QuadDec_Rear_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_WritePeriodBuf(uint32 periodBuf)
{
    QuadDec_Rear_PERIOD_BUF_REG = (periodBuf & QuadDec_Rear_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 QuadDec_Rear_ReadPeriodBuf(void)
{
    return (QuadDec_Rear_PERIOD_BUF_REG & QuadDec_Rear_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_CONTROL_REG &= (uint32)~QuadDec_Rear_RELOAD_PERIOD_MASK;
    QuadDec_Rear_CONTROL_REG |= ((uint32)((swapEnable & QuadDec_Rear_1BIT_MASK) <<
                                                            QuadDec_Rear_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_WriteCompare(uint32 compare)
{
    #if (QuadDec_Rear_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (QuadDec_Rear_CY_TCPWM_4000) */

    #if (QuadDec_Rear_CY_TCPWM_4000)
        currentMode = ((QuadDec_Rear_CONTROL_REG & QuadDec_Rear_UPDOWN_MASK) >> QuadDec_Rear_UPDOWN_SHIFT);

        if (((uint32)QuadDec_Rear__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)QuadDec_Rear__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (QuadDec_Rear_CY_TCPWM_4000) */
    
    QuadDec_Rear_COMP_CAP_REG = (compare & QuadDec_Rear_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
*******************************************************************************/
uint32 QuadDec_Rear_ReadCompare(void)
{
    #if (QuadDec_Rear_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (QuadDec_Rear_CY_TCPWM_4000) */

    #if (QuadDec_Rear_CY_TCPWM_4000)
        currentMode = ((QuadDec_Rear_CONTROL_REG & QuadDec_Rear_UPDOWN_MASK) >> QuadDec_Rear_UPDOWN_SHIFT);
        
        regVal = QuadDec_Rear_COMP_CAP_REG;
        
        if (((uint32)QuadDec_Rear__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)QuadDec_Rear__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & QuadDec_Rear_16BIT_MASK);
    #else
        return (QuadDec_Rear_COMP_CAP_REG & QuadDec_Rear_16BIT_MASK);
    #endif /* (QuadDec_Rear_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: QuadDec_Rear_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_WriteCompareBuf(uint32 compareBuf)
{
    #if (QuadDec_Rear_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (QuadDec_Rear_CY_TCPWM_4000) */

    #if (QuadDec_Rear_CY_TCPWM_4000)
        currentMode = ((QuadDec_Rear_CONTROL_REG & QuadDec_Rear_UPDOWN_MASK) >> QuadDec_Rear_UPDOWN_SHIFT);

        if (((uint32)QuadDec_Rear__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)QuadDec_Rear__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (QuadDec_Rear_CY_TCPWM_4000) */
    
    QuadDec_Rear_COMP_CAP_BUF_REG = (compareBuf & QuadDec_Rear_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
*******************************************************************************/
uint32 QuadDec_Rear_ReadCompareBuf(void)
{
    #if (QuadDec_Rear_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (QuadDec_Rear_CY_TCPWM_4000) */

    #if (QuadDec_Rear_CY_TCPWM_4000)
        currentMode = ((QuadDec_Rear_CONTROL_REG & QuadDec_Rear_UPDOWN_MASK) >> QuadDec_Rear_UPDOWN_SHIFT);

        regVal = QuadDec_Rear_COMP_CAP_BUF_REG;
        
        if (((uint32)QuadDec_Rear__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)QuadDec_Rear__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & QuadDec_Rear_16BIT_MASK);
    #else
        return (QuadDec_Rear_COMP_CAP_BUF_REG & QuadDec_Rear_16BIT_MASK);
    #endif /* (QuadDec_Rear_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: QuadDec_Rear_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 QuadDec_Rear_ReadCapture(void)
{
    return (QuadDec_Rear_COMP_CAP_REG & QuadDec_Rear_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 QuadDec_Rear_ReadCaptureBuf(void)
{
    return (QuadDec_Rear_COMP_CAP_BUF_REG & QuadDec_Rear_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QuadDec_Rear_TRIG_LEVEL     - Level
*     - QuadDec_Rear_TRIG_RISING    - Rising edge
*     - QuadDec_Rear_TRIG_FALLING   - Falling edge
*     - QuadDec_Rear_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_TRIG_CONTROL1_REG &= (uint32)~QuadDec_Rear_CAPTURE_MASK;
    QuadDec_Rear_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QuadDec_Rear_TRIG_LEVEL     - Level
*     - QuadDec_Rear_TRIG_RISING    - Rising edge
*     - QuadDec_Rear_TRIG_FALLING   - Falling edge
*     - QuadDec_Rear_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_TRIG_CONTROL1_REG &= (uint32)~QuadDec_Rear_RELOAD_MASK;
    QuadDec_Rear_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QuadDec_Rear_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QuadDec_Rear_TRIG_LEVEL     - Level
*     - QuadDec_Rear_TRIG_RISING    - Rising edge
*     - QuadDec_Rear_TRIG_FALLING   - Falling edge
*     - QuadDec_Rear_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_TRIG_CONTROL1_REG &= (uint32)~QuadDec_Rear_START_MASK;
    QuadDec_Rear_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QuadDec_Rear_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QuadDec_Rear_TRIG_LEVEL     - Level
*     - QuadDec_Rear_TRIG_RISING    - Rising edge
*     - QuadDec_Rear_TRIG_FALLING   - Falling edge
*     - QuadDec_Rear_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_TRIG_CONTROL1_REG &= (uint32)~QuadDec_Rear_STOP_MASK;
    QuadDec_Rear_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QuadDec_Rear_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QuadDec_Rear_TRIG_LEVEL     - Level
*     - QuadDec_Rear_TRIG_RISING    - Rising edge
*     - QuadDec_Rear_TRIG_FALLING   - Falling edge
*     - QuadDec_Rear_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_TRIG_CONTROL1_REG &= (uint32)~QuadDec_Rear_COUNT_MASK;
    QuadDec_Rear_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QuadDec_Rear_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - QuadDec_Rear_CMD_CAPTURE    - Trigger Capture command
*     - QuadDec_Rear_CMD_RELOAD     - Trigger Reload command
*     - QuadDec_Rear_CMD_STOP       - Trigger Stop command
*     - QuadDec_Rear_CMD_START      - Trigger Start command
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QuadDec_Rear_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the QuadDec_Rear.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - QuadDec_Rear_STATUS_DOWN    - Set if counting down
*     - QuadDec_Rear_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 QuadDec_Rear_ReadStatus(void)
{
    return ((QuadDec_Rear_STATUS_REG >> QuadDec_Rear_RUNNING_STATUS_SHIFT) |
            (QuadDec_Rear_STATUS_REG & QuadDec_Rear_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - QuadDec_Rear_INTR_MASK_TC       - Terminal count mask
*     - QuadDec_Rear_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetInterruptMode(uint32 interruptMask)
{
    QuadDec_Rear_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: QuadDec_Rear_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - QuadDec_Rear_INTR_MASK_TC       - Terminal count mask
*     - QuadDec_Rear_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 QuadDec_Rear_GetInterruptSourceMasked(void)
{
    return (QuadDec_Rear_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - QuadDec_Rear_INTR_MASK_TC       - Terminal count mask
*     - QuadDec_Rear_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 QuadDec_Rear_GetInterruptSource(void)
{
    return (QuadDec_Rear_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: QuadDec_Rear_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - QuadDec_Rear_INTR_MASK_TC       - Terminal count mask
*     - QuadDec_Rear_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_ClearInterrupt(uint32 interruptMask)
{
    QuadDec_Rear_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: QuadDec_Rear_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - QuadDec_Rear_INTR_MASK_TC       - Terminal count mask
*     - QuadDec_Rear_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void QuadDec_Rear_SetInterrupt(uint32 interruptMask)
{
    QuadDec_Rear_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
