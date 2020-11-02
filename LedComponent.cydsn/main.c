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
#include "main.h"

#define TEST_CNT    (6)
extern const uint32 LEDS_CLUT[ ];
uint8 i;
int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Init();
    uint32 testList[] = {LEDS_BLUE,LEDS_GREEN,LEDS_RED,LEDS_YELLOW,LEDS_VIOLET,LEDS_ORANGE};
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        for (i = 0; i < TEST_CNT; i++){
            LED_Set(testList[i]);
//            CyDelay(2500);
//            LED_Set(LEDS_OFF);
//            CyDelay(2500);
        }
    }
}


void Init(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    Din_Write(1);
}
/* [] END OF FILE */
