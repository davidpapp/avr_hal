/*
 * TIM8.h
 *
 * Created: 2018. 05. 12. 15:52:22
 *  Author: David
 */ 


#ifndef TIM8_H_
#define TIM8_H_

typedef volatile struct
{
	uint8_t TCCRA;
	uint8_t TCCRB;
	uint8_t TCNT;
	uint8_t OCRA;
	uint8_t OCRB;
}TIM8_Control_t;

typedef volatile struct
{
	TIM8_Control_t *p_Control;
	uint8_t *p_TIMSK;
	uint8_t *p_TIFR;
	void (*p_ovr_cb)();
	void (*p_compa_cb)();
	void (*p_compb_cb)();
}TIM8_t;

typedef enum
{
	TIM8_WGM_NORMAL,
	TIM8_WGM_PWM_PC_TOP,
	TIM8_WGM_CTC,
	TIM8_WGM_FAST_PWM_TOP,
	TIM8_WGM_RESERVED_1,
	TIM8_WGM_PWM_PC_OCRA,
	TIM8_WGM_RESERVED_2,
	TIM8_WGM_FAST_PWM_OCRA
}TIM8_WGM_t;

typedef enum
{
	TIM8_COM_NORMAL,
	TIM8_COM_TOGGLE,
	TIM8_COM_CLEAR,
	TIM8_COM_SET
}TIM8_COM_t;

typedef enum
{
	TIM8_CS_NO_CLK,
	TIM8_CS_CLK_DIV1,
	TIM8_CS_CLK_DIV8,
	TIM8_CS_CLK_DIV64,
	TIM8_CS_CLK_DIV256,
	TIM8_CS_CLK_DIV1024,
	TIM8_CS_EXT_FALLING,
	TIM8_CS_EXT_RISING
}TIM8_CS_t;

typedef enum
{
	TIM8_IRQ_OVERFLOW,
	TIM8_IRQ_OCR_A_MATCH,
	TIM8_IRQ_OCR_B_MATCH
}TIM8_IRQ_t;

typedef enum
{
	TIM8_OCR_A,
	TIM8_OCR_B
}TIM8_OCR_t;

void TIM8_set_wgm(TIM8_t* timer, TIM8_WGM_t mode);
void TIM8_set_cs(TIM8_t* timer , TIM8_CS_t clock_source);
void TIM8_set_com(TIM8_t* timer , TIM8_OCR_t channel, TIM8_COM_t out_mode);
void TIM8_enable_interrupt(TIM8_t* timer, TIM8_IRQ_t interrupt);
void TIM8_disable_interrupt(TIM8_t* timer, TIM8_IRQ_t interrupt);
void TIM8_set_interrupt_callback(TIM8_t* timer, TIM8_IRQ_t interrupt, void(*callback)(void));

#endif /* TIM8_H_ */