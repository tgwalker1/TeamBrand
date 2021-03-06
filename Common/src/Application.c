/**
 * \file
 * \brief Main Application Module.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module is the main application module. 
 * From here the application runs and performs all tasks.
 */

#include "Platform.h"
#include "Application.h"
#include "Strategy.h"
#include "WAIT1.h"
#include "Q4CLeft.h"

#if PL_HAS_EVENTS
#include "Event.h"
#endif
#if PL_HAS_LED
#include "LED.h"
#endif
#if PL_HAS_KEYS
#include "Keys.h"
#endif
#if PL_HAS_BUZZER
#include "Buzzer.h"
#endif
#if PL_HAS_RTOS
#include "FRTOS1.h"
#include "RTOS.h"
#endif
#if PL_HAS_RTOS_TRACE
#include "RTOSTRC1.h"
#endif
#if PL_HAS_ACCEL
#include "Accel.h"
#endif
#if PL_HAS_ULTRASONIC
#include "Ultrasonic.h"
#endif

#if PL_HAS_LINE_SENSOR
#include "Reflectance.h"
#endif

#if PL_HAS_DRIVE
#include "Drive.h"
#endif

#if PL_HAS_STRATEGY
#include "Strategy.h"
#endif

static void APP_EvntHandler(EVNT_Handle event) {
	switch (event) {
	case EVNT_INIT:
		LED1_On();
		WAIT1_Waitms(100);
		LED1_Off();
		break;

#if PL_HAS_LED_HEARTBEAT
		case EVNT_LED_HEARTBEAT:
		LED3_Neg();
		break;
#endif
#if PL_NOF_KEYS>=1
	case EVNT_SW1_PRESSED:

		if (REF_IsCalibrated()) {
			STR_Start();
		}

		break;

	case EVNT_SW1_LPRESSED:
#if PL_HAS_LINE_SENSOR
		LED4_On();
		WAIT1_Waitms(500);
		EVNT_SetEvent(EVNT_REF_START_STOP_CALIBRATION);
		DRV_Drive_Forward(40);
		WAIT1_Waitms(300);
		DRV_Drive_Forward(-60);
		WAIT1_Waitms(200);
		DRV_Drive_Forward(0);
		EVNT_SetEvent(EVNT_REF_START_STOP_CALIBRATION);
		WAIT1_Waitms(500);
		if (REF_IsCalibrated()) {
			LED4_Off();
		}
		break;
		
#endif
		break;
#endif
#if PL_NOF_KEYS>=2
		case EVNT_SW2_PRESSED:
		LED2_Neg();
		break;
#endif
#if PL_NOF_KEYS>=3
		case EVNT_SW3_PRESSED:
		LED3_Neg();
		break;
#endif
#if PL_NOF_KEYS>=4
		case EVNT_SW4_PRESSED:
		LED4_Neg();
		break;
#endif

	default:
		break;
	}
}

#if PL_HAS_RTOS
static portTASK_FUNCTION(MainTask, pvParameters) {
	uint16_t msCnt;

	(void) pvParameters; /* parameter not used */
#if PL_HAS_ACCEL
  ACCEL_LowLevelInit();
#endif
	for (;;) {
		EVNT_HandleEvent(APP_EvntHandler);
#if PL_HAS_KEYS && !PL_HAS_KBI
		KEY_Scan(); /* poll keys */
#endif
		
		FRTOS1_vTaskDelay(20/portTICK_RATE_MS);
		msCnt += 20;
		if (msCnt > 280) {
			#if PL_HAS_ULTRASONIC
				(void)US_Measure_us(); /* Measure distance */

			#endif
			msCnt = 0;
			
	
		}
	}
}
#else
static void APP_Loop(void) {
	for(;;) {
		EVNT_HandleEvent(APP_EvntHandler);
#if PL_HAS_KEYS && !PL_HAS_KBI
		KEY_Scan(); /* poll keys */
#endif
	} /* for */
}
#endif

void APP_Run(void) {
#if PL_HAS_RTOS_TRACE
	if (!RTOSTRC1_uiTraceStart()) {
		for(;;) {} /* failed! */
	}
#endif
	EVNT_SetEvent(EVNT_INIT);
#if PL_HAS_RTOS
	if (FRTOS1_xTaskCreate(
			MainTask, /* pointer to the task */
			"Main", /* task name for kernel awareness debugging */
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
	FRTOS1_vTaskStartScheduler();
#else
	APP_Loop();
#endif
}
