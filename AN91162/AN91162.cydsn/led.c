/*******************************************************************************
* Contains function definitions for RGB LED control application
*******************************************************************************/
#include "main.h"

void UpdateBikeState(uint8 value)
{
    // 0b 0000 0111 mask
    // 0b 0000 0110 -> turn on LED on bit 0 
    // 0b 0000 0101 -> bit 1 
    // 0b 0000 0011 -> bit 2 
	uint8 regData = 0;
	switch(value)
	{
	case 1: 
		regData = 6; 
		break;
	case 2: 
		regData = 5; 
		break;
	case 3: 
		regData = 3; 
		break;
	case 0: 
	default:
		regData = 7; 
	}
	ControlStatusRegs_Write(regData);
}
