#ifndef _PRESSURE_SENSOR_H
#define _PRESSURE_SENSOR_H

#include "state.h"

#define GPIOA_IDR *(volatile uint32_t *)(GPIO_PORTA + 0x08)
extern void (*PPRESSURE_SENSOR_State)();

/*extern enum
{
	PRESSURE_SENSOR_BUSY
}PRESSURE_SENSOR_STATE_ID;
*/
STATE_FUNC_DEFINE(PRESSURE_SENSOR_BUSY);

void PRESSURE_SENSOR_Init();

#endif /* _PRESSURE_SENSOR_H */