/*******************************************************************************
* File Name: RS485CTL.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_RS485CTL_H) /* CY_CONTROL_REG_RS485CTL_H */
#define CY_CONTROL_REG_RS485CTL_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} RS485CTL_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    RS485CTL_Write(uint8 control) ;
uint8   RS485CTL_Read(void) ;

void RS485CTL_SaveConfig(void) ;
void RS485CTL_RestoreConfig(void) ;
void RS485CTL_Sleep(void) ; 
void RS485CTL_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define RS485CTL_Control        (* (reg8 *) RS485CTL_Sync_ctrl_reg__CONTROL_REG )
#define RS485CTL_Control_PTR    (  (reg8 *) RS485CTL_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_RS485CTL_H */


/* [] END OF FILE */
