/*******************************************************************************
* File Name: UINT.c
* Version 2.50
*
* Description:
*  This file provides all Interrupt Service functionality of the UART component
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "U.h"


/***************************************
* Custom Declarations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */

#if (U_RX_INTERRUPT_ENABLED && (U_RX_ENABLED || U_HD_ENABLED))
    /*******************************************************************************
    * Function Name: U_RXISR
    ********************************************************************************
    *
    * Summary:
    *  Interrupt Service Routine for RX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  U_rxBuffer - RAM buffer pointer for save received data.
    *  U_rxBufferWrite - cyclic index for write to rxBuffer,
    *     increments after each byte saved to buffer.
    *  U_rxBufferRead - cyclic index for read from rxBuffer,
    *     checked to detect overflow condition.
    *  U_rxBufferOverflow - software overflow flag. Set to one
    *     when U_rxBufferWrite index overtakes
    *     U_rxBufferRead index.
    *  U_rxBufferLoopDetect - additional variable to detect overflow.
    *     Set to one when U_rxBufferWrite is equal to
    *    U_rxBufferRead
    *  U_rxAddressMode - this variable contains the Address mode,
    *     selected in customizer or set by UART_SetRxAddressMode() API.
    *  U_rxAddressDetected - set to 1 when correct address received,
    *     and analysed to store following addressed data bytes to the buffer.
    *     When not correct address received, set to 0 to skip following data bytes.
    *
    *******************************************************************************/
    CY_ISR(U_RXISR)
    {
        uint8 readData;
        uint8 readStatus;
        uint8 increment_pointer = 0u;

    #if(CY_PSOC3)
        uint8 int_en;
    #endif /* (CY_PSOC3) */

        /* User code required at start of ISR */
        /* `#START U_RXISR_START` */

        /* `#END` */

    #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
        int_en = EA;
        CyGlobalIntEnable;
    #endif /* (CY_PSOC3) */

        do
        {
            /* Read receiver status register */
            readStatus = U_RXSTATUS_REG;
            /* Copy the same status to readData variable for backward compatibility support 
            *  of the user code in U_RXISR_ERROR` section. 
            */
            readData = readStatus;

            if((readStatus & (U_RX_STS_BREAK | 
                            U_RX_STS_PAR_ERROR |
                            U_RX_STS_STOP_ERROR | 
                            U_RX_STS_OVERRUN)) != 0u)
            {
                /* ERROR handling. */
                U_errorStatus |= readStatus & ( U_RX_STS_BREAK | 
                                                            U_RX_STS_PAR_ERROR | 
                                                            U_RX_STS_STOP_ERROR | 
                                                            U_RX_STS_OVERRUN);
                /* `#START U_RXISR_ERROR` */

                /* `#END` */
            }
            
            if((readStatus & U_RX_STS_FIFO_NOTEMPTY) != 0u)
            {
                /* Read data from the RX data register */
                readData = U_RXDATA_REG;
            #if (U_RXHW_ADDRESS_ENABLED)
                if(U_rxAddressMode == (uint8)U__B_UART__AM_SW_DETECT_TO_BUFFER)
                {
                    if((readStatus & U_RX_STS_MRKSPC) != 0u)
                    {
                        if ((readStatus & U_RX_STS_ADDR_MATCH) != 0u)
                        {
                            U_rxAddressDetected = 1u;
                        }
                        else
                        {
                            U_rxAddressDetected = 0u;
                        }
                    }
                    if(U_rxAddressDetected != 0u)
                    {   /* Store only addressed data */
                        U_rxBuffer[U_rxBufferWrite] = readData;
                        increment_pointer = 1u;
                    }
                }
                else /* Without software addressing */
                {
                    U_rxBuffer[U_rxBufferWrite] = readData;
                    increment_pointer = 1u;
                }
            #else  /* Without addressing */
                U_rxBuffer[U_rxBufferWrite] = readData;
                increment_pointer = 1u;
            #endif /* (U_RXHW_ADDRESS_ENABLED) */

                /* Do not increment buffer pointer when skip not addressed data */
                if(increment_pointer != 0u)
                {
                    if(U_rxBufferLoopDetect != 0u)
                    {   /* Set Software Buffer status Overflow */
                        U_rxBufferOverflow = 1u;
                    }
                    /* Set next pointer. */
                    U_rxBufferWrite++;

                    /* Check pointer for a loop condition */
                    if(U_rxBufferWrite >= U_RX_BUFFER_SIZE)
                    {
                        U_rxBufferWrite = 0u;
                    }

                    /* Detect pre-overload condition and set flag */
                    if(U_rxBufferWrite == U_rxBufferRead)
                    {
                        U_rxBufferLoopDetect = 1u;
                        /* When Hardware Flow Control selected */
                        #if (U_FLOW_CONTROL != 0u)
                            /* Disable RX interrupt mask, it is enabled when user read data from the buffer using APIs */
                            U_RXSTATUS_MASK_REG  &= (uint8)~U_RX_STS_FIFO_NOTEMPTY;
                            CyIntClearPending(U_RX_VECT_NUM);
                            break; /* Break the reading of the FIFO loop, leave the data there for generating RTS signal */
                        #endif /* (U_FLOW_CONTROL != 0u) */
                    }
                }
            }
        }while((readStatus & U_RX_STS_FIFO_NOTEMPTY) != 0u);

        /* User code required at end of ISR (Optional) */
        /* `#START U_RXISR_END` */

        /* `#END` */

    #if(CY_PSOC3)
        EA = int_en;
    #endif /* (CY_PSOC3) */
    }

#endif /* (U_RX_INTERRUPT_ENABLED && (U_RX_ENABLED || U_HD_ENABLED)) */


#if (U_TX_INTERRUPT_ENABLED && U_TX_ENABLED)
    /*******************************************************************************
    * Function Name: U_TXISR
    ********************************************************************************
    *
    * Summary:
    * Interrupt Service Routine for the TX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  U_txBuffer - RAM buffer pointer for transmit data from.
    *  U_txBufferRead - cyclic index for read and transmit data
    *     from txBuffer, increments after each transmitted byte.
    *  U_rxBufferWrite - cyclic index for write to txBuffer,
    *     checked to detect available for transmission bytes.
    *
    *******************************************************************************/
    CY_ISR(U_TXISR)
    {
    #if(CY_PSOC3)
        uint8 int_en;
    #endif /* (CY_PSOC3) */

        /* User code required at start of ISR */
        /* `#START U_TXISR_START` */

        /* `#END` */

    #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
        int_en = EA;
        CyGlobalIntEnable;
    #endif /* (CY_PSOC3) */

        while((U_txBufferRead != U_txBufferWrite) &&
             ((U_TXSTATUS_REG & U_TX_STS_FIFO_FULL) == 0u))
        {
            /* Check pointer wrap around */
            if(U_txBufferRead >= U_TX_BUFFER_SIZE)
            {
                U_txBufferRead = 0u;
            }

            U_TXDATA_REG = U_txBuffer[U_txBufferRead];

            /* Set next pointer */
            U_txBufferRead++;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START U_TXISR_END` */

        /* `#END` */

    #if(CY_PSOC3)
        EA = int_en;
    #endif /* (CY_PSOC3) */
    }

#endif /* (U_TX_INTERRUPT_ENABLED && U_TX_ENABLED) */


/* [] END OF FILE */
