/*******************************************************************************
* File Name: LedScanningStatus.h  
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

#if !defined(CY_PINS_LedScanningStatus_ALIASES_H) /* Pins LedScanningStatus_ALIASES_H */
#define CY_PINS_LedScanningStatus_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LedScanningStatus_0			(LedScanningStatus__0__PC)
#define LedScanningStatus_0_PS		(LedScanningStatus__0__PS)
#define LedScanningStatus_0_PC		(LedScanningStatus__0__PC)
#define LedScanningStatus_0_DR		(LedScanningStatus__0__DR)
#define LedScanningStatus_0_SHIFT	(LedScanningStatus__0__SHIFT)
#define LedScanningStatus_0_INTR	((uint16)((uint16)0x0003u << (LedScanningStatus__0__SHIFT*2u)))

#define LedScanningStatus_INTR_ALL	 ((uint16)(LedScanningStatus_0_INTR))


#endif /* End Pins LedScanningStatus_ALIASES_H */


/* [] END OF FILE */
