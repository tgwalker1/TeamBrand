/*
 * Platform.h
 *
 *  Created on: Feb 25, 2014
 *      Author: tastyger
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "PE_Types.h" /* for common Processor Expert types used throughout the project, e.g. 'bool' */
#include "PE_Error.h" /* global error constants */
#include <stddef.h>   /* for NULL */

/* List of supported platforms. The PL_BOARD_IS_xxx is defined in the compiler command line settings.  */
#define PL_IS_SRB   (defined(PL_BOARD_IS_SRB))
  /*!< Macro is defined through compiler option for the SRB board */
#define PL_IS_FRDM  (defined(PL_BOARD_IS_FRDM))
  /*!< Macro is defined through compiler option for the FRDM board */


#define PL_HAS_LED   (1)

#if PL_IS_FRDM
  #define PL_NOF_LED 1  // 3
#elif PL_IS_SRB
  #define PL_NOF_LED 5
#else
  #error "unknown configuration?"
#endif

void PL_Init(void);
void PL_Deinit(void);

#endif /* PLATFORM_H_ */
