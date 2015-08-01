/*******************************************************************************
* File Name: Power_Rear.h  
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

#if !defined(CY_PINS_Power_Rear_H) /* Pins Power_Rear_H */
#define CY_PINS_Power_Rear_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Power_Rear_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Power_Rear_Write(uint8 value) ;
void    Power_Rear_SetDriveMode(uint8 mode) ;
uint8   Power_Rear_ReadDataReg(void) ;
uint8   Power_Rear_Read(void) ;
uint8   Power_Rear_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Power_Rear_DRIVE_MODE_BITS        (3)
#define Power_Rear_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Power_Rear_DRIVE_MODE_BITS))

#define Power_Rear_DM_ALG_HIZ         (0x00u)
#define Power_Rear_DM_DIG_HIZ         (0x01u)
#define Power_Rear_DM_RES_UP          (0x02u)
#define Power_Rear_DM_RES_DWN         (0x03u)
#define Power_Rear_DM_OD_LO           (0x04u)
#define Power_Rear_DM_OD_HI           (0x05u)
#define Power_Rear_DM_STRONG          (0x06u)
#define Power_Rear_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Power_Rear_MASK               Power_Rear__MASK
#define Power_Rear_SHIFT              Power_Rear__SHIFT
#define Power_Rear_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Power_Rear_PS                     (* (reg32 *) Power_Rear__PS)
/* Port Configuration */
#define Power_Rear_PC                     (* (reg32 *) Power_Rear__PC)
/* Data Register */
#define Power_Rear_DR                     (* (reg32 *) Power_Rear__DR)
/* Input Buffer Disable Override */
#define Power_Rear_INP_DIS                (* (reg32 *) Power_Rear__PC2)


#if defined(Power_Rear__INTSTAT)  /* Interrupt Registers */

    #define Power_Rear_INTSTAT                (* (reg32 *) Power_Rear__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Power_Rear_DRIVE_MODE_SHIFT       (0x00u)
#define Power_Rear_DRIVE_MODE_MASK        (0x07u << Power_Rear_DRIVE_MODE_SHIFT)


#endif /* End Pins Power_Rear_H */


/* [] END OF FILE */
