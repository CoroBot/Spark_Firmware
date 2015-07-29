/*******************************************************************************
* File Name: cursense2.h  
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

#if !defined(CY_PINS_cursense2_H) /* Pins cursense2_H */
#define CY_PINS_cursense2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cursense2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    cursense2_Write(uint8 value) ;
void    cursense2_SetDriveMode(uint8 mode) ;
uint8   cursense2_ReadDataReg(void) ;
uint8   cursense2_Read(void) ;
uint8   cursense2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define cursense2_DRIVE_MODE_BITS        (3)
#define cursense2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - cursense2_DRIVE_MODE_BITS))

#define cursense2_DM_ALG_HIZ         (0x00u)
#define cursense2_DM_DIG_HIZ         (0x01u)
#define cursense2_DM_RES_UP          (0x02u)
#define cursense2_DM_RES_DWN         (0x03u)
#define cursense2_DM_OD_LO           (0x04u)
#define cursense2_DM_OD_HI           (0x05u)
#define cursense2_DM_STRONG          (0x06u)
#define cursense2_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define cursense2_MASK               cursense2__MASK
#define cursense2_SHIFT              cursense2__SHIFT
#define cursense2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define cursense2_PS                     (* (reg32 *) cursense2__PS)
/* Port Configuration */
#define cursense2_PC                     (* (reg32 *) cursense2__PC)
/* Data Register */
#define cursense2_DR                     (* (reg32 *) cursense2__DR)
/* Input Buffer Disable Override */
#define cursense2_INP_DIS                (* (reg32 *) cursense2__PC2)


#if defined(cursense2__INTSTAT)  /* Interrupt Registers */

    #define cursense2_INTSTAT                (* (reg32 *) cursense2__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define cursense2_DRIVE_MODE_SHIFT       (0x00u)
#define cursense2_DRIVE_MODE_MASK        (0x07u << cursense2_DRIVE_MODE_SHIFT)


#endif /* End Pins cursense2_H */


/* [] END OF FILE */
