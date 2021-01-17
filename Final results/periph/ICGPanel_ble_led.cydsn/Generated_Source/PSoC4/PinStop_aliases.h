/*******************************************************************************
* File Name: PinStop.h  
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

#if !defined(CY_PINS_PinStop_ALIASES_H) /* Pins PinStop_ALIASES_H */
#define CY_PINS_PinStop_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PinStop_0			(PinStop__0__PC)
#define PinStop_0_PS		(PinStop__0__PS)
#define PinStop_0_PC		(PinStop__0__PC)
#define PinStop_0_DR		(PinStop__0__DR)
#define PinStop_0_SHIFT	(PinStop__0__SHIFT)
#define PinStop_0_INTR	((uint16)((uint16)0x0003u << (PinStop__0__SHIFT*2u)))

#define PinStop_INTR_ALL	 ((uint16)(PinStop_0_INTR))


#endif /* End Pins PinStop_ALIASES_H */


/* [] END OF FILE */
