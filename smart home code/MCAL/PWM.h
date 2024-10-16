/*
 * PWM.h
 *
 *  Created on: Oct 7, 2024
 *      Author: user
 */

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"

/* Description

 Initializes Timer0 in PWM mode and sets the required duty cycle.
 Prescaler: F_CPU/1024
 Non-inverting mode
 The function configures OC0 as the output pin.
 Parameters:
 duty_cycle: Percentage (0 to 100%) representing the PWM duty cycle.
 *
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
