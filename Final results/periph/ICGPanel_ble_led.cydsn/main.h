
#if !defined(MAIN_H)
#define MAIN_H
#include <project.h>
#include "led.h"
#include "BLEProcess.h"
	
/********************************** Macros ******************************************/
/* General Macros*/
#define TRUE							0x01
#define FALSE							0x00
    
#define SIGNAL                          0
#define RIGHT                           1
#define LEFT                            2
#define STOP                            3
/************************************************************************************/

void InitializeSystem(void);


#endif
