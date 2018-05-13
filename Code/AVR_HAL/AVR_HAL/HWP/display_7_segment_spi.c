/*
 * display_7_segment_spi.c
 *
 * Created: 2018. 05. 13. 12:24:25
 *  Author: David
 */ 

 #ifdef _YOLO


#include <stdint.h>
#include <math.h>
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
	_display_counter++;
	_SPI->SPI_SPDR = _display_buffer[_display_counter%4];
}

void spi_callback(void)
{
	GPIOF->PORT |= 0xFF;

	GPIOB->PORT &= 0xFE;
	GPIOB->PORT |= 0x01;
	GPIOB->PORT &= 0xFE;

	GPIOF->PORT &= ~(1 << (_display_counter%4));
}

void display_7_segment_create()
{
	GPIOB->DDR |= 0x07;
	GPIOF->DDR |= 0x0F;

	GPIOB->PORT |= 0x01;

	GPIOF->PORT |= 0xFF;
	GPIOF->PORT &= 0xFE;

	SPI_enable_interrupt(_SPI);
	SPI_set_data_order_MSB(_SPI);
	SPI_set_master(_SPI);
	SPI_set_mode(_SPI, SPI_MODE_SETUP_FALLING_SAMPLE_RISING);
	SPI_set_clock_rate(_SPI, SPI_SCK_CLK_DIV128);
	SPI_set_callback(spi_callback);
	SPI_enable(_SPI);

	TIM8_set_com(&_TIM8_0,TIM8_OCR_A,TIM8_COM_NORMAL);
	TIM8_set_com(&_TIM8_0,TIM8_OCR_B,TIM8_COM_NORMAL);
	TIM8_set_wgm(&_TIM8_0, TIM8_WGM_CTC);

	TIM8_set_interrupt_callback(&_TIM8_0, TIM8_IRQ_OCR_A_MATCH, character_update_callback);
	TIM8_enable_interrupt(&_TIM8_0, TIM8_IRQ_OCR_A_MATCH);

	_TIM8_0.p_Control->OCRA = 159;

	TIM8_set_cs(&_TIM8_0, TIM8_CS_CLK_DIV64);
}

void display_7_segment(float value, uint8_t no_of_decimals)
{
	  
	if (no_of_decimals > 3)
	{
		no_of_decimals = 3;
	}

	for (uint8_t decimal_counter =0; decimal_counter < no_of_decimals; decimal_counter++)
	{
		value *= 10.0;
	}

	value = roundf(value);
	value = fmodf(value, 10000.0);

	uint16_t integer_part = (uint16_t)value;

	for (uint8_t char_counter = 3; char_counter < 4; char_counter--)
	{
		_display_buffer[char_counter] = _digits[integer_part % 10];
		integer_part /= 10;
	}

	_display_buffer[3 - no_of_decimals] &= 0x7F;
}
#endif