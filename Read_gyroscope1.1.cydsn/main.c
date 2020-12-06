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
    
    MPU6050_init();
	MPU6050_initialize();
	UART_UartPutString(MPU6050_testConnection() ? "MPU6050 connection successful\n\r" : "MPU6050 connection failed\n\n\r");
  
//Here we are looking for offset      
   test_values();
    
    while(1){
         Up_Write(1);
        Down_Write(1);
        Right_Write(1);
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
    
    //show control values
      sprintf(Abuf, "roll: %f; pitch: %f\t\r\n",Roll,Pitch);
      UART_UartPutString(Abuf);
    
    float control_num = 40;//control angle
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
}

