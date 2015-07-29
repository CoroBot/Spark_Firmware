/*******************************************************************************
* File Name: Power2.h  
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

#if !defined(CY_PINS_Power2_H) /* Pins Power2_H */
#define CY_PINS_Power2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Power2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Power2_Write(uint8 value) ;
void    Power2_SetDriveMode(uint8 mode) ;
uint8   Power2_ReadDataReg(void) ;
uint8   Power2_Read(void) ;
uint8   Power2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Power2_DRIVE_MODE_BITS        (3)
#define Power2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Power2_DRIVE_MODE_BITS))

#define Power2_DM_ALG_HIZ         (0x00u)
#define Power2_DM_DIG_HIZ         (0x01u)
#define Power2_DM_RES_UP          (0x02u)
#define Power2_DM_RES_DWN         (0x03u)
#define Power2_DM_OD_LO           (0x04u)
#define Power2_DM_OD_HI           (0x05u)
#define Power2_DM_STRONG          (0x06u)
#define Power2_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Power2_MASK               Power2__MASK
#define Power2_SHIFT              Power2__SHIFT
#define Power2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Power2_PS                     (* (reg32 *) Power2__PS)
/* Port Configuration */
#define Power2_PC                     (* (reg32 *) Power2__PC)
/* Data Register */
#define Power2_DR                     (* (reg32 *) Power2__DR)
/* Input Buffer Disable Override */
#define Power2_INP_DIS                (* (reg32 *) Power2__PC2)


#if defined(Power2__INTSTAT)  /* Interrupt Registers */

    #define Power2_INTSTAT                (* (reg32 *) Power2__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Power2_DRIVE_MODE_SHIFT       (0x00u)
#define Power2_DRIVE_MODE_MASK        (0x07u << Power2_DRIVE_MODE_SHIFT)


#endif /* End Pins Power2_H */


/* [] END OF FILE */
