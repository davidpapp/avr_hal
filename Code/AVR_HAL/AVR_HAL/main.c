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
#include "HWP/rc_servo.h"
#include "HWP/key.h"

static int8_t _rc_servo_position = 0;

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

int main(void)
{
	key_create(key_callback);

	rc_servo_create();
	rc_servo(_rc_servo_position);

	sei();

    while (1) 
    {
		
    }
}

