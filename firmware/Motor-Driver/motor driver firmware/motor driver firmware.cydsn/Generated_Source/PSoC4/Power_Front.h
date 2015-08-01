/*******************************************************************************
* File Name: Power_Front.h  
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

#if !defined(CY_PINS_Power_Front_H) /* Pins Power_Front_H */
#define CY_PINS_Power_Front_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Power_Front_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Power_Front_Write(uint8 value) ;
void    Power_Front_SetDriveMode(uint8 mode) ;
uint8   Power_Front_ReadDataReg(void) ;
uint8   Power_Front_Read(void) ;
uint8   Power_Front_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Power_Front_DRIVE_MODE_BITS        (3)
#define Power_Front_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Power_Front_DRIVE_MODE_BITS))

#define Power_Front_DM_ALG_HIZ         (0x00u)
#define Power_Front_DM_DIG_HIZ         (0x01u)
#define Power_Front_DM_RES_UP          (0x02u)
#define Power_Front_DM_RES_DWN         (0x03u)
#define Power_Front_DM_OD_LO           (0x04u)
#define Power_Front_DM_OD_HI           (0x05u)
#define Power_Front_DM_STRONG          (0x06u)
#define Power_Front_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Power_Front_MASK               Power_Front__MASK
#define Power_Front_SHIFT              Power_Front__SHIFT
#define Power_Front_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Power_Front_PS                     (* (reg32 *) Power_Front__PS)
/* Port Configuration */
#define Power_Front_PC                     (* (reg32 *) Power_Front__PC)
/* Data Register */
#define Power_Front_DR                     (* (reg32 *) Power_Front__DR)
/* Input Buffer Disable Override */
#define Power_Front_INP_DIS                (* (reg32 *) Power_Front__PC2)


#if defined(Power_Front__INTSTAT)  /* Interrupt Registers */

    #define Power_Front_INTSTAT                (* (reg32 *) Power_Front__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Power_Front_DRIVE_MODE_SHIFT       (0x00u)
#define Power_Front_DRIVE_MODE_MASK        (0x07u << Power_Front_DRIVE_MODE_SHIFT)


#endif /* End Pins Power_Front_H */


/* [] END OF FILE */
