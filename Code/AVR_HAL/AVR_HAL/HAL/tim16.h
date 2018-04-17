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

typedef enum
{
	WGM_NORMAL,
	WGM_PWM_PC_8,
	WGM_PWM_PC_9,
	WGM_PWM_PC_10,
	WGM_CTC_OCR,
	WGM_FAST_PWM_8,
	WGM_FAST_PWM_9,
	WGM_FAST_PWM_10,
	WGM_PWM_PFC_ICR,
	WGM_PWM_PFC_OCRA,
	WGM_PWM_PC_ICR,
	WGM_PWM_PC_OCRA,
	WGM_CTC_ICR,
	WGM_FAST_PWM_ICR,
	WGM_FAST_PWM_OCR
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

#endif /* TIM16_H_ */