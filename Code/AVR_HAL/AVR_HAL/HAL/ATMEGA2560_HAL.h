/*
 * ATMEGA2560_HAL.h
 *
 * Created: 2018. 04. 19. 22:23:00
 *  Author: David
 */ 


#ifndef ATMEGA2560_HAL_H_
#define ATMEGA2560_HAL_H_

#include "TIM16.h"

//volatile TIM16_t _TIM16_1 = { (TIM16_Control_t*) 0x80, (uint8_t*) 0x6F, (uint8_t*) 0x36};
//volatile TIM16_t _TIM16_3 = { (TIM16_Control_t*) 0x90, (uint8_t*) 0x71, (uint8_t*) 0x38};
//volatile TIM16_t _TIM16_4 = { (TIM16_Control_t*) 0xA0, (uint8_t*) 0x72, (uint8_t*) 0x39};
volatile TIM16_t _TIM16_5 = { (TIM16_Control_t*) 0x120, (uint8_t*) 0x73, (uint8_t*) 0x3A};


#endif /* ATMEGA2560_HAL_H_ */