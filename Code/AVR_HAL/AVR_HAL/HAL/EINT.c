/*
 * EINT.c
 *
 * Created: 18/04/2018 15:34:19
 *  Author: David
 */
 
 #include <avr/io.h>
 #include <stddef.h>
 #include <avr/interrupt.h>
 #include "EINT.h"

 static void(*_cb)(uint8_t) = NULL;

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
	 volatile uint8_t *target_register = &EICRA;

	 if (ext_int > EINT_3)
	 {
		 target_register = &EICRB;
		 ext_int -= 4;
	 }

	 sense_type <<= 2 * ext_int;
	 uint8_t buffer = *target_register;
	 buffer &= ~(0x03 << 2 * ext_int);
	 *target_register = buffer | sense_type;
 }

 void EINT_set_callback(void(*cb)(uint8_t))
 {
	 _cb = cb;
 }

#ifndef _TestHarness

 ISR(INT0_vect)
 {
	 if (_cb != NULL)
	 {
		 _cb(0);
	 }
 }

 ISR(INT1_vect)
 {
	 if (_cb != NULL)
	 {
		 _cb(1);
	 }
 }

 ISR(INT2_vect)
 {
	 if (_cb != NULL)
	 {
		 _cb(2);
	 }
 }

 ISR(INT3_vect)
 {
	 if (_cb != NULL)
	 {
		 _cb(3);
	 }
 }

 ISR(INT4_vect)
 {
	 if (_cb != NULL)
	 {
		 _cb(4);
	 }
 }

 ISR(INT5_vect)
 {
	 if (_cb != NULL)
	 {
		 _cb(5);
	 }
 }

 ISR(INT6_vect)
 {
	 if (_cb != NULL)
	 {
		 _cb(6);
	 }
 }

 ISR(INT7_vect)
 {
	 if (_cb != NULL)
	 {
		 _cb(7);
	 }
 }

#endif // !_TestHarness