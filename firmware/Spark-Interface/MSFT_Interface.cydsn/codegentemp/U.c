/*******************************************************************************
* File Name: U.c
* Version 2.50
*
* Description:
*  This file provides all API functionality of the UART component
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
#if (U_INTERNAL_CLOCK_USED)
    #include "U_IntClock.h"
#endif /* End U_INTERNAL_CLOCK_USED */


/***************************************
* Global data allocation
***************************************/

uint8 U_initVar = 0u;

#if (U_TX_INTERRUPT_ENABLED && U_TX_ENABLED)
    volatile uint8 U_txBuffer[U_TX_BUFFER_SIZE];
    volatile uint16 U_txBufferRead = 0u;
    uint16 U_txBufferWrite = 0u;
#endif /* (U_TX_INTERRUPT_ENABLED && U_TX_ENABLED) */

#if (U_RX_INTERRUPT_ENABLED && (U_RX_ENABLED || U_HD_ENABLED))
    uint8 U_errorStatus = 0u;
    volatile uint8 U_rxBuffer[U_RX_BUFFER_SIZE];
    volatile uint16 U_rxBufferRead  = 0u;
    volatile uint16 U_rxBufferWrite = 0u;
    volatile uint8 U_rxBufferLoopDetect = 0u;
    volatile uint8 U_rxBufferOverflow   = 0u;
    #if (U_RXHW_ADDRESS_ENABLED)
        volatile uint8 U_rxAddressMode = U_RX_ADDRESS_MODE;
        volatile uint8 U_rxAddressDetected = 0u;
    #endif /* (U_RXHW_ADDRESS_ENABLED) */
#endif /* (U_RX_INTERRUPT_ENABLED && (U_RX_ENABLED || U_HD_ENABLED)) */


/*******************************************************************************
* Function Name: U_Start
********************************************************************************
*
* Summary:
*  This is the preferred method to begin component operation.
*  U_Start() sets the initVar variable, calls the
*  U_Init() function, and then calls the
*  U_Enable() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  The U_intiVar variable is used to indicate initial
*  configuration of this component. The variable is initialized to zero (0u)
*  and set to one (1u) the first time U_Start() is called. This
*  allows for component initialization without re-initialization in all
*  subsequent calls to the U_Start() routine.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void U_Start(void) 
{
    /* If not initialized then initialize all required hardware and software */
    if(U_initVar == 0u)
    {
        U_Init();
        U_initVar = 1u;
    }

    U_Enable();
}


/*******************************************************************************
* Function Name: U_Init
********************************************************************************
*
* Summary:
*  Initializes or restores the component according to the customizer Configure
*  dialog settings. It is not necessary to call U_Init() because
*  the U_Start() API calls this function and is the preferred
*  method to begin component operation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void U_Init(void) 
{
    #if(U_RX_ENABLED || U_HD_ENABLED)

        #if (U_RX_INTERRUPT_ENABLED)
            /* Set RX interrupt vector and priority */
            (void) CyIntSetVector(U_RX_VECT_NUM, &U_RXISR);
            CyIntSetPriority(U_RX_VECT_NUM, U_RX_PRIOR_NUM);
            U_errorStatus = 0u;
        #endif /* (U_RX_INTERRUPT_ENABLED) */

        #if (U_RXHW_ADDRESS_ENABLED)
            U_SetRxAddressMode(U_RX_ADDRESS_MODE);
            U_SetRxAddress1(U_RX_HW_ADDRESS1);
            U_SetRxAddress2(U_RX_HW_ADDRESS2);
        #endif /* End U_RXHW_ADDRESS_ENABLED */

        /* Init Count7 period */
        U_RXBITCTR_PERIOD_REG = U_RXBITCTR_INIT;
        /* Configure the Initial RX interrupt mask */
        U_RXSTATUS_MASK_REG  = U_INIT_RX_INTERRUPTS_MASK;
    #endif /* End U_RX_ENABLED || U_HD_ENABLED*/

    #if(U_TX_ENABLED)
        #if (U_TX_INTERRUPT_ENABLED)
            /* Set TX interrupt vector and priority */
            (void) CyIntSetVector(U_TX_VECT_NUM, &U_TXISR);
            CyIntSetPriority(U_TX_VECT_NUM, U_TX_PRIOR_NUM);
        #endif /* (U_TX_INTERRUPT_ENABLED) */

        /* Write Counter Value for TX Bit Clk Generator*/
        #if (U_TXCLKGEN_DP)
            U_TXBITCLKGEN_CTR_REG = U_BIT_CENTER;
            U_TXBITCLKTX_COMPLETE_REG = ((U_NUMBER_OF_DATA_BITS +
                        U_NUMBER_OF_START_BIT) * U_OVER_SAMPLE_COUNT) - 1u;
        #else
            U_TXBITCTR_PERIOD_REG = ((U_NUMBER_OF_DATA_BITS +
                        U_NUMBER_OF_START_BIT) * U_OVER_SAMPLE_8) - 1u;
        #endif /* End U_TXCLKGEN_DP */

        /* Configure the Initial TX interrupt mask */
        #if (U_TX_INTERRUPT_ENABLED)
            U_TXSTATUS_MASK_REG = U_TX_STS_FIFO_EMPTY;
        #else
            U_TXSTATUS_MASK_REG = U_INIT_TX_INTERRUPTS_MASK;
        #endif /*End U_TX_INTERRUPT_ENABLED*/

    #endif /* End U_TX_ENABLED */

    #if(U_PARITY_TYPE_SW)  /* Write Parity to Control Register */
        U_WriteControlRegister( \
            (U_ReadControlRegister() & (uint8)~U_CTRL_PARITY_TYPE_MASK) | \
            (uint8)(U_PARITY_TYPE << U_CTRL_PARITY_TYPE0_SHIFT) );
    #endif /* End U_PARITY_TYPE_SW */
}


