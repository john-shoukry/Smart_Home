/*
 * adc.c
 *
 *  Created on: Oct 2, 2024
 *      Author: user
 */
#include "gpio.h"
#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* For GET_BIT Macro */
#include "adc.h"
#include "avr/io.h" /* To use the IO Ports Registers */

void ADC_init(void)
{
	/* to choose the VREF
	 * internal 2.56V Voltage Refernce
	 */
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	/* ENABLE ADC */
	SET_BIT(ADCSRA,ADEN);
	/* CLOSE ADC INTERRUPT */
	CLEAR_BIT(ADCSRA,ADIE);
	/* ADJUST CLOCK PRESCALER */
	ADCSRA= ADCSRA | 0x07;	// prescaler 128
	/* CHOOSE WHICH SET OF BITS TO REPRESENT THE NUMBER */
	CLEAR_BIT(ADMUX,ADLAR);

}
uint16 ADC_readChannel(uint8 ch_num)
{
	/* CHOOSE WHICH CHANNEL USING THE FIRST 4 BITS */
	ADMUX=(ADMUX & ~(0x1F)) | ch_num;
	/* ENABLE CONVERSION */
	SET_BIT(ADCSRA,ADSC);
	/* WAIT UNTIL CONVERSION IS DONE*/
	while (GET_BIT(ADCSRA,ADIF) == 0);
	SET_BIT(ADCSRA,ADIF);
	return ADC;



}
