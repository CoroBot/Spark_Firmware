/*******************************************************************************
* File Name: EchoSignal.h  
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

#if !defined(CY_PINS_EchoSignal_H) /* Pins EchoSignal_H */
#define CY_PINS_EchoSignal_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EchoSignal_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EchoSignal__PORT == 15 && ((EchoSignal__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EchoSignal_Write(uint8 value) ;
void    EchoSignal_SetDriveMode(uint8 mode) ;
uint8   EchoSignal_ReadDataReg(void) ;
uint8   EchoSignal_Read(void) ;
uint8   EchoSignal_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EchoSignal_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EchoSignal_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EchoSignal_DM_RES_UP          PIN_DM_RES_UP
#define EchoSignal_DM_RES_DWN         PIN_DM_RES_DWN
#define EchoSignal_DM_OD_LO           PIN_DM_OD_LO
#define EchoSignal_DM_OD_HI           PIN_DM_OD_HI
#define EchoSignal_DM_STRONG          PIN_DM_STRONG
#define EchoSignal_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EchoSignal_MASK               EchoSignal__MASK
#define EchoSignal_SHIFT              EchoSignal__SHIFT
#define EchoSignal_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EchoSignal_PS                     (* (reg8 *) EchoSignal__PS)
/* Data Register */
#define EchoSignal_DR                     (* (reg8 *) EchoSignal__DR)
/* Port Number */
#define EchoSignal_PRT_NUM                (* (reg8 *) EchoSignal__PRT) 
/* Connect to Analog Globals */                                                  
#define EchoSignal_AG                     (* (reg8 *) EchoSignal__AG)                       
/* Analog MUX bux enable */
#define EchoSignal_AMUX                   (* (reg8 *) EchoSignal__AMUX) 
/* Bidirectional Enable */                                                        
#define EchoSignal_BIE                    (* (reg8 *) EchoSignal__BIE)
/* Bit-mask for Aliased Register Access */
#define EchoSignal_BIT_MASK               (* (reg8 *) EchoSignal__BIT_MASK)
/* Bypass Enable */
#define EchoSignal_BYP                    (* (reg8 *) EchoSignal__BYP)
/* Port wide control signals */                                                   
#define EchoSignal_CTL                    (* (reg8 *) EchoSignal__CTL)
/* Drive Modes */
#define EchoSignal_DM0                    (* (reg8 *) EchoSignal__DM0) 
#define EchoSignal_DM1                    (* (reg8 *) EchoSignal__DM1)
#define EchoSignal_DM2                    (* (reg8 *) EchoSignal__DM2) 
/* Input Buffer Disable Override */
#define EchoSignal_INP_DIS                (* (reg8 *) EchoSignal__INP_DIS)
/* LCD Common or Segment Drive */
#define EchoSignal_LCD_COM_SEG            (* (reg8 *) EchoSignal__LCD_COM_SEG)
/* Enable Segment LCD */
#define EchoSignal_LCD_EN                 (* (reg8 *) EchoSignal__LCD_EN)
/* Slew Rate Control */
#define EchoSignal_SLW                    (* (reg8 *) EchoSignal__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EchoSignal_PRTDSI__CAPS_SEL       (* (reg8 *) EchoSignal__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EchoSignal_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EchoSignal__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EchoSignal_PRTDSI__OE_SEL0        (* (reg8 *) EchoSignal__PRTDSI__OE_SEL0) 
#define EchoSignal_PRTDSI__OE_SEL1        (* (reg8 *) EchoSignal__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EchoSignal_PRTDSI__OUT_SEL0       (* (reg8 *) EchoSignal__PRTDSI__OUT_SEL0) 
#define EchoSignal_PRTDSI__OUT_SEL1       (* (reg8 *) EchoSignal__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EchoSignal_PRTDSI__SYNC_OUT       (* (reg8 *) EchoSignal__PRTDSI__SYNC_OUT) 


#if defined(EchoSignal__INTSTAT)  /* Interrupt Registers */

    #define EchoSignal_INTSTAT                (* (reg8 *) EchoSignal__INTSTAT)
    #define EchoSignal_SNAP                   (* (reg8 *) EchoSignal__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EchoSignal_H */


/* [] END OF FILE */
