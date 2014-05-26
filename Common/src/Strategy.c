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
#include "Accel.h"
#if PL_HAS_LED
#include "LED.h"
#endif
#if PL_HAS_BUZZER
#include "Buzzer.h"
#endif
#if PL_HAS_DRIVE
#include "Drive.h"
#endif

STR_States_t state;

STR_States_t STR_GetState(void) {
	return state;
}
void STR_SetState(STR_States_t nextState) {
	state = nextState;
}
void STR_StateMachine() {
#if PL_HAS_ACCEL
	int16_t x, y, z;
	bool isEnabled;
	uint8_t res;

	res = ACCEL_isEnabled(&isEnabled);
	if (res == ERR_OK && isEnabled) {
		ACCEL_GetValues(&x, &y, &z);
		if (z > 800) {
#if PL_HAS_DRIVE
			DRV_Drive_Forward(0);
			BUZ_Beep(800, 1000);
			state = STR_IDLE;
#endif
		}
	}
#endif

	switch (state) {
	case STR_IDLE:
		break;
	case STR_WAIT:
		LED2_On();
		BUZ_Beep(400, 500);
		WAIT1_Waitms(1000);
		BUZ_Beep(400, 500);
		WAIT1_Waitms(1000);
		BUZ_Beep(400, 500);
		WAIT1_Waitms(1000);
		BUZ_Beep(400, 500);
		WAIT1_Waitms(1000);
		BUZ_Beep(800, 500);
		DRV_Drive_Forward(SPEED_NORM);
		state = STR_SEEK;
		LED2_Off();
		break;
	case STR_SEEK:
		LED3_On();
		if(US_GetLastCentimeterValue()<DISTANCE_MIN)
		{
			state = STR_KAMIKAZE;
		}
		if (REF_CheckOnEdge()) 
		{
			DRV_Motor_Stop_Stop();
			state = STR_ONEDGE;
		}
		LED3_Off();
		break;
	case STR_ONEDGE:
		LED4_On();
		DRV_Edge_Correction();
		LED4_Off();
		break;
		
	case STR_KAMIKAZE:
		LED2_On();
		DRV_Drive_Forward(SPEED_MAX);
		while (US_GetLastCentimeterValue() < DISTANCE_MIN) {
			
		}
		DRV_Drive_Forward(SPEED_NORM);
		state = STR_SEEK;
		LED2_Off();
		break;
	case STR_DRIVING:
		break;
	case STR_OBSERVING:
		if(US_GetLastCentimeterValue()<DISTANCE_MIN)
		{
			DRV_Motor_Stop_Stop();
			state = STR_KAMIKAZE;
		}
		break;
	}

}
#if PL_HAS_RTOS
static portTASK_FUNCTION(StrategyTask, pvParameters) {

	(void) pvParameters; /* parameter not used */
	for (;;) {
		STR_StateMachine();
		FRTOS1_vTaskDelay(10/portTICK_RATE_MS);

	}
}

void STR_Init(void) {
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

void STR_Deinit(void) {

}

void STR_Start() {
	state = STR_WAIT;
}

#endif
