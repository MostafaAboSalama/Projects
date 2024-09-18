#include "MainAlgo.h"
#include "library.h"

void (*PMAIN_ALGO)();
static int MAIN_ALGO_ALARM_State = 0;
static int MAIN_ALGO_Pressure    = 0;
static int MAIN_ALGO_Threshold   = 20;

 enum
{
	MAIN_ALGO_WAITING,
	MAIN_ALGO_RUNNING,
}MAIN_ALGO_STATE_ID;


STATE_FUNC_DEFINE(MAIN_ALGO_WAITING)
{
	/* STATE NAME */
	MAIN_ALGO_STATE_ID = MAIN_ALGO_WAITING;
	//printf ("MAIN_ALGO_WAITING state : pressure=%d  ALARM_State=%d \n" ,MAIN_ALGO_Pressure, MAIN_ALGO_ALARM_State );
	
	/* ACTION */
	MAIN_ALGO_ALARM_State = 0; 				
	Set_Alarm_actuator(MAIN_ALGO_ALARM_State);
}

STATE_FUNC_DEFINE(MAIN_ALGO_RUNNING)
{
	/* STATE NAME */
	MAIN_ALGO_STATE_ID = MAIN_ALGO_RUNNING;
	//printf ("MAIN_ALGO_RUNNING state : pressure=%d  ALARM_State=%d \n" ,MAIN_ALGO_Pressure, MAIN_ALGO_ALARM_State );
	
	/* ACTION */
	MAIN_ALGO_ALARM_State = 1; 				
	Set_Alarm_actuator(MAIN_ALGO_ALARM_State);
}

void SetCarMainAlgoState(int p)
{
	MAIN_ALGO_Pressure = p;

	( MAIN_ALGO_Pressure <= MAIN_ALGO_Threshold ) ? (PMAIN_ALGO = STATE(MAIN_ALGO_WAITING)) : (PMAIN_ALGO = STATE(MAIN_ALGO_RUNNING));

	//printf ("PS ---------- pressure=%d ----------> CA\n" ,MAIN_ALGO_Pressure);

}

