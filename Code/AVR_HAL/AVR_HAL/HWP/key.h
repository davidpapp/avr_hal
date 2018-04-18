/*
 * key.h
 *
 * Created: 2018. 04. 18. 22:13:37
 *  Author: David
 */ 


#ifndef KEY_H_
#define KEY_H_

#define KEY_MAX_KEY_NO 7

typedef enum {
	GPIO_OFF = 0,	/**< The pin is OFF */
	GPIO_ON,		/**< The pin is ON */
	GPIO_UNKNOWN	/**< The pin state is unknown */
} gpio_state_t;

void key_create(void (*cb)(uint8_t));
gpio_state_t key_get_key(uint8_t key_no);

#endif /* KEY_H_ */