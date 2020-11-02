
#ifndef SWITCHMODE_H
#define SWITCHMODE_H
#include <project.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
    
#define BITNUM      (8)
#define RED_VAL(x)  ((x >> BITNUM) & 0xFF)
#define BLUE_VAL(x)  ((x >> (BITNUM*2)) & 0xFF)
#define GREEN_VAL(x)  (x & 0xFF)

/*COLOR Definitions - uint32 */
#define LEDS_getColor( a ) LEDS_CLUT[a]
#define LEDS_CWHEEL_SIZE 24
#define LEDS_YELLOW      LEDS_getColor(1)
#define LEDS_GREEN       LEDS_getColor((70 + LEDS_CWHEEL_SIZE))
#define LEDS_ORANGE      LEDS_getColor(20)
#define LEDS_BLACK       LEDS_getColor((0 + LEDS_CWHEEL_SIZE))
#define LEDS_OFF         LEDS_getColor((0 + LEDS_CWHEEL_SIZE))
#define LEDS_LTBLUE      LEDS_getColor((1 + LEDS_CWHEEL_SIZE))
#define LEDS_MBLUE       LEDS_getColor((2 + LEDS_CWHEEL_SIZE))
#define LEDS_BLUE        LEDS_getColor((3 + LEDS_CWHEEL_SIZE))
#define LEDS_LTGREEN     LEDS_getColor((4 + LEDS_CWHEEL_SIZE))
#define LEDS_MGREEN      LEDS_getColor((8 + LEDS_CWHEEL_SIZE))
//#define LEDS_GREEN       (12 + LEDS_CWHEEL_SIZE) 
#define LEDS_LTRED       LEDS_getColor((16 + LEDS_CWHEEL_SIZE)) 
#define LEDS_LTYELLOW    LEDS_getColor((20 + LEDS_CWHEEL_SIZE))
#define LEDS_MGRED       LEDS_getColor((32 + LEDS_CWHEEL_SIZE)) 
#define LEDS_RED         LEDS_getColor((48 + LEDS_CWHEEL_SIZE)) 
#define LEDS_MAGENTA     LEDS_getColor((51 + LEDS_CWHEEL_SIZE))
#define LEDS_WHITE       LEDS_getColor((63 + LEDS_CWHEEL_SIZE)) 
/**/
#define LEDS_SPRING_GREEN LEDS_getColor((64 + LEDS_CWHEEL_SIZE)) 
#define LEDS_TURQUOSE    LEDS_getColor((65 + LEDS_CWHEEL_SIZE)) 
#define LEDS_CYAN        LEDS_getColor((66 + LEDS_CWHEEL_SIZE)) 
#define LEDS_OCEAN       LEDS_getColor((67 + LEDS_CWHEEL_SIZE)) 
#define LEDS_VIOLET      LEDS_getColor((68 + LEDS_CWHEEL_SIZE)) 
#define LEDS_RASPBERRY   LEDS_getColor((69 + LEDS_CWHEEL_SIZE)) 
#define LEDS_DIM_WHITE   LEDS_getColor((71 + LEDS_CWHEEL_SIZE)) 
#define LEDS_DIM_BLUE    LEDS_getColor((72 + LEDS_CWHEEL_SIZE)) 
#define LEDS_INVISIBLE   LEDS_getColor((73 + LEDS_CWHEEL_SIZE))
#define LEDS_COLD_TEMP   LEDS_getColor((80 + LEDS_CWHEEL_SIZE)) 
#define LEDS_HOT_TEMP    LEDS_getColor((95 + LEDS_CWHEEL_SIZE)) 
#define LEDS_CLUT_SIZE  (96 + LEDS_CWHEEL_SIZE)

/*WS2812B Data Transfer*/
#define T1H  1200    // Width of a 1 bit in ns
#define T1L  1300    // Width of a 1 bit in ns
#define T0H  500    // Width of a 0 bit in ns
#define T0L  2000    // Width of a 0 bit in ns
#define RES  50000    // Width of the low gap between bits to cause a frame to latch
    
#define NS_PER_SEC (1000000000L) // Note that this has to be SIGNED since we want to be able to check for negative values of derivatives
#define CYCLES_PER_SEC (CYDEV_BCLK__HFCLK__HZ) //48Mhz
#define NS_PER_CYCLE ( NS_PER_SEC / CYCLES_PER_SEC ) //~20.83
#define NS_TO_CYCLES(n) ( (n) / NS_PER_CYCLE )    
    
uint32 LED_Set(uint32 col);
void show();
uint32 currSet;
#endif