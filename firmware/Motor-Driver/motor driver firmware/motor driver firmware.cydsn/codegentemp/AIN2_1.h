/*******************************************************************************
* File Name: AIN2_1.h  
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

#if !defined(CY_PINS_AIN2_1_H) /* Pins AIN2_1_H */
#define CY_PINS_AIN2_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "AIN2_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    AIN2_1_Write(uint8 value) ;
void    AIN2_1_SetDriveMode(uint8 mode) ;
uint8   AIN2_1_ReadDataReg(void) ;
uint8   AIN2_1_Read(void) ;
uint8   AIN2_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define AIN2_1_DRIVE_MODE_BITS        (3)
#define AIN2_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - AIN2_1_DRIVE_MODE_BITS))

#define AIN2_1_DM_ALG_HIZ         (0x00u)
#define AIN2_1_DM_DIG_HIZ         (0x01u)
#define AIN2_1_DM_RES_UP          (0x02u)
#define AIN2_1_DM_RES_DWN         (0x03u)
#define AIN2_1_DM_OD_LO           (0x04u)
#define AIN2_1_DM_OD_HI           (0x05u)
#define AIN2_1_DM_STRONG          (0x06u)
#define AIN2_1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define AIN2_1_MASK               AIN2_1__MASK
#define AIN2_1_SHIFT              AIN2_1__SHIFT
#define AIN2_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AIN2_1_PS                     (* (reg32 *) AIN2_1__PS)
/* Port Configuration */
#define AIN2_1_PC                     (* (reg32 *) AIN2_1__PC)
/* Data Register */
#define AIN2_1_DR                     (* (reg32 *) AIN2_1__DR)
/* Input Buffer Disable Override */
#define AIN2_1_INP_DIS                (* (reg32 *) AIN2_1__PC2)


#if defined(AIN2_1__INTSTAT)  /* Interrupt Registers */

    #define AIN2_1_INTSTAT                (* (reg32 *) AIN2_1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define AIN2_1_DRIVE_MODE_SHIFT       (0x00u)
#define AIN2_1_DRIVE_MODE_MASK        (0x07u << AIN2_1_DRIVE_MODE_SHIFT)


#endif /* End Pins AIN2_1_H */


/* [] END OF FILE */
