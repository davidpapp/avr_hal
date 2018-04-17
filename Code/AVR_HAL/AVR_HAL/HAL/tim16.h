/*
 * tim.h
 *
 * Created: 2018. 04. 17. 20:31:04
 *  Author: David
 */ 


#ifndef TIM16_H_
#define TIM16_H_

typedef struct
{
	volatile uint8_t TCCRA;
	volatile uint8_t TCCRB;
	volatile uint8_t TCCRC;
	volatile uint8_t Reserved;
	volatile uint16_t TCNT;
	volatile uint16_t ICR;
	volatile uint16_t OCRA;
	volatile uint16_t OCRB;
	volatile uint16_t OCRC;
}TIM16_t;

#define Tim16_1 ((volatile TIM16_t*) 0x80)
#define Tim16_3 ((volatile TIM16_t *) 0x90 )
#define Tim16_4 ((volatile TIM16_t*) 0xA0)
#define Tim16_5 ((volatile TIM16_t*) 0x120)

#endif /* TIM16_H_ */