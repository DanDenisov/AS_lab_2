#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void LedStateMachine(struct LedStateMachine* inst)
{
	if (state == DoorStates.ST_INIT)
	{
		inst->led1 = inst->led2 = inst->led3 = inst->led4 = 0;
	}
	else if (inst->state == DoorStates.ST_UNKNOWN)
	{
		if (count++ % 100 == 0)
			ledEnable = !ledEnable;
		
		inst->led1 = inst->led2 = inst->led3 = inst->led4 = ledEnable;
	}
	else if (inst->state == DoorStates.ST_OPEN)
	{
		inst->led1 = 0;
		inst->led2 = 0;
		inst->led3 = 0;
		inst->led4 = 0;
	}
	else if (inst->state == DoorStates.ST_CLOSE)
	{
		inst->led1 = 1;
		inst->led2 = 1;
		inst->led3 = 1;
		inst->led4 = 1;
	}
	else if (inst->state == DoorStates.ST_ACC_POS)
	{		
		inst->led1 = 0;
		inst->led2 = 0;
		if (count++ % (int)(1000 / (2 * 2 * 25)) == 0)  //25 Hz
			inst->led3 = !inst->led3;
		inst->led4 = 1;
	}
	else if (inst->state == DoorStates.ST_ACC_NEG)
	{
		if (inst->sw3)
		{
			inst->state = DoorStates.ST_NEG;
			inst->speed = -890;
		}
		else if (inst->direction == 1)
		{
			inst->state = DoorStates.ST_DEC_POS;
			inst->speed = 890 / 9;
		}
	}
	else if (inst->state == DoorStates.ST_POS)
	{
		if (inst->sw3)
		{
			inst->state = DoorStates.ST_DEC_POS;
			inst->speed = 890 / 9;
		}
		else if (inst->direction == 0)
		{
			inst->state = DoorStates.ST_NEG;
			inst->speed = -890;
		}
	}
	else if (inst->state == DoorStates.ST_NEG)
	{
		if (inst->sw2)
		{
			inst->state = DoorStates.ST_DEC_NEG;
			inst->speed = -890 / 9;
		}
		else if (inst->direction == 1)
		{
			inst->state = DoorStates.ST_POS;
			inst->speed = 890;
		}
	}
	else if (inst->state == DoorStates.ST_DEC_POS)
	{
		if (inst->sw4)
		{
			inst->state = DoorStates.ST_CLOSE;
			inst->speed = 0;
		}
		else if (inst->direction == 0)
		{
			inst->state = DoorStates.ST_ACC_NEG;
			inst->speed = -890 / 9;
		}
	}
	else if (inst->state == DoorStates.ST_DEC_NEG)
	{
		if (inst->sw1)
		{
			inst->state = DoorStates.ST_OPEN;
			inst->speed = 0;
		}
		else if (inst->direction == 1)
		{
			inst->state = DoorStates.ST_ACC_POS;
			inst->speed = 890 / 9;
		}
	}
}