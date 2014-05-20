/**
 * \file
 * \brief 
 * \author 
 *
 * 
 * 
 */

#include "Platform.h"
#include "Strategy.h"
#include "WAIT1.h"
#include "Drive.h"
#include "FRTOS1.h"
#include "Reflectance.h"
#include "Ultrasonic.h"
#if PL_HAS_LED
#include "LED.h"
#endif
#if PL_HAS_BUZZER
#include "Buzzer.h"
#endif




STR_States_t state;

STR_States_t STR_GetState(void)
{
	return state;
}
void STR_SetState(STR_States_t nextState)
{
	state = nextState;
}
void STR_StateMachine()
{
	switch(state)
	{
	case STR_IDLE :
		break;
	case STR_WAIT : 
		LED2_On();
		BUZ_Beep(400,500);
		WAIT1_Waitms(500);
		BUZ_Beep(400,500);
		WAIT1_Waitms(500);
		BUZ_Beep(600,500);
		DRV_Drive_Forward(SPEED_NORM);
		state = STR_SEEK;
		LED2_Off();
		break;
	case STR_SEEK :
		LED3_On();
		if(REF_CheckOnEdge())
		{
			LED4_On();
			DRV_Edge_Correction();
			LED4_Off();
		}
		LED3_Off();
		break;
	case STR_KAMIKAZE: 
		LED2_On();
		while(US_GetLastCentimeterValue()<DISTANCE_MIN)
		{
			DRV_Drive_Forward(SPEED_MAX);
		}
		DRV_Drive_Forward(SPEED_NORM);
		state = STR_SEEK;
		LED2_Off();
		break;
	case STR_SHUTDOWN : 
		break;
	}
	
}
#if PL_HAS_RTOS
static portTASK_FUNCTION(StrategyTask, pvParameters) {

	(void) pvParameters; /* parameter not used */
	for (;;) 
	{		
		STR_StateMachine();
		FRTOS1_vTaskDelay(10/portTICK_RATE_MS);
	
	}
}

void STR_Init(void) 
{
	state = STR_IDLE;
	
	if (FRTOS1_xTaskCreate(
			StrategyTask, /* pointer to the task */
			"Strategy", /* task name for kernel awareness debugging */
			configMINIMAL_STACK_SIZE, /* task stack size */
			(void*)NULL, /* optional task startup argument */
			tskIDLE_PRIORITY, /* initial priority */
			(xTaskHandle*)NULL /* optional task handle to create */
	) != pdPASS ) {
		/*lint -e527 */
		for (;;) {
		} /* error! probably out of memory */
		/*lint +e527 */
	}
}

void STR_Deinit(void) 
{
	
}

void STR_Start()
{
	state = STR_WAIT;
}

#endif