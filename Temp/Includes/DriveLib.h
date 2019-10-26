/* Automation Studio generated header file */
/* Do not edit ! */
/* DriveLib  */

#ifndef _DRIVELIB_
#define _DRIVELIB_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define maxSpeed 890
 #define minSpeed 89
 #define maxFreq 10U
 #define cycleTime 2U
#else
 _GLOBAL_CONST signed short maxSpeed;
 _GLOBAL_CONST signed short minSpeed;
 _GLOBAL_CONST unsigned char maxFreq;
 _GLOBAL_CONST unsigned char cycleTime;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum DoorStates
{	ST_INIT,
	ST_UNKNOWN,
	ST_OPEN,
	ST_CLOSE,
	ST_ACC_POS,
	ST_ACC_NEG,
	ST_POS,
	ST_NEG,
	ST_DEC_POS,
	ST_DEC_NEG
} DoorStates;

typedef enum DriveStates
{	ST_DISABLED = 64,
	ST_SWITCHED_ON = 35,
	ST_READY = 33
} DriveStates;

typedef enum DriveCommands
{	CMD_ENABLE = 15,
	CMD_SWITCH_ON = 7,
	CMD_SHUTDOWN = 6
} DriveCommands;

typedef struct DoorStateMachine
{
	/* VAR_INPUT (analog) */
	enum DoorStates state;
	/* VAR_OUTPUT (analog) */
	signed short speed;
	/* VAR_INPUT (digital) */
	plcbit direction;
	plcbit sw[4];
	/* VAR (digital) */
	plcbit sw_prev[4];
	plcbit sw_pressed[4];
} DoorStateMachine_typ;

typedef struct DriveStateMachine
{
	/* VAR_INPUT (analog) */
	unsigned short state;
	signed short speed;
	/* VAR_OUTPUT (analog) */
	unsigned short command;
	signed short speedFeedback;
	/* VAR_INPUT (digital) */
	plcbit enable;
} DriveStateMachine_typ;

typedef struct LedStateMachine
{
	/* VAR_INPUT (analog) */
	enum DoorStates state;
	signed short speed;
	/* VAR (analog) */
	unsigned short count;
	/* VAR_OUTPUT (digital) */
	plcbit led[4];
} LedStateMachine_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void DoorStateMachine(struct DoorStateMachine* inst);
_BUR_PUBLIC void DriveStateMachine(struct DriveStateMachine* inst);
_BUR_PUBLIC void LedStateMachine(struct LedStateMachine* inst);
_BUR_PUBLIC unsigned char SpeedToFreq(signed short speed);


#ifdef __cplusplus
};
#endif
#endif /* _DRIVELIB_ */

