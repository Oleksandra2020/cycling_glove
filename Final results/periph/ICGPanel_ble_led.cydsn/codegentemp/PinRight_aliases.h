/*******************************************************************************
* File Name: PinRight.h  
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

#if !defined(CY_PINS_PinRight_ALIASES_H) /* Pins PinRight_ALIASES_H */
#define CY_PINS_PinRight_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PinRight_0			(PinRight__0__PC)
#define PinRight_0_PS		(PinRight__0__PS)
#define PinRight_0_PC		(PinRight__0__PC)
#define PinRight_0_DR		(PinRight__0__DR)
#define PinRight_0_SHIFT	(PinRight__0__SHIFT)
#define PinRight_0_INTR	((uint16)((uint16)0x0003u << (PinRight__0__SHIFT*2u)))

#define PinRight_INTR_ALL	 ((uint16)(PinRight_0_INTR))


#endif /* End Pins PinRight_ALIASES_H */


/* [] END OF FILE */
