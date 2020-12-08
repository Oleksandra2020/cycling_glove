/******************************************************************************
* Project Name		: PSoC_4_BLE_Central_IAS
* File Name			: BLEclient.c
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

/* 'list_of_devices' is an array of type 'CYBLE_GAPC_ADV_REPORT_T' (defined in 
 * BLE_StackGap.h) that is used to store the reports of the peripheral devices
* being scanned by this Central device*/
CYBLE_GAPC_ADV_REPORT_T 	list_of_devices[CYBLE_MAX_ADV_DEVICES];

/* 'connectPeriphDevice' is a variable of type 'CYBLE_GAP_BD_ADDR_T' (defined in 
* BLE_StackGap.h) and is used to store address of the connected device. */
CYBLE_GAP_BD_ADDR_T 		connectPeriphDevice;

/* 'connHandle' is a variable of type 'CYBLE_CONN_HANDLE_T' (defined in 
* BLE_StackGatt.h) and is used to store the connection handle parameters after
* connecting with the peripheral device. */
CYBLE_CONN_HANDLE_T			connHandle;

/* 'deviceConnected' flag tells the status of connection with BLE peripheral Device */
uint8 deviceConnected = FALSE;

/* 'ble_state' stores the state of connection which is used for updating LEDs */
uint8 ble_state = BLE_DISCONNECTED;

/* 'address_store' stores the addresses returned by Scanning results */
uint8 address_store[CYBLE_MAX_ADV_DEVICES][6];

/* 'peripheralAddress' stores the addresses of device presently connected to */
uint8 peripheralAddress[6];

/* 'peripheralFound' flag tells whether the peripheral device with the required Address
 * has been found during scanning or not. */
uint8 peripheralFound = FALSE;

/* 'addedDevices' tells the number of devices that have been added to the list till now. */
uint8 addedDevices = FALSE;

/* 'iasLevel' stores the current alert level as set by Central device */
extern uint8 iasLevel;

/* 'restartScanning' flag indicates to application whether starting scan API has to be
* called or not */
uint8 restartScanning = FALSE;

