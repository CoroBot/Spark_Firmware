/*******************************************************************************
* File Name: Mode2.h  
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

#if !defined(CY_PINS_Mode2_H) /* Pins Mode2_H */
#define CY_PINS_Mode2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Mode2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Mode2_Write(uint8 value) ;
void    Mode2_SetDriveMode(uint8 mode) ;
uint8   Mode2_ReadDataReg(void) ;
uint8   Mode2_Read(void) ;
uint8   Mode2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Mode2_DRIVE_MODE_BITS        (3)
#define Mode2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Mode2_DRIVE_MODE_BITS))

#define Mode2_DM_ALG_HIZ         (0x00u)
#define Mode2_DM_DIG_HIZ         (0x01u)
#define Mode2_DM_RES_UP          (0x02u)
#define Mode2_DM_RES_DWN         (0x03u)
#define Mode2_DM_OD_LO           (0x04u)
#define Mode2_DM_OD_HI           (0x05u)
#define Mode2_DM_STRONG          (0x06u)
#define Mode2_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Mode2_MASK               Mode2__MASK
#define Mode2_SHIFT              Mode2__SHIFT
#define Mode2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Mode2_PS                     (* (reg32 *) Mode2__PS)
/* Port Configuration */
#define Mode2_PC                     (* (reg32 *) Mode2__PC)
/* Data Register */
#define Mode2_DR                     (* (reg32 *) Mode2__DR)
/* Input Buffer Disable Override */
#define Mode2_INP_DIS                (* (reg32 *) Mode2__PC2)


#if defined(Mode2__INTSTAT)  /* Interrupt Registers */

    #define Mode2_INTSTAT                (* (reg32 *) Mode2__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Mode2_DRIVE_MODE_SHIFT       (0x00u)
#define Mode2_DRIVE_MODE_MASK        (0x07u << Mode2_DRIVE_MODE_SHIFT)


#endif /* End Pins Mode2_H */


/* [] END OF FILE */
