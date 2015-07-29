/*******************************************************************************
* File Name: U.h
* Version 2.50
*
* Description:
*  Contains the function prototypes and constants available to the UART
*  user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_UART_U_H)
#define CY_UART_U_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"


/***************************************
* Conditional Compilation Parameters
***************************************/

#define U_RX_ENABLED                     (1u)
#define U_TX_ENABLED                     (1u)
#define U_HD_ENABLED                     (0u)
#define U_RX_INTERRUPT_ENABLED           (1u)
#define U_TX_INTERRUPT_ENABLED           (1u)
#define U_INTERNAL_CLOCK_USED            (1u)
#define U_RXHW_ADDRESS_ENABLED           (0u)
#define U_OVER_SAMPLE_COUNT              (8u)
#define U_PARITY_TYPE                    (0u)
#define U_PARITY_TYPE_SW                 (1u)
#define U_BREAK_DETECT                   (0u)
#define U_BREAK_BITS_TX                  (13u)
#define U_BREAK_BITS_RX                  (13u)
#define U_TXCLKGEN_DP                    (1u)
#define U_USE23POLLING                   (1u)
#define U_FLOW_CONTROL                   (0u)
#define U_CLK_FREQ                       (0u)
#define U_TX_BUFFER_SIZE                 (512u)
#define U_RX_BUFFER_SIZE                 (512u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component UART_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

#if defined(U_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG)
    #define U_CONTROL_REG_REMOVED            (0u)
#else
    #define U_CONTROL_REG_REMOVED            (1u)
#endif /* End U_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */


/***************************************
*      Data Structure Definition
***************************************/

/* Sleep Mode API Support */
typedef struct U_backupStruct_
{
    uint8 enableState;

    #if(U_CONTROL_REG_REMOVED == 0u)
        uint8 cr;
    #endif /* End U_CONTROL_REG_REMOVED */

} U_BACKUP_STRUCT;


/***************************************
*       Function Prototypes
***************************************/

void U_Start(void) ;
void U_Stop(void) ;
uint8 U_ReadControlRegister(void) ;
void U_WriteControlRegister(uint8 control) ;

void U_Init(void) ;
void U_Enable(void) ;
void U_SaveConfig(void) ;
void U_RestoreConfig(void) ;
void U_Sleep(void) ;
void U_Wakeup(void) ;

/* Only if RX is enabled */
#if( (U_RX_ENABLED) || (U_HD_ENABLED) )

    #if (U_RX_INTERRUPT_ENABLED)
        #define U_EnableRxInt()  CyIntEnable (U_RX_VECT_NUM)
        #define U_DisableRxInt() CyIntDisable(U_RX_VECT_NUM)
        CY_ISR_PROTO(U_RXISR);
    #endif /* U_RX_INTERRUPT_ENABLED */

    void U_SetRxAddressMode(uint8 addressMode)
                                                           ;
    void U_SetRxAddress1(uint8 address) ;
    void U_SetRxAddress2(uint8 address) ;

    void  U_SetRxInterruptMode(uint8 intSrc) ;
    uint8 U_ReadRxData(void) ;
    uint8 U_ReadRxStatus(void) ;
    uint8 U_GetChar(void) ;
    uint16 U_GetByte(void) ;
    uint16 U_GetRxBufferSize(void)
                                                            ;
    void U_ClearRxBuffer(void) ;

    /* Obsolete functions, defines for backward compatible */
    #define U_GetRxInterruptSource   U_ReadRxStatus

#endif /* End (U_RX_ENABLED) || (U_HD_ENABLED) */

/* Only if TX is enabled */
#if(U_TX_ENABLED || U_HD_ENABLED)

    #if(U_TX_INTERRUPT_ENABLED)
        #define U_EnableTxInt()  CyIntEnable (U_TX_VECT_NUM)
        #define U_DisableTxInt() CyIntDisable(U_TX_VECT_NUM)
        #define U_SetPendingTxInt() CyIntSetPending(U_TX_VECT_NUM)
        #define U_ClearPendingTxInt() CyIntClearPending(U_TX_VECT_NUM)
        CY_ISR_PROTO(U_TXISR);
    #endif /* U_TX_INTERRUPT_ENABLED */

    void U_SetTxInterruptMode(uint8 intSrc) ;
    void U_WriteTxData(uint8 txDataByte) ;
    uint8 U_ReadTxStatus(void) ;
    void U_PutChar(uint8 txDataByte) ;
    void U_PutString(const char8 string[]) ;
    void U_PutArray(const uint8 string[], uint16 byteCount)
                                                            ;
    void U_PutCRLF(uint8 txDataByte) ;
    void U_ClearTxBuffer(void) ;
    void U_SetTxAddressMode(uint8 addressMode) ;
    void U_SendBreak(uint8 retMode) ;
    uint16 U_GetTxBufferSize(void)
                                                            ;
    /* Obsolete functions, defines for backward compatible */
    #define U_PutStringConst         U_PutString
    #define U_PutArrayConst          U_PutArray
    #define U_GetTxInterruptSource   U_ReadTxStatus

