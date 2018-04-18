/*
 * key.c
 *
 * Created: 2018. 04. 18. 22:14:03
 *  Author: David
 */ 

 /*! 
 @file key.c
 @brief Library to control the keys on the arduino shield.
 @author David Papp
 @defgroup keys Keys driver
 @brief Key functions
 */

 #include "../HAL/EINT.h"
 #include "../HAL/Gpio.h"
 #include "key.h"

 /*!
  @ingroup keys
  @brief Constructor function for keys driver.
  
  Sets up the PC0-5 pins as simple inputs and the PD2-3 pins as
	external interrupts.
  
  @param[in] cb function pointer to the interrupt callback function

  @note Must be called once before the keys functions must be used!
  @note To use the interrupts sei() must be called after this function!
 */
 void key_create(void (*cb)(uint8_t))
 {
	GPIOD->DDR &= 0xF3;
	GPIOD->PORT |= 0x0C;

	GPIOC->DDR &= 0x3F;
	GPIOD->PORT |= 0xC0;

	EINT_set_sense(EINT_2, ISC_RISING);
	EINT_set_sense(EINT_3, ISC_RISING);
	EINT_set_callback(cb);
	EINT_enable(EINT_2);
	EINT_enable(EINT_3);
 }

 /*!
  @ingroup keys
  @brief Reads the state of a key
  
  Reads the pin input registers and returns the state of the pin.
  
  @param[in] key_no number of the key

  @return gpio_state_t
  @retval GPIO_OFF Key is not pressed
  @retval GPIO_ON Key is pressed
  @retval GPIO_UNKNOWN State is unknown, may indicate error
 */
 gpio_state_t key_get_key(uint8_t key_no)
 {
	 if (KEY_MAX_KEY_NO < key_no)
	 {
		 return GPIO_UNKNOWN;
	 }

	 uint8_t pin_buffer = GPIOC->PIN;

	 if (key_no > 5)
	 {
		key_no -= 4;
		pin_buffer = GPIOD->PIN;
	 }

	 if (pin_buffer & (1 << key_no))
	 {
		 return GPIO_OFF;
	 }
	 return GPIO_ON;
 }