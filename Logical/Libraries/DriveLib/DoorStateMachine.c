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
void DoorStateMachine(struct DoorStateMachine* inst)
{
	if (state == DoorStates.ST_INIT)
	{
		inst->state = DoorStates.ST_UNKNOWN;
		inst->speed = 890;
	}
	else if (inst->state == DoorStates.ST_UNKNOWN)
	{
		if (inst->sw1 && inst->direction == 0)
		{
			inst->state = DoorStates.ST_OPEN;
			inst->speed = 0;
		}
		else if (inst->sw4 && inst->direction == 1)
		{
			inst->state = DoorStates.ST_CLOSE;
			inst->speed = 0;
		}
	}
	else if (inst->state == DoorStates.ST_OPEN)
	{
		if (inst->direction == 1)
		{
			inst->state = DoorStates.ST_ACC_POS;
			inst->speed = 890 / 9;
		}
	}
	else if (inst->state == DoorStates.ST_CLOSE)
	{
		if (inst->direction == 0)
		{
			inst->state = DoorStates.ST_ACC_NEG;
			inst->speed = -890 / 9;
		}
	}
	else if (inst->state == DoorStates.ST_ACC_POS)
	{
		if (inst->sw2)
		{
			inst->state = DoorStates.ST_POS;
			inst->speed = 890;
		}
		else if (inst->direction == 0)
		{
			inst->state = DoorStates.ST_DEC_NEG;
			inst->speed = -890 / 9;
		}
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