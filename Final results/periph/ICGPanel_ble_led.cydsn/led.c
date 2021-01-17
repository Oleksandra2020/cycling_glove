#include "main.h"


void light_array(uint16 arr[], uint16 length, uint32 color)
{
    CyDelay(500);   
    int16 i = 0;
    while (i < length)
    {
        StripLights_Pixel(arr[i], 0, color);
        i += 1;
    }
    while( StripLights_Ready() == 0);
    StripLights_Trigger(1);
    CyDelay(500);
}

void clear_array()
{
    int16 i = 0;
    while (i < 60)
    {   
       
        StripLights_Pixel(i, 0, 0);
        i += 1;
    }
    while( StripLights_Ready() == 0);
    StripLights_Trigger(1);
    CyDelay(300);
}

void stop_signal()
{
    uint16 led_length = 60;
    uint16 stop[led_length];
    for (int i=0; i < led_length; ++i) {
        stop[i] = i;
    }
    light_array(stop, led_length, StripLights_RED);

}

void light_right()
{ 
    /* small lines
    uint16 right_arr[] = {4, 18, 21, 34, 38, 51, 53,
                          6, 16, 23, 32, 40, 49, 55,
                          8,  14, 25, 30, 42, 47, 57}; */
    
    /* thick lines separated by one
    uint16 right_arr[] = {4, 18, 21, 34, 38, 51, 53,
                          5, 17, 22, 33, 39, 50, 54,
                          7,  15, 24, 31, 41, 48, 56,
                          8, 14, 25, 30, 42, 47, 57}; */
    
    /* thick lines separated by two  - final choice*/
    uint16 right_arr[] = {4, 18, 21, 34, 38, 51, 53,
                          5, 17, 22, 33, 39, 50, 54,
                          8, 14, 25, 30, 42, 46, 57,
                          9, 13, 26, 28, 43, 47, 58
                          };
    light_array(right_arr, 28, StripLights_YELLOW);
}

void light_left()
{
    /* thick lines separated by two  - final choice*/
    uint16 left_arr[] = {59, 46, 42, 31, 25, 13, 10,
                         58, 47, 41, 32, 24, 14, 9,
                         55, 50, 38, 35, 21, 17, 6,
                         54, 51, 37, 36, 20, 18, 5};
    light_array(left_arr, 28, StripLights_YELLOW);
}


void UpdateBikeState(uint8 value)
{
    uint8 regs = 0;
    uint8 counter = 0;
	switch(value)
	{
	case RIGHT: 		
        regs = 6;     
        clear_array();
        light_right();
        CyDelay(100);
        
        clear_array();
        light_right();
        CyDelay(100);
        
        clear_array();
        light_right();
        CyDelay(100);
        
        clear_array();
        light_right();
        CyDelay(100);
        
		break;
        
	case LEFT: 		
        regs = 5;        
        light_left();
        CyDelay(100);
        clear_array();
		break;
        
	case STOP:         
        regs = 3;
        stop_signal();
        CyDelay(100);
        clear_array();
        break;
	default:
		
        regs = 7; 
	}
    ControlStatusRegs_Write(regs);
}
