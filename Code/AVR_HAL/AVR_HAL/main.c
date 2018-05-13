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
#include "HWP/display_7_segment.h"

static uint8_t _number_of_decimals = 2;

void key_callback(uint8_t key)
{
	if (key == EXT_INT_3)
	{
		if (_number_of_decimals < 3)
		{
			_number_of_decimals++;
		}
	}
	else if (key == EXT_INT_2)
	{
		if (_number_of_decimals > 0)
		{
			_number_of_decimals--;
		}
		
	}
	display_7_segment(3.1415926, _number_of_decimals);
}

int main(void)
{
	
	key_create(key_callback);

	display_7_segment_create();

	sei();
	display_7_segment(3.1415926, _number_of_decimals);

    while (1) 
    {
		
    }
}

