#include "project.h"

void display_move();

int16 length = 10;

int main(void)
{
    CyGlobalIntEnable;
    StripLights_Start();

    for(;;)
    {
        display_move();
    }
}

void light_array(uint16 arr[])
{
    StripLights_Trigger(0);
    CyDelay(500);   
    int16 i = 0;
    while (i < length)
    {   
        StripLights_Pixel(arr[i], 0, StripLights_GREEN);
        i += 1;
    }
    while( StripLights_Ready() == 0);
    StripLights_Trigger(1);
    CyDelay(500);
}

void stop_signal()
{
    uint16 i = 0;
    while (i < 30)
    {
        StripLights_Pixel(i, 0, StripLights_RED);
        i += 1;
    }
}

void light_right()
{ 
    uint16 right_arr[] = {1, 3, 7, 9, 12, 14, 19, 21, 25, 27};
    light_array(right_arr);
}

void light_left()
{
    uint16 left_arr[] = {0, 2, 7, 9, 13, 15, 19, 21, 24, 26};
    light_array(left_arr);
}

void display_move()
{
    StripLights_Dim(0); 

    for(;;)
    {   
        light_left();
	    CyDelay(50);  
    }
}

/* [] END OF FILE */
