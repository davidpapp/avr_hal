/*
 * rc_servo.c
 *
 * Created: 2018. 04. 18. 21:42:13
 *  Author: David
 */ 


 #include "../HAL/tim16.h"
 #include "../HAL/Gpio.h"
 #include <avr/io.h>
  #include <avr/interrupt.h>

 /*! 
 @file rc_servo.c
 @brief Library to control the rc servos.
 @author David Papp
 @defgroup rc_servo RC Servo driver
 @brief RC Servo functions
 */

 /*!
  @ingroup rc_servo
  @brief Constructor function for rc_servo driver.
  
  Initialize the pin PL4 as output and sets the TIMER5 with 20ms period.
  It sets the OCRB as output with 1.5 ms.
  
  @note Must be called once before the rc_servo functions must be used!
 */
 void rc_servo_create()
{
	Tim16_5->ICR = 0x9C3F;
	Tim16_5->OCRA = 0x0000;
	Tim16_5->OCRB = 0x0BB7;
	Tim16_5->OCRC = 0x0000;

	TIM16_set_com(Tim16_5, OCR_A, COM_NORMAL);
	TIM16_set_com(Tim16_5, OCR_B, COM_CLEAR);
	TIM16_set_com(Tim16_5, OCR_C, COM_NORMAL);

	TIM16_set_wgm(Tim16_5,WGM_FAST_PWM_ICR);
	TIM16_set_cs(Tim16_5, CS_CLK_DIV8);
	
	GPIOL->DDR |= 0x10;
}

/*!
  @ingroup rc_servo
  @brief Sets the servo to a position.
  
  Percentage translates the following way:
	-100 -> 1ms pulse
	0 -> 1.5ms pulse
	100 -> 2ms pulse
   
   Values of <-100 and >100 are ignored.
  
  @param[in] percent position percentage
 */
void rc_servo(int8_t percent)
{
	if (percent < 101 && percent > -101)
	{
		int16_t period = percent;
		period += 100;
		period *= 10;
		period += 0x7CF;
		
		volatile uint8_t sreg_buffer = _SFR_IO8(0x3F);
		cli();
		Tim16_5->OCRB = (uint16_t)period;
		_SFR_IO8(0x3F) = sreg_buffer;
	}
}