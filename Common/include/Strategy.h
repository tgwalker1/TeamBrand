/**
 * \file
 * \brief Motor driver interface.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module a driver for up to two small DC motors.
 */

#ifndef STRATEGY_H_
#define STRATEGY_H_

#include "Platform.h"

#define WHITEEDGE 10 
#define SPEED_MAX 300
#define	SPEED_NORM 90

#define	DISTANCE_MIN 50

typedef enum
{
	STR_IDLE,
	STR_WAIT,
	STR_SEEK,
	STR_ONEDGE,
	STR_KAMIKAZE,
	STR_DRIVING,
	STR_OBSERVING
}STR_States_t;

void STR_Start(void);
void STR_StateMachine(void);
void STR_SetState(STR_States_t nextState);
STR_States_t STR_GetState(void);
void STR_Init(void);
void STR_Deinit(void);

#endif
