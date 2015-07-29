/*******************************************************************************
* File Name: BIN1_1.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BIN1_1_H) /* Pins BIN1_1_H */
#define CY_PINS_BIN1_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BIN1_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BIN1_1_Write(uint8 value) ;
void    BIN1_1_SetDriveMode(uint8 mode) ;
uint8   BIN1_1_ReadDataReg(void) ;
uint8   BIN1_1_Read(void) ;
uint8   BIN1_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BIN1_1_DRIVE_MODE_BITS        (3)
#define BIN1_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BIN1_1_DRIVE_MODE_BITS))

#define BIN1_1_DM_ALG_HIZ         (0x00u)
#define BIN1_1_DM_DIG_HIZ         (0x01u)
#define BIN1_1_DM_RES_UP          (0x02u)
#define BIN1_1_DM_RES_DWN         (0x03u)
#define BIN1_1_DM_OD_LO           (0x04u)
#define BIN1_1_DM_OD_HI           (0x05u)
#define BIN1_1_DM_STRONG          (0x06u)
#define BIN1_1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define BIN1_1_MASK               BIN1_1__MASK
#define BIN1_1_SHIFT              BIN1_1__SHIFT
#define BIN1_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BIN1_1_PS                     (* (reg32 *) BIN1_1__PS)
/* Port Configuration */
#define BIN1_1_PC                     (* (reg32 *) BIN1_1__PC)
/* Data Register */
#define BIN1_1_DR                     (* (reg32 *) BIN1_1__DR)
/* Input Buffer Disable Override */
#define BIN1_1_INP_DIS                (* (reg32 *) BIN1_1__PC2)


#if defined(BIN1_1__INTSTAT)  /* Interrupt Registers */

    #define BIN1_1_INTSTAT                (* (reg32 *) BIN1_1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define BIN1_1_DRIVE_MODE_SHIFT       (0x00u)
#define BIN1_1_DRIVE_MODE_MASK        (0x07u << BIN1_1_DRIVE_MODE_SHIFT)


#endif /* End Pins BIN1_1_H */


/* [] END OF FILE */
