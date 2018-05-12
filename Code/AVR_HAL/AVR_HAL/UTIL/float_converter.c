/*
 * float_converter.c
 *
 * Created: 2018. 05. 11. 13:56:33
 *  Author: David
 */ 

#include <stdint.h>
#include <math.h>
#include "float_converter.h"

uint16_t float_converter_get_fraction(float value, uint8_t no_of_digits)
 {
	if (no_of_digits > 4)
	{
		no_of_digits = 4;
	}

	float fraction = fmodf(value, 1.0);

	if (fraction < 0)
	{
		fraction *= -1.0;
	}

	for (; no_of_digits > 0; no_of_digits--)
	{
		fraction *= 10;
	}

	if (fraction < 1.0)
	{
		return 0;
	}

	fraction = roundf(fraction);

	return (uint16_t) fraction;
 }