#include "PressureSensor.h"
#include "library.h"

enum
{
	PRESSURE_SENSOR_BUSY
}PRESSURE_SENSOR_STATE_ID;


void (*PPRESSURE_SENSOR_State)();
static int pressure = 0;
int PS_Get_Pressure_Random (int l , int r , int count);

int getPressureVal()
{
	return (GPIOA_IDR & 0xFF);
}

STATE_FUNC_DEFINE(PRESSURE_SENSOR_BUSY)
{
	PRESSURE_SENSOR_STATE_ID = PRESSURE_SENSOR_BUSY;
	
	pressure = getPressureVal(); //PS_Get_Pressure_Random (45 , 55 , 1); 
	
	//printf ("PRESSURE_SENSOR_BUSY state : Pressure=%d \n" ,pressure);
	
	SetCarMainAlgoState(pressure);
	
	PPRESSURE_SENSOR_State = STATE(PRESSURE_SENSOR_BUSY);
}


void PRESSURE_SENSOR_Init()
{
	//printf("PRESSURE_SENSOR Init");
}

/* For Testing */
/*int PS_Get_Pressure_Random (int l , int r , int count)
{
	// Generate one(count) random number in the range [l:r] 
	int i,rand_num;
	for (i=0 ; i<count ; i++)
	{
		rand_num = (rand() % (r - l + 1 )) + l ;
	}
	return rand_num;
}*/