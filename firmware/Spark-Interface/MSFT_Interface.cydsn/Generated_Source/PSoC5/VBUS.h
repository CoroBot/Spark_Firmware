/*******************************************************************************
* File Name: VBUS.h  
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

#if !defined(CY_PINS_VBUS_H) /* Pins VBUS_H */
#define CY_PINS_VBUS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VBUS_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VBUS__PORT == 15 && ((VBUS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    VBUS_Write(uint8 value) ;
void    VBUS_SetDriveMode(uint8 mode) ;
uint8   VBUS_ReadDataReg(void) ;
uint8   VBUS_Read(void) ;
uint8   VBUS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VBUS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define VBUS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define VBUS_DM_RES_UP          PIN_DM_RES_UP
#define VBUS_DM_RES_DWN         PIN_DM_RES_DWN
#define VBUS_DM_OD_LO           PIN_DM_OD_LO
#define VBUS_DM_OD_HI           PIN_DM_OD_HI
#define VBUS_DM_STRONG          PIN_DM_STRONG
#define VBUS_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define VBUS_MASK               VBUS__MASK
#define VBUS_SHIFT              VBUS__SHIFT
#define VBUS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VBUS_PS                     (* (reg8 *) VBUS__PS)
/* Data Register */
#define VBUS_DR                     (* (reg8 *) VBUS__DR)
/* Port Number */
#define VBUS_PRT_NUM                (* (reg8 *) VBUS__PRT) 
/* Connect to Analog Globals */                                                  
#define VBUS_AG                     (* (reg8 *) VBUS__AG)                       
/* Analog MUX bux enable */
#define VBUS_AMUX                   (* (reg8 *) VBUS__AMUX) 
/* Bidirectional Enable */                                                        
#define VBUS_BIE                    (* (reg8 *) VBUS__BIE)
/* Bit-mask for Aliased Register Access */
#define VBUS_BIT_MASK               (* (reg8 *) VBUS__BIT_MASK)
/* Bypass Enable */
#define VBUS_BYP                    (* (reg8 *) VBUS__BYP)
/* Port wide control signals */                                                   
#define VBUS_CTL                    (* (reg8 *) VBUS__CTL)
/* Drive Modes */
#define VBUS_DM0                    (* (reg8 *) VBUS__DM0) 
#define VBUS_DM1                    (* (reg8 *) VBUS__DM1)
#define VBUS_DM2                    (* (reg8 *) VBUS__DM2) 
/* Input Buffer Disable Override */
#define VBUS_INP_DIS                (* (reg8 *) VBUS__INP_DIS)
/* LCD Common or Segment Drive */
#define VBUS_LCD_COM_SEG            (* (reg8 *) VBUS__LCD_COM_SEG)
/* Enable Segment LCD */
#define VBUS_LCD_EN                 (* (reg8 *) VBUS__LCD_EN)
/* Slew Rate Control */
#define VBUS_SLW                    (* (reg8 *) VBUS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VBUS_PRTDSI__CAPS_SEL       (* (reg8 *) VBUS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VBUS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VBUS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VBUS_PRTDSI__OE_SEL0        (* (reg8 *) VBUS__PRTDSI__OE_SEL0) 
#define VBUS_PRTDSI__OE_SEL1        (* (reg8 *) VBUS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VBUS_PRTDSI__OUT_SEL0       (* (reg8 *) VBUS__PRTDSI__OUT_SEL0) 
#define VBUS_PRTDSI__OUT_SEL1       (* (reg8 *) VBUS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VBUS_PRTDSI__SYNC_OUT       (* (reg8 *) VBUS__PRTDSI__SYNC_OUT) 


#if defined(VBUS__INTSTAT)  /* Interrupt Registers */

    #define VBUS_INTSTAT                (* (reg8 *) VBUS__INTSTAT)
    #define VBUS_SNAP                   (* (reg8 *) VBUS__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VBUS_H */


/* [] END OF FILE */
