
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	
}

void _CYCLIC ProgramCyclic(void)
{	
	//state handling
	if (state == DoorStates.ST_INIT)
	{
		ledSM.led1 = 0;
		ledSM.led2 = 0;
		ledSM.led3 = 0;
		ledSM.led4 = 0;
		driveS
		
		state = DoorStates.ST_UNKNOWN;
	}
	else if (state == DoorStates.ST_UNKNOWN)
	{
		if (count++ % 10 == 0)
			ledEnable = !ledEnable;
		
		ledSM.led1 = ledSM.led2 = ledSM.led3 = ledSM.led4 = ledEnable;
		
		if (doorSM.sw1 && doorSM.direction == 0)
			state = DoorStates.ST_OPEN;
		else if (doorSM.sw4 && doorSM.direction == 1)
			state = DoorStates.ST_CLOSE;
	}
	else if (state == DoorStates.ST_OPEN)
	{
		ledSM.led1 = 0;
		ledSM.led2 = 0;
		ledSM.led3 = 0;
		ledSM.led4 = 0;
		
		if (doorSM.direction == 1)
			state = DoorStates.ST_ACC_POS;
	}
	else if (state == DoorStates.ST_CLOSE)
	{
		ledSM.led1 = 1;
		ledSM.led2 = 1;
		ledSM.led3 = 1;
		ledSM.led4 = 1;
		
		if (doorSM.direction == 0)
			state = DoorStates.ST_ACC_NEG;
	}
	else if (state == DoorStates.ST_ACC_POS)
	{
		ledSM.led1 = 0;
		ledSM.led2 = 0;
		ledSM.led3 = 0;
		ledSM.led4 = 1;
		
		if (doorSM.sw2)
			state = DoorStates.ST_POS;
		else if (doorSM.direction == 0)
			state = DoorStates.ST_DEC_NEG;
	}
	else if (state == DoorStates.ST_ACC_NEG)
	{
		ledSM.led1 = 0;
		ledSM.led2 = 1;
		ledSM.led3 = 1;
		ledSM.led4 = 1;
		
		if (doorSM.sw3)
			state = DoorStates.ST_NEG;
		else if (doorSM.direction == 1)
			state = DoorStates.ST_DEC_POS;
	}
	else if (state == DoorStates.ST_POS)
	{
		ledSM.led1 = 0;
		ledSM.led2 = 0;
		ledSM.led3 = 1;
		ledSM.led4 = 1;
		
		if (doorSM.sw3)
			state = DoorStates.ST_DEC_POS;
		else if (doorSM.direction == 0)
			state = DoorStates.ST_NEG;
	}
	else if (state == DoorStates.ST_NEG)
	{
		ledSM.led1 = 0;
		ledSM.led2 = 0;
		ledSM.led3 = 1;
		ledSM.led4 = 1;
		
		if (doorSM.sw2)
			state = DoorStates.ST_DEC_NEG;
		else if (doorSM.direction == 1)
			state = DoorStates.ST_POS;
	}
	else if (state == DoorStates.ST_DEC_POS)
	{
		ledSM.led1 = 0;
		ledSM.led2 = 1;
		ledSM.led3 = 1;
		ledSM.led4 = 1;
		
		if (doorSM.sw4)
			state = DoorStates.ST_CLOSE;
		else if (doorSM.direction == 0)
			state = DoorStates.ST_ACC_NEG;
	}
	else if (state == DoorStates.ST_DEC_NEG)
	{
		ledSM.led1 = 0;
		ledSM.led2 = 0;
		ledSM.led3 = 0;
		ledSM.led4 = 1;
		
		if (doorSM.sw1)
			state = DoorStates.ST_OPEN;
		else if (doorSM.direction == 1)
			state = DoorStates.ST_ACC_POS;
	}
}

void _EXIT ProgramExit(void)
{

}

