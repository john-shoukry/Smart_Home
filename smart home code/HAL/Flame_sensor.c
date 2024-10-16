/*
 * Flame_sensor.c
 *
 *  Created on: Oct 7, 2024
 *      Author: user
 */

#include"Flame_sensor.h"
#include "gpio.h"
#define FLAME_SENSOR_PORT PORTD_ID
#define FLAME_SENSOR_PIN  PIN2_ID
 void FlameSensor_init(void)
 {
	 GPIO_setupPinDirection(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN,PIN_INPUT);
 }
 uint8 FlameSensor_getValue(void)
 {
 return GPIO_readPin(FLAME_SENSOR_PORT, FLAME_SENSOR_PIN);
 }
