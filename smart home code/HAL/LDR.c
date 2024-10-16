/*
 * LDR.c
 *
 *  Created on: Oct 7, 2024
 *      Author: user
 */
#include"LDR.h"
#include "adc.h"
#include "gpio.h"





// get the light intensity from the LDR
uint16 LDR_getLightIntensity(void)
{
    uint16 adcValue = 0;

    // Read the ADC value from the LDR sensor
    adcValue = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

    // Convert the ADC value to voltage
    float voltage = (adcValue * LDR_SENSOR_MAX_VOLT_VALUE) / 1023.0;

    // Convert voltage to light intensity percentage )
    uint16 lightIntensity = (uint16)((voltage / LDR_SENSOR_MAX_VOLT_VALUE) * LDR_SENSOR_MAX_LIGHT_INTENSITY);

    // Ensure the light intensity does not exceed 100%
    if (lightIntensity > LDR_SENSOR_MAX_LIGHT_INTENSITY)
    {
        lightIntensity = LDR_SENSOR_MAX_LIGHT_INTENSITY;
    }

    return lightIntensity; // Return the calculated light intensity
}

