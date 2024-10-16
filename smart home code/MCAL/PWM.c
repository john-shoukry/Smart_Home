/*
 * PWM.c
 *
 *  Created on: Oct 7, 2024
 *      Author: user
 */

#include"gpio.h"
#include"std_types.h"
#include"common_macros.h"
#include "PWM.h"
#include <avr/io.h>
/* Description

 Initializes Timer0 in PWM mode and sets the required duty cycle.
 Prescaler: F_CPU/1024
 Non-inverting mode
 The function configures OC0 as the output pin.
 Parameters:
 duty_cycle: Percentage (0 to 100%) representing the PWM duty cycle.
 *
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{

		TCNT0=0; // Set Timer Initial Value to 0
		OCR0=duty_cycle;  // Set Compare Value
		SET_BIT(DDRB,PB3);// Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

		/* Configure timer control register
			 * 1. Fast PWM mode FOC0=0
			 * 2. Fast PWM Mode WGM01=1 & WGM00=1
			 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
			 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
			 */
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,COM01);
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS02);


}
