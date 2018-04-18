/*
 * EINT.c
 *
 * Created: 18/04/2018 15:34:19
 *  Author: David
 */
 
 #include <stdint.h>
 #include <avr/io.h>
 #include "EINT.h"

 void EINT_enable(EINT_INT_t ext_int)
 {
	uint8_t buffer = EIMSK;
	buffer |= (1 << ext_int);
	EIMSK = buffer;
 }

 void EINT_disable(EINT_INT_t ext_int)
 {
	 uint8_t buffer = EIMSK;
	 buffer &= ~(1 << ext_int);
	 EIMSK = buffer;
 }

 void EINT_set_sense(EINT_INT_t ext_int, EINT_ISC_t sense_type)
 {
	volatile uint8_t* target_register = (&EICRA);
	
	if (ext_int > EINT_3)
	{
		target_register = (&EICRB);
	}

	uint8_t buffer = *target_register;
	buffer &= (0x03 << (ext_int/2) * 2);
	*target_register = buffer | sense_type;
 }