#ifndef _ALARM_H
#define _ALARM_H

#include "state.h"

#define GPIOA_ODR *(volatile uint32_t *)(GPIO_PORTA + 0x0C)

extern void (*PAlarmState)();

/*extern enum
{
	ALARM_ON,
	ALARM_OFF
}ALARM_STATE_ID;
*/
STATE_FUNC_DEFINE(ALARM_ON);
STATE_FUNC_DEFINE(ALARM_OFF);

void ALARM_Init();
void Set_Alarm_actuator(int i);

#endif /* _ALARM_H */