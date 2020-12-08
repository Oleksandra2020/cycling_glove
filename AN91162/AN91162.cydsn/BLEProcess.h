/*This file contains the macros and declaration of BLE related functions.*/

#if !defined (BLEPROCESS_H)
#define BLEPROCESS_H
#include <project.h>

#define BIKE_STATUS_CHAR_DATA_LEN				1

void GeneralEventHandler(uint32 , void*);
void UpdateBikeStatuscharacteristic(uint8* , uint8, uint16);

#endif

