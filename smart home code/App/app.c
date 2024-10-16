#include "LED.h"
#include <util/delay.h>
#include "Buzzer.h"
#include "Lm35_sensor.h"
#include "PWM.h"
#include "adc.h"
#include "Motor.h"
#include "gpio.h"
#include "LDR.h"
#include "Flame_sensor.h"
#include "lcd.h" // Include the LCD header file

int main(void)
{
	uint8 temp;
	uint8 speed;
	uint16 intensity = 0;
	uint8 flameDetected;

	// Initialize peripherals
	ADC_init();
	LEDS_init();
	Buzzer_init();
	DcMotor_Init();
	FlameSensor_init(); // Initialize the flame sensor
	LCD_init(); // Initialize the LCD

	// Variable to keep track of fan status
	char *fan_mode = "FAN is OFF"; // Default fan status

	while (1)
	{
		// Read temperature from LM35 sensor
		temp = LM35_GetTemperature();

		// Control motor based on temperature
		if (temp >= 40)
		{
			speed = 255;
			DcMotor_Rotate(CW, speed);
			fan_mode = "FAN is ON ";
		}
		else if (temp >= 35)
		{
			speed = 192;
			DcMotor_Rotate(CW, speed);
			fan_mode = "FAN is ON ";
		}
		else if (temp >= 30)
		{
			speed = 128;
			DcMotor_Rotate(CW, speed);
			fan_mode = "FAN is ON ";
		}
		else if (temp >= 25)
		{
			speed = 64;
			DcMotor_Rotate(CW, speed);
			fan_mode = "FAN is ON ";
		}
		else // temp < 25
		{
			speed = 0;
			DcMotor_Rotate(STOP, speed);
			fan_mode = "FAN is OFF";
		}

		// Get light intensity from LDR
		intensity = LDR_getLightIntensity();

		// Control LEDs based on light intensity
		if (intensity <= 15)
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);
		}
		else if (intensity >= 16 && intensity <= 50)
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_off(BLUE_LED);
		}
		else if (intensity >= 51 && intensity <= 70)
		{
			LED_on(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
		}
		else // intensity >= 71
		{
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);
		}

		// Update the LCD display

		LCD_displayStringRowColumn(0, 0, fan_mode); // First Row: Fan status
		LCD_moveCursor(1, 0); // Move cursor to second row
		LCD_displayString("Temp="); // Display temperature label
		if(intensity >= 100)
		{
			LCD_intgerToString(temp); // Display temperature
		}
		else
		{
			LCD_intgerToString(temp); // Display temperature
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

		LCD_moveCursor(1, 7);
		LCD_displayString(" LDR="); // Light intensity label
		LCD_moveCursor(1, 12);
		if(intensity >= 100)
		{
			LCD_intgerToString(intensity); // Display light intensity
		}
		else
		{
			LCD_intgerToString(intensity); // Display light intensity
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');

		}
		LCD_moveCursor(1, 15);
		LCD_displayString("%"); // Percentage sign

		// Check the flame sensor output
		flameDetected = FlameSensor_getValue(); // Read the flame sensor value
		if (flameDetected == LOGIC_HIGH) // HIGH means flame detected
		{
			// Flame detected, activate buzzer and alert
			Buzzer_on();
			LCD_sendCommand(LCD_CLEAR_COMMAND);
			LCD_displayStringRowColumn(0, 0, "Critical alert!");
			while (flameDetected == LOGIC_HIGH) // Stay in alert mode until no flame is detected
			{
				flameDetected = FlameSensor_getValue();

			}

			Buzzer_off(); // Turn off buzzer when flame is no longer detected
			LCD_sendCommand(LCD_CLEAR_COMMAND);
		}
		else
		{
			Buzzer_off(); // Ensure buzzer is off if no flame is detected
		}



	}
}