/*******************************************************************************
* Function Name: ApplicationEventHandler
********************************************************************************
* Summary:
*        Call back event function to handle various events from BLE stack
*
* Parameters:
*  uint32 event:		event returned
*  void *eventparam:	link to value of the event parameter returned
*
* Return:
*  void
*
*******************************************************************************/
void ApplicationEventHandler(uint32 event, void *eventparam)
{
	/* 'apiResult' is a variable of type 'CYBLE_API_RESULT_T' (defined in 
	* BLE_StackTypes.h) and is used to store the return value from BLE APIs. */
	CYBLE_API_RESULT_T 			apiResult;
	
	/* 'scan_report' is a variable of type 'CYBLE_GAPC_ADV_REPORT_T' (defined in 
	* BLE_StackGap.h) and is used to store report returned from Scan results. */
	CYBLE_GAPC_ADV_REPORT_T		scan_report;
	
	/* Local variable for Loop */
	uint16 i = FALSE;
	
	switch(event)
	{
		case CYBLE_EVT_STACK_ON:
			
			/* Set start scanning flag to allow calling the API in main loop */
			restartScanning = TRUE;
		break;
			
		case CYBLE_EVT_GAPC_SCAN_START_STOP:
			/* Add relevant code here pertaining to Starting/Stopping of Scan*/
			if(CyBle_GetState() == CYBLE_STATE_DISCONNECTED)
			{
				ble_state = BLE_DISCONNECTED;
				
				if(!peripheralFound)
				{
					/* Restart Scanning */
					ShowConnectingStatus(BLE_DISCONNECTED);
					restartScanning = TRUE;
				}
			}
			else
			{
				ble_state = BLE_SCANNING;
			}
		break;
			
		case CYBLE_EVT_GAPC_SCAN_PROGRESS_RESULT:
			/* This event is generated whenever there is a device found*/
			if(CYBLE_STATE_CONNECTED != CyBle_GetState())	
			{
				/* If we are not connected to any peripheral device, then save the new device  
					information so to add it to our list */
				scan_report = *(CYBLE_GAPC_ADV_REPORT_T*) eventparam;
				
				/* Add the new device to existing list if not done yet, and compare the address with our
					required address.*/
				HandleScanDevices(&scan_report);
			}
			/* Update the LED status for BLE scanning mode*/
			ble_state = BLE_SCANNING;
		break;
			
 		case CYBLE_EVT_GATT_CONNECT_IND:

			/* When the peripheral device is connected, store the connection handle.*/
            connHandle = *(CYBLE_CONN_HANDLE_T *)eventparam;
            break;
			
		case CYBLE_EVT_GATT_DISCONNECT_IND:
			/* When the peripheral device is disconnected, reset variables*/
			
			break;
			
		case CYBLE_EVT_GAP_DEVICE_CONNECTED:
			
			/* The Device is connected now. Start Attributes discovery process.*/
			apiResult = CyBle_GattcStartDiscovery(connHandle);
			
			if(apiResult != CYBLE_ERROR_OK)
			{

			}
			
			/* Update the LED status for BLE discovery mode*/
			ble_state = BLE_SERVICE_DISCOVERY;
        break;
			
		case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
			/* Reset all saved peripheral Addresses */
			for(i=0;i<addedDevices;i++)
			{
				list_of_devices[i].peerBdAddr[0] = FALSE;
				list_of_devices[i].peerBdAddr[1] = FALSE;
				list_of_devices[i].peerBdAddr[2] = FALSE;
				list_of_devices[i].peerBdAddr[3] = FALSE;
				list_of_devices[i].peerBdAddr[4] = FALSE;
				list_of_devices[i].peerBdAddr[5] = FALSE;
			}
			
			/* Reset application Flags on BLE Disconnect */
			addedDevices = FALSE;
			peripheralFound = FALSE;
			deviceConnected = FALSE;
			iasLevel = FALSE;
			ble_state = BLE_DISCONNECTED;
			
			/* Set the flag for rescanning after wakeup */
			restartScanning = TRUE;
			
			/* Update LED Status for Disconnection */
			ShowConnectingStatus(ble_state);
			if(apiResult != CYBLE_ERROR_OK)
			{
			}
			break;
			
	
		case CYBLE_EVT_GATTC_DISCOVERY_COMPLETE:
			/* This event is generated whenever the discovery procedure is complete*/
			
			/*Set the Device connected flag*/
			deviceConnected = TRUE;
			
			/* Update the LED status for BLE discovery mode*/
			ble_state = BLE_CONNECTED;
		break;
			
		default:
			
		break;
	}
}
/*******************************************************************************
* Function Name: HandleScanDevices
********************************************************************************
* Summary:
*        This function checks for new devices that have been scanned and adds them
* to its internal list. Also, if one of the scanned peripherals is a CySmart
* USB Dongle, then it sets flag to allow connection with it.
*
* Parameters:
*  CYBLE_GAPC_ADV_REPORT_T* scanReport:	parameter of type CYBLE_GAPC_ADV_REPORT_T* returned
* 										by BLE event CYBLE_EVT_GAPC_SCAN_PROGRESS_RESULT.
*
* Return:
*  void
*
*******************************************************************************/
void HandleScanDevices(CYBLE_GAPC_ADV_REPORT_T* scanReport)
{
	uint16 i;
	uint8 newDevice = TRUE;
	
	if((addedDevices < CYBLE_MAX_ADV_DEVICES))
	{
		for(i = 0; i < addedDevices; i++)
		{
			/* Initialize the peerBdAddr element of our list.*/
			list_of_devices[i].peerBdAddr = &address_store[i][0];
			
			/* In this for loop, compare the new device address with the existing addresses in the list to 
				determine if the address is new or not. If the address exists in the list, then the device 
				is not new.*/
			if(FALSE == memcmp(list_of_devices[i].peerBdAddr, scanReport->peerBdAddr, ADV_ADDR_LEN))
			{
				newDevice = FALSE;
				break;
			}
		}
		
		if(newDevice)
		{
			/* If the device address is new, then add the device to our existing list and compare the address
				with our expected address to see if the desired peripheral is advertising or not.*/
			
			list_of_devices[addedDevices].peerBdAddr = &address_store[addedDevices][0];
			
			/* Store the data*/
			list_of_devices[addedDevices].dataLen = scanReport->dataLen;
			
			list_of_devices[addedDevices].data = scanReport->data;
			
			list_of_devices[addedDevices].eventType = scanReport->eventType;
			/* Record the address type, Public or Random, of the advertising peripheral.*/
			list_of_devices[addedDevices].peerAddrType = scanReport->peerAddrType;
			
			/* Save the BD addresses */
			list_of_devices[addedDevices].peerBdAddr[0] = scanReport->peerBdAddr[0];
			list_of_devices[addedDevices].peerBdAddr[1] = scanReport->peerBdAddr[1];
			list_of_devices[addedDevices].peerBdAddr[2] = scanReport->peerBdAddr[2];
			list_of_devices[addedDevices].peerBdAddr[3] = scanReport->peerBdAddr[3];
			list_of_devices[addedDevices].peerBdAddr[4] = scanReport->peerBdAddr[4];
			list_of_devices[addedDevices].peerBdAddr[5] = scanReport->peerBdAddr[5];
			
			list_of_devices[addedDevices].rssi = scanReport->rssi;
			
			/* If the new BD address found matches the desired BD address, the Dongle has been found*/
			if(FALSE == memcmp(peripheralAddress, scanReport->peerBdAddr, ADV_ADDR_LEN))
			{
				/* Save the connected device BD Address and Type*/
				connectPeriphDevice.bdAddr[0] = scanReport->peerBdAddr[0];
				connectPeriphDevice.bdAddr[1] = scanReport->peerBdAddr[1];
				connectPeriphDevice.bdAddr[2] = scanReport->peerBdAddr[2];
				connectPeriphDevice.bdAddr[3] = scanReport->peerBdAddr[3];
				connectPeriphDevice.bdAddr[4] = scanReport->peerBdAddr[4];
				connectPeriphDevice.bdAddr[5] = scanReport->peerBdAddr[5];
				
				connectPeriphDevice.type = list_of_devices[addedDevices].peerAddrType;
					
				/* Set the flag to notify application of a connected peripheral device */
				peripheralFound = TRUE;	
				
				/* Stop existing BLE Scan */
				CyBle_GapcStopScan();
			}
			
			addedDevices++;
		}
		
		newDevice = TRUE;
	}
}


/*******************************************************************************
* Function Name: LoadPeripheralDeviceData
********************************************************************************
* Summary:
*        This function stores the address of the peripheral device to which this
* Central device wishes to connect. 
*
* Parameters:
*  void
*
* Return:
*  void
*

*******************************************************************************/
void LoadPeripheralDeviceData(void)
{
	/* This stores the 6-byte BD address of peripheral device to which we have to connect.
	   In this project, we have peripheral (CySmart USB Dongle) with BD Address 0x00A050654325. 
	   We write this address to the 6-byte array 'peripheralAddress'. This array is then  
	   used to compare the addresses of the advertising peripherals. If one of the advertising 
	   peripherals has the same address, then we know it is the device which we want to connect  
	   and initiate a connection request to it.*/
		peripheralAddress[5] = 0x00;
		peripheralAddress[4] = 0xA0;
		peripheralAddress[3] = 0x50;
		peripheralAddress[2] = 0x7E;
		peripheralAddress[1] = 0x47;
		peripheralAddress[0] = 0xD0;
}
/* [] END OF FILE */
