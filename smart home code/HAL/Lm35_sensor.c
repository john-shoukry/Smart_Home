/*
 * Lm35_sensor.c
 *
 *  Created on: Oct 6, 2024
 *      Author: user
 */

#include "gpio.h"
#include "Lm35_sensor.h"
#include "adc.h"


uint8 LM35_GetTemperature(void)
{
	uint8 temp_value = 0;

		uint16 adc_value = 0;

		/* Read ADC channel where the temperature sensor is connected */
		adc_value = ADC_readChannel(LM35_CHANNEL_ID);

		/* Calculate the temperature from the ADC value*/
		temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

		return temp_value;
}
