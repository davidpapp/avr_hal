/*
 * TIM8.c
 *
 * Created: 2018. 05. 12. 16:15:42
 *  Author: David
 */ 

#include <stddef.h>
#include <avr/interrupt.h>  
#include "tim8.h"

volatile  TIM8_t _TIM8_0 = { (TIM8_Control_t*) 0x44, (uint8_t*) 0x6E, (uint8_t*) 0x35, NULL, NULL, NULL};

  void TIM8_set_wgm(TIM8_t* timer, TIM8_WGM_t mode)
  {
	  if (mode == TIM8_WGM_RESERVED_1 || mode == TIM8_WGM_RESERVED_2)
	  {
		  mode = TIM8_WGM_NORMAL;
	  }
	  
	  uint8_t buf = timer->p_Control->TCCRA;
	  buf &= 0xFC;
	  timer->p_Control->TCCRA = buf | (mode & 0x3);
	  buf = timer->p_Control->TCCRB;
	  buf &= 0xF7;
	  timer->p_Control->TCCRB = buf | ((mode & 0xC) << 1);	  
  }

  void TIM8_set_cs(TIM8_t* timer, TIM8_CS_t clock_source)
  {
	  uint8_t buf = timer->p_Control->TCCRB;
	  buf &= 0xF8;
	  timer->p_Control->TCCRB = buf | clock_source;
  }

  void TIM8_set_com(TIM8_t* timer, TIM8_OCR_t channel, TIM8_COM_t out_mode)
  {
	  
	  uint8_t channel_offset = 4;
	  if (channel == TIM8_OCR_A)
	  {
		  channel_offset += 2;
	  }

	  uint8_t buf = timer->p_Control->TCCRA;
	  buf &= ~(0x03 << channel_offset);
	  timer->p_Control->TCCRA = buf | (out_mode << channel_offset);
  }

  void TIM8_enable_interrupt(TIM8_t* timer, TIM8_IRQ_t interrupt)
  {
	  *timer->p_TIMSK |= 0x01 << interrupt;
  }

  void TIM8_disable_interrupt(TIM8_t* timer, TIM8_IRQ_t interrupt)
  {
	  *timer->p_TIMSK &= ~(0x01 << interrupt);
  }

  void TIM8_set_interrupt_callback(TIM8_t* timer, TIM8_IRQ_t interrupt, void(*callback)(void))
  {
	  switch (interrupt)
	  {
	  case TIM8_IRQ_OVERFLOW:
		  timer->p_ovr_cb = callback;
		  break;
	  case TIM8_IRQ_OCR_A_MATCH:
		  timer->p_compa_cb = callback;
		  break;
	  case TIM8_IRQ_OCR_B_MATCH:
		  timer->p_compb_cb = callback;
		  break;
	  default:
		  break;
	  }
  }

#ifndef _TestHarness

  ISR(TIMER0_OVF_vect)
  {
	  if (_TIM8_0.p_ovr_cb != NULL)
	  {
		  _TIM8_0.p_ovr_cb();
	  }
  }

  ISR(TIMER0_COMPA_vect)
  {
	  if (_TIM8_0.p_compa_cb != NULL)
	  {
		  _TIM8_0.p_compa_cb();
	  }
  }

  ISR(TIMER0_COMPB_vect)
  {
	  if (_TIM8_0.p_compb_cb != NULL)
	  {
		  _TIM8_0.p_compb_cb();
	  }
  }

#endif // !_TestHarness
  