
FUNCTION_BLOCK DoorStateMachine
	VAR_INPUT
		state : DoorStates;
		sw1 : BOOL;
		sw2 : BOOL;
		sw3 : BOOL;
		sw4 : BOOL;
		direction : BOOL;
	END_VAR
	VAR_OUTPUT
		speed : INT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK DriveStateMachine
	VAR_INPUT
		state : UINT;
		enable : BOOL;
	END_VAR
	VAR_OUTPUT
		command : UINT;
		speed : INT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LedStateMachine
	VAR_INPUT
		state : DoorStates;
	END_VAR
	VAR_OUTPUT
		led1 : BOOL;
		led2 : BOOL;
		led3 : BOOL;
		led4 : BOOL;
		timer : INT;
	END_VAR
END_FUNCTION_BLOCK
