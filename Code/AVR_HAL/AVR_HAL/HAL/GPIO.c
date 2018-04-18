/*
 * GPIO.c
 *
 * Created: 18/04/2018 14:39:49
 *  Author: David
 */ 

 #include <stdint.h>
 #include "Gpio.h"

 void GPIO_set_input(GPIO_t *port, uint8_t pin_mask)
 {
	uint8_t buffer = port->DDR;
	port->DDR = buffer & ~pin_mask;
 }

 void GPIO_set_output(GPIO_t *port, uint8_t pin_mask)
 {
	uint8_t buffer = port->DDR;
	port->DDR = buffer | pin_mask;
 }

