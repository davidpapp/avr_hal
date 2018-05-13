/*
 * TIM8.c
 *
 * Created: 2018. 05. 12. 16:15:42
 *  Author: David
 */

 /*! 
 @file TIM8.c
 @brief Low level library to control the 8-bit timers of the ATMEGA2560
 @author David Papp
 @defgroup TIM8 8-bit timer driver
 @brief 8-bit timer functions
 */

#include <stddef.h>
#include <avr/interrupt.h>  
#include "tim8.h"

volatile  TIM8_t _TIM8_0 = { (TIM8_Control_t*) 0x44, (uint8_t*) 0x6E, (uint8_t*) 0x35, NULL, NULL, NULL};

	/*!
	@ingroup TIM8
	@brief Sets the waveform generation mode (WGM)
  
	@param[in] timer pointer to the timer that will be set
	@param[in] mode WGM mode

	@note Both TIM8_WGM_RESERVED_1 and TIM8_WGM_RESERVED_2 will be set as TIM8_WGM_NORMAL
	*/

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

	/*!
	@ingroup TIM8
	@brief Sets the clock source (CS)
  
	@param[in] timer pointer to the timer that will be set
	@param[in] clock_source clock source

	*/
  void TIM8_set_cs(TIM8_t* timer, TIM8_CS_t clock_source)
  {
	  uint8_t buf = timer->p_Control->TCCRB;
	  buf &= 0xF8;
	  timer->p_Control->TCCRB = buf | clock_source;
  }

	/*!
	@ingroup TIM8
	@brief Sets the compare match output mode (COM)
  
	@param[in] timer pointer to the timer that will be set
	@param[in] channel the compare output channel that will be set
	@param[in] out_mode compare match output mode 

	@note COM can mean different things according the used WGM, see datasheet 
	*/
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

	/*!
	@ingroup TIM8
	@brief Enable a timer interrupt
  
	@param[in] timer pointer to the timer that will be set
	@param[in] interrupt the interrupt will be enabled

	@note To the interrupt be called the global interrupt has to be enabled by calling sei()
	*/
  void TIM8_enable_interrupt(TIM8_t* timer, TIM8_IRQ_t interrupt)
  {
	  *timer->p_TIMSK |= 0x01 << interrupt;
  }

	/*!
	@ingroup TIM8
	@brief Disable a timer interrupt
  
	@param[in] timer pointer to the timer that will be set
	@param[in] interrupt the interrupt will be disabled

	@note To the interrupt be called the global interrupt has to be enabled by calling sei()
	*/
  void TIM8_disable_interrupt(TIM8_t* timer, TIM8_IRQ_t interrupt)
  {
	  *timer->p_TIMSK &= ~(0x01 << interrupt);
  }

	/*!
	@ingroup TIM8
	@brief Sets the callback of a timer interrupt
  
	@param[in] timer pointer to the timer that will be set
	@param[in] interrupt the interrupt will be enabled
	@param[in] callback pointer to the callback function

	@note To the interrupt be called the global interrupt has to be enabled by calling sei()
	*/
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
  