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

	set_com(Tim16_5, OCR_A, COM_NORMAL);
	set_com(Tim16_5, OCR_B, COM_SET);
	set_com(Tim16_5, OCR_C, COM_NORMAL);

	set_wgm(Tim16_5,WGM_FAST_PWM_ICR);
	set_cs(Tim16_5, CS_CLK_DIV8);

    /* Replace with your application code */
    while (1) 
    {
		
    }
}

