/*******************************************************************************
* File Name: M2QB.h  
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

#if !defined(CY_PINS_M2QB_H) /* Pins M2QB_H */
#define CY_PINS_M2QB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "M2QB_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    M2QB_Write(uint8 value) ;
void    M2QB_SetDriveMode(uint8 mode) ;
uint8   M2QB_ReadDataReg(void) ;
uint8   M2QB_Read(void) ;
uint8   M2QB_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define M2QB_DRIVE_MODE_BITS        (3)
#define M2QB_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - M2QB_DRIVE_MODE_BITS))

#define M2QB_DM_ALG_HIZ         (0x00u)
#define M2QB_DM_DIG_HIZ         (0x01u)
#define M2QB_DM_RES_UP          (0x02u)
#define M2QB_DM_RES_DWN         (0x03u)
#define M2QB_DM_OD_LO           (0x04u)
#define M2QB_DM_OD_HI           (0x05u)
#define M2QB_DM_STRONG          (0x06u)
#define M2QB_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define M2QB_MASK               M2QB__MASK
#define M2QB_SHIFT              M2QB__SHIFT
#define M2QB_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define M2QB_PS                     (* (reg32 *) M2QB__PS)
/* Port Configuration */
#define M2QB_PC                     (* (reg32 *) M2QB__PC)
/* Data Register */
#define M2QB_DR                     (* (reg32 *) M2QB__DR)
/* Input Buffer Disable Override */
#define M2QB_INP_DIS                (* (reg32 *) M2QB__PC2)


#if defined(M2QB__INTSTAT)  /* Interrupt Registers */

    #define M2QB_INTSTAT                (* (reg32 *) M2QB__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define M2QB_DRIVE_MODE_SHIFT       (0x00u)
#define M2QB_DRIVE_MODE_MASK        (0x07u << M2QB_DRIVE_MODE_SHIFT)


#endif /* End Pins M2QB_H */


/* [] END OF FILE */