/*******************************************************************************
* Function Name: U_Enable
********************************************************************************
*
* Summary:
*  Activates the hardware and begins component operation. It is not necessary
*  to call U_Enable() because the U_Start() API
*  calls this function, which is the preferred method to begin component
*  operation.

* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  U_rxAddressDetected - set to initial state (0).
*
*******************************************************************************/
void U_Enable(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    #if (U_RX_ENABLED || U_HD_ENABLED)
        /* RX Counter (Count7) Enable */
        U_RXBITCTR_CONTROL_REG |= U_CNTR_ENABLE;

        /* Enable the RX Interrupt */
        U_RXSTATUS_ACTL_REG  |= U_INT_ENABLE;

        #if (U_RX_INTERRUPT_ENABLED)
            U_EnableRxInt();

            #if (U_RXHW_ADDRESS_ENABLED)
                U_rxAddressDetected = 0u;
            #endif /* (U_RXHW_ADDRESS_ENABLED) */
        #endif /* (U_RX_INTERRUPT_ENABLED) */
    #endif /* (U_RX_ENABLED || U_HD_ENABLED) */

    #if(U_TX_ENABLED)
        /* TX Counter (DP/Count7) Enable */
        #if(!U_TXCLKGEN_DP)
            U_TXBITCTR_CONTROL_REG |= U_CNTR_ENABLE;
        #endif /* End U_TXCLKGEN_DP */

        /* Enable the TX Interrupt */
        U_TXSTATUS_ACTL_REG |= U_INT_ENABLE;
        #if (U_TX_INTERRUPT_ENABLED)
            U_ClearPendingTxInt(); /* Clear history of TX_NOT_EMPTY */
            U_EnableTxInt();
        #endif /* (U_TX_INTERRUPT_ENABLED) */
     #endif /* (U_TX_INTERRUPT_ENABLED) */

    #if (U_INTERNAL_CLOCK_USED)
        U_IntClock_Start();  /* Enable the clock */
    #endif /* (U_INTERNAL_CLOCK_USED) */

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: U_Stop
********************************************************************************
*
* Summary:
*  Disables the UART operation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void U_Stop(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    /* Write Bit Counter Disable */
    #if (U_RX_ENABLED || U_HD_ENABLED)
        U_RXBITCTR_CONTROL_REG &= (uint8) ~U_CNTR_ENABLE;
    #endif /* (U_RX_ENABLED || U_HD_ENABLED) */

    #if (U_TX_ENABLED)
        #if(!U_TXCLKGEN_DP)
            U_TXBITCTR_CONTROL_REG &= (uint8) ~U_CNTR_ENABLE;
        #endif /* (!U_TXCLKGEN_DP) */
    #endif /* (U_TX_ENABLED) */

    #if (U_INTERNAL_CLOCK_USED)
        U_IntClock_Stop();   /* Disable the clock */
    #endif /* (U_INTERNAL_CLOCK_USED) */

    /* Disable internal interrupt component */
    #if (U_RX_ENABLED || U_HD_ENABLED)
        U_RXSTATUS_ACTL_REG  &= (uint8) ~U_INT_ENABLE;

        #if (U_RX_INTERRUPT_ENABLED)
            U_DisableRxInt();
        #endif /* (U_RX_INTERRUPT_ENABLED) */
    #endif /* (U_RX_ENABLED || U_HD_ENABLED) */

    #if (U_TX_ENABLED)
        U_TXSTATUS_ACTL_REG &= (uint8) ~U_INT_ENABLE;

        #if (U_TX_INTERRUPT_ENABLED)
            U_DisableTxInt();
        #endif /* (U_TX_INTERRUPT_ENABLED) */
    #endif /* (U_TX_ENABLED) */

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: U_ReadControlRegister
********************************************************************************
*
* Summary:
*  Returns the current value of the control register.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the control register.
*
*******************************************************************************/
uint8 U_ReadControlRegister(void) 
{
    #if (U_CONTROL_REG_REMOVED)
        return(0u);
    #else
        return(U_CONTROL_REG);
    #endif /* (U_CONTROL_REG_REMOVED) */
}


/*******************************************************************************
* Function Name: U_WriteControlRegister
********************************************************************************
*
* Summary:
*  Writes an 8-bit value into the control register
*
* Parameters:
*  control:  control register value
*
* Return:
*  None.
*
*******************************************************************************/
void  U_WriteControlRegister(uint8 control) 
{
    #if (U_CONTROL_REG_REMOVED)
        if(0u != control)
        {
            /* Suppress compiler warning */
        }
    #else
       U_CONTROL_REG = control;
    #endif /* (U_CONTROL_REG_REMOVED) */
}


#if(U_RX_ENABLED || U_HD_ENABLED)
    /*******************************************************************************
    * Function Name: U_SetRxInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  Configures the RX interrupt sources enabled.
    *
    * Parameters:
    *  IntSrc:  Bit field containing the RX interrupts to enable. Based on the 
    *  bit-field arrangement of the status register. This value must be a 
    *  combination of status register bit-masks shown below:
    *      U_RX_STS_FIFO_NOTEMPTY    Interrupt on byte received.
    *      U_RX_STS_PAR_ERROR        Interrupt on parity error.
    *      U_RX_STS_STOP_ERROR       Interrupt on stop error.
    *      U_RX_STS_BREAK            Interrupt on break.
    *      U_RX_STS_OVERRUN          Interrupt on overrun error.
    *      U_RX_STS_ADDR_MATCH       Interrupt on address match.
    *      U_RX_STS_MRKSPC           Interrupt on address detect.
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Enables the output of specific status bits to the interrupt controller
    *
    *******************************************************************************/
    void U_SetRxInterruptMode(uint8 intSrc) 
    {
        U_RXSTATUS_MASK_REG  = intSrc;
    }


    /*******************************************************************************
    * Function Name: U_ReadRxData
    ********************************************************************************
    *
    * Summary:
    *  Returns the next byte of received data. This function returns data without
    *  checking the status. You must check the status separately.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Received data from RX register
    *
    * Global Variables:
    *  U_rxBuffer - RAM buffer pointer for save received data.
    *  U_rxBufferWrite - cyclic index for write to rxBuffer,
    *     checked to identify new data.
    *  U_rxBufferRead - cyclic index for read from rxBuffer,
    *     incremented after each byte has been read from buffer.
    *  U_rxBufferLoopDetect - cleared if loop condition was detected
    *     in RX ISR.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint8 U_ReadRxData(void) 
    {
        uint8 rxData;

    #if (U_RX_INTERRUPT_ENABLED)

        uint16 locRxBufferRead;
        uint16 locRxBufferWrite;

        /* Protect variables that could change on interrupt */
        U_DisableRxInt();

        locRxBufferRead  = U_rxBufferRead;
        locRxBufferWrite = U_rxBufferWrite;

        if( (U_rxBufferLoopDetect != 0u) || (locRxBufferRead != locRxBufferWrite) )
        {
            rxData = U_rxBuffer[locRxBufferRead];
            locRxBufferRead++;

            if(locRxBufferRead >= U_RX_BUFFER_SIZE)
            {
                locRxBufferRead = 0u;
            }
            /* Update the real pointer */
            U_rxBufferRead = locRxBufferRead;

            if(U_rxBufferLoopDetect != 0u)
            {
                U_rxBufferLoopDetect = 0u;
                #if ((U_RX_INTERRUPT_ENABLED) && (U_FLOW_CONTROL != 0u))
                    /* When Hardware Flow Control selected - return RX mask */
                    #if( U_HD_ENABLED )
                        if((U_CONTROL_REG & U_CTRL_HD_SEND) == 0u)
                        {   /* In Half duplex mode return RX mask only in RX
                            *  configuration set, otherwise
                            *  mask will be returned in LoadRxConfig() API.
                            */
                            U_RXSTATUS_MASK_REG  |= U_RX_STS_FIFO_NOTEMPTY;
                        }
                    #else
                        U_RXSTATUS_MASK_REG  |= U_RX_STS_FIFO_NOTEMPTY;
                    #endif /* end U_HD_ENABLED */
                #endif /* ((U_RX_INTERRUPT_ENABLED) && (U_FLOW_CONTROL != 0u)) */
            }
        }
        else
        {   /* Needs to check status for RX_STS_FIFO_NOTEMPTY bit */
            rxData = U_RXDATA_REG;
        }

        U_EnableRxInt();

    #else

        /* Needs to check status for RX_STS_FIFO_NOTEMPTY bit */
        rxData = U_RXDATA_REG;

    #endif /* (U_RX_INTERRUPT_ENABLED) */

        return(rxData);
    }


    /*******************************************************************************
    * Function Name: U_ReadRxStatus
    ********************************************************************************
    *
    * Summary:
    *  Returns the current state of the receiver status register and the software
    *  buffer overflow status.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Current state of the status register.
    *
    * Side Effect:
    *  All status register bits are clear-on-read except
    *  U_RX_STS_FIFO_NOTEMPTY.
    *  U_RX_STS_FIFO_NOTEMPTY clears immediately after RX data
    *  register read.
    *
    * Global Variables:
    *  U_rxBufferOverflow - used to indicate overload condition.
    *   It set to one in RX interrupt when there isn't free space in
    *   U_rxBufferRead to write new data. This condition returned
    *   and cleared to zero by this API as an
    *   U_RX_STS_SOFT_BUFF_OVER bit along with RX Status register
    *   bits.
    *
    *******************************************************************************/
    uint8 U_ReadRxStatus(void) 
    {
        uint8 status;

        status = U_RXSTATUS_REG & U_RX_HW_MASK;

    #if (U_RX_INTERRUPT_ENABLED)
        if(U_rxBufferOverflow != 0u)
        {
            status |= U_RX_STS_SOFT_BUFF_OVER;
            U_rxBufferOverflow = 0u;
        }
    #endif /* (U_RX_INTERRUPT_ENABLED) */

        return(status);
    }


    /*******************************************************************************
    * Function Name: U_GetChar
    ********************************************************************************
    *
    * Summary:
    *  Returns the last received byte of data. U_GetChar() is
    *  designed for ASCII characters and returns a uint8 where 1 to 255 are values
    *  for valid characters and 0 indicates an error occurred or no data is present.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Character read from UART RX buffer. ASCII characters from 1 to 255 are valid.
    *  A returned zero signifies an error condition or no data available.
    *
    * Global Variables:
    *  U_rxBuffer - RAM buffer pointer for save received data.
    *  U_rxBufferWrite - cyclic index for write to rxBuffer,
    *     checked to identify new data.
    *  U_rxBufferRead - cyclic index for read from rxBuffer,
    *     incremented after each byte has been read from buffer.
    *  U_rxBufferLoopDetect - cleared if loop condition was detected
    *     in RX ISR.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint8 U_GetChar(void) 
    {
        uint8 rxData = 0u;
        uint8 rxStatus;

    #if (U_RX_INTERRUPT_ENABLED)
        uint16 locRxBufferRead;
        uint16 locRxBufferWrite;

        /* Protect variables that could change on interrupt */
        U_DisableRxInt();

        locRxBufferRead  = U_rxBufferRead;
        locRxBufferWrite = U_rxBufferWrite;

        if( (U_rxBufferLoopDetect != 0u) || (locRxBufferRead != locRxBufferWrite) )
        {
            rxData = U_rxBuffer[locRxBufferRead];
            locRxBufferRead++;
            if(locRxBufferRead >= U_RX_BUFFER_SIZE)
            {
                locRxBufferRead = 0u;
            }
            /* Update the real pointer */
            U_rxBufferRead = locRxBufferRead;

            if(U_rxBufferLoopDetect != 0u)
            {
                U_rxBufferLoopDetect = 0u;
                #if( (U_RX_INTERRUPT_ENABLED) && (U_FLOW_CONTROL != 0u) )
                    /* When Hardware Flow Control selected - return RX mask */
                    #if( U_HD_ENABLED )
                        if((U_CONTROL_REG & U_CTRL_HD_SEND) == 0u)
                        {   /* In Half duplex mode return RX mask only if
                            *  RX configuration set, otherwise
                            *  mask will be returned in LoadRxConfig() API.
                            */
                            U_RXSTATUS_MASK_REG |= U_RX_STS_FIFO_NOTEMPTY;
                        }
                    #else
                        U_RXSTATUS_MASK_REG |= U_RX_STS_FIFO_NOTEMPTY;
                    #endif /* end U_HD_ENABLED */
                #endif /* U_RX_INTERRUPT_ENABLED and Hardware flow control*/
            }

        }
        else
        {   rxStatus = U_RXSTATUS_REG;
            if((rxStatus & U_RX_STS_FIFO_NOTEMPTY) != 0u)
            {   /* Read received data from FIFO */
                rxData = U_RXDATA_REG;
                /*Check status on error*/
                if((rxStatus & (U_RX_STS_BREAK | U_RX_STS_PAR_ERROR |
                                U_RX_STS_STOP_ERROR | U_RX_STS_OVERRUN)) != 0u)
                {
                    rxData = 0u;
                }
            }
        }

        U_EnableRxInt();

    #else

        rxStatus =U_RXSTATUS_REG;
        if((rxStatus & U_RX_STS_FIFO_NOTEMPTY) != 0u)
        {
            /* Read received data from FIFO */
            rxData = U_RXDATA_REG;

            /*Check status on error*/
            if((rxStatus & (U_RX_STS_BREAK | U_RX_STS_PAR_ERROR |
                            U_RX_STS_STOP_ERROR | U_RX_STS_OVERRUN)) != 0u)
            {
                rxData = 0u;
            }
        }
    #endif /* (U_RX_INTERRUPT_ENABLED) */

        return(rxData);
    }


    /*******************************************************************************
    * Function Name: U_GetByte
    ********************************************************************************
    *
    * Summary:
    *  Reads UART RX buffer immediately, returns received character and error
    *  condition.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  MSB contains status and LSB contains UART RX data. If the MSB is nonzero,
    *  an error has occurred.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint16 U_GetByte(void) 
    {
        
    #if (U_RX_INTERRUPT_ENABLED)
        uint16 locErrorStatus;
        /* Protect variables that could change on interrupt */
        U_DisableRxInt();
        locErrorStatus = (uint16)U_errorStatus;
        U_errorStatus = 0u;
        U_EnableRxInt();
        return ( (uint16)(locErrorStatus << 8u) | U_ReadRxData() );
    #else
        return ( ((uint16)U_ReadRxStatus() << 8u) | U_ReadRxData() );
    #endif /* U_RX_INTERRUPT_ENABLED */
        
    }


    /*******************************************************************************
    * Function Name: U_GetRxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Returns the number of received bytes available in the RX buffer.
    *  * RX software buffer is disabled (RX Buffer Size parameter is equal to 4): 
    *    returns 0 for empty RX FIFO or 1 for not empty RX FIFO.
    *  * RX software buffer is enabled: returns the number of bytes available in 
    *    the RX software buffer. Bytes available in the RX FIFO do not take to 
    *    account.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  uint16: Number of bytes in the RX buffer. 
    *    Return value type depends on RX Buffer Size parameter.
    *
    * Global Variables:
    *  U_rxBufferWrite - used to calculate left bytes.
    *  U_rxBufferRead - used to calculate left bytes.
    *  U_rxBufferLoopDetect - checked to decide left bytes amount.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Allows the user to find out how full the RX Buffer is.
    *
    *******************************************************************************/
    uint16 U_GetRxBufferSize(void)
                                                            
    {
        uint16 size;

    #if (U_RX_INTERRUPT_ENABLED)

        /* Protect variables that could change on interrupt */
        U_DisableRxInt();

        if(U_rxBufferRead == U_rxBufferWrite)
        {
            if(U_rxBufferLoopDetect != 0u)
            {
                size = U_RX_BUFFER_SIZE;
            }
            else
            {
                size = 0u;
            }
        }
        else if(U_rxBufferRead < U_rxBufferWrite)
        {
            size = (U_rxBufferWrite - U_rxBufferRead);
        }
        else
        {
            size = (U_RX_BUFFER_SIZE - U_rxBufferRead) + U_rxBufferWrite;
        }

        U_EnableRxInt();

    #else

        /* We can only know if there is data in the fifo. */
        size = ((U_RXSTATUS_REG & U_RX_STS_FIFO_NOTEMPTY) != 0u) ? 1u : 0u;

    #endif /* (U_RX_INTERRUPT_ENABLED) */

        return(size);
    }


    /*******************************************************************************
    * Function Name: U_ClearRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the receiver memory buffer and hardware RX FIFO of all received data.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  U_rxBufferWrite - cleared to zero.
    *  U_rxBufferRead - cleared to zero.
    *  U_rxBufferLoopDetect - cleared to zero.
    *  U_rxBufferOverflow - cleared to zero.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Setting the pointers to zero makes the system believe there is no data to
    *  read and writing will resume at address 0 overwriting any data that may
    *  have remained in the RAM.
    *
    * Side Effects:
    *  Any received data not read from the RAM or FIFO buffer will be lost.
    *
    *******************************************************************************/
    void U_ClearRxBuffer(void) 
    {
        uint8 enableInterrupts;

        /* Clear the HW FIFO */
        enableInterrupts = CyEnterCriticalSection();
        U_RXDATA_AUX_CTL_REG |= (uint8)  U_RX_FIFO_CLR;
        U_RXDATA_AUX_CTL_REG &= (uint8) ~U_RX_FIFO_CLR;
        CyExitCriticalSection(enableInterrupts);

    #if (U_RX_INTERRUPT_ENABLED)

        /* Protect variables that could change on interrupt. */
        U_DisableRxInt();

        U_rxBufferRead = 0u;
        U_rxBufferWrite = 0u;
        U_rxBufferLoopDetect = 0u;
        U_rxBufferOverflow = 0u;

        U_EnableRxInt();

    #endif /* (U_RX_INTERRUPT_ENABLED) */

    }


    /*******************************************************************************
    * Function Name: U_SetRxAddressMode
    ********************************************************************************
    *
    * Summary:
    *  Sets the software controlled Addressing mode used by the RX portion of the
    *  UART.
    *
    * Parameters:
    *  addressMode: Enumerated value indicating the mode of RX addressing
    *  U__B_UART__AM_SW_BYTE_BYTE -  Software Byte-by-Byte address
    *                                               detection
    *  U__B_UART__AM_SW_DETECT_TO_BUFFER - Software Detect to Buffer
    *                                               address detection
    *  U__B_UART__AM_HW_BYTE_BY_BYTE - Hardware Byte-by-Byte address
    *                                               detection
    *  U__B_UART__AM_HW_DETECT_TO_BUFFER - Hardware Detect to Buffer
    *                                               address detection
    *  U__B_UART__AM_NONE - No address detection
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  U_rxAddressMode - the parameter stored in this variable for
    *   the farther usage in RX ISR.
    *  U_rxAddressDetected - set to initial state (0).
    *
    *******************************************************************************/
    void U_SetRxAddressMode(uint8 addressMode)
                                                        
    {
        #if(U_RXHW_ADDRESS_ENABLED)
            #if(U_CONTROL_REG_REMOVED)
                if(0u != addressMode)
                {
                    /* Suppress compiler warning */
                }
            #else /* U_CONTROL_REG_REMOVED */
                uint8 tmpCtrl;
                tmpCtrl = U_CONTROL_REG & (uint8)~U_CTRL_RXADDR_MODE_MASK;
                tmpCtrl |= (uint8)(addressMode << U_CTRL_RXADDR_MODE0_SHIFT);
                U_CONTROL_REG = tmpCtrl;

                #if(U_RX_INTERRUPT_ENABLED && \
                   (U_RXBUFFERSIZE > U_FIFO_LENGTH) )
                    U_rxAddressMode = addressMode;
                    U_rxAddressDetected = 0u;
                #endif /* End U_RXBUFFERSIZE > U_FIFO_LENGTH*/
            #endif /* End U_CONTROL_REG_REMOVED */
        #else /* U_RXHW_ADDRESS_ENABLED */
            if(0u != addressMode)
            {
                /* Suppress compiler warning */
            }
        #endif /* End U_RXHW_ADDRESS_ENABLED */
    }


    /*******************************************************************************
    * Function Name: U_SetRxAddress1
    ********************************************************************************
    *
    * Summary:
    *  Sets the first of two hardware-detectable receiver addresses.
    *
    * Parameters:
    *  address: Address #1 for hardware address detection.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void U_SetRxAddress1(uint8 address) 
    {
        U_RXADDRESS1_REG = address;
    }


    /*******************************************************************************
    * Function Name: U_SetRxAddress2
    ********************************************************************************
    *
    * Summary:
    *  Sets the second of two hardware-detectable receiver addresses.
    *
    * Parameters:
    *  address: Address #2 for hardware address detection.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void U_SetRxAddress2(uint8 address) 
    {
        U_RXADDRESS2_REG = address;
    }

#endif  /* U_RX_ENABLED || U_HD_ENABLED*/


