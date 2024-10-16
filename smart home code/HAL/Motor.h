/*
 * Motor.h
 *
 *  Created on: Oct 7, 2024
 *      Author: user
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"
#define MOTOR_PORT	PORTB_ID
#define MOTOR_IN1	PIN0_ID
#define MOTOR_IN2	PIN1_ID
#define MOTOR_EN	PIN3_ID
#define MOTOR_OFF	0
#define MOTOR_ON	1
typedef enum
{
	CW=1,A_CW,STOP
}DcMotor_State;
/*Initializes the DC motor by setting the direction for the motor pins and stopping the motor at the beginning.*/
void DcMotor_Init(void);

/*
o Controls the motor's state (Clockwise/Anti-Clockwise/Stop) and adjusts the speed based
on the input duty cycle.
o Parameters:
▪ state: Enum or uint8 that indicates motor direction (CW, A-CW, Stop). passed
▪ speed: Motor speed in percentage (0 to 100%). pass to pwm
*/
void DcMotor_Rotate(DcMotor_State state, uint8 speed);


#endif /* MOTOR_H_ */
