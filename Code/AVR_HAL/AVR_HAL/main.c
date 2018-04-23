/*
 * AVR_HAL.c
 *
 * Created: 2018. 04. 17. 20:24:41
 * Author : David
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "HAL/tim16.h"
#include "HAL/GPIO.h"
#include "HAL/EXT_INT.h"
#include "HAL/SPI.h"
#include "HWP/rc_servo.h"
#include "HWP/key.h"

const uint8_t _digits[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};

static int8_t _rc_servo_position = 0;
static volatile SPI_t *_spi = ((SPI_t*) 0x4C);
static uint8_t _display[4] = {0x00};
static uint8_t _display_position = 0;


void key_callback(uint8_t key)
{
	if (key == EXT_INT_2)
	{
		_rc_servo_position -= 10;
		if (_rc_servo_position < -100)
		{
			_rc_servo_position = -100;
		}
	}
	else if (key == EXT_INT_3)
	{
		_rc_servo_position += 10;
		if (_rc_servo_position > 100)
		{
			_rc_servo_position = 100;
		}
	}
	rc_servo(_rc_servo_position);
}

void spi_callback(void)
{
	GPIOF->PORT |= 0xFF;

	GPIOB->PORT |= 0x01;
	GPIOB->PORT &= 0xFE;
	GPIOF->PORT &= ~(1 << (_display_position%4));

	_display_position++;
	_spi->SPI_SPDR = _display[_display_position%4];

}

int main(void)
{
	_display[0] = _digits[11];
	_display[1] = _digits[0];
	_display[2] = _digits[0];
	_display[3] = _digits[11];

	key_create(key_callback);

	rc_servo_create();
	rc_servo(_rc_servo_position);

	
	GPIOB->DDR |= 0x07;
	GPIOF->DDR |= 0x0F;

	GPIOB->PORT |= 0x01;
	GPIOF->PORT |= 0xFF;
	GPIOF->PORT &= 0xFE;

	SPI_enable_interrupt(_spi);
	SPI_set_data_order_MSB(_spi);
	SPI_set_master(_spi);
	SPI_set_mode(_spi, SPI_MODE_SETUP_FALLING_SAMPLE_RISING);
	SPI_set_clock_rate(_spi, SPI_SCK_CLK_DIV128);
	SPI_set_callback(spi_callback);
	SPI_enable(_spi);
	
	sei();
	
	_spi->SPI_SPDR = _display[0xFF];

    while (1) 
    {
		
    }
}

