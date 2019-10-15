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
void DriveStateMachine(struct DriveStateMachine* inst)
{
//	if (inst->state == DISABLED)
//	{
//		if (inst->enable == 1 && inst->state & 0x6F == STATE_SWITCHED_ON)
//		{
//			inst->state = STATE_SWITCHED_ON;
//			inst->command = CMD_SWITCHED_ON;
//		}
//	}
//	else if (inst->state == STATE_SWITCHED_ON)
//	{
//		if (inst->enable == 0)
//		{
//			inst->state = DISABLED;
//			inst->command = CMD_SHUTDOWN;
//		}
//		else if (inst->enable == 1 && inst->state & 0x6F == STATE_READY)
//		{
//			inst->state = STATE_READY;
//			inst->command = CMD_ENABLE;
//		}
//	}
//	else if (inst->state == STATE_READY)
//	{
//		if (inst->enable == 0)
//		{
//			inst->state = DISABLED;
//			inst->command = CMD_SHUTDOWN;
//		}
//	}
}