/*
*******************************************************************************/

/******************************************************************************
*                           THEORY OF OPERATION
*******************************************************************************
* This project showcases the capability of PSoC 4 BLE to communicate 
* with a BLE Central device over custom BLE service. The RGB LED custom service  
* allows read and write of attributes under the RGB characteristics.
* The LED control values sent to PSoC 4 BLE over BLE connection is converted to 
* respective color and intensity on the onboard RGB LED. The BLE central device 
* can be either CySmart mobile app, CySmart PC tool or third party App. 
* Refer to application note AN91162 for details.
*******************************************************************************
* No explicit Hardware connection is required. The LED is hard-wired on the BLE 
* Pioneer kit. The assigned pins are:
* R-G-B LED 	- P2[6], P3[6] and P3[7], respectively
******************************************************************************/
#include <main.h>
int main()
{
	CyGlobalIntEnable;		
	CyBle_Start(GeneralEventHandler);
	UpdateBikeState(0);

	
    for(;;)
    {
        /* Process BLE Events. This API pushes the BLE events from the stack
		* to the generic event callback function in the application. This  function
		* also pushes data from application to BLE stack for transmission */
		CyBle_ProcessEvents();
    }
}
