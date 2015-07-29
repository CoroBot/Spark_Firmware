/*******************************************************************************
* File Name: nRE.h  
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

#if !defined(CY_PINS_nRE_H) /* Pins nRE_H */
#define CY_PINS_nRE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "nRE_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 nRE__PORT == 15 && ((nRE__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    nRE_Write(uint8 value) ;
void    nRE_SetDriveMode(uint8 mode) ;
uint8   nRE_ReadDataReg(void) ;
uint8   nRE_Read(void) ;
uint8   nRE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define nRE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define nRE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define nRE_DM_RES_UP          PIN_DM_RES_UP
#define nRE_DM_RES_DWN         PIN_DM_RES_DWN
#define nRE_DM_OD_LO           PIN_DM_OD_LO
#define nRE_DM_OD_HI           PIN_DM_OD_HI
#define nRE_DM_STRONG          PIN_DM_STRONG
#define nRE_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define nRE_MASK               nRE__MASK
#define nRE_SHIFT              nRE__SHIFT
#define nRE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define nRE_PS                     (* (reg8 *) nRE__PS)
/* Data Register */
#define nRE_DR                     (* (reg8 *) nRE__DR)
/* Port Number */
#define nRE_PRT_NUM                (* (reg8 *) nRE__PRT) 
/* Connect to Analog Globals */                                                  
#define nRE_AG                     (* (reg8 *) nRE__AG)                       
/* Analog MUX bux enable */
#define nRE_AMUX                   (* (reg8 *) nRE__AMUX) 
/* Bidirectional Enable */                                                        
#define nRE_BIE                    (* (reg8 *) nRE__BIE)
/* Bit-mask for Aliased Register Access */
#define nRE_BIT_MASK               (* (reg8 *) nRE__BIT_MASK)
/* Bypass Enable */
#define nRE_BYP                    (* (reg8 *) nRE__BYP)
/* Port wide control signals */                                                   
#define nRE_CTL                    (* (reg8 *) nRE__CTL)
/* Drive Modes */
#define nRE_DM0                    (* (reg8 *) nRE__DM0) 
#define nRE_DM1                    (* (reg8 *) nRE__DM1)
#define nRE_DM2                    (* (reg8 *) nRE__DM2) 
/* Input Buffer Disable Override */
#define nRE_INP_DIS                (* (reg8 *) nRE__INP_DIS)
/* LCD Common or Segment Drive */
#define nRE_LCD_COM_SEG            (* (reg8 *) nRE__LCD_COM_SEG)
/* Enable Segment LCD */
#define nRE_LCD_EN                 (* (reg8 *) nRE__LCD_EN)
/* Slew Rate Control */
#define nRE_SLW                    (* (reg8 *) nRE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define nRE_PRTDSI__CAPS_SEL       (* (reg8 *) nRE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define nRE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) nRE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define nRE_PRTDSI__OE_SEL0        (* (reg8 *) nRE__PRTDSI__OE_SEL0) 
#define nRE_PRTDSI__OE_SEL1        (* (reg8 *) nRE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define nRE_PRTDSI__OUT_SEL0       (* (reg8 *) nRE__PRTDSI__OUT_SEL0) 
#define nRE_PRTDSI__OUT_SEL1       (* (reg8 *) nRE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define nRE_PRTDSI__SYNC_OUT       (* (reg8 *) nRE__PRTDSI__SYNC_OUT) 


#if defined(nRE__INTSTAT)  /* Interrupt Registers */

    #define nRE_INTSTAT                (* (reg8 *) nRE__INTSTAT)
    #define nRE_SNAP                   (* (reg8 *) nRE__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_nRE_H */


/* [] END OF FILE */
