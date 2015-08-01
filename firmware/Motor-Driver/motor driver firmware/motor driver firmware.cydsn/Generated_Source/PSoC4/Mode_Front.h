/*******************************************************************************
* File Name: Mode_Front.h  
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

#if !defined(CY_PINS_Mode_Front_H) /* Pins Mode_Front_H */
#define CY_PINS_Mode_Front_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Mode_Front_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Mode_Front_Write(uint8 value) ;
void    Mode_Front_SetDriveMode(uint8 mode) ;
uint8   Mode_Front_ReadDataReg(void) ;
uint8   Mode_Front_Read(void) ;
uint8   Mode_Front_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Mode_Front_DRIVE_MODE_BITS        (3)
#define Mode_Front_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Mode_Front_DRIVE_MODE_BITS))

#define Mode_Front_DM_ALG_HIZ         (0x00u)
#define Mode_Front_DM_DIG_HIZ         (0x01u)
#define Mode_Front_DM_RES_UP          (0x02u)
#define Mode_Front_DM_RES_DWN         (0x03u)
#define Mode_Front_DM_OD_LO           (0x04u)
#define Mode_Front_DM_OD_HI           (0x05u)
#define Mode_Front_DM_STRONG          (0x06u)
#define Mode_Front_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Mode_Front_MASK               Mode_Front__MASK
#define Mode_Front_SHIFT              Mode_Front__SHIFT
#define Mode_Front_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Mode_Front_PS                     (* (reg32 *) Mode_Front__PS)
/* Port Configuration */
#define Mode_Front_PC                     (* (reg32 *) Mode_Front__PC)
/* Data Register */
#define Mode_Front_DR                     (* (reg32 *) Mode_Front__DR)
/* Input Buffer Disable Override */
#define Mode_Front_INP_DIS                (* (reg32 *) Mode_Front__PC2)


#if defined(Mode_Front__INTSTAT)  /* Interrupt Registers */

    #define Mode_Front_INTSTAT                (* (reg32 *) Mode_Front__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Mode_Front_DRIVE_MODE_SHIFT       (0x00u)
#define Mode_Front_DRIVE_MODE_MASK        (0x07u << Mode_Front_DRIVE_MODE_SHIFT)


#endif /* End Pins Mode_Front_H */


/* [] END OF FILE */
