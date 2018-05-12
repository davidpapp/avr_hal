/*
 * hal_utils.h
 *
 * Created: 2018. 05. 11. 15:25:28
 *  Author: David
 */ 


#ifndef HAL_UTILS_H_
#define HAL_UTILS_H_

void system_interrupt_enter_critical_section();
void system_interrupt_leave_critical_section();

#endif /* HAL_UTILS_H_ */