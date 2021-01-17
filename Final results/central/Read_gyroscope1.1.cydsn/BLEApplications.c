/******************************************************************************
* Project Name		: PSoC_4_BLE_Central_IAS
* File Name			: BLEApplications.c
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
#include <main.h>
/* 'connHandle' contains the connection handle parameter and is used for BLE API 
* to send data to particular connected device */
extern CYBLE_CONN_HANDLE_T			connHandle;

/* 'ble_state' contains the present status of BLE, used for LED state update */
extern uint8 ble_state;

/* 'iasLevel' contains the alert level that is sent to the connected peripheral 
* device */
uint8 iasLevel = 0;

/*******************************************************************************
* Function Name: CheckButtonStatus
********************************************************************************
* Summary:
*        This function checks the press of the User button on BLE Pioneer Kit, 
* applies proper debounce and then initiates sending of the Alert notification.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void CheckButtonStatus(void)
{
	static uint8 switchDebounceTimer;
	
	static uint8 buttonStatus = FALSE;
	
	if(User_Button_Read() == FALSE)
    {
        /* Register the button press for the first time and check if button debouncing is completed */
        if(!(buttonStatus & (USER_BUTTON_PUSHED_MASK | USER_BUTTON_DETECTED_MASK)))
        {
           
            /* If button press not registered, register the User button press event*/
            buttonStatus = buttonStatus | USER_BUTTON_PUSHED_MASK;
            
            /* Initiate a debounce counter */
            switchDebounceTimer = SWITCH_DEBOUNCE_DELAY;
        }
        else if( (buttonStatus & USER_BUTTON_PUSHED_MASK) && (switchDebounceTimer == 0) )
        {
            /* If debounce counter has elapsed, then register a button press detect event */
            buttonStatus = buttonStatus & (~USER_BUTTON_PUSHED_MASK);
            buttonStatus = buttonStatus | USER_BUTTON_DETECTED_MASK;
        }
    }
    else
    {
        if((buttonStatus & USER_BUTTON_DETECTED_MASK))
        {
            /* Increment the Alert level, which will then be sent to peripheral. Limit the value till 0x02 */
			iasLevel = (iasLevel+1)%4;
            
			/* Send the updated Alert level to Peripheral over Immediate Alert Service*/
			WriteCharacteristicValue(&iasLevel);
			
            buttonStatus = buttonStatus & ( ~(USER_BUTTON_DETECTED_MASK) );
        }
        /* If button press is not detected and the switch debounce timer has expired, clear the button press status
         * in the ButtonStatus register */
        else if((buttonStatus & USER_BUTTON_PUSHED_MASK) && switchDebounceTimer == 0)
        {
             buttonStatus = buttonStatus & (~USER_BUTTON_PUSHED_MASK);
        }
    }
	
	if(switchDebounceTimer)
	{
		switchDebounceTimer--;	
	}
}

/*******************************************************************************
* Function Name: HandleLEDs
********************************************************************************
* Summary:
*        This function handles the LED on the BLE Pioneer kit that signifies the 
* state of the BLE connection.
*
* Parameters:
*  uint8 state: the state of connection.
*
* Return:
*  void
*
*******************************************************************************/
void ShowConnectingStatus(uint8 state)
{
	switch(state)
	{
		case BLE_DISCONNECTED:
			/* Set LED to OFF for Disconnected state*/
            LedScanningStatus_Write(LED_OFF);
			LedServiceDiscoveryStatus_Write(LED_OFF);
			LedConnectedStatus_Write(LED_OFF);
		break;
		
		case BLE_SCANNING:
            LedScanningStatus_Write(LED_ON);
			LedServiceDiscoveryStatus_Write(LED_OFF);
			LedConnectedStatus_Write(LED_OFF);
		break;
			
		case BLE_SERVICE_DISCOVERY:
            LedScanningStatus_Write(LED_OFF);
			LedServiceDiscoveryStatus_Write(LED_ON);
			LedConnectedStatus_Write(LED_OFF);
		break;
		
		case BLE_CONNECTED:
            LedScanningStatus_Write(LED_OFF);
			LedServiceDiscoveryStatus_Write(LED_OFF);
			LedConnectedStatus_Write(LED_ON);
		break;
		
		default:
		
		break;
	}
}

/*******************************************************************************
* Function Name: SetAlertLevel
********************************************************************************
* Summary:
*        This function sends the appropriate Alert level to peripheral device.
*
* Parameters:
*  uint8* alertLevel: address of the variable containing the present state of BLE
*				connection
*
* Return:
*  void
*
*******************************************************************************/
void WriteCharacteristicValue(uint8* alertLevel)
{
	CYBLE_GATTC_WRITE_CMD_REQ_T wrCmdReq;
    wrCmdReq.value.val = alertLevel;
    wrCmdReq.value.len = BIKE_STATUS_ATTR_SIZE;
    wrCmdReq.attrHandle = cyBle_customCServ[0].customServChar[0].customServCharHandle;

    CYBLE_API_RESULT_T apiResult;
    apiResult = CyBle_GattcWriteCharacteristicValue(connHandle, &wrCmdReq);
    
	if(apiResult != CYBLE_ERROR_OK)
	{
		
	}
}

/* [] END OF FILE */
