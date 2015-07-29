/*******************************************************************************
* File Name: Mode1.h  
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

#if !defined(CY_PINS_Mode1_H) /* Pins Mode1_H */
#define CY_PINS_Mode1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Mode1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Mode1_Write(uint8 value) ;
void    Mode1_SetDriveMode(uint8 mode) ;
uint8   Mode1_ReadDataReg(void) ;
uint8   Mode1_Read(void) ;
uint8   Mode1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Mode1_DRIVE_MODE_BITS        (3)
#define Mode1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Mode1_DRIVE_MODE_BITS))

#define Mode1_DM_ALG_HIZ         (0x00u)
#define Mode1_DM_DIG_HIZ         (0x01u)
#define Mode1_DM_RES_UP          (0x02u)
#define Mode1_DM_RES_DWN         (0x03u)
#define Mode1_DM_OD_LO           (0x04u)
#define Mode1_DM_OD_HI           (0x05u)
#define Mode1_DM_STRONG          (0x06u)
#define Mode1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Mode1_MASK               Mode1__MASK
#define Mode1_SHIFT              Mode1__SHIFT
#define Mode1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Mode1_PS                     (* (reg32 *) Mode1__PS)
/* Port Configuration */
#define Mode1_PC                     (* (reg32 *) Mode1__PC)
/* Data Register */
#define Mode1_DR                     (* (reg32 *) Mode1__DR)
/* Input Buffer Disable Override */
#define Mode1_INP_DIS                (* (reg32 *) Mode1__PC2)


#if defined(Mode1__INTSTAT)  /* Interrupt Registers */

    #define Mode1_INTSTAT                (* (reg32 *) Mode1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Mode1_DRIVE_MODE_SHIFT       (0x00u)
#define Mode1_DRIVE_MODE_MASK        (0x07u << Mode1_DRIVE_MODE_SHIFT)


#endif /* End Pins Mode1_H */


/* [] END OF FILE */
