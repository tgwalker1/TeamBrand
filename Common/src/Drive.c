 /**
 * \file
 * \brief Drive interface.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements a simple 'drive' task which is responsible to move the robot around.
 */
#include "Platform.h"
#if PL_HAS_DRIVE
#include "FRTOS1.h"
#include "Pid.h"
#include "Tacho.h"
#include "Reflectance.h"
#include "Drive.h"
#include "WAIT1.h"
#include "Trigger.h"
#include "Strategy.h"
#if PL_HAS_BUZZER
#include "Buzzer.h"
#endif
#include  "Q4CLeft.h"

static bool DRV_SpeedOn = FALSE;
static int32_t DRV_SpeedLeft, DRV_SpeedRight;

static portTASK_FUNCTION(DriveTask, pvParameters) {
  (void)pvParameters; /* parameter not used */
  for(;;) {
    /*! \todo extend this for your own needs and with a position PID */
    TACHO_CalcSpeed();
    if (DRV_SpeedOn) {
      PID_Speed(TACHO_GetSpeed(TRUE), DRV_SpeedLeft, TRUE); /* left */
      PID_Speed(TACHO_GetSpeed(FALSE), DRV_SpeedRight, FALSE); /* right */
    }
    FRTOS1_vTaskDelay(10/portTICK_RATE_MS);
  } /* for */
}
void DRV_Motor_Stop(void *dataPtr)
{
	DRV_SpeedLeft = 0;
	DRV_SpeedRight = 0;
}
void DRV_Edge_Correction(void)
{
	uint16_t value;
//	value = REF_GetLinePos();
	
	DRV_Drive_Forward(-SPEED_NORM);
	TRG_SetTrigger(TRG_MOT_STOP,200/TMR_TICK_MS,DRV_Motor_Stop,NULL);
	DRV_Drive_Circle(-SPEED_NORM);
	TRG_SetTrigger(TRG_MOT_STOP,200/TMR_TICK_MS,DRV_Motor_Stop,NULL);
//	if(value<2000)
//	{
//		BUZ_Beep(300,500);
//		DRV_Drive_Circle_Tick(SPEED_NORM,24);
//		
//	}
//	else if(value>4000)
//	{
//		BUZ_Beep(500,500);
//		DRV_Drive_Circle_Tick(-SPEED_NORM,24);
//
//	}
//	else
//	{
//		BUZ_Beep(700,500);
//		DRV_Drive_Circle_Tick(-SPEED_NORM,48);
//
//	}
	DRV_Drive_Forward(SPEED_NORM);
}
void DRV_Drive_Forward(int32_t speed)
{
	DRV_SpeedLeft = speed;
	DRV_SpeedRight = speed;
	
}

void DRV_Drive_Forward_Tick(int32_t speed, word ticks)
{
	word ticks_Start;
	ticks_Start = Q4CLeft_GetPos()+20000;
	DRV_SpeedLeft = speed;
	DRV_SpeedRight = speed;
	if(DRV_SpeedLeft>0)
	{
		while(((Q4CLeft_GetPos()+20000) < (ticks_Start+ticks)))
		{
			FRTOS1_vTaskDelay(100/portTICK_RATE_MS);
		}
		DRV_Motor_Stop(NULL);
	}
	else
	{
		while(((Q4CLeft_GetPos()+20000) > (ticks_Start-ticks)))
		{
			FRTOS1_vTaskDelay(100/portTICK_RATE_MS);
		}
		DRV_Motor_Stop(NULL);
	}


}
void DRV_Drive_Circle(int32_t speed)
{
	DRV_SpeedLeft = -speed;
	DRV_SpeedRight = speed;

}

void DRV_Drive_Circle_Tick(int32_t speed, word ticks)
{
	DRV_SpeedLeft = speed;
	DRV_SpeedRight = -speed;
	word ticks_Start;
	ticks_Start = Q4CLeft_GetPos()+20000;
	if(DRV_SpeedLeft>0)
	{
		while(((Q4CLeft_GetPos()+20000) < (ticks_Start+ticks)))
		{
			FRTOS1_vTaskDelay(10/portTICK_RATE_MS);
		}
		DRV_Motor_Stop(NULL);
	}
	else
	{
		while(((Q4CLeft_GetPos()+20000) > (ticks_Start-ticks)))
		{
			FRTOS1_vTaskDelay(10/portTICK_RATE_MS);
		}
		DRV_Motor_Stop(NULL);
	}
}

