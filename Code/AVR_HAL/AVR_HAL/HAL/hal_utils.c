/*
 * hal_utils.c
 *
 * Created: 2018. 05. 11. 15:07:15
 *  Author: David
 */ 

 #include <avr/interrupt.h>
 #include <avr/common.h>

 static volatile uint8_t _sreg = 0x00;

 void system_interrupt_enter_critical_section()
 {
	_sreg = _SFR_IO8(0x3F);
	cli();
 }


 void system_interrupt_leave_critical_section()
 {
	_SFR_IO8(0x3F) = _sreg;
 }