#if( (U_TX_ENABLED) || (U_HD_ENABLED) )
    /*******************************************************************************
    * Function Name: U_SetTxInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  Configures the TX interrupt sources to be enabled, but does not enable the
    *  interrupt.
    *
    * Parameters:
    *  intSrc: Bit field containing the TX interrupt sources to enable
    *   U_TX_STS_COMPLETE        Interrupt on TX byte complete
    *   U_TX_STS_FIFO_EMPTY      Interrupt when TX FIFO is empty
    *   U_TX_STS_FIFO_FULL       Interrupt when TX FIFO is full
    *   U_TX_STS_FIFO_NOT_FULL   Interrupt when TX FIFO is not full
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Enables the output of specific status bits to the interrupt controller
    *
    *******************************************************************************/
    void U_SetTxInterruptMode(uint8 intSrc) 
    {
        U_TXSTATUS_MASK_REG = intSrc;
    }


    /*******************************************************************************
    * Function Name: U_WriteTxData
    ********************************************************************************
    *
    * Summary:
    *  Places a byte of data into the transmit buffer to be sent when the bus is
    *  available without checking the TX status register. You must check status
    *  separately.
    *
    * Parameters:
    *  txDataByte: data byte
    *
    * Return:
    * None.
    *
    * Global Variables:
    *  U_txBuffer - RAM buffer pointer for save data for transmission
    *  U_txBufferWrite - cyclic index for write to txBuffer,
    *    incremented after each byte saved to buffer.
    *  U_txBufferRead - cyclic index for read from txBuffer,
    *    checked to identify the condition to write to FIFO directly or to TX buffer
    *  U_initVar - checked to identify that the component has been
    *    initialized.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void U_WriteTxData(uint8 txDataByte) 
    {
        /* If not Initialized then skip this function*/
        if(U_initVar != 0u)
        {
        #if (U_TX_INTERRUPT_ENABLED)

            /* Protect variables that could change on interrupt. */
            U_DisableTxInt();

            if( (U_txBufferRead == U_txBufferWrite) &&
                ((U_TXSTATUS_REG & U_TX_STS_FIFO_FULL) == 0u) )
            {
                /* Add directly to the FIFO. */
                U_TXDATA_REG = txDataByte;
            }
            else
            {
                if(U_txBufferWrite >= U_TX_BUFFER_SIZE)
                {
                    U_txBufferWrite = 0u;
                }

                U_txBuffer[U_txBufferWrite] = txDataByte;

                /* Add to the software buffer. */
                U_txBufferWrite++;
            }

            U_EnableTxInt();

        #else

            /* Add directly to the FIFO. */
            U_TXDATA_REG = txDataByte;

        #endif /*(U_TX_INTERRUPT_ENABLED) */
        }
    }


    /*******************************************************************************
    * Function Name: U_ReadTxStatus
    ********************************************************************************
    *
    * Summary:
    *  Reads the status register for the TX portion of the UART.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Contents of the status register
    *
    * Theory:
    *  This function reads the TX status register, which is cleared on read.
    *  It is up to the user to handle all bits in this return value accordingly,
    *  even if the bit was not enabled as an interrupt source the event happened
    *  and must be handled accordingly.
    *
    *******************************************************************************/
    uint8 U_ReadTxStatus(void) 
    {
        return(U_TXSTATUS_REG);
    }


    /*******************************************************************************
    * Function Name: U_PutChar
    ********************************************************************************
    *
    * Summary:
    *  Puts a byte of data into the transmit buffer to be sent when the bus is
    *  available. This is a blocking API that waits until the TX buffer has room to
    *  hold the data.
    *
    * Parameters:
    *  txDataByte: Byte containing the data to transmit
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  U_txBuffer - RAM buffer pointer for save data for transmission
    *  U_txBufferWrite - cyclic index for write to txBuffer,
    *     checked to identify free space in txBuffer and incremented after each byte
    *     saved to buffer.
    *  U_txBufferRead - cyclic index for read from txBuffer,
    *     checked to identify free space in txBuffer.
    *  U_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Allows the user to transmit any byte of data in a single transfer
    *
    *******************************************************************************/
    void U_PutChar(uint8 txDataByte) 
    {
    #if (U_TX_INTERRUPT_ENABLED)
        /* The temporary output pointer is used since it takes two instructions
        *  to increment with a wrap, and we can't risk doing that with the real
        *  pointer and getting an interrupt in between instructions.
        */
        uint16 locTxBufferWrite;
        uint16 locTxBufferRead;

        do
        { /* Block if software buffer is full, so we don't overwrite. */

        #if ((U_TX_BUFFER_SIZE > U_MAX_BYTE_VALUE) && (CY_PSOC3))
            /* Disable TX interrupt to protect variables from modification */
            U_DisableTxInt();
        #endif /* (U_TX_BUFFER_SIZE > U_MAX_BYTE_VALUE) && (CY_PSOC3) */

            locTxBufferWrite = U_txBufferWrite;
            locTxBufferRead  = U_txBufferRead;

        #if ((U_TX_BUFFER_SIZE > U_MAX_BYTE_VALUE) && (CY_PSOC3))
            /* Enable interrupt to continue transmission */
            U_EnableTxInt();
        #endif /* (U_TX_BUFFER_SIZE > U_MAX_BYTE_VALUE) && (CY_PSOC3) */
        }
        while( (locTxBufferWrite < locTxBufferRead) ? (locTxBufferWrite == (locTxBufferRead - 1u)) :
                                ((locTxBufferWrite - locTxBufferRead) ==
                                (uint16)(U_TX_BUFFER_SIZE - 1u)) );

        if( (locTxBufferRead == locTxBufferWrite) &&
            ((U_TXSTATUS_REG & U_TX_STS_FIFO_FULL) == 0u) )
        {
            /* Add directly to the FIFO */
            U_TXDATA_REG = txDataByte;
        }
        else
        {
            if(locTxBufferWrite >= U_TX_BUFFER_SIZE)
            {
                locTxBufferWrite = 0u;
            }
            /* Add to the software buffer. */
            U_txBuffer[locTxBufferWrite] = txDataByte;
            locTxBufferWrite++;

            /* Finally, update the real output pointer */
        #if ((U_TX_BUFFER_SIZE > U_MAX_BYTE_VALUE) && (CY_PSOC3))
            U_DisableTxInt();
        #endif /* (U_TX_BUFFER_SIZE > U_MAX_BYTE_VALUE) && (CY_PSOC3) */

            U_txBufferWrite = locTxBufferWrite;

        #if ((U_TX_BUFFER_SIZE > U_MAX_BYTE_VALUE) && (CY_PSOC3))
            U_EnableTxInt();
        #endif /* (U_TX_BUFFER_SIZE > U_MAX_BYTE_VALUE) && (CY_PSOC3) */

            if(0u != (U_TXSTATUS_REG & U_TX_STS_FIFO_EMPTY))
            {
                /* Trigger TX interrupt to send software buffer */
                U_SetPendingTxInt();
            }
        }

    #else

        while((U_TXSTATUS_REG & U_TX_STS_FIFO_FULL) != 0u)
        {
            /* Wait for room in the FIFO */
        }

        /* Add directly to the FIFO */
        U_TXDATA_REG = txDataByte;

    #endif /* U_TX_INTERRUPT_ENABLED */
    }


    /*******************************************************************************
    * Function Name: U_PutString
    ********************************************************************************
    *
    * Summary:
    *  Sends a NULL terminated string to the TX buffer for transmission.
    *
    * Parameters:
    *  string[]: Pointer to the null terminated string array residing in RAM or ROM
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  U_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  If there is not enough memory in the TX buffer for the entire string, this
    *  function blocks until the last character of the string is loaded into the
    *  TX buffer.
    *
    *******************************************************************************/
    void U_PutString(const char8 string[]) 
    {
        uint16 bufIndex = 0u;

        /* If not Initialized then skip this function */
        if(U_initVar != 0u)
        {
            /* This is a blocking function, it will not exit until all data is sent */
            while(string[bufIndex] != (char8) 0)
            {
                U_PutChar((uint8)string[bufIndex]);
                bufIndex++;
            }
        }
    }


    /*******************************************************************************
    * Function Name: U_PutArray
    ********************************************************************************
    *
    * Summary:
    *  Places N bytes of data from a memory array into the TX buffer for
    *  transmission.
    *
    * Parameters:
    *  string[]: Address of the memory array residing in RAM or ROM.
    *  byteCount: Number of bytes to be transmitted. The type depends on TX Buffer
    *             Size parameter.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  U_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  If there is not enough memory in the TX buffer for the entire string, this
    *  function blocks until the last character of the string is loaded into the
    *  TX buffer.
    *
    *******************************************************************************/
    void U_PutArray(const uint8 string[], uint16 byteCount)
                                                                    
    {
        uint16 bufIndex = 0u;

        /* If not Initialized then skip this function */
        if(U_initVar != 0u)
        {
            while(bufIndex < byteCount)
            {
                U_PutChar(string[bufIndex]);
                bufIndex++;
            }
        }
    }


    /*******************************************************************************
    * Function Name: U_PutCRLF
    ********************************************************************************
    *
    * Summary:
    *  Writes a byte of data followed by a carriage return (0x0D) and line feed
    *  (0x0A) to the transmit buffer.
    *
    * Parameters:
    *  txDataByte: Data byte to transmit before the carriage return and line feed.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  U_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void U_PutCRLF(uint8 txDataByte) 
    {
        /* If not Initialized then skip this function */
        if(U_initVar != 0u)
        {
            U_PutChar(txDataByte);
            U_PutChar(0x0Du);
            U_PutChar(0x0Au);
        }
    }


    /*******************************************************************************
    * Function Name: U_GetTxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Returns the number of bytes in the TX buffer which are waiting to be 
    *  transmitted.
    *  * TX software buffer is disabled (TX Buffer Size parameter is equal to 4): 
    *    returns 0 for empty TX FIFO, 1 for not full TX FIFO or 4 for full TX FIFO.
    *  * TX software buffer is enabled: returns the number of bytes in the TX 
    *    software buffer which are waiting to be transmitted. Bytes available in the
    *    TX FIFO do not count.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Number of bytes used in the TX buffer. Return value type depends on the TX 
    *  Buffer Size parameter.
    *
    * Global Variables:
    *  U_txBufferWrite - used to calculate left space.
    *  U_txBufferRead - used to calculate left space.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Allows the user to find out how full the TX Buffer is.
    *
    *******************************************************************************/
    uint16 U_GetTxBufferSize(void)
                                                            
    {
        uint16 size;

    #if (U_TX_INTERRUPT_ENABLED)

        /* Protect variables that could change on interrupt. */
        U_DisableTxInt();

        if(U_txBufferRead == U_txBufferWrite)
        {
            size = 0u;
        }
        else if(U_txBufferRead < U_txBufferWrite)
        {
            size = (U_txBufferWrite - U_txBufferRead);
        }
        else
        {
            size = (U_TX_BUFFER_SIZE - U_txBufferRead) +
                    U_txBufferWrite;
        }

        U_EnableTxInt();

    #else

        size = U_TXSTATUS_REG;

        /* Is the fifo is full. */
        if((size & U_TX_STS_FIFO_FULL) != 0u)
        {
            size = U_FIFO_LENGTH;
        }
        else if((size & U_TX_STS_FIFO_EMPTY) != 0u)
        {
            size = 0u;
        }
        else
        {
            /* We only know there is data in the fifo. */
            size = 1u;
        }

    #endif /* (U_TX_INTERRUPT_ENABLED) */

    return(size);
    }


    /*******************************************************************************
    * Function Name: U_ClearTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears all data from the TX buffer and hardware TX FIFO.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  U_txBufferWrite - cleared to zero.
    *  U_txBufferRead - cleared to zero.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Setting the pointers to zero makes the system believe there is no data to
    *  read and writing will resume at address 0 overwriting any data that may have
    *  remained in the RAM.
    *
    * Side Effects:
    *  Data waiting in the transmit buffer is not sent; a byte that is currently
    *  transmitting finishes transmitting.
    *
    *******************************************************************************/
    void U_ClearTxBuffer(void) 
    {
        uint8 enableInterrupts;

        enableInterrupts = CyEnterCriticalSection();
        /* Clear the HW FIFO */
        U_TXDATA_AUX_CTL_REG |= (uint8)  U_TX_FIFO_CLR;
        U_TXDATA_AUX_CTL_REG &= (uint8) ~U_TX_FIFO_CLR;
        CyExitCriticalSection(enableInterrupts);

    #if (U_TX_INTERRUPT_ENABLED)

        /* Protect variables that could change on interrupt. */
        U_DisableTxInt();

        U_txBufferRead = 0u;
        U_txBufferWrite = 0u;

        /* Enable Tx interrupt. */
        U_EnableTxInt();

    #endif /* (U_TX_INTERRUPT_ENABLED) */
    }


    /*******************************************************************************
    * Function Name: U_SendBreak
    ********************************************************************************
    *
    * Summary:
    *  Transmits a break signal on the bus.
    *
    * Parameters:
    *  uint8 retMode:  Send Break return mode. See the following table for options.
    *   U_SEND_BREAK - Initialize registers for break, send the Break
    *       signal and return immediately.
    *   U_WAIT_FOR_COMPLETE_REINIT - Wait until break transmission is
    *       complete, reinitialize registers to normal transmission mode then return
    *   U_REINIT - Reinitialize registers to normal transmission mode
    *       then return.
    *   U_SEND_WAIT_REINIT - Performs both options: 
    *      U_SEND_BREAK and U_WAIT_FOR_COMPLETE_REINIT.
    *      This option is recommended for most cases.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  U_initVar - checked to identify that the component has been
    *     initialized.
    *  txPeriod - static variable, used for keeping TX period configuration.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  SendBreak function initializes registers to send 13-bit break signal. It is
    *  important to return the registers configuration to normal for continue 8-bit
    *  operation.
    *  There are 3 variants for this API usage:
    *  1) SendBreak(3) - function will send the Break signal and take care on the
    *     configuration returning. Function will block CPU until transmission
    *     complete.
    *  2) User may want to use blocking time if UART configured to the low speed
    *     operation
    *     Example for this case:
    *     SendBreak(0);     - initialize Break signal transmission
    *         Add your code here to use CPU time
    *     SendBreak(1);     - complete Break operation
    *  3) Same to 2) but user may want to initialize and use the interrupt to
    *     complete break operation.
    *     Example for this case:
    *     Initialize TX interrupt with "TX - On TX Complete" parameter
    *     SendBreak(0);     - initialize Break signal transmission
    *         Add your code here to use CPU time
    *     When interrupt appear with U_TX_STS_COMPLETE status:
    *     SendBreak(2);     - complete Break operation
    *
    * Side Effects:
    *  The U_SendBreak() function initializes registers to send a
    *  break signal.
    *  Break signal length depends on the break signal bits configuration.
    *  The register configuration should be reinitialized before normal 8-bit
    *  communication can continue.
    *
    *******************************************************************************/
    void U_SendBreak(uint8 retMode) 
    {

        /* If not Initialized then skip this function*/
        if(U_initVar != 0u)
        {
            /* Set the Counter to 13-bits and transmit a 00 byte */
            /* When that is done then reset the counter value back */
            uint8 tmpStat;

        #if(U_HD_ENABLED) /* Half Duplex mode*/

            if( (retMode == U_SEND_BREAK) ||
                (retMode == U_SEND_WAIT_REINIT ) )
            {
                /* CTRL_HD_SEND_BREAK - sends break bits in HD mode */
                U_WriteControlRegister(U_ReadControlRegister() |
                                                      U_CTRL_HD_SEND_BREAK);
                /* Send zeros */
                U_TXDATA_REG = 0u;

                do /* Wait until transmit starts */
                {
                    tmpStat = U_TXSTATUS_REG;
                }
                while((tmpStat & U_TX_STS_FIFO_EMPTY) != 0u);
            }

            if( (retMode == U_WAIT_FOR_COMPLETE_REINIT) ||
                (retMode == U_SEND_WAIT_REINIT) )
            {
                do /* Wait until transmit complete */
                {
                    tmpStat = U_TXSTATUS_REG;
                }
                while(((uint8)~tmpStat & U_TX_STS_COMPLETE) != 0u);
            }

            if( (retMode == U_WAIT_FOR_COMPLETE_REINIT) ||
                (retMode == U_REINIT) ||
                (retMode == U_SEND_WAIT_REINIT) )
            {
                U_WriteControlRegister(U_ReadControlRegister() &
                                              (uint8)~U_CTRL_HD_SEND_BREAK);
            }

        #else /* U_HD_ENABLED Full Duplex mode */

            static uint8 txPeriod;

            if( (retMode == U_SEND_BREAK) ||
                (retMode == U_SEND_WAIT_REINIT) )
            {
                /* CTRL_HD_SEND_BREAK - skip to send parity bit at Break signal in Full Duplex mode */
                #if( (U_PARITY_TYPE != U__B_UART__NONE_REVB) || \
                                    (U_PARITY_TYPE_SW != 0u) )
                    U_WriteControlRegister(U_ReadControlRegister() |
                                                          U_CTRL_HD_SEND_BREAK);
                #endif /* End U_PARITY_TYPE != U__B_UART__NONE_REVB  */

                #if(U_TXCLKGEN_DP)
                    txPeriod = U_TXBITCLKTX_COMPLETE_REG;
                    U_TXBITCLKTX_COMPLETE_REG = U_TXBITCTR_BREAKBITS;
                #else
                    txPeriod = U_TXBITCTR_PERIOD_REG;
                    U_TXBITCTR_PERIOD_REG = U_TXBITCTR_BREAKBITS8X;
                #endif /* End U_TXCLKGEN_DP */

                /* Send zeros */
                U_TXDATA_REG = 0u;

                do /* Wait until transmit starts */
                {
                    tmpStat = U_TXSTATUS_REG;
                }
                while((tmpStat & U_TX_STS_FIFO_EMPTY) != 0u);
            }

            if( (retMode == U_WAIT_FOR_COMPLETE_REINIT) ||
                (retMode == U_SEND_WAIT_REINIT) )
            {
                do /* Wait until transmit complete */
                {
                    tmpStat = U_TXSTATUS_REG;
                }
                while(((uint8)~tmpStat & U_TX_STS_COMPLETE) != 0u);
            }

            if( (retMode == U_WAIT_FOR_COMPLETE_REINIT) ||
                (retMode == U_REINIT) ||
                (retMode == U_SEND_WAIT_REINIT) )
            {

            #if(U_TXCLKGEN_DP)
                U_TXBITCLKTX_COMPLETE_REG = txPeriod;
            #else
                U_TXBITCTR_PERIOD_REG = txPeriod;
            #endif /* End U_TXCLKGEN_DP */

            #if( (U_PARITY_TYPE != U__B_UART__NONE_REVB) || \
                 (U_PARITY_TYPE_SW != 0u) )
                U_WriteControlRegister(U_ReadControlRegister() &
                                                      (uint8) ~U_CTRL_HD_SEND_BREAK);
            #endif /* End U_PARITY_TYPE != NONE */
            }
        #endif    /* End U_HD_ENABLED */
        }
    }


    /*******************************************************************************
    * Function Name: U_SetTxAddressMode
    ********************************************************************************
    *
    * Summary:
    *  Configures the transmitter to signal the next bytes is address or data.
    *
    * Parameters:
    *  addressMode: 
    *       U_SET_SPACE - Configure the transmitter to send the next
    *                                    byte as a data.
    *       U_SET_MARK  - Configure the transmitter to send the next
    *                                    byte as an address.
    *
    * Return:
    *  None.
    *
    * Side Effects:
    *  This function sets and clears U_CTRL_MARK bit in the Control
    *  register.
    *
    *******************************************************************************/
    void U_SetTxAddressMode(uint8 addressMode) 
    {
        /* Mark/Space sending enable */
        if(addressMode != 0u)
        {
        #if( U_CONTROL_REG_REMOVED == 0u )
            U_WriteControlRegister(U_ReadControlRegister() |
                                                  U_CTRL_MARK);
        #endif /* End U_CONTROL_REG_REMOVED == 0u */
        }
        else
        {
        #if( U_CONTROL_REG_REMOVED == 0u )
            U_WriteControlRegister(U_ReadControlRegister() &
                                                  (uint8) ~U_CTRL_MARK);
        #endif /* End U_CONTROL_REG_REMOVED == 0u */
        }
    }

