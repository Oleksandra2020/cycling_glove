#include <main.h>


int main()
{
	CyGlobalIntEnable;		
	CyBle_Start(GeneralEventHandler);
	UpdateBikeState(0);
    StripLights_Start();

	
    for(;;)
    {
        /* Process BLE Events. This API pushes the BLE events from the stack
		* to the generic event callback function in the application. This  function
		* also pushes data from application to BLE stack for transmission */
		CyBle_ProcessEvents();
    }
}
