/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpu6050.h>
#include <math.h>

void StackEventHandler( uint32 eventCode, void *eventParam );

#define numberOfTests   1000

char buf[500]; //just to hold text values in for writing to UART
int i = 0; //for loop increment variable
   
uint8 flag = 0;

char Abuf[200];   //to hold acceleration value text
   
int16_t CAX, CAY, CAZ; //current acceleration values
int16_t CGX, CGY, CGZ; //current gyroscope values
int16_t CT;            //current temperature
   
float   AXoff, AYoff, AZoff; //accelerometer offset values
float   GXoff, GYoff, GZoff; //gyroscope offset values

float   AX, AY, AZ; //acceleration floats
float   GX, GY, GZ; //gyroscope floats

float   Roll,Pitch,Yaw;

void test_values()
{
     for(i =0; i<numberOfTests; i++)
    {
     sprintf(buf, "Test Number: %d \n\r", i);
      UART_UartPutString(buf);
    
      MPU6050_getMotion6t(&CAX, &CAY, &CAZ, &CGX, &CGY, &CGZ, &CT);
      AXoff += CAX;
      AYoff += CAY;
      AZoff += CAZ;
      GXoff += CGX;
      GYoff += CGY;
      GZoff += CGZ;
       
      sprintf(buf, "AX:%d, AY:%d, AZ:%d || GX:%d, GY:%d, GZ:%d,\t", CAX,CAY,CAZ,CGX,CGY,CGZ);
      UART_UartPutString(buf);
      UART_UartPutString("\n\r");
      CyDelay(25);
    }
    AXoff = AXoff/numberOfTests;
    AYoff = AYoff/numberOfTests;
    AZoff = AZoff/numberOfTests;
    GXoff = GXoff/numberOfTests;
    GYoff = GYoff/numberOfTests;
    GZoff = GZoff/numberOfTests;
    
    UART_UartPutString("\n\nTest finished, offset values are shown below\n\n\r");
    sprintf(buf, "AXoff:%d, AYoff:%d, AZoff:%d || GXoff:%d, GYoff:%d, GZoff:%d,\t", (int)AXoff,(int)AYoff,(int)AZoff,(int)GXoff,(int)GYoff,(int)GZoff);
    UART_UartPutString(buf);
}
    

int main (void)
{
    CyGlobalIntEnable;   /* Enable global interrupts */
   
	I2C_MPU6050_Start();
	UART_Start();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    MPU6050_init();
	MPU6050_initialize();
	UART_UartPutString(MPU6050_testConnection() ? "MPU6050 connection successful\n\r" : "MPU6050 connection failed\n\n\r");
    
    UART_UartPutString("Raw values from gyroscope..\n\r");
//Test was used and numbers are known        
   test_values();
    
    while(1){
         Up_Write(1);
        Down_Write(1);
        Right_Write(1);
    //Convert values to G's 
        UART_UartPutString("\r\n\nWorking...\n\n\r"); 
        
    MPU6050_getMotion6t(&CAX, &CAY, &CAZ, &CGX, &CGY, &CGZ, &CT);
    //sprintf(buf, "AX:%d, AY:%d, AZ:%d || GX:%d, GY:%d, GZ:%d,\t", CAX,CAY,CAZ,CGX,CGY,CGZ);
      //UART_UartPutString(buf);
      //UART_UartPutString("\n\r");
    
      AX = ((float)CAX-AXoff)/16384.00;
      AY = ((float)CAY-AYoff)/16384.00; //16384 is just 32768/2 to get our 1G value
      AZ = ((float)CAZ-(AZoff-16384))/16384.00; //remove 1G before dividing
    
      GX = ((float)CGX-GXoff)/131.07; //131.07 is just 32768/250 to get us our 1deg/sec value
      GY = ((float)CGY-GYoff)/131.07;
      GZ = ((float)CGZ-GZoff)/131.07; 
    
      //sprintf(buf, "AX:%+5.2f, AY:%+5.2f, AZ:%+5.2f || GX:%+5.2f, GY:%+5.2f, GZ:%+5.2f,\t\r\n", AX,AY,AZ,GX,GY,GZ);
      //UART_UartPutString(buf);
    
    
      Roll  = atan2f(AY, AZ) * 180/M_PI;
      Pitch = atan2f(AX, sqrt(AY*AY + AZ*AZ)) * 180/M_PI;    
    
    //%f,%f,%f - AX,AY,AZ,
      sprintf(Abuf, "roll: %f; pitch: %f\t\r\n",Roll,Pitch);
      UART_UartPutString(Abuf);
    
    float control_num = 40;
    if(Roll>=control_num)
    {
        //Right
        UART_UartPutString("\r\n\nRight\n\n\r");
        Right_Write(0);
        CyDelay(500);
    }
    else if(Roll<=-control_num)
    {
        //Left
        UART_UartPutString("\r\n\nLeft\n\n\r");
        Up_Write(0);
        CyDelay(500);
        Down_Write(0);
        CyDelay(500);
    }
    else if(Pitch>=control_num)
    {
        //Down
        UART_UartPutString("\r\n\nDown\n\n\r");
        Down_Write(0);
        CyDelay(500);
    }
    else if(Pitch<=-control_num)
    {
        //Up
        UART_UartPutString("\r\n\nUp\n\n\r");
        Up_Write(0);
        CyDelay(500);
    }
    
      CyDelay(500);  
    }
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    CyBle_Start( StackEventHandler );
    
    for(;;)
    {
        /* Place your application code here */
        CyBle_ProcessEvents();
    }
}

