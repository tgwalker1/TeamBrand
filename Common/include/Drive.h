/**
 * \file
 * \brief Drive interface.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements a simple 'drive' task which is responsible to move the robot around.
 */

#ifndef DRIVE_H_
#define DRIVE_H_

#include "Platform.h"
#if PL_HAS_DRIVE

#if PL_HAS_SHELL
#include "CLS1.h"
/*!
 * \brief Shell command line parser.
 * \param[in] cmd Pointer to command string
 * \param[out] handled If command is handled by the parser
 * \param[in] io Std I/O handler of shell
 */

void DRV_Drive_Forward(int32_t speed);
void DRV_Drive_Circle(int32_t speed);

uint8_t DRV_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io);
#endif

/*! \brief Driver initialization */
void DRV_Init(void);

/*! \brief Driver de-initialization */
void DRV_Deinit(void);

#endif /* PL_HAS_DRIVE */

#endif /* DRIVE_H_ */