#if PL_HAS_SHELL
static void DRV_PrintStatus(const CLS1_StdIOType *io) {
  uint8_t buf[32];
  
  CLS1_SendStatusStr((unsigned char*)"drive", (unsigned char*)"\r\n", io->stdOut);
  CLS1_SendStatusStr((unsigned char*)"  speed", DRV_SpeedOn?(unsigned char*)"on\r\n":(unsigned char*)"off\r\n", io->stdOut);
  buf[0]='\0';
  UTIL1_strcatNum32s(buf, sizeof(buf), DRV_SpeedLeft);
  UTIL1_strcat(buf, sizeof(buf), (unsigned char*)"\r\n");
  CLS1_SendStatusStr((unsigned char*)"  speed L", buf, io->stdOut);
  buf[0]='\0';
  UTIL1_strcatNum32s(buf, sizeof(buf), DRV_SpeedRight);
  UTIL1_strcat(buf, sizeof(buf), (unsigned char*)"\r\n");
  CLS1_SendStatusStr((unsigned char*)"  speed R", buf, io->stdOut);
}

static void DRV_PrintHelp(const CLS1_StdIOType *io) {
  CLS1_SendHelpStr((unsigned char*)"drive", (unsigned char*)"Group of drive commands\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  help|status", (unsigned char*)"Shows help or status\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  speed (on|off)", (unsigned char*)"Turns speed pid on or ff\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  speed (L|R) <value>", (unsigned char*)"Sets speed value\r\n", io->stdOut);
}

uint8_t DRV_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io) {
  uint8_t res = ERR_OK;
  const uint8_t *p;
  int32_t val32;

  if (UTIL1_strcmp((char*)cmd, (char*)CLS1_CMD_HELP)==0 || UTIL1_strcmp((char*)cmd, (char*)"drive help")==0) {
    DRV_PrintHelp(io);
    *handled = TRUE;
  } else if (UTIL1_strcmp((char*)cmd, (char*)CLS1_CMD_STATUS)==0 || UTIL1_strcmp((char*)cmd, (char*)"drive status")==0) {
    DRV_PrintStatus(io);
    *handled = TRUE;
  } else if (UTIL1_strncmp((char*)cmd, (char*)"drive speed L", sizeof("drive speed L")-1)==0) {
    p = cmd+sizeof("drive speed L");
    if (UTIL1_ScanDecimal32sNumber(&p, &val32)==ERR_OK) {
      DRV_SpeedLeft = val32;
      *handled = TRUE;
    } else {
      res = ERR_FAILED;
    }
  } else if (UTIL1_strncmp((char*)cmd, (char*)"drive speed R", sizeof("drive speed R")-1)==0) {
    p = cmd+sizeof("drive speed R");
    if (UTIL1_ScanDecimal32sNumber(&p, &val32)==ERR_OK) {
      DRV_SpeedRight = val32;
      *handled = TRUE;
    } else {
      res = ERR_FAILED;
    }
  } else if (UTIL1_strcmp((char*)cmd, (char*)"drive speed on")==0) {
    DRV_SpeedOn = TRUE;
    *handled = TRUE;
  } else if (UTIL1_strcmp((char*)cmd, (char*)"drive speed off")==0) {
    DRV_SpeedOn = FALSE;
    *handled = TRUE;
  }
  return res;
}
#endif /* PL_HAS_SHELL */

void DRV_Deinit(void) {
   /* nothing needed */
}

void DRV_Init(void) {
  DRV_SpeedOn = TRUE;
  DRV_SpeedLeft = 0;
  DRV_SpeedRight = 0;
  if (FRTOS1_xTaskCreate(
        DriveTask,  /* pointer to the task */
        "Drive", /* task name for kernel awareness debugging */
        configMINIMAL_STACK_SIZE, /* task stack size */
        (void*)NULL, /* optional task startup argument */
        tskIDLE_PRIORITY,  /* initial priority */
        (xTaskHandle*)NULL /* optional task handle to create */
      ) != pdPASS) {
    /*lint -e527 */
    for(;;){} /* error! probably out of memory */
    /*lint +e527 */
  }
}

#endif /* PL_HAS_DRIVE */
