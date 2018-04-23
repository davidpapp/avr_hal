/*
 * tim.h
 *
 * Created: 2018. 04. 17. 20:31:04
 *  Author: David
 */ 


#ifndef TIM16_H_
#define TIM16_H_

#include <stdint.h>

typedef volatile struct
{
	uint8_t TCCRA;
	uint8_t TCCRB;
	uint8_t TCCRC;
	uint8_t Reserved;
	uint16_t TCNT;
	uint16_t ICR;
	uint16_t OCRA;
	uint16_t OCRB;
	uint16_t OCRC;
}TIM16_Control_t;

typedef volatile struct
{
	TIM16_Control_t *p_Control;
	uint8_t *p_TIMSK;
	uint8_t *p_TIFR;
}TIM16_t;

typedef enum
{
	WGM_NORMAL,
	WGM_PWM_PC_8,
	WGM_PWM_PC_9,
	WGM_PWM_PC_10,
	WGM_CTC_OCRA,
	WGM_FAST_PWM_8,
	WGM_FAST_PWM_9,
	WGM_FAST_PWM_10,
	WGM_PWM_PFC_ICR,
	WGM_PWM_PFC_OCRA,
	WGM_PWM_PC_ICR,
	WGM_PWM_PC_OCRA,
	WGM_CTC_ICR,
	WGM_RESERVED,
	WGM_FAST_PWM_ICR,
	WGM_FAST_PWM_OCRA
}TIM_WGM_t;

typedef enum
{
	COM_NORMAL,
	COM_TOGGLE,
	COM_CLEAR,
	COM_SET
}TIM_COM_t;

typedef enum
{
	CS_NO_CLK,
	CS_CLK_DIV1,
	CS_CLK_DIV8,
	CS_CLK_DIV64,
	CS_CLK_DIV256,
	CS_CLK_DIV1024,
	CS_EXT_FALLING,
	CS_EXT_RISING
}TIM_CS_t;

typedef enum
{
	OCR_A,
	OCR_B,
	OCR_C
}TIM_OCR_t;

void TIM16_set_wgm(TIM16_t* timer, TIM_WGM_t mode);
void TIM16_set_cs(TIM16_t* timer , TIM_CS_t clock_source);
void TIM16_set_com(TIM16_t* timer , TIM_OCR_t channel, TIM_COM_t out_mode);

#endif /* TIM16_H_ */