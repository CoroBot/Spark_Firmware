/*******************************************************************************
* File Name: cursense1.h  
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

#if !defined(CY_PINS_cursense1_H) /* Pins cursense1_H */
#define CY_PINS_cursense1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cursense1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    cursense1_Write(uint8 value) ;
void    cursense1_SetDriveMode(uint8 mode) ;
uint8   cursense1_ReadDataReg(void) ;
uint8   cursense1_Read(void) ;
uint8   cursense1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define cursense1_DRIVE_MODE_BITS        (3)
#define cursense1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - cursense1_DRIVE_MODE_BITS))

#define cursense1_DM_ALG_HIZ         (0x00u)
#define cursense1_DM_DIG_HIZ         (0x01u)
#define cursense1_DM_RES_UP          (0x02u)
#define cursense1_DM_RES_DWN         (0x03u)
#define cursense1_DM_OD_LO           (0x04u)
#define cursense1_DM_OD_HI           (0x05u)
#define cursense1_DM_STRONG          (0x06u)
#define cursense1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define cursense1_MASK               cursense1__MASK
#define cursense1_SHIFT              cursense1__SHIFT
#define cursense1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define cursense1_PS                     (* (reg32 *) cursense1__PS)
/* Port Configuration */
#define cursense1_PC                     (* (reg32 *) cursense1__PC)
/* Data Register */
#define cursense1_DR                     (* (reg32 *) cursense1__DR)
/* Input Buffer Disable Override */
#define cursense1_INP_DIS                (* (reg32 *) cursense1__PC2)


#if defined(cursense1__INTSTAT)  /* Interrupt Registers */

    #define cursense1_INTSTAT                (* (reg32 *) cursense1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define cursense1_DRIVE_MODE_SHIFT       (0x00u)
#define cursense1_DRIVE_MODE_MASK        (0x07u << cursense1_DRIVE_MODE_SHIFT)


#endif /* End Pins cursense1_H */


/* [] END OF FILE */
