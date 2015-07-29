/*******************************************************************************
* File Name: M1QA.h  
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

#if !defined(CY_PINS_M1QA_H) /* Pins M1QA_H */
#define CY_PINS_M1QA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "M1QA_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    M1QA_Write(uint8 value) ;
void    M1QA_SetDriveMode(uint8 mode) ;
uint8   M1QA_ReadDataReg(void) ;
uint8   M1QA_Read(void) ;
uint8   M1QA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define M1QA_DRIVE_MODE_BITS        (3)
#define M1QA_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - M1QA_DRIVE_MODE_BITS))

#define M1QA_DM_ALG_HIZ         (0x00u)
#define M1QA_DM_DIG_HIZ         (0x01u)
#define M1QA_DM_RES_UP          (0x02u)
#define M1QA_DM_RES_DWN         (0x03u)
#define M1QA_DM_OD_LO           (0x04u)
#define M1QA_DM_OD_HI           (0x05u)
#define M1QA_DM_STRONG          (0x06u)
#define M1QA_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define M1QA_MASK               M1QA__MASK
#define M1QA_SHIFT              M1QA__SHIFT
#define M1QA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define M1QA_PS                     (* (reg32 *) M1QA__PS)
/* Port Configuration */
#define M1QA_PC                     (* (reg32 *) M1QA__PC)
/* Data Register */
#define M1QA_DR                     (* (reg32 *) M1QA__DR)
/* Input Buffer Disable Override */
#define M1QA_INP_DIS                (* (reg32 *) M1QA__PC2)


#if defined(M1QA__INTSTAT)  /* Interrupt Registers */

    #define M1QA_INTSTAT                (* (reg32 *) M1QA__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define M1QA_DRIVE_MODE_SHIFT       (0x00u)
#define M1QA_DRIVE_MODE_MASK        (0x07u << M1QA_DRIVE_MODE_SHIFT)


#endif /* End Pins M1QA_H */


/* [] END OF FILE */
