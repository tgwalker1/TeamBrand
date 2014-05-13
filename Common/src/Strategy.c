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
#if PL_HAS_LED
#include "LED.h"
#endif

typedef enum
{
	STR_IDLE,
	STR_WAIT,
	STR_SEEK,
	STR_KAMIKAZE,
	STR_SHUTDOWN //Wenner auf dem Rücken liegt
}STR_States_t;

STR_States_t state;

void STR_StateMachine()
{
	switch(state)
	{
	case STR_IDLE :
		break;
	case STR_WAIT : 
		LED2_On();
		WAIT1_Waitms(1000);
		state = STR_SEEK;
		LED2_Off();
		break;
	case STR_SEEK :
		LED3_On();
		DRV_Drive_Circle(120);
		LED3_Off();
		break;
	case STR_KAMIKAZE: 
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