#endif /* End U_TX_ENABLED || U_HD_ENABLED */

#if(U_HD_ENABLED)
    void U_LoadRxConfig(void) ;
    void U_LoadTxConfig(void) ;
#endif /* End U_HD_ENABLED */


/* Communication bootloader APIs */
#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_U) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))
    /* Physical layer functions */
    void    U_CyBtldrCommStart(void) CYSMALL ;
    void    U_CyBtldrCommStop(void) CYSMALL ;
    void    U_CyBtldrCommReset(void) CYSMALL ;
    cystatus U_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;
    cystatus U_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_U)
        #define CyBtldrCommStart    U_CyBtldrCommStart
        #define CyBtldrCommStop     U_CyBtldrCommStop
        #define CyBtldrCommReset    U_CyBtldrCommReset
        #define CyBtldrCommWrite    U_CyBtldrCommWrite
        #define CyBtldrCommRead     U_CyBtldrCommRead
    #endif  /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_U) */

    /* Byte to Byte time out for detecting end of block data from host */
    #define U_BYTE2BYTE_TIME_OUT (25u)
    #define U_PACKET_EOP         (0x17u) /* End of packet defined by bootloader */
    #define U_WAIT_EOP_DELAY     (5u)    /* Additional 5ms to wait for End of packet */
    #define U_BL_CHK_DELAY_MS    (1u)    /* Time Out quantity equal 1mS */

#endif /* CYDEV_BOOTLOADER_IO_COMP */


/***************************************
*          API Constants
***************************************/
/* Parameters for SetTxAddressMode API*/
#define U_SET_SPACE      (0x00u)
#define U_SET_MARK       (0x01u)

/* Status Register definitions */
#if( (U_TX_ENABLED) || (U_HD_ENABLED) )
    #if(U_TX_INTERRUPT_ENABLED)
        #define U_TX_VECT_NUM            (uint8)U_TXInternalInterrupt__INTC_NUMBER
        #define U_TX_PRIOR_NUM           (uint8)U_TXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* U_TX_INTERRUPT_ENABLED */

    #define U_TX_STS_COMPLETE_SHIFT          (0x00u)
    #define U_TX_STS_FIFO_EMPTY_SHIFT        (0x01u)
    #define U_TX_STS_FIFO_NOT_FULL_SHIFT     (0x03u)
    #if(U_TX_ENABLED)
        #define U_TX_STS_FIFO_FULL_SHIFT     (0x02u)
    #else /* (U_HD_ENABLED) */
        #define U_TX_STS_FIFO_FULL_SHIFT     (0x05u)  /* Needs MD=0 */
    #endif /* (U_TX_ENABLED) */

    #define U_TX_STS_COMPLETE            (uint8)(0x01u << U_TX_STS_COMPLETE_SHIFT)
    #define U_TX_STS_FIFO_EMPTY          (uint8)(0x01u << U_TX_STS_FIFO_EMPTY_SHIFT)
    #define U_TX_STS_FIFO_FULL           (uint8)(0x01u << U_TX_STS_FIFO_FULL_SHIFT)
    #define U_TX_STS_FIFO_NOT_FULL       (uint8)(0x01u << U_TX_STS_FIFO_NOT_FULL_SHIFT)
#endif /* End (U_TX_ENABLED) || (U_HD_ENABLED)*/

