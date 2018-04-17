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
	 timer->TCCRA = buf | (mode & 0x3);
	 buf = timer->TCCRB;
	 timer->TCCRB = buf | ((mode & 0xC) << 1);
 }