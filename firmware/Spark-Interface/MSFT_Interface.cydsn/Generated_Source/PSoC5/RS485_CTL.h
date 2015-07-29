/*******************************************************************************
* File Name: RS485_CTL.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_RS485_CTL_H) /* CY_STATUS_REG_RS485_CTL_H */
#define CY_STATUS_REG_RS485_CTL_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} RS485_CTL_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 RS485_CTL_Read(void) ;
void RS485_CTL_InterruptEnable(void) ;
void RS485_CTL_InterruptDisable(void) ;
void RS485_CTL_WriteMask(uint8 mask) ;
uint8 RS485_CTL_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define RS485_CTL_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define RS485_CTL_INPUTS              8


/***************************************
*             Registers
***************************************/

/* Status Register */
#define RS485_CTL_Status             (* (reg8 *) RS485_CTL_sts_sts_reg__STATUS_REG )
#define RS485_CTL_Status_PTR         (  (reg8 *) RS485_CTL_sts_sts_reg__STATUS_REG )
#define RS485_CTL_Status_Mask        (* (reg8 *) RS485_CTL_sts_sts_reg__MASK_REG )
#define RS485_CTL_Status_Aux_Ctrl    (* (reg8 *) RS485_CTL_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_RS485_CTL_H */


/* [] END OF FILE */
