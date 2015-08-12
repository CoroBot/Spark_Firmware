/*******************************************************************************
* File Name: TrigSignal.h  
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

#if !defined(CY_PINS_TrigSignal_H) /* Pins TrigSignal_H */
#define CY_PINS_TrigSignal_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TrigSignal_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TrigSignal__PORT == 15 && ((TrigSignal__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    TrigSignal_Write(uint8 value) ;
void    TrigSignal_SetDriveMode(uint8 mode) ;
uint8   TrigSignal_ReadDataReg(void) ;
uint8   TrigSignal_Read(void) ;
uint8   TrigSignal_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TrigSignal_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define TrigSignal_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define TrigSignal_DM_RES_UP          PIN_DM_RES_UP
#define TrigSignal_DM_RES_DWN         PIN_DM_RES_DWN
#define TrigSignal_DM_OD_LO           PIN_DM_OD_LO
#define TrigSignal_DM_OD_HI           PIN_DM_OD_HI
#define TrigSignal_DM_STRONG          PIN_DM_STRONG
#define TrigSignal_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define TrigSignal_MASK               TrigSignal__MASK
#define TrigSignal_SHIFT              TrigSignal__SHIFT
#define TrigSignal_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TrigSignal_PS                     (* (reg8 *) TrigSignal__PS)
/* Data Register */
#define TrigSignal_DR                     (* (reg8 *) TrigSignal__DR)
/* Port Number */
#define TrigSignal_PRT_NUM                (* (reg8 *) TrigSignal__PRT) 
/* Connect to Analog Globals */                                                  
#define TrigSignal_AG                     (* (reg8 *) TrigSignal__AG)                       
/* Analog MUX bux enable */
#define TrigSignal_AMUX                   (* (reg8 *) TrigSignal__AMUX) 
/* Bidirectional Enable */                                                        
#define TrigSignal_BIE                    (* (reg8 *) TrigSignal__BIE)
/* Bit-mask for Aliased Register Access */
#define TrigSignal_BIT_MASK               (* (reg8 *) TrigSignal__BIT_MASK)
/* Bypass Enable */
#define TrigSignal_BYP                    (* (reg8 *) TrigSignal__BYP)
/* Port wide control signals */                                                   
#define TrigSignal_CTL                    (* (reg8 *) TrigSignal__CTL)
/* Drive Modes */
#define TrigSignal_DM0                    (* (reg8 *) TrigSignal__DM0) 
#define TrigSignal_DM1                    (* (reg8 *) TrigSignal__DM1)
#define TrigSignal_DM2                    (* (reg8 *) TrigSignal__DM2) 
/* Input Buffer Disable Override */
#define TrigSignal_INP_DIS                (* (reg8 *) TrigSignal__INP_DIS)
/* LCD Common or Segment Drive */
#define TrigSignal_LCD_COM_SEG            (* (reg8 *) TrigSignal__LCD_COM_SEG)
/* Enable Segment LCD */
#define TrigSignal_LCD_EN                 (* (reg8 *) TrigSignal__LCD_EN)
/* Slew Rate Control */
#define TrigSignal_SLW                    (* (reg8 *) TrigSignal__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TrigSignal_PRTDSI__CAPS_SEL       (* (reg8 *) TrigSignal__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TrigSignal_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TrigSignal__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TrigSignal_PRTDSI__OE_SEL0        (* (reg8 *) TrigSignal__PRTDSI__OE_SEL0) 
#define TrigSignal_PRTDSI__OE_SEL1        (* (reg8 *) TrigSignal__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TrigSignal_PRTDSI__OUT_SEL0       (* (reg8 *) TrigSignal__PRTDSI__OUT_SEL0) 
#define TrigSignal_PRTDSI__OUT_SEL1       (* (reg8 *) TrigSignal__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TrigSignal_PRTDSI__SYNC_OUT       (* (reg8 *) TrigSignal__PRTDSI__SYNC_OUT) 


#if defined(TrigSignal__INTSTAT)  /* Interrupt Registers */

    #define TrigSignal_INTSTAT                (* (reg8 *) TrigSignal__INTSTAT)
    #define TrigSignal_SNAP                   (* (reg8 *) TrigSignal__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TrigSignal_H */


/* [] END OF FILE */
