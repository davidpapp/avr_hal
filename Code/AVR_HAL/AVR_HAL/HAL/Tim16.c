/*
 * Tim16.c
 *
 * Created: 2018. 04. 17. 22:46:12
 *  Author: David
 */ 

 #include "tim16.h"

 void set_wgm(TIM16_t* timer, TIM_WGM_t mode)
 {
	 if (mode == WGM_RESERVED)
	 {
		 mode = WGM_NORMAL;
	 }

	 uint8_t buf = timer->TCCRA;
	 buf &= 0xFC;
	 timer->TCCRA = buf | (mode & 0x3);
	 buf = timer->TCCRB;
	 buf &= 0xE7;
	 timer->TCCRB = buf | ((mode & 0xC) << 1);
 }

 void set_cs(TIM16_t* timer , TIM_CS_t clock_source)
 {
	uint8_t buf = timer->TCCRB;
	buf &= 0xF8;
	timer->TCCRB = buf | clock_source;
 }

 void set_com(TIM16_t* timer , TIM_OCR_t channel , TIM_COM_t out_mode)
 {
	 uint8_t channel_offset = 8;
	 switch (channel)
	 {
	 case OCR_A:
		 channel_offset = 6;
		 break;
	 case OCR_B:
		 channel_offset = 4;
		 break;
	 case OCR_C:
		 channel_offset = 2;
		 break;
	 default:
		 break;
	 }

	 uint8_t buf = timer->TCCRA;
	 buf &= ~(0x03 << channel_offset);
	 timer->TCCRA = buf | (out_mode << channel_offset);
 }