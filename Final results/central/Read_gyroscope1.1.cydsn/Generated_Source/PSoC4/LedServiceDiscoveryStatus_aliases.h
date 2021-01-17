/*******************************************************************************
* File Name: LedServiceDiscoveryStatus.h  
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

#if !defined(CY_PINS_LedServiceDiscoveryStatus_ALIASES_H) /* Pins LedServiceDiscoveryStatus_ALIASES_H */
#define CY_PINS_LedServiceDiscoveryStatus_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LedServiceDiscoveryStatus_0			(LedServiceDiscoveryStatus__0__PC)
#define LedServiceDiscoveryStatus_0_PS		(LedServiceDiscoveryStatus__0__PS)
#define LedServiceDiscoveryStatus_0_PC		(LedServiceDiscoveryStatus__0__PC)
#define LedServiceDiscoveryStatus_0_DR		(LedServiceDiscoveryStatus__0__DR)
#define LedServiceDiscoveryStatus_0_SHIFT	(LedServiceDiscoveryStatus__0__SHIFT)
#define LedServiceDiscoveryStatus_0_INTR	((uint16)((uint16)0x0003u << (LedServiceDiscoveryStatus__0__SHIFT*2u)))

#define LedServiceDiscoveryStatus_INTR_ALL	 ((uint16)(LedServiceDiscoveryStatus_0_INTR))


#endif /* End Pins LedServiceDiscoveryStatus_ALIASES_H */


/* [] END OF FILE */