#if( (U_RX_ENABLED) || (U_HD_ENABLED) )
    #if(U_RX_INTERRUPT_ENABLED)
        #define U_RX_VECT_NUM            (uint8)U_RXInternalInterrupt__INTC_NUMBER
        #define U_RX_PRIOR_NUM           (uint8)U_RXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* U_RX_INTERRUPT_ENABLED */
    #define U_RX_STS_MRKSPC_SHIFT            (0x00u)
    #define U_RX_STS_BREAK_SHIFT             (0x01u)
    #define U_RX_STS_PAR_ERROR_SHIFT         (0x02u)
    #define U_RX_STS_STOP_ERROR_SHIFT        (0x03u)
    #define U_RX_STS_OVERRUN_SHIFT           (0x04u)
    #define U_RX_STS_FIFO_NOTEMPTY_SHIFT     (0x05u)
    #define U_RX_STS_ADDR_MATCH_SHIFT        (0x06u)
    #define U_RX_STS_SOFT_BUFF_OVER_SHIFT    (0x07u)

    #define U_RX_STS_MRKSPC           (uint8)(0x01u << U_RX_STS_MRKSPC_SHIFT)
    #define U_RX_STS_BREAK            (uint8)(0x01u << U_RX_STS_BREAK_SHIFT)
    #define U_RX_STS_PAR_ERROR        (uint8)(0x01u << U_RX_STS_PAR_ERROR_SHIFT)
    #define U_RX_STS_STOP_ERROR       (uint8)(0x01u << U_RX_STS_STOP_ERROR_SHIFT)
    #define U_RX_STS_OVERRUN          (uint8)(0x01u << U_RX_STS_OVERRUN_SHIFT)
    #define U_RX_STS_FIFO_NOTEMPTY    (uint8)(0x01u << U_RX_STS_FIFO_NOTEMPTY_SHIFT)
    #define U_RX_STS_ADDR_MATCH       (uint8)(0x01u << U_RX_STS_ADDR_MATCH_SHIFT)
    #define U_RX_STS_SOFT_BUFF_OVER   (uint8)(0x01u << U_RX_STS_SOFT_BUFF_OVER_SHIFT)
    #define U_RX_HW_MASK                     (0x7Fu)
#endif /* End (U_RX_ENABLED) || (U_HD_ENABLED) */

/* Control Register definitions */
#define U_CTRL_HD_SEND_SHIFT                 (0x00u) /* 1 enable TX part in Half Duplex mode */
#define U_CTRL_HD_SEND_BREAK_SHIFT           (0x01u) /* 1 send BREAK signal in Half Duplez mode */
#define U_CTRL_MARK_SHIFT                    (0x02u) /* 1 sets mark, 0 sets space */
#define U_CTRL_PARITY_TYPE0_SHIFT            (0x03u) /* Defines the type of parity implemented */
#define U_CTRL_PARITY_TYPE1_SHIFT            (0x04u) /* Defines the type of parity implemented */
#define U_CTRL_RXADDR_MODE0_SHIFT            (0x05u)
#define U_CTRL_RXADDR_MODE1_SHIFT            (0x06u)
#define U_CTRL_RXADDR_MODE2_SHIFT            (0x07u)

#define U_CTRL_HD_SEND               (uint8)(0x01u << U_CTRL_HD_SEND_SHIFT)
#define U_CTRL_HD_SEND_BREAK         (uint8)(0x01u << U_CTRL_HD_SEND_BREAK_SHIFT)
#define U_CTRL_MARK                  (uint8)(0x01u << U_CTRL_MARK_SHIFT)
#define U_CTRL_PARITY_TYPE_MASK      (uint8)(0x03u << U_CTRL_PARITY_TYPE0_SHIFT)
#define U_CTRL_RXADDR_MODE_MASK      (uint8)(0x07u << U_CTRL_RXADDR_MODE0_SHIFT)

/* StatusI Register Interrupt Enable Control Bits. As defined by the Register map for the AUX Control Register */
#define U_INT_ENABLE                         (0x10u)

/* Bit Counter (7-bit) Control Register Bit Definitions. As defined by the Register map for the AUX Control Register */
#define U_CNTR_ENABLE                        (0x20u)

/*   Constants for SendBreak() "retMode" parameter  */
#define U_SEND_BREAK                         (0x00u)
#define U_WAIT_FOR_COMPLETE_REINIT           (0x01u)
#define U_REINIT                             (0x02u)
#define U_SEND_WAIT_REINIT                   (0x03u)

#define U_OVER_SAMPLE_8                      (8u)
#define U_OVER_SAMPLE_16                     (16u)

#define U_BIT_CENTER                         (U_OVER_SAMPLE_COUNT - 2u)

#define U_FIFO_LENGTH                        (4u)
#define U_NUMBER_OF_START_BIT                (1u)
#define U_MAX_BYTE_VALUE                     (0xFFu)

