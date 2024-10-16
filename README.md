Project Overview
This project implements a smart home automation system using an ATmega32 microcontroller. The system automatically controls lighting, adjusts fan speed based on room temperature, and triggers safety alerts in case of fire. Key components include an LM35 temperature sensor, LDR (Light Dependent Resistor), Flame sensor, PWM-controlled motor, and an LCD to provide real-time feedback on the environment and system status.

Features
1. Automatic Lighting Control
The system uses an LDR to monitor ambient light intensity and controls three LEDs accordingly:
Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON.
Intensity 16–50%: Red and Green LEDs turn ON.
Intensity 51–70%: Only the Red LED turns ON.
Intensity > 70%: All LEDs turn OFF.
2. Automatic Fan Speed Control
A PWM signal adjusts the fan speed based on room temperature measured by the LM35 sensor:
Temperature ≥ 40°C: Fan operates at 100% speed.
Temperature ≥ 35°C and < 40°C: Fan operates at 75% speed.
Temperature ≥ 30°C and < 35°C: Fan operates at 50% speed.
Temperature ≥ 25°C and < 30°C: Fan operates at 25% speed.
Temperature < 25°C: Fan is OFF.
3. Fire Detection and Alert
A flame sensor detects fire, triggers an alarm, and displays a "Critical alert!" message on the LCD.
The alert remains active until the flame is no longer detected.
4. LCD Display
Provides real-time feedback on system status:
First Row: Displays "FAN is ON" or "FAN is OFF" depending on the fan's state.
Second Row: Displays the current temperature and light intensity (Temp=xxC LDR=xxx%).
Components
ATmega32 Microcontroller: The brain of the system.
LM35 Temperature Sensor: Measures room temperature.
LDR (Light Dependent Resistor): Detects ambient light intensity.
Flame Sensor: Detects the presence of fire.
PWM-controlled Motor: Controls fan speed based on temperature.
H-Bridge Circuit: Drives the fan motor.
LCD Display: Provides real-time system status.
LEDs: Indicate different light intensity levels.
How It Works
Lighting Control: The LDR continuously measures the room's ambient light. Depending on predefined light intensity thresholds, the system activates different combinations of Red, Green, and Blue LEDs.

Fan Speed Control: The LM35 sensor reads the room temperature and the fan speed is adjusted proportionally using PWM control. The fan operates at different speeds depending on the temperature range.

Fire Detection: If the flame sensor detects a fire, an alarm is triggered and the LCD displays a "Critical alert!" message. The system continues to monitor the flame sensor and returns to normal operation once the fire is no longer detected.

LCD Feedback: The LCD shows real-time information on the temperature, fan status, and light intensity.
