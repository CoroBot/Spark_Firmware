/*******************************************************************************
* File Name: AIN1_2.h  
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

#if !defined(CY_PINS_AIN1_2_H) /* Pins AIN1_2_H */
#define CY_PINS_AIN1_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "AIN1_2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    AIN1_2_Write(uint8 value) ;
void    AIN1_2_SetDriveMode(uint8 mode) ;
uint8   AIN1_2_ReadDataReg(void) ;
uint8   AIN1_2_Read(void) ;
uint8   AIN1_2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define AIN1_2_DRIVE_MODE_BITS        (3)
#define AIN1_2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - AIN1_2_DRIVE_MODE_BITS))

#define AIN1_2_DM_ALG_HIZ         (0x00u)
#define AIN1_2_DM_DIG_HIZ         (0x01u)
#define AIN1_2_DM_RES_UP          (0x02u)
#define AIN1_2_DM_RES_DWN         (0x03u)
#define AIN1_2_DM_OD_LO           (0x04u)
#define AIN1_2_DM_OD_HI           (0x05u)
#define AIN1_2_DM_STRONG          (0x06u)
#define AIN1_2_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define AIN1_2_MASK               AIN1_2__MASK
#define AIN1_2_SHIFT              AIN1_2__SHIFT
#define AIN1_2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AIN1_2_PS                     (* (reg32 *) AIN1_2__PS)
/* Port Configuration */
#define AIN1_2_PC                     (* (reg32 *) AIN1_2__PC)
/* Data Register */
#define AIN1_2_DR                     (* (reg32 *) AIN1_2__DR)
/* Input Buffer Disable Override */
#define AIN1_2_INP_DIS                (* (reg32 *) AIN1_2__PC2)


#if defined(AIN1_2__INTSTAT)  /* Interrupt Registers */

    #define AIN1_2_INTSTAT                (* (reg32 *) AIN1_2__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define AIN1_2_DRIVE_MODE_SHIFT       (0x00u)
#define AIN1_2_DRIVE_MODE_MASK        (0x07u << AIN1_2_DRIVE_MODE_SHIFT)


#endif /* End Pins AIN1_2_H */


/* [] END OF FILE */
