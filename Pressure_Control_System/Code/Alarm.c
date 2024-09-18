#include "Alarm.h"
#include "library.h"

 enum
{
	ALARM_ON,
	ALARM_OFF
}ALARM_STATE_ID;

void (*PAlarmState)();
static int ALARM_State = 0;;

STATE_FUNC_DEFINE(ALARM_ON)
{
	ALARM_STATE_ID = ALARM_ON;
	PAlarmState = STATE(ALARM_OFF);
	//printf ("ALARM_ON state : State=%d \n",ALARM_State);
}

STATE_FUNC_DEFINE(ALARM_OFF)
{
	ALARM_STATE_ID = ALARM_OFF;
	//printf ("ALARM_OFF state : State=%d \n",ALARM_State);
}

void Set_Alarm_actuator(int i)
{
	ALARM_State = i;
	PAlarmState = STATE(ALARM_ON);
	if (i == 1)
		SET_BIT(GPIOA_ODR,13);
	else if (i == 0)
		RESET_BIT(GPIOA_ODR,13);
	
	//printf ("MA ---------- State=%d ----------> Alarm\n" ,ALARM_State);

}

void ALARM_Init()
{
	//printf("Alarm Init");
}