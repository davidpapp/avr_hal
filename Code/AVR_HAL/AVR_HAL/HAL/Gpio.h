/*
 * Gpio.h
 *
 * Created: 2018. 04. 17. 21:34:10
 *  Author: David
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

typedef struct
{
	volatile uint8_t PIN;
	volatile uint8_t DDR;
	volatile uint8_t PORT;
}GPIO_t;

#define GPIOA ((volatile GPIO_t*) 0x20)
#define GPIOB ((volatile GPIO_t*) 0x23)
#define GPIOC ((volatile GPIO_t*) 0x26)
#define GPIOD ((volatile GPIO_t*) 0x29)
#define GPIOE ((volatile GPIO_t*) 0x2C)
#define GPIOF ((volatile GPIO_t*) 0x2F)
#define GPIOG ((volatile GPIO_t*) 0x32)
#define GPIOH ((volatile GPIO_t*) 0x100)
#define GPIOJ ((volatile GPIO_t*) 0x103)
#define GPIOK ((volatile GPIO_t*) 0x106)
#define GPIOL ((volatile GPIO_t*) 0x109)

void GPIO_set_input(GPIO_t *port, uint8_t pin_mask);
void GPIO_set_output(GPIO_t *port, uint8_t pin_mask);

#endif /* GPIO_H_ */