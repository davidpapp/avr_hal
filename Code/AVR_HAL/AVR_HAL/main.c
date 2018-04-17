/*
 * AVR_HAL.c
 *
 * Created: 2018. 04. 17. 20:24:41
 * Author : David
 */ 

#include <avr/io.h>
#include "HAL/tim16.h"

int main(void)
{
	Tim16_1->ICR = 0x0000;
    /* Replace with your application code */
    while (1) 
    {
    }
}

