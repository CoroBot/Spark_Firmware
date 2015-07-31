/*******************************************************************************
* File Name: SRVO1.h  
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

#if !defined(CY_PINS_SRVO1_H) /* Pins SRVO1_H */
#define CY_PINS_SRVO1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SRVO1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SRVO1__PORT == 15 && ((SRVO1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SRVO1_Write(uint8 value) ;
void    SRVO1_SetDriveMode(uint8 mode) ;
uint8   SRVO1_ReadDataReg(void) ;
uint8   SRVO1_Read(void) ;
uint8   SRVO1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SRVO1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SRVO1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SRVO1_DM_RES_UP          PIN_DM_RES_UP
#define SRVO1_DM_RES_DWN         PIN_DM_RES_DWN
#define SRVO1_DM_OD_LO           PIN_DM_OD_LO
#define SRVO1_DM_OD_HI           PIN_DM_OD_HI
#define SRVO1_DM_STRONG          PIN_DM_STRONG
#define SRVO1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SRVO1_MASK               SRVO1__MASK
#define SRVO1_SHIFT              SRVO1__SHIFT
#define SRVO1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SRVO1_PS                     (* (reg8 *) SRVO1__PS)
/* Data Register */
#define SRVO1_DR                     (* (reg8 *) SRVO1__DR)
/* Port Number */
#define SRVO1_PRT_NUM                (* (reg8 *) SRVO1__PRT) 
/* Connect to Analog Globals */                                                  
#define SRVO1_AG                     (* (reg8 *) SRVO1__AG)                       
/* Analog MUX bux enable */
#define SRVO1_AMUX                   (* (reg8 *) SRVO1__AMUX) 
/* Bidirectional Enable */                                                        
#define SRVO1_BIE                    (* (reg8 *) SRVO1__BIE)
/* Bit-mask for Aliased Register Access */
#define SRVO1_BIT_MASK               (* (reg8 *) SRVO1__BIT_MASK)
/* Bypass Enable */
#define SRVO1_BYP                    (* (reg8 *) SRVO1__BYP)
/* Port wide control signals */                                                   
#define SRVO1_CTL                    (* (reg8 *) SRVO1__CTL)
/* Drive Modes */
#define SRVO1_DM0                    (* (reg8 *) SRVO1__DM0) 
#define SRVO1_DM1                    (* (reg8 *) SRVO1__DM1)
#define SRVO1_DM2                    (* (reg8 *) SRVO1__DM2) 
/* Input Buffer Disable Override */
#define SRVO1_INP_DIS                (* (reg8 *) SRVO1__INP_DIS)
/* LCD Common or Segment Drive */
#define SRVO1_LCD_COM_SEG            (* (reg8 *) SRVO1__LCD_COM_SEG)
/* Enable Segment LCD */
#define SRVO1_LCD_EN                 (* (reg8 *) SRVO1__LCD_EN)
/* Slew Rate Control */
#define SRVO1_SLW                    (* (reg8 *) SRVO1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SRVO1_PRTDSI__CAPS_SEL       (* (reg8 *) SRVO1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SRVO1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SRVO1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SRVO1_PRTDSI__OE_SEL0        (* (reg8 *) SRVO1__PRTDSI__OE_SEL0) 
#define SRVO1_PRTDSI__OE_SEL1        (* (reg8 *) SRVO1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SRVO1_PRTDSI__OUT_SEL0       (* (reg8 *) SRVO1__PRTDSI__OUT_SEL0) 
#define SRVO1_PRTDSI__OUT_SEL1       (* (reg8 *) SRVO1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SRVO1_PRTDSI__SYNC_OUT       (* (reg8 *) SRVO1__PRTDSI__SYNC_OUT) 


#if defined(SRVO1__INTSTAT)  /* Interrupt Registers */

    #define SRVO1_INTSTAT                (* (reg8 *) SRVO1__INTSTAT)
    #define SRVO1_SNAP                   (* (reg8 *) SRVO1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SRVO1_H */


/* [] END OF FILE */
