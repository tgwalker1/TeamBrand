/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Vectors.c
**     Project     : ProcessorExpert
**     Processor   : MC13213
**     Version     : Component 01.065, Driver 01.40, CPU db: 2.87.133
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-03-04, 11:28, # CodeGen: 4
**     Abstract    :
**         This component "MC13214" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
**     Settings    :
**
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Vectors.c                                                  
** @version 01.40
** @brief
**         This component "MC13214" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
*/         
/*!
**  @addtogroup Vectors_module Vectors module documentation
**  @{
*/         


#include "Cpu.h"
#include "LED1.h"
#include "LEDpin5.h"
#include "LED2.h"
#include "LEDpin1.h"
#include "LED3.h"
#include "LEDpin2.h"
#include "LED4.h"
#include "LEDpin3.h"
#include "LED5.h"
#include "LEDpin4.h"

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
static void (* near const _vect[])(void) @0xFFCC = { /* Interrupt vector table */
/*lint -restore Enable MISRA rule (1.1) checking. */
         Cpu_Interrupt,                /* Int.no. 25 Vrti (at FFCC)                  Unassigned */
         Cpu_Interrupt,                /* Int.no. 24 Viic1 (at FFCE)                 Unassigned */
         Cpu_Interrupt,                /* Int.no. 23 Vatd1 (at FFD0)                 Unassigned */
         Cpu_Interrupt,                /* Int.no. 22 Vkeyboard1 (at FFD2)            Unassigned */
         Cpu_Interrupt,                /* Int.no. 21 Vsci2tx (at FFD4)               Unassigned */
         Cpu_Interrupt,                /* Int.no. 20 Vsci2rx (at FFD6)               Unassigned */
         Cpu_Interrupt,                /* Int.no. 19 Vsci2err (at FFD8)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 18 Vsci1tx (at FFDA)               Unassigned */
         Cpu_Interrupt,                /* Int.no. 17 Vsci1rx (at FFDC)               Unassigned */
         Cpu_Interrupt,                /* Int.no. 16 Vsci1err (at FFDE)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 15 Vspi1 (at FFE0)                 Unassigned */
         Cpu_Interrupt,                /* Int.no. 14 Vtpm2ovf (at FFE2)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 13 Vtpm2ch4 (at FFE4)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 12 Vtpm2ch3 (at FFE6)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 11 Vtpm2ch2 (at FFE8)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 10 Vtpm2ch1 (at FFEA)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  9 Vtpm2ch0 (at FFEC)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  8 Vtpm1ovf (at FFEE)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  7 Vtpm1ch2 (at FFF0)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  6 Vtpm1ch1 (at FFF2)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  5 Vtpm1ch0 (at FFF4)              Unassigned */
         Cpu_VicgInterrupt,            /* Int.no.  4 Vicg (at FFF6)                  Used */
         Cpu_Interrupt,                /* Int.no.  3 Vlvd (at FFF8)                  Unassigned */
         Cpu_Interrupt,                /* Int.no.  2 Virq (at FFFA)                  Unassigned */
         Cpu_Interrupt,                /* Int.no.  1 Vswi (at FFFC)                  Unassigned */
         _EntryPoint                   /* Int.no.  0 Vreset (at FFFE)                Reset vector */
};
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/

