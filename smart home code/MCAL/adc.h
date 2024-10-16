
/*
 * adc.h
 *
 *  Created on: Oct 2, 2024
 *      Author: user
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
void ADC_init(void);
uint16 ADC_readChannel(uint8 ch_num);


#endif /* ADC_H_ */
