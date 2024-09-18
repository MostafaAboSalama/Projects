#include "library.h"
#include "state.h"
#include "PressureSensor.h"
#include "Alarm.h"
#include "GPIO.h"
#include "MainAlgo.h"

void Delay(int nCount)
{
	for(; nCount != 0; nCount--);
}

void Setup()
{
	GPIO_INITIALIZATION();
	PRESSURE_SENSOR_Init();
	ALARM_Init();
	PAlarmState = STATE(ALARM_OFF);
	PPRESSURE_SENSOR_State = STATE(PRESSURE_SENSOR_BUSY);	
	PMAIN_ALGO = STATE(MAIN_ALGO_WAITING);
}

int main ()
{
	Setup();
	
	while (1)
	{
		PAlarmState();
		PPRESSURE_SENSOR_State();
        PMAIN_ALGO(); 
		Delay(1000);
	}
}
