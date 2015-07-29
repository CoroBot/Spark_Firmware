/*******************************************************************************
* File Name: Power1.h  
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

#if !defined(CY_PINS_Power1_H) /* Pins Power1_H */
#define CY_PINS_Power1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Power1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Power1_Write(uint8 value) ;
void    Power1_SetDriveMode(uint8 mode) ;
uint8   Power1_ReadDataReg(void) ;
uint8   Power1_Read(void) ;
uint8   Power1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Power1_DRIVE_MODE_BITS        (3)
#define Power1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Power1_DRIVE_MODE_BITS))

#define Power1_DM_ALG_HIZ         (0x00u)
#define Power1_DM_DIG_HIZ         (0x01u)
#define Power1_DM_RES_UP          (0x02u)
#define Power1_DM_RES_DWN         (0x03u)
#define Power1_DM_OD_LO           (0x04u)
#define Power1_DM_OD_HI           (0x05u)
#define Power1_DM_STRONG          (0x06u)
#define Power1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Power1_MASK               Power1__MASK
#define Power1_SHIFT              Power1__SHIFT
#define Power1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Power1_PS                     (* (reg32 *) Power1__PS)
/* Port Configuration */
#define Power1_PC                     (* (reg32 *) Power1__PC)
/* Data Register */
#define Power1_DR                     (* (reg32 *) Power1__DR)
/* Input Buffer Disable Override */
#define Power1_INP_DIS                (* (reg32 *) Power1__PC2)


#if defined(Power1__INTSTAT)  /* Interrupt Registers */

    #define Power1_INTSTAT                (* (reg32 *) Power1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Power1_DRIVE_MODE_SHIFT       (0x00u)
#define Power1_DRIVE_MODE_MASK        (0x07u << Power1_DRIVE_MODE_SHIFT)


#endif /* End Pins Power1_H */


/* [] END OF FILE */
