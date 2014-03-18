/*
 * Timer.c
 *
 *  Created on: Mar 11, 2014
 *      Author: Reto
 */

#include "platform.h"
#include "trigger.h"

/*! \brief Function called from timer interrupt every TMR_TICK_MS. */
void TMR_OnInterrupt(void){
	TRG_IncTick();
}

/*! \brief Timer driver initialization */
void TMR_Init(void){
	
}

/*! \brief Timer driver de-initialization */
void TMR_Deinit(void){
	
}
