#ifndef _STATE_H
#define _STATE_H

#define STATE_FUNC_DEFINE(_STATE_FUNC_)	void ST_##_STATE_FUNC_()

#define STATE(_STATE_FUNC_)	 ST_##_STATE_FUNC_

void Set_Alarm_actuator(int i);

int getPressureVal();

void SetCarMainAlgoState(int p);

#endif /* _STATE_H */