void StackEventHandler( uint32 eventCode, void *eventParam )
{
    switch( eventCode )
    {
        /* Generic events */

        case CYBLE_EVT_HOST_INVALID:
        break;

        case CYBLE_EVT_STACK_ON:
            /* CyBle_GappStartAdvertisement( CYBLE_ADVERTISING_FAST ); */
        break;

        case CYBLE_EVT_TIMEOUT:
        break;

        case CYBLE_EVT_HARDWARE_ERROR:
        break;

        case CYBLE_EVT_HCI_STATUS:
        break;

        case CYBLE_EVT_STACK_BUSY_STATUS:
        break;

        case CYBLE_EVT_PENDING_FLASH_WRITE:
        break;


        /* GAP events */

        case CYBLE_EVT_GAP_AUTH_REQ:
        break;

        case CYBLE_EVT_GAP_PASSKEY_ENTRY_REQUEST:
        break;

        case CYBLE_EVT_GAP_PASSKEY_DISPLAY_REQUEST:
        break;

        case CYBLE_EVT_GAP_AUTH_COMPLETE:
        break;

        case CYBLE_EVT_GAP_AUTH_FAILED:
        break;

        case CYBLE_EVT_GAP_DEVICE_CONNECTED:
        break;

        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
            /* CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST); */
        break;

        case CYBLE_EVT_GAP_ENCRYPT_CHANGE:
        break;

        case CYBLE_EVT_GAP_CONNECTION_UPDATE_COMPLETE:
        break;

        case CYBLE_EVT_GAP_KEYINFO_EXCHNGE_CMPLT:
        break;


        /* GAP Peripheral events */

        case CYBLE_EVT_GAPP_ADVERTISEMENT_START_STOP:
        break;


        /* GAP Central events */

        case CYBLE_EVT_GAPC_SCAN_PROGRESS_RESULT:
        break;

        case CYBLE_EVT_GAPC_SCAN_START_STOP:
        break;


        /* GATT events */

        case CYBLE_EVT_GATT_CONNECT_IND:
        break;

        case CYBLE_EVT_GATT_DISCONNECT_IND:
        break;


        /* GATT Client events (CYBLE_EVENT_T) */

        case CYBLE_EVT_GATTC_ERROR_RSP:
        break;

        case CYBLE_EVT_GATTC_XCHNG_MTU_RSP:
        break;

        case CYBLE_EVT_GATTC_READ_BY_GROUP_TYPE_RSP:
        break;

        case CYBLE_EVT_GATTC_READ_BY_TYPE_RSP:
        break;

        case CYBLE_EVT_GATTC_FIND_INFO_RSP:
        break;

        case CYBLE_EVT_GATTC_FIND_BY_TYPE_VALUE_RSP:
        break;

        case CYBLE_EVT_GATTC_READ_RSP:
        break;

        case CYBLE_EVT_GATTC_READ_BLOB_RSP:
        break;

        case CYBLE_EVT_GATTC_READ_MULTI_RSP:
        break;

        case CYBLE_EVT_GATTC_WRITE_RSP:
        break;

        case CYBLE_EVT_GATTC_EXEC_WRITE_RSP:
        break;

        case CYBLE_EVT_GATTC_HANDLE_VALUE_NTF:
        break;

        case CYBLE_EVT_GATTC_HANDLE_VALUE_IND:
        break;


        /* GATT Client events (CYBLE_EVT_T) */

        case CYBLE_EVT_GATTC_INDICATION:
        break;

        case CYBLE_EVT_GATTC_SRVC_DISCOVERY_FAILED:
        break;

        case CYBLE_EVT_GATTC_INCL_DISCOVERY_FAILED:
        break;

        case CYBLE_EVT_GATTC_CHAR_DISCOVERY_FAILED:
        break;

        case CYBLE_EVT_GATTC_DESCR_DISCOVERY_FAILED:
        break;

        case CYBLE_EVT_GATTC_SRVC_DUPLICATION:
        break;

        case CYBLE_EVT_GATTC_CHAR_DUPLICATION:
        break;

        case CYBLE_EVT_GATTC_DESCR_DUPLICATION:
        break;

        case CYBLE_EVT_GATTC_SRVC_DISCOVERY_COMPLETE:
        break;

        case CYBLE_EVT_GATTC_INCL_DISCOVERY_COMPLETE:
        break;

        case CYBLE_EVT_GATTC_CHAR_DISCOVERY_COMPLETE:
        break;

        case CYBLE_EVT_GATTC_DISCOVERY_COMPLETE:
        break;


        /* GATT Server events (CYBLE_EVENT_T) */

        case CYBLE_EVT_GATTS_XCNHG_MTU_REQ:
        break;

        case CYBLE_EVT_GATTS_WRITE_REQ:
        break;

        case CYBLE_EVT_GATTS_WRITE_CMD_REQ:
        break;

        case CYBLE_EVT_GATTS_PREP_WRITE_REQ:
        break;

        case CYBLE_EVT_GATTS_EXEC_WRITE_REQ:
        break;

        case CYBLE_EVT_GATTS_HANDLE_VALUE_CNF:
        break;

        case CYBLE_EVT_GATTS_DATA_SIGNED_CMD_REQ:
        break;


        /* GATT Server events (CYBLE_EVT_T) */

        case CYBLE_EVT_GATTS_INDICATION_ENABLED:
        break;

        case CYBLE_EVT_GATTS_INDICATION_DISABLED:
        break;


        /* L2CAP events */

        case CYBLE_EVT_L2CAP_CONN_PARAM_UPDATE_REQ:
        break;

        case CYBLE_EVT_L2CAP_CONN_PARAM_UPDATE_RSP:
        break;

        case CYBLE_EVT_L2CAP_COMMAND_REJ:
        break;

        case CYBLE_EVT_L2CAP_CBFC_CONN_IND:
        break;

        case CYBLE_EVT_L2CAP_CBFC_CONN_CNF:
        break;

        case CYBLE_EVT_L2CAP_CBFC_DISCONN_IND:
        break;

        case CYBLE_EVT_L2CAP_CBFC_DISCONN_CNF:
        break;

        case CYBLE_EVT_L2CAP_CBFC_DATA_READ:
        break;

        case CYBLE_EVT_L2CAP_CBFC_RX_CREDIT_IND:
        break;

        case CYBLE_EVT_L2CAP_CBFC_TX_CREDIT_IND:
        break;

        case CYBLE_EVT_L2CAP_CBFC_DATA_WRITE_IND:
        break;


        /* default catch-all case */

        default:
        break;
    }
}
