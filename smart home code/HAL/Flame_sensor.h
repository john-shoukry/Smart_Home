/*
 * Flame_sensor.h
 *
 *  Created on: Oct 7, 2024
 *      Author: user
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_
#include "std_types.h"


/*Initializes the flame sensor pin direction.*/
 void FlameSensor_init(void);
 /* Reads the value from the flame sensor and returns it.*/
 uint8 FlameSensor_getValue(void);



#endif /* FLAME_SENSOR_H_ */
