#include <main.h>

void GeneralEventHandler(uint32 event, void * eventParam)
{
	/* Structure to store data written by Client */	
	CYBLE_GATTS_WRITE_REQ_PARAM_T *wrReqParam;
	
	/* 'RGBledData[]' is an array to store 4 bytes of RGB LED data*/
	uint8 BikeStatusData[BIKE_STATUS_CHAR_DATA_LEN];
	
	switch(event)
    {
		case CYBLE_EVT_STACK_ON:
			/* BLE stack is on. Start BLE advertisement */
			CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
		break;
				
		case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
			/* This event is generated at GAP disconnection. */
			
			/* Reset the color values*/	
			BikeStatusData[0] = 0;
			/* Switch off LEDs */
			UpdateBikeState(BikeStatusData[0]);
			
			/* Register the new color in GATT DB*/			
			UpdateBikeStatuscharacteristic(BikeStatusData, 
									sizeof(BikeStatusData),
									CYBLE_BIKESTATUS_BIKESTATUSCHARACTERISTIC_CHAR_HANDLE);
			
			/* Restart advertisement */
			CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
		break;

        case CYBLE_EVT_GATTS_WRITE_REQ: 
			/* This event is generated when the connected Central device sends a
			* Write request. The parameter contains the data written */
			
			/* Extract the Write data sent by Client */
            wrReqParam = (CYBLE_GATTS_WRITE_REQ_PARAM_T *) eventParam;
			
			/* If the attribute handle of the characteristic written to 
			* is equal to that of RGB_LED characteristic, then extract 
			* the RGB LED data */
			if(CYBLE_BIKESTATUS_BIKESTATUSCHARACTERISTIC_CHAR_HANDLE == wrReqParam->handleValPair.attrHandle)
            {
				/* Store RGB LED data in local array */
                BikeStatusData[0] = wrReqParam->handleValPair.value.val[0];
                
				/* Update the PrISM component density value to represent color */
                UpdateBikeState(BikeStatusData[0]);
				
				/* Update the GATT DB for RGB LED read characteristics*/
				UpdateBikeStatuscharacteristic(BikeStatusData, 
										sizeof(BikeStatusData), 
										CYBLE_BIKESTATUS_BIKESTATUSCHARACTERISTIC_CHAR_HANDLE);
            }
			
			/* Send the response to the write request. */
			CyBle_GattsWriteRsp(cyBle_connHandle);
			break;

        default:

       	break;
    }   	
}



void UpdateBikeStatuscharacteristic(uint8* ledData, uint8 len, uint16 attrHandle)
{
	/* 'rgbHandle' stores RGB control data parameters */
	CYBLE_GATT_HANDLE_VALUE_PAIR_T		handle;

	/* Update RGB control handle with new values */
	handle.attrHandle = attrHandle;
	handle.value.val = ledData;
	handle.value.len = len;
	
	/* Update the RGB LED attribute value. This will allow 
	* Client device to read the existing color values over 
	* RGB LED characteristic */
	CyBle_GattsWriteAttributeValue(&handle, 
									FALSE, 
									&cyBle_connHandle, 
									CYBLE_GATT_DB_PEER_INITIATED);
}