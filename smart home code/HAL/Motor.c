/*
 * Motor.c
 *
 *  Created on: Oct 7, 2024
 *      Author: user
 */

#include"gpio.h"
#include"std_types.h"
#include"common_macros.h"
#include "Motor.h"
#include "PWM.h"
#include <avr/io.h>

/*Initializes the DC motor by setting the direction for the motor pins and stopping the motor at the beginning.*/
void DcMotor_Init(void)
{


	/* configure pin IN1 and IN2 as output pins */
	GPIO_setupPinDirection(MOTOR_PORT,MOTOR_IN1,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT,MOTOR_IN2,PIN_OUTPUT);
	/*STOP THE MOTOR AT THE BEGINNING */
	GPIO_writePin( MOTOR_PORT,MOTOR_IN1,MOTOR_OFF);
	GPIO_writePin( MOTOR_PORT,MOTOR_IN2,MOTOR_OFF);

}
/*
Controls the motor's state (Clockwise/Anti-Clockwise/Stop) and adjusts the speed based on the input duty cycle.
 Parameters:
 state: Enum or uint8 that indicates motor direction (CW, A-CW, Stop). passed
 speed: Motor speed in percentage (0 to 100%). pass to pwm
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
    // Set the PWM duty cycle for motor speed control
    PWM_Timer0_Start(speed); // Start PWM with the given speed

    // Set motor direction
    if (state == CW) {
        GPIO_writePin(MOTOR_PORT, MOTOR_IN1, MOTOR_ON);
        GPIO_writePin(MOTOR_PORT, MOTOR_IN2, MOTOR_OFF);
    } else if (state == A_CW) {
        GPIO_writePin(MOTOR_PORT, MOTOR_IN1, MOTOR_OFF);
        GPIO_writePin(MOTOR_PORT, MOTOR_IN2, MOTOR_ON);
    } else if (state == STOP) {
        GPIO_writePin(MOTOR_PORT, MOTOR_IN1, MOTOR_OFF);
        GPIO_writePin(MOTOR_PORT, MOTOR_IN2, MOTOR_OFF);
    }
}


