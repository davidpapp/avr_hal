/*
 * INT.h
 *
 * Created: 18/04/2018 15:25:47
 *  Author: David
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

typedef enum
{
	EXT_INT_ISC_LOW,
	EXT_INT_ISC_ANY,
	EXT_INT_ISC_FALLING,
	EXT_INT_ISC_RISING
}EXT_INT_ISC_t;

typedef enum
{
	EXT_INT_0,
	EXT_INT_1,
	EXT_INT_2,
	EXT_INT_3,
	EXT_INT_4,
	EXT_INT_5,
	EXT_INT_6,
	EXT_INT_7
}EXT_INT_t;

void EXT_INT_enable(EXT_INT_t ext_int);
void EXT_INT_disable(EXT_INT_t ext_int);
void EXT_INT_set_sense(EXT_INT_t ext_int, EXT_INT_ISC_t sense_type);
void EXT_INT_set_callback(void (*cb)(uint8_t));

#endif /* EXT_INT_H_ */