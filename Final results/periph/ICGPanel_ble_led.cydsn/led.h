#if !defined (LED_H)
#define LED_H
#include <project.h>


void UpdateBikeState(uint8 value);
void display_move();


void light_array(uint16 arr[], uint16 size, uint32 color);
void stop_signal();
void light_right();
void light_left();
void light_connection();
void display_move();


#endif
