/*******************************************************************************
* File Name: M2QA.h  
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

#if !defined(CY_PINS_M2QA_H) /* Pins M2QA_H */
#define CY_PINS_M2QA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "M2QA_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    M2QA_Write(uint8 value) ;
void    M2QA_SetDriveMode(uint8 mode) ;
uint8   M2QA_ReadDataReg(void) ;
uint8   M2QA_Read(void) ;
uint8   M2QA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define M2QA_DRIVE_MODE_BITS        (3)
#define M2QA_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - M2QA_DRIVE_MODE_BITS))

#define M2QA_DM_ALG_HIZ         (0x00u)
#define M2QA_DM_DIG_HIZ         (0x01u)
#define M2QA_DM_RES_UP          (0x02u)
#define M2QA_DM_RES_DWN         (0x03u)
#define M2QA_DM_OD_LO           (0x04u)
#define M2QA_DM_OD_HI           (0x05u)
#define M2QA_DM_STRONG          (0x06u)
#define M2QA_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define M2QA_MASK               M2QA__MASK
#define M2QA_SHIFT              M2QA__SHIFT
#define M2QA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define M2QA_PS                     (* (reg32 *) M2QA__PS)
/* Port Configuration */
#define M2QA_PC                     (* (reg32 *) M2QA__PC)
/* Data Register */
#define M2QA_DR                     (* (reg32 *) M2QA__DR)
/* Input Buffer Disable Override */
#define M2QA_INP_DIS                (* (reg32 *) M2QA__PC2)


#if defined(M2QA__INTSTAT)  /* Interrupt Registers */

    #define M2QA_INTSTAT                (* (reg32 *) M2QA__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define M2QA_DRIVE_MODE_SHIFT       (0x00u)
#define M2QA_DRIVE_MODE_MASK        (0x07u << M2QA_DRIVE_MODE_SHIFT)


#endif /* End Pins M2QA_H */


/* [] END OF FILE */
