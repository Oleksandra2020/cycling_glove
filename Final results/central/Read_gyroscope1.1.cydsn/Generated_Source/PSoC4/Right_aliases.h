/*******************************************************************************
* File Name: Right.h  
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

#if !defined(CY_PINS_Right_ALIASES_H) /* Pins Right_ALIASES_H */
#define CY_PINS_Right_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Right_0			(Right__0__PC)
#define Right_0_PS		(Right__0__PS)
#define Right_0_PC		(Right__0__PC)
#define Right_0_DR		(Right__0__DR)
#define Right_0_SHIFT	(Right__0__SHIFT)
#define Right_0_INTR	((uint16)((uint16)0x0003u << (Right__0__SHIFT*2u)))

#define Right_INTR_ALL	 ((uint16)(Right_0_INTR))


#endif /* End Pins Right_ALIASES_H */


/* [] END OF FILE */
