/*
 * AVR_HAL.c
 *
 * Created: 2018. 04. 17. 20:24:41
 * Author : David
 */ 

#include <avr/io.h>
#include "HAL/tim16.h"
#include "HAL/Gpio.h"

int main(void)
{
	GPIOL->DDR = 0xFF;

	Tim16_5->ICR = 0x9C3F;
	Tim16_5->OCRA = 0x0000;
	Tim16_5->OCRB = 0x0BB7;
	Tim16_5->OCRC = 0x0000;
	
	Tim16_5->TCCRC = 0x00;
	Tim16_5->TCCRB = 0b00011010;
	Tim16_5->TCCRA = 0b00110010;

	Tim16_5->TCCRA = 0x00;
	Tim16_5->OCRB = 0x00B7;
	Tim16_5->TCCRA = 0b00110010;

    /* Replace with your application code */
    while (1) 
    {
		
    }
}

