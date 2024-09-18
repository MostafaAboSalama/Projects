#ifndef _MAIN_ALGO_H
#define _MAIN_ALGO_H

#include "state.h"

extern void (*PMAIN_ALGO)();

/*extern enum
{
	MAIN_ALGO_WAITING,
	MAIN_ALGO_RUNNING,
};
*/
STATE_FUNC_DEFINE(MAIN_ALGO_WAITING);
STATE_FUNC_DEFINE(MAIN_ALGO_RUNNING);


#endif /* _MAIN_ALGO_H */