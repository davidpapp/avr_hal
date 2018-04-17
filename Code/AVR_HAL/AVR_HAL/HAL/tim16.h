/*
 * tim.h
 *
 * Created: 2018. 04. 17. 20:31:04
 *  Author: David
 */ 


#ifndef TIM16_H_
#define TIM16_H_

typedef volatile struct
{
	volatile TCCRA;
	volatile uint8_t TCCRB;
	volatile uint8_t TCCRC;
	volatile uint8_t Reserved;
	volatile uint16_t TCNT;
	volatile uint16_t ICR;
	volatile uint16_t OCRA;
	volatile uint16_t OCRB;
	volatile uint16_t OCRC;
}TIM16_t;



#endif /* TIM16_H_ */