/* 8X always for count7 implementation */
#define U_TXBITCTR_BREAKBITS8X   ((U_BREAK_BITS_TX * U_OVER_SAMPLE_8) - 1u)
/* 8X or 16X for DP implementation */
#define U_TXBITCTR_BREAKBITS ((U_BREAK_BITS_TX * U_OVER_SAMPLE_COUNT) - 1u)

#define U_HALF_BIT_COUNT   \
                            (((U_OVER_SAMPLE_COUNT / 2u) + (U_USE23POLLING * 1u)) - 2u)
#if (U_OVER_SAMPLE_COUNT == U_OVER_SAMPLE_8)
    #define U_HD_TXBITCTR_INIT   (((U_BREAK_BITS_TX + \
                            U_NUMBER_OF_START_BIT) * U_OVER_SAMPLE_COUNT) - 1u)

    /* This parameter is increased on the 2 in 2 out of 3 mode to sample voting in the middle */
    #define U_RXBITCTR_INIT  ((((U_BREAK_BITS_RX + U_NUMBER_OF_START_BIT) \
                            * U_OVER_SAMPLE_COUNT) + U_HALF_BIT_COUNT) - 1u)

#else /* U_OVER_SAMPLE_COUNT == U_OVER_SAMPLE_16 */
    #define U_HD_TXBITCTR_INIT   ((8u * U_OVER_SAMPLE_COUNT) - 1u)
    /* 7bit counter need one more bit for OverSampleCount = 16 */
    #define U_RXBITCTR_INIT      (((7u * U_OVER_SAMPLE_COUNT) - 1u) + \
                                                      U_HALF_BIT_COUNT)
#endif /* End U_OVER_SAMPLE_COUNT */

#define U_HD_RXBITCTR_INIT                   U_RXBITCTR_INIT


/***************************************
* Global variables external identifier
***************************************/

extern uint8 U_initVar;
#if (U_TX_INTERRUPT_ENABLED && U_TX_ENABLED)
    extern volatile uint8 U_txBuffer[U_TX_BUFFER_SIZE];
    extern volatile uint16 U_txBufferRead;
    extern uint16 U_txBufferWrite;
#endif /* (U_TX_INTERRUPT_ENABLED && U_TX_ENABLED) */
#if (U_RX_INTERRUPT_ENABLED && (U_RX_ENABLED || U_HD_ENABLED))
    extern uint8 U_errorStatus;
    extern volatile uint8 U_rxBuffer[U_RX_BUFFER_SIZE];
    extern volatile uint16 U_rxBufferRead;
    extern volatile uint16 U_rxBufferWrite;
    extern volatile uint8 U_rxBufferLoopDetect;
    extern volatile uint8 U_rxBufferOverflow;
    #if (U_RXHW_ADDRESS_ENABLED)
        extern volatile uint8 U_rxAddressMode;
        extern volatile uint8 U_rxAddressDetected;
    #endif /* (U_RXHW_ADDRESS_ENABLED) */
#endif /* (U_RX_INTERRUPT_ENABLED && (U_RX_ENABLED || U_HD_ENABLED)) */


/***************************************
* Enumerated Types and Parameters
***************************************/

#define U__B_UART__AM_SW_BYTE_BYTE 1
#define U__B_UART__AM_SW_DETECT_TO_BUFFER 2
#define U__B_UART__AM_HW_BYTE_BY_BYTE 3
#define U__B_UART__AM_HW_DETECT_TO_BUFFER 4
#define U__B_UART__AM_NONE 0

#define U__B_UART__NONE_REVB 0
#define U__B_UART__EVEN_REVB 1
#define U__B_UART__ODD_REVB 2
#define U__B_UART__MARK_SPACE_REVB 3



/***************************************
*    Initial Parameter Constants
***************************************/

/* UART shifts max 8 bits, Mark/Space functionality working if 9 selected */
#define U_NUMBER_OF_DATA_BITS    ((8u > 8u) ? 8u : 8u)
#define U_NUMBER_OF_STOP_BITS    (1u)

#if (U_RXHW_ADDRESS_ENABLED)
    #define U_RX_ADDRESS_MODE    (0u)
    #define U_RX_HW_ADDRESS1     (0u)
    #define U_RX_HW_ADDRESS2     (0u)
#endif /* (U_RXHW_ADDRESS_ENABLED) */

