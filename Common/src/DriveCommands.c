/**
 * \file
 * \brief DriveCommand Module
 * \author Reto Mueller, Andreas Walker
 *
 * Module contains a collection of User defined drive commands.
 */
#include "Platform.h"
#if PL_HAS_MOTOR
#include "DriveCommands.h" 
#include "Motor.h"

//This is a method to test the functionality of the motors. Can be deleted if not used.
void DCM_Motor_Test(MOT_SpeedPercent percent)
{
	MOT_MotorDevice 
	  MOT_SetDirection(MOT_GetMotorHandle(MOT_MOTOR_LEFT), MOT_DIR_FORWARD);
	  MOT_SetDirection(&motorR, MOT_DIR_BACKWARD);
	  MOT_SetSpeedPercent(&motorL, percent);
	  MOT_SetSpeedPercent(&motorR, percent);
	  MOT_SetDirection(&motorL, MOT_DIR_FORWARD);
	  MOT_SetDirection(&motorR, MOT_DIR_BACKWARD);
}




#endif /* PL_HAS_MOTOR */
