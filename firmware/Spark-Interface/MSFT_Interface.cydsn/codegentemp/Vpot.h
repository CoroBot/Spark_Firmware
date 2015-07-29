/*******************************************************************************
* File Name: Vpot.h  
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

#if !defined(CY_PINS_Vpot_H) /* Pins Vpot_H */
#define CY_PINS_Vpot_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Vpot_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Vpot__PORT == 15 && ((Vpot__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Vpot_Write(uint8 value) ;
void    Vpot_SetDriveMode(uint8 mode) ;
uint8   Vpot_ReadDataReg(void) ;
uint8   Vpot_Read(void) ;
uint8   Vpot_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Vpot_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Vpot_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Vpot_DM_RES_UP          PIN_DM_RES_UP
#define Vpot_DM_RES_DWN         PIN_DM_RES_DWN
#define Vpot_DM_OD_LO           PIN_DM_OD_LO
#define Vpot_DM_OD_HI           PIN_DM_OD_HI
#define Vpot_DM_STRONG          PIN_DM_STRONG
#define Vpot_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Vpot_MASK               Vpot__MASK
#define Vpot_SHIFT              Vpot__SHIFT
#define Vpot_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vpot_PS                     (* (reg8 *) Vpot__PS)
/* Data Register */
#define Vpot_DR                     (* (reg8 *) Vpot__DR)
/* Port Number */
#define Vpot_PRT_NUM                (* (reg8 *) Vpot__PRT) 
/* Connect to Analog Globals */                                                  
#define Vpot_AG                     (* (reg8 *) Vpot__AG)                       
/* Analog MUX bux enable */
#define Vpot_AMUX                   (* (reg8 *) Vpot__AMUX) 
/* Bidirectional Enable */                                                        
#define Vpot_BIE                    (* (reg8 *) Vpot__BIE)
/* Bit-mask for Aliased Register Access */
#define Vpot_BIT_MASK               (* (reg8 *) Vpot__BIT_MASK)
/* Bypass Enable */
#define Vpot_BYP                    (* (reg8 *) Vpot__BYP)
/* Port wide control signals */                                                   
#define Vpot_CTL                    (* (reg8 *) Vpot__CTL)
/* Drive Modes */
#define Vpot_DM0                    (* (reg8 *) Vpot__DM0) 
#define Vpot_DM1                    (* (reg8 *) Vpot__DM1)
#define Vpot_DM2                    (* (reg8 *) Vpot__DM2) 
/* Input Buffer Disable Override */
#define Vpot_INP_DIS                (* (reg8 *) Vpot__INP_DIS)
/* LCD Common or Segment Drive */
#define Vpot_LCD_COM_SEG            (* (reg8 *) Vpot__LCD_COM_SEG)
/* Enable Segment LCD */
#define Vpot_LCD_EN                 (* (reg8 *) Vpot__LCD_EN)
/* Slew Rate Control */
#define Vpot_SLW                    (* (reg8 *) Vpot__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Vpot_PRTDSI__CAPS_SEL       (* (reg8 *) Vpot__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Vpot_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Vpot__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Vpot_PRTDSI__OE_SEL0        (* (reg8 *) Vpot__PRTDSI__OE_SEL0) 
#define Vpot_PRTDSI__OE_SEL1        (* (reg8 *) Vpot__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Vpot_PRTDSI__OUT_SEL0       (* (reg8 *) Vpot__PRTDSI__OUT_SEL0) 
#define Vpot_PRTDSI__OUT_SEL1       (* (reg8 *) Vpot__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Vpot_PRTDSI__SYNC_OUT       (* (reg8 *) Vpot__PRTDSI__SYNC_OUT) 


#if defined(Vpot__INTSTAT)  /* Interrupt Registers */

    #define Vpot_INTSTAT                (* (reg8 *) Vpot__INTSTAT)
    #define Vpot_SNAP                   (* (reg8 *) Vpot__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Vpot_H */


/* [] END OF FILE */
