/******************************************************************************
* Project Name		: PSoC_4_BLE_Central_IAS
* File Name			: main.c
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

/******************************************************************************
*                           THEORY OF OPERATION
*******************************************************************************
* The project will showcase the capability of PSoC 4 BLE to act as BLE Central
* device and communicate with a BLE Peripheral device. The example 
* demonstrated is a BLE application called Find Me. Here, the BLE Pioneer kit,
* programmed with this firmware, acts as a Find Me Collector. CySmart USB Dongle, 
* which is programmed with the BLE_Dongle_Peripheral_IAS, acts as a Find Me 
* Reporter. 
* This Central project supports low power mode, which makes low power current 
* consumption possible for this application. The BLE central project goes to deep 
* sleep during scanning timeout or disconnection and can be woken up using 
* the User Button. During connection, the firmware pushes the system to deep 
* sleep whenever possible. If BLE_Dongle_Peripheral_IAS is advertising, then this 
* project connects to it automatically. 
* After the two devices are connected, the Push Button on the BLE Pioneer kit 
* will switch the Alert level between No, Mid and High Alert on CySmart USB Dongle,
* which is demonstrated by the different modes of lighting LED.
*
* Note: Though this project has Deep Sleep mode implemented allowing very low power 
* consumption, the BLE scanning process consists of radio RX activity and thus
* consumes considerably more current. 

* The programming pins have been configured as GPIO, and not SWD. This is because 
* the silicon consumes extra power through the pins when the programming pins 
* are configured for SWD. To prevent the leakage of power, the pins have been set 
* to GPIO. With this setting, the kit can still be acquired by PSoC Creator or
* PSoC Programmer software tools for programming, but the project cannot be 
* externally debugged. To re-enable debugging, go to PSoC_4_BLE_Central_IAS.cydwr from
* Workspace Explorer, go to Systems tab, and set the Debug Select option to 'SWD'.
* Build and program this project to enable external Debugging.
*
* Refer to CY8CKIT-042-BLE-A Pioneer Kit guide for details.
*******************************************************************************
* Hardware connection required for testing -
* Status LED- P3[7] (Hard-wired on the BLE Pioneer kit)
* User Button- P2[7] (hard-wired in the BLE Pioneer kit)
******************************************************************************/
#include <main.h>

/* 'ble_state' stores the state of connection which is used for updating LEDs */
extern uint8 					ble_state ;

/* 'deviceConnected' flag tells the status of connection with BLE peripheral Device */
extern uint8 					deviceConnected;

/* 'connectPeriphDevice' is a variable of type 'CYBLE_GAP_BD_ADDR_T' (defined in 
* BLE_StackGap.h) and is used to store address of the connected device. */
extern CYBLE_GAP_BD_ADDR_T connectPeriphDevice;

/* 'peripheralAddress' stores the address of device presently connected to */
extern uint8 peripheralFound;

extern uint8 restartScanning;
/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*        System entrance point. This calls the BLE routine functions as well as
* function for sending Immediate Alert level notifications and handling low power
* mode.
*
* Parameters:
*  void
*
* Return:
*  int
*

*******************************************************************************/
int main()
{
    /* Initialize the system */
	InitializeSystem();
	
    for(;;)
    {
        /*Process Event callback to handle BLE events. The events generated and 
		* used for this application are inside the 'ApplicationEventHandler' routine */
		CyBle_ProcessEvents();
		
		/* Handle BLE Status LED */
		ShowConnectingStatus(ble_state);
		
		if(peripheralFound)
		{
			/* If the desired peripheral is found, then connect to that peripheral */
			CyBle_GapcConnectDevice(&connectPeriphDevice);
			
			/* Call CyBle_ProcessEvents() once to process the Connect request sent above. */
			CyBle_ProcessEvents();
		
			/* Reset flag to prevent resending the Connect command */
			peripheralFound = FALSE;
		}
			
		if(deviceConnected)
		{
			/* Check if the button was pressed and update the Alert Level Accordingly.*/
			CheckButtonStatus();	
		}

		
		/* If rescanning flag is TRUE, then restart the scan */
		if(restartScanning)
		{
			/* Reset flag to prevent calling multiple Start Scan commands */
			restartScanning = FALSE;
			
			/* Start Fast BLE Scanning. This API will only take effect after calling
			* CyBle_ProcessEvents()*/
			CyBle_GapcStartScan(CYBLE_SCANNING_FAST);
		}
	}
}

/*******************************************************************************
* Function Name: InitializeSystem
********************************************************************************
* Summary:
*        This function starts and initializes the components involved in the 
* system
*
* Parameters:
*  void
*
* Return:
*  void
*

*******************************************************************************/
void InitializeSystem(void)
{
	/* Enable global interrupts. */
	CyGlobalIntEnable; 
	
    /* Set the divider for ECO, ECO will be used as source when IMO is switched off to save power */
    CySysClkWriteEcoDiv(CY_SYS_CLK_ECO_DIV8);

	/* Start BLE component with appropriate Event handler function */
	CyBle_Start(ApplicationEventHandler);	
	
	/* Load the BD address of peripheral device to which we have to connect */
	LoadPeripheralDeviceData(); 
}

/* [] END OF FILE */
