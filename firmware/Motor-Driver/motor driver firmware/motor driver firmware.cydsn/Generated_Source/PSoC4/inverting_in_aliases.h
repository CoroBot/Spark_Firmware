/*******************************************************************************
* File Name: inverting_in.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_inverting_in_ALIASES_H) /* Pins inverting_in_ALIASES_H */
#define CY_PINS_inverting_in_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define inverting_in_0			(inverting_in__0__PC)
#define inverting_in_0_PS		(inverting_in__0__PS)
#define inverting_in_0_PC		(inverting_in__0__PC)
#define inverting_in_0_DR		(inverting_in__0__DR)
#define inverting_in_0_SHIFT	(inverting_in__0__SHIFT)
#define inverting_in_0_INTR	((uint16)((uint16)0x0003u << (inverting_in__0__SHIFT*2u)))

#define inverting_in_INTR_ALL	 ((uint16)(inverting_in_0_INTR))


#endif /* End Pins inverting_in_ALIASES_H */


/* [] END OF FILE */
