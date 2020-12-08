/******************************************************************************
* Project Name		: PSoC_4_BLE_Central_IAS
* File Name			: BLEApplications.h
* Version 			: 1.0
* Device Used		: CY8C4248LQI-BL583
* Software Used		: PSoC Creator 4.2
* Compiler    		: ARM GCC 5.4.1
* Related Hardware	: CY8CKIT-042-BLE-A Bluetooth Low Energy Pioneer Kit
******************************************************************************
* Copyright (2018), Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* (“Software”), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries (“Cypress”) and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software (“EULA”).
*
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress 
* reserves the right to make changes to the Software without notice. Cypress 
* does not assume any liability arising out of the application or use of the 
* Software or any product or circuit described in the Software. Cypress does 
* not authorize its products for use in any products where a malfunction or 
* failure of the Cypress product may reasonably be expected to result in 
* significant property damage, injury or death (“High Risk Product”). By 
* including Cypress’s product in a High Risk Product, the manufacturer of such 
* system or application assumes all risk of such use and in doing so agrees to 
* indemnify Cypress against all liability.
*******************************************************************************/

/********************************************************************************
* Contains all macros and function declarations used in the BLEApplications.c file 
********************************************************************************/
#if !defined (BLEAPPLICATIONS_H)
#define BLEAPPLICATIONS_H
#include <project.h>

/*************************Pre-processor directives****************************/
/* 'ENABLE_LOW_POWER_MODE' pre-processor directive enables the low power mode 
* handling in the firmware, ensuring low power consumption during project usage.
* To disable, comment the following #define. 
* If disabled, prevent usage of the project with coin cell */
#define ENABLE_LOW_POWER_MODE
/****************************************************************************/
	
/* BLE State Macros used for LED status updates*/
#define BLE_DISCONNECTED				0x01
#define BLE_SCANNING					0x02
#define BLE_SERVICE_DISCOVERY			0x03
#define BLE_CONNECTED					0x04

/* Size of IAS Data */
#define BIKE_STATUS_ATTR_SIZE			0x01

/* LED State Macros*/
#define LED_OFF							0x01
#define LED_ON							0x00
	
/* User button related Macros for Debouncing and Detection*/
#define USER_BUTTON_PUSHED_MASK			0x01
#define	USER_BUTTON_DETECTED_MASK		0x02
#define SWITCH_DEBOUNCE_DELAY			4

/**************************Function Declarations*****************************/
void CheckButtonStatus(void);
void ShowConnectingStatus(uint8 state);
void WriteCharacteristicValue(uint8* alertLevel);
/****************************************************************************/

#endif
/* [] END OF FILE */
