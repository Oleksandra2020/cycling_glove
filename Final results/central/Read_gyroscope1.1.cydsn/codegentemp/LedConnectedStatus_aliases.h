/*******************************************************************************
* File Name: LedConnectedStatus.h  
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

#if !defined(CY_PINS_LedConnectedStatus_ALIASES_H) /* Pins LedConnectedStatus_ALIASES_H */
#define CY_PINS_LedConnectedStatus_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LedConnectedStatus_0			(LedConnectedStatus__0__PC)
#define LedConnectedStatus_0_PS		(LedConnectedStatus__0__PS)
#define LedConnectedStatus_0_PC		(LedConnectedStatus__0__PC)
#define LedConnectedStatus_0_DR		(LedConnectedStatus__0__DR)
#define LedConnectedStatus_0_SHIFT	(LedConnectedStatus__0__SHIFT)
#define LedConnectedStatus_0_INTR	((uint16)((uint16)0x0003u << (LedConnectedStatus__0__SHIFT*2u)))

#define LedConnectedStatus_INTR_ALL	 ((uint16)(LedConnectedStatus_0_INTR))


#endif /* End Pins LedConnectedStatus_ALIASES_H */


/* [] END OF FILE */