#endif  /* EndU_TX_ENABLED */

#if(U_HD_ENABLED)


    /*******************************************************************************
    * Function Name: U_LoadRxConfig
    ********************************************************************************
    *
    * Summary:
    *  Loads the receiver configuration in half duplex mode. After calling this
    *  function, the UART is ready to receive data.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Side Effects:
    *  Valid only in half duplex mode. You must make sure that the previous
    *  transaction is complete and it is safe to unload the transmitter
    *  configuration.
    *
    *******************************************************************************/
    void U_LoadRxConfig(void) 
    {
        U_WriteControlRegister(U_ReadControlRegister() &
                                                (uint8)~U_CTRL_HD_SEND);
        U_RXBITCTR_PERIOD_REG = U_HD_RXBITCTR_INIT;

    #if (U_RX_INTERRUPT_ENABLED)
        /* Enable RX interrupt after set RX configuration */
        U_SetRxInterruptMode(U_INIT_RX_INTERRUPTS_MASK);
    #endif /* (U_RX_INTERRUPT_ENABLED) */
    }


    /*******************************************************************************
    * Function Name: U_LoadTxConfig
    ********************************************************************************
    *
    * Summary:
    *  Loads the transmitter configuration in half duplex mode. After calling this
    *  function, the UART is ready to transmit data.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Side Effects:
    *  Valid only in half duplex mode. You must make sure that the previous
    *  transaction is complete and it is safe to unload the receiver configuration.
    *
    *******************************************************************************/
    void U_LoadTxConfig(void) 
    {
    #if (U_RX_INTERRUPT_ENABLED)
        /* Disable RX interrupts before set TX configuration */
        U_SetRxInterruptMode(0u);
    #endif /* (U_RX_INTERRUPT_ENABLED) */

        U_WriteControlRegister(U_ReadControlRegister() | U_CTRL_HD_SEND);
        U_RXBITCTR_PERIOD_REG = U_HD_TXBITCTR_INIT;
    }

#endif  /* U_HD_ENABLED */


/* [] END OF FILE */
