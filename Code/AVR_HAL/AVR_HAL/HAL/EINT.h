/*
 * INT.h
 *
 * Created: 18/04/2018 15:25:47
 *  Author: David
 */ 


#ifndef EINT_H_
#define EINT_H_

typedef enum
{
	ISC_LOW,
	ISC_ANY,
	ISC_FALLING,
	ISC_RISING
}EINT_ISC_t;

typedef enum
{
	EINT_0,
	EINT_1,
	EINT_2,
	EINT_3,
	EINT_4,
	EINT_5,
	EINT_6,
	EINT_7
}EINT_INT_t;

void EINT_enable(EINT_INT_t ext_int);
void EINT_disable(EINT_INT_t ext_int);
void EINT_set_sense(EINT_INT_t ext_int, EINT_ISC_t sense_type);
void EINT_set_callback(void (*cb)(uint8_t));

#endif /* EINT_H_ */