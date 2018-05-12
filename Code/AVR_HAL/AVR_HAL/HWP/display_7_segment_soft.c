/*
 * display_7_segment.c
 *
 * Created: 2018. 05. 11. 15:01:45
 *  Author: David
 */ 

 #include <stdint.h>
 #include <avr/interrupt.h>
 #include "../HAL/ATMEGA2560_HAL.h"
 #include "../HAL/Gpio.h"
 #include "display_7_segment.h"

 static void transmit_byte_to_shit_register(uint8_t data);
 static void update_shiftregister_output();

 const uint8_t _digits[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};
 static uint8_t _display_buffer[4] = {0xFF, 0xFF,0xFF,0xFF};
 static uint8_t _display_counter = 0;

 void character_update_callback()
 {
	GPIOF->PORT |= 0xFF;
	
	transmit_byte_to_shit_register(_display_buffer[_display_counter%4]);
	update_shiftregister_output();

	GPIOF->PORT &= ~(1 << (_display_counter%4));
	_display_counter++;
 }

 void update_shiftregister_output()
 {
	GPIOB->PORT &= 0xFE;
	GPIOB->PORT |= 0x01;
	GPIOB->PORT &= 0xFE;
 }

 void transmit_bit(uint8_t is_high)
 {
	GPIOB->PORT &= 0xFD;

	if (is_high)
	{
		GPIOB->PORT |= 0x04;
	}
	else
	{
		GPIOB->PORT &= 0xFB;
	}
	

	GPIOB->PORT |= 0x02;
	GPIOB->PORT &= 0xFD;
 }

 void transmit_byte_to_shit_register(uint8_t data)
 {
	for (uint8_t bit = 0; bit < 8; bit++)
	{
		transmit_bit(data & 0x80);
		data <<= 1;
	}
 }

 void display_7_segment_create()
 {
	GPIOB->DDR |= 0x07;
	GPIOF->DDR |= 0x0F;

	GPIOB->PORT |= 0x01;

	GPIOF->PORT |= 0xFF;
	GPIOF->PORT &= 0xFE;

	TIM8_set_com(&_TIM8_0,TIM8_OCR_A,TIM8_COM_NORMAL);
	TIM8_set_com(&_TIM8_0,TIM8_OCR_B,TIM8_COM_NORMAL);
	TIM8_set_wgm(&_TIM8_0, TIM8_WGM_CTC);

	TIM8_set_interrupt_callback(&_TIM8_0, TIM8_IRQ_OCR_A_MATCH, character_update_callback);
	TIM8_enable_interrupt(&_TIM8_0, TIM8_IRQ_OCR_A_MATCH);

	_TIM8_0.p_Control->OCRA = 159;

	transmit_byte_to_shit_register(0xBB);
	update_shiftregister_output();

	TIM8_set_cs(&_TIM8_0, TIM8_CS_CLK_DIV64);
 }

 void display_7_segment(float value, uint8_t no_of_decimals)
 {
	if (no_of_decimals > 3)
	{
		no_of_decimals = 3;
	}
	uint16_t integer_part = (uint16_t)value;
	uint16_t divider = 1;
	for (uint8_t int_digits_counter = 3 - no_of_decimals; int_digits_counter < 4; int_digits_counter--)
	{

		_display_buffer[int_digits_counter] = _digits[(integer_part % (10 * divider) / divider)];
		divider *= 10;
	}

	_display_buffer[3 - no_of_decimals] &= 0x7F;

	uint16_t fraction_part = float_converter_get_fraction(value, no_of_decimals);
	divider = 1;
	for (uint8_t fraction_digits_counter = 0; fraction_digits_counter < no_of_decimals; fraction_digits_counter++)
	{

		_display_buffer[3-fraction_digits_counter] = _digits[(fraction_part % (10 * divider) / divider)];
		divider *= 10;
	}

	/*
	_display_buffer[0] = _digits[(integer_part % 10000 / 1000)];
	_display_buffer[1] = _digits[(integer_part % 1000 / 100)];
	_display_buffer[2] = _digits[(integer_part % 100 / 10)];
	_display_buffer[3] = _digits[(integer_part % 10)];
	*/
 }