#define U_INIT_RX_INTERRUPTS_MASK \
                                  (uint8)((1 << U_RX_STS_FIFO_NOTEMPTY_SHIFT) \
                                        | (0 << U_RX_STS_MRKSPC_SHIFT) \
                                        | (0 << U_RX_STS_ADDR_MATCH_SHIFT) \
                                        | (0 << U_RX_STS_PAR_ERROR_SHIFT) \
                                        | (0 << U_RX_STS_STOP_ERROR_SHIFT) \
                                        | (0 << U_RX_STS_BREAK_SHIFT) \
                                        | (0 << U_RX_STS_OVERRUN_SHIFT))

#define U_INIT_TX_INTERRUPTS_MASK \
                                  (uint8)((0 << U_TX_STS_COMPLETE_SHIFT) \
                                        | (1 << U_TX_STS_FIFO_EMPTY_SHIFT) \
                                        | (0 << U_TX_STS_FIFO_FULL_SHIFT) \
                                        | (0 << U_TX_STS_FIFO_NOT_FULL_SHIFT))


/***************************************
*              Registers
***************************************/

#ifdef U_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define U_CONTROL_REG \
                            (* (reg8 *) U_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
    #define U_CONTROL_PTR \
                            (  (reg8 *) U_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
#endif /* End U_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(U_TX_ENABLED)
    #define U_TXDATA_REG          (* (reg8 *) U_BUART_sTX_TxShifter_u0__F0_REG)
    #define U_TXDATA_PTR          (  (reg8 *) U_BUART_sTX_TxShifter_u0__F0_REG)
    #define U_TXDATA_AUX_CTL_REG  (* (reg8 *) U_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define U_TXDATA_AUX_CTL_PTR  (  (reg8 *) U_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define U_TXSTATUS_REG        (* (reg8 *) U_BUART_sTX_TxSts__STATUS_REG)
    #define U_TXSTATUS_PTR        (  (reg8 *) U_BUART_sTX_TxSts__STATUS_REG)
    #define U_TXSTATUS_MASK_REG   (* (reg8 *) U_BUART_sTX_TxSts__MASK_REG)
    #define U_TXSTATUS_MASK_PTR   (  (reg8 *) U_BUART_sTX_TxSts__MASK_REG)
    #define U_TXSTATUS_ACTL_REG   (* (reg8 *) U_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)
    #define U_TXSTATUS_ACTL_PTR   (  (reg8 *) U_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)

    /* DP clock */
    #if(U_TXCLKGEN_DP)
        #define U_TXBITCLKGEN_CTR_REG        \
                                        (* (reg8 *) U_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define U_TXBITCLKGEN_CTR_PTR        \
                                        (  (reg8 *) U_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define U_TXBITCLKTX_COMPLETE_REG    \
                                        (* (reg8 *) U_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
        #define U_TXBITCLKTX_COMPLETE_PTR    \
                                        (  (reg8 *) U_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
    #else     /* Count7 clock*/
        #define U_TXBITCTR_PERIOD_REG    \
                                        (* (reg8 *) U_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define U_TXBITCTR_PERIOD_PTR    \
                                        (  (reg8 *) U_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define U_TXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) U_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define U_TXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) U_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define U_TXBITCTR_COUNTER_REG   \
                                        (* (reg8 *) U_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
        #define U_TXBITCTR_COUNTER_PTR   \
                                        (  (reg8 *) U_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
    #endif /* U_TXCLKGEN_DP */

#endif /* End U_TX_ENABLED */

#if(U_HD_ENABLED)

    #define U_TXDATA_REG             (* (reg8 *) U_BUART_sRX_RxShifter_u0__F1_REG )
    #define U_TXDATA_PTR             (  (reg8 *) U_BUART_sRX_RxShifter_u0__F1_REG )
    #define U_TXDATA_AUX_CTL_REG     (* (reg8 *) U_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)
    #define U_TXDATA_AUX_CTL_PTR     (  (reg8 *) U_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define U_TXSTATUS_REG           (* (reg8 *) U_BUART_sRX_RxSts__STATUS_REG )
    #define U_TXSTATUS_PTR           (  (reg8 *) U_BUART_sRX_RxSts__STATUS_REG )
    #define U_TXSTATUS_MASK_REG      (* (reg8 *) U_BUART_sRX_RxSts__MASK_REG )
    #define U_TXSTATUS_MASK_PTR      (  (reg8 *) U_BUART_sRX_RxSts__MASK_REG )
    #define U_TXSTATUS_ACTL_REG      (* (reg8 *) U_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define U_TXSTATUS_ACTL_PTR      (  (reg8 *) U_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End U_HD_ENABLED */

#if( (U_RX_ENABLED) || (U_HD_ENABLED) )
    #define U_RXDATA_REG             (* (reg8 *) U_BUART_sRX_RxShifter_u0__F0_REG )
    #define U_RXDATA_PTR             (  (reg8 *) U_BUART_sRX_RxShifter_u0__F0_REG )
    #define U_RXADDRESS1_REG         (* (reg8 *) U_BUART_sRX_RxShifter_u0__D0_REG )
    #define U_RXADDRESS1_PTR         (  (reg8 *) U_BUART_sRX_RxShifter_u0__D0_REG )
    #define U_RXADDRESS2_REG         (* (reg8 *) U_BUART_sRX_RxShifter_u0__D1_REG )
    #define U_RXADDRESS2_PTR         (  (reg8 *) U_BUART_sRX_RxShifter_u0__D1_REG )
    #define U_RXDATA_AUX_CTL_REG     (* (reg8 *) U_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define U_RXBITCTR_PERIOD_REG    (* (reg8 *) U_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define U_RXBITCTR_PERIOD_PTR    (  (reg8 *) U_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define U_RXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) U_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define U_RXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) U_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define U_RXBITCTR_COUNTER_REG   (* (reg8 *) U_BUART_sRX_RxBitCounter__COUNT_REG )
    #define U_RXBITCTR_COUNTER_PTR   (  (reg8 *) U_BUART_sRX_RxBitCounter__COUNT_REG )

    #define U_RXSTATUS_REG           (* (reg8 *) U_BUART_sRX_RxSts__STATUS_REG )
    #define U_RXSTATUS_PTR           (  (reg8 *) U_BUART_sRX_RxSts__STATUS_REG )
    #define U_RXSTATUS_MASK_REG      (* (reg8 *) U_BUART_sRX_RxSts__MASK_REG )
    #define U_RXSTATUS_MASK_PTR      (  (reg8 *) U_BUART_sRX_RxSts__MASK_REG )
    #define U_RXSTATUS_ACTL_REG      (* (reg8 *) U_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define U_RXSTATUS_ACTL_PTR      (  (reg8 *) U_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End  (U_RX_ENABLED) || (U_HD_ENABLED) */

#if(U_INTERNAL_CLOCK_USED)
    /* Register to enable or disable the digital clocks */
    #define U_INTCLOCK_CLKEN_REG     (* (reg8 *) U_IntClock__PM_ACT_CFG)
    #define U_INTCLOCK_CLKEN_PTR     (  (reg8 *) U_IntClock__PM_ACT_CFG)

    /* Clock mask for this clock. */
    #define U_INTCLOCK_CLKEN_MASK    U_IntClock__PM_ACT_MSK
#endif /* End U_INTERNAL_CLOCK_USED */


/***************************************
*       Register Constants
***************************************/

#if(U_TX_ENABLED)
    #define U_TX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End U_TX_ENABLED */

#if(U_HD_ENABLED)
    #define U_TX_FIFO_CLR            (0x02u) /* FIFO1 CLR */
#endif /* End U_HD_ENABLED */

#if( (U_RX_ENABLED) || (U_HD_ENABLED) )
    #define U_RX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End  (U_RX_ENABLED) || (U_HD_ENABLED) */


/***************************************
* The following code is DEPRECATED and
* should not be used in new projects.
***************************************/

/* UART v2_40 obsolete definitions */
#define U_WAIT_1_MS      U_BL_CHK_DELAY_MS   

#define U_TXBUFFERSIZE   U_TX_BUFFER_SIZE
#define U_RXBUFFERSIZE   U_RX_BUFFER_SIZE

#if (U_RXHW_ADDRESS_ENABLED)
    #define U_RXADDRESSMODE  U_RX_ADDRESS_MODE
    #define U_RXHWADDRESS1   U_RX_HW_ADDRESS1
    #define U_RXHWADDRESS2   U_RX_HW_ADDRESS2
    /* Backward compatible define */
    #define U_RXAddressMode  U_RXADDRESSMODE
#endif /* (U_RXHW_ADDRESS_ENABLED) */

/* UART v2_30 obsolete definitions */
#define U_initvar                    U_initVar

#define U_RX_Enabled                 U_RX_ENABLED
#define U_TX_Enabled                 U_TX_ENABLED
#define U_HD_Enabled                 U_HD_ENABLED
#define U_RX_IntInterruptEnabled     U_RX_INTERRUPT_ENABLED
#define U_TX_IntInterruptEnabled     U_TX_INTERRUPT_ENABLED
#define U_InternalClockUsed          U_INTERNAL_CLOCK_USED
#define U_RXHW_Address_Enabled       U_RXHW_ADDRESS_ENABLED
#define U_OverSampleCount            U_OVER_SAMPLE_COUNT
#define U_ParityType                 U_PARITY_TYPE

#if( U_TX_ENABLED && (U_TXBUFFERSIZE > U_FIFO_LENGTH))
    #define U_TXBUFFER               U_txBuffer
    #define U_TXBUFFERREAD           U_txBufferRead
    #define U_TXBUFFERWRITE          U_txBufferWrite
#endif /* End U_TX_ENABLED */
#if( ( U_RX_ENABLED || U_HD_ENABLED ) && \
     (U_RXBUFFERSIZE > U_FIFO_LENGTH) )
    #define U_RXBUFFER               U_rxBuffer
    #define U_RXBUFFERREAD           U_rxBufferRead
    #define U_RXBUFFERWRITE          U_rxBufferWrite
    #define U_RXBUFFERLOOPDETECT     U_rxBufferLoopDetect
    #define U_RXBUFFER_OVERFLOW      U_rxBufferOverflow
#endif /* End U_RX_ENABLED */

#ifdef U_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define U_CONTROL                U_CONTROL_REG
#endif /* End U_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(U_TX_ENABLED)
    #define U_TXDATA                 U_TXDATA_REG
    #define U_TXSTATUS               U_TXSTATUS_REG
    #define U_TXSTATUS_MASK          U_TXSTATUS_MASK_REG
    #define U_TXSTATUS_ACTL          U_TXSTATUS_ACTL_REG
    /* DP clock */
    #if(U_TXCLKGEN_DP)
        #define U_TXBITCLKGEN_CTR        U_TXBITCLKGEN_CTR_REG
        #define U_TXBITCLKTX_COMPLETE    U_TXBITCLKTX_COMPLETE_REG
    #else     /* Count7 clock*/
        #define U_TXBITCTR_PERIOD        U_TXBITCTR_PERIOD_REG
        #define U_TXBITCTR_CONTROL       U_TXBITCTR_CONTROL_REG
        #define U_TXBITCTR_COUNTER       U_TXBITCTR_COUNTER_REG
    #endif /* U_TXCLKGEN_DP */
#endif /* End U_TX_ENABLED */

#if(U_HD_ENABLED)
    #define U_TXDATA                 U_TXDATA_REG
    #define U_TXSTATUS               U_TXSTATUS_REG
    #define U_TXSTATUS_MASK          U_TXSTATUS_MASK_REG
    #define U_TXSTATUS_ACTL          U_TXSTATUS_ACTL_REG
#endif /* End U_HD_ENABLED */

#if( (U_RX_ENABLED) || (U_HD_ENABLED) )
    #define U_RXDATA                 U_RXDATA_REG
    #define U_RXADDRESS1             U_RXADDRESS1_REG
    #define U_RXADDRESS2             U_RXADDRESS2_REG
    #define U_RXBITCTR_PERIOD        U_RXBITCTR_PERIOD_REG
    #define U_RXBITCTR_CONTROL       U_RXBITCTR_CONTROL_REG
    #define U_RXBITCTR_COUNTER       U_RXBITCTR_COUNTER_REG
    #define U_RXSTATUS               U_RXSTATUS_REG
    #define U_RXSTATUS_MASK          U_RXSTATUS_MASK_REG
    #define U_RXSTATUS_ACTL          U_RXSTATUS_ACTL_REG
#endif /* End  (U_RX_ENABLED) || (U_HD_ENABLED) */

#if(U_INTERNAL_CLOCK_USED)
    #define U_INTCLOCK_CLKEN         U_INTCLOCK_CLKEN_REG
#endif /* End U_INTERNAL_CLOCK_USED */

#define U_WAIT_FOR_COMLETE_REINIT    U_WAIT_FOR_COMPLETE_REINIT

#endif  /* CY_UART_U_H */


/* [] END OF FILE */
