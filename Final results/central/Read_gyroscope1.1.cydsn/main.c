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
#include <main.h>

extern uint8 					ble_state ;
extern uint8 					deviceConnected;

extern CYBLE_GAP_BD_ADDR_T connectPeriphDevice;
extern uint8 peripheralFound;

extern uint8 restartScanning;

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
float angle_gx=0,angle_gy=0,angle_gz=0;
float angle_ax=0,angle_ay=0,angle_az=0;
#define TIME_GYRO 2000

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

void InitializeSystem(void)
{
	CyGlobalIntEnable; 
	CySysClkWriteEcoDiv(CY_SYS_CLK_ECO_DIV8);
	CyBle_Start(ApplicationEventHandler);	
	LoadPeripheralDeviceData(); 
}

int main (void)
{
    float FK = 0.9;
    CyGlobalIntEnable;   /* Enable global interrupts */
   
	I2C_MPU6050_Start();
	UART_Start();
    
    MPU6050_init();
	MPU6050_initialize();
	UART_UartPutString(MPU6050_testConnection() ? "MPU6050 connection successful\n\r" : "MPU6050 connection failed\n\n\r");
  
//Here we are looking for offset      
    test_values();
    InitializeSystem();
    
    while(1){
        CyBle_ProcessEvents();		
		ShowConnectingStatus(ble_state);
        
        if(peripheralFound)
		{
			CyBle_GapcConnectDevice(&connectPeriphDevice);
			CyBle_ProcessEvents();
			peripheralFound = FALSE;
		}
			
		if(deviceConnected)
		{		
            //Convert values to G's 
               UART_UartPutString("\r\n\nWorking...\n\n\r"); 
                
            //Getting values from MPU6050
            MPU6050_getMotion6t(&CAX, &CAY, &CAZ, &CGX, &CGY, &CGZ, &CT);
            //sprintf(buf, "AX:%d, AY:%d, AZ:%d || GX:%d, GY:%d, GZ:%d,\t", CAX,CAY,CAZ,CGX,CGY,CGZ);
              //UART_UartPutString(buf);
              //UART_UartPutString("\n\r");
            
            //callibrate values
              AX = ((float)CAX-AXoff)/16384.00;
              AY = ((float)CAY-AYoff)/16384.00; //16384 is just 32768/2 to get our 1G value
              AZ = ((float)CAZ-(AZoff-16384))/16384.00; //remove 1G before dividing
            
              GX = ((float)CGX-GXoff)/131.07; //131.07 is just 32768/250 to get us our 1deg/sec value
              GY = ((float)CGY-GYoff)/131.07;
              GZ = ((float)CGZ-GZoff)/131.07; 
            
            //Here we can look at G values    
              //sprintf(buf, "AX:%+5.2f, AY:%+5.2f, AZ:%+5.2f || GX:%+5.2f, GY:%+5.2f, GZ:%+5.2f,\t\r\n", AX,AY,AZ,GX,GY,GZ);
              //UART_UartPutString(buf);
            
            //converting to angles
              Roll  = atan2f(AY, AZ) * 180/M_PI;
              Pitch = atan2f(AX, sqrt(AY*AY + AZ*AZ)) * 180/M_PI;    
            
              angle_ax = atan2(AY,AZ)*180/M_PI;
              angle_ay = atan2(AX,AZ)*180/M_PI;
              angle_az = atan2(AY,AX)*180/M_PI;
            
            
              angle_gx = angle_gx + GX*TIME_GYRO/1000000.0;
              angle_gy = angle_gy + GY*TIME_GYRO/1000000.0;
              angle_gz = angle_gz + GZ*TIME_GYRO/1000000.0;
            
              //Комплементарний фільтр
              angle_ax = angle_ax*FK + angle_gx *(1-FK);
              angle_ay = angle_ay*FK + angle_gy *(1-FK);
              angle_az = angle_az*FK + angle_gz *(1-FK);
            
            //sprintf(Abuf, "AX:%f, AY:%f, AZ:%f\t", angle_ax,angle_ay,angle_az);
              UART_UartPutString(Abuf);
            //show control values
              //sprintf(Abuf, "roll: %f; pitch: %f\t\r\n",Roll,Pitch);
              UART_UartPutString(Abuf);
            
            float control_num = 40;//control angle
            if(angle_ax>=control_num)//if(Roll>=control_num)
            {
                //Right
                UART_UartPutString("\r\n\nRight\n\n\r");
                uint8_t iasLevel = 1;
            
    			/* Send the updated Alert level to Peripheral over Immediate Alert Service*/
    			WriteCharacteristicValue(&iasLevel);
                CyDelay(500);
            }
            else if(angle_ax<=-control_num)//else if(Roll<=-control_num)
            {
                //Left
                UART_UartPutString("\r\n\nLeft\n\n\r");
                uint8_t iasLevel = 2;
            
    			/* Send the updated Alert level to Peripheral over Immediate Alert Service*/
    			WriteCharacteristicValue(&iasLevel);
                CyDelay(500);
            }
            else if(angle_ay>=control_num)//else if(Pitch>=control_num)
            {
                //Down
                UART_UartPutString("\r\n\nDown\n\n\r");
                CyDelay(500);
            }
            else if(angle_ay<=-control_num)//else if(Pitch<=-control_num)
            {
                //Up
                UART_UartPutString("\r\n\nUp\n\n\r");
                uint8_t iasLevel = 3;
            
    			/* Send the updated Alert level to Peripheral over Immediate Alert Service*/
    			WriteCharacteristicValue(&iasLevel);
                CyDelay(500);
            }
        }
        if(restartScanning)
		{
			restartScanning = FALSE;			
			CyBle_GapcStartScan(CYBLE_SCANNING_FAST);
		}
    
      CyDelay(500);  
    }
}
