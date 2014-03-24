/**
 * \file
 * \brief Real Time Operating System (RTOS) main program.
 * \author Erich Styger, erich.styger@hslu.ch
 */

#include "Platform.h"
#if PL_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "LED1.h"
#include "LED2.h"


void RTOS_Init(void) {
  /* \todo add tasks here */
}

void RTOS_Deinit(void) {
}

#endif /* PL_HAS_RTOS */
