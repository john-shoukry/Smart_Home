/*
 * Lm35_sensor.h
 *
 *  Created on: Oct 6, 2024
 *      Author: user
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"
#define LM35_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

uint8 LM35_GetTemperature(void);

#endif /* LM35_SENSOR_H_ */
