/*******************************************************************************
* File Name: PinLeft.h  
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

#if !defined(CY_PINS_PinLeft_ALIASES_H) /* Pins PinLeft_ALIASES_H */
#define CY_PINS_PinLeft_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PinLeft_0			(PinLeft__0__PC)
#define PinLeft_0_PS		(PinLeft__0__PS)
#define PinLeft_0_PC		(PinLeft__0__PC)
#define PinLeft_0_DR		(PinLeft__0__DR)
#define PinLeft_0_SHIFT	(PinLeft__0__SHIFT)
#define PinLeft_0_INTR	((uint16)((uint16)0x0003u << (PinLeft__0__SHIFT*2u)))

#define PinLeft_INTR_ALL	 ((uint16)(PinLeft_0_INTR))


#endif /* End Pins PinLeft_ALIASES_H */


/* [] END OF FILE */
