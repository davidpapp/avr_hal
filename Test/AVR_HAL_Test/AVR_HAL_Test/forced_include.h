#ifndef FORCED_H_
#define FORCED_H_

#include <stdint.h>
#define __AVR_ATmega2560__
#define __AVR_LIBC_DEPRECATED_ENABLE__
#define _AVR_SFR_DEFS_H_ 1
#define _UTIL_DELAY_H_ 1

#define F_CPU 10000000UL  // 10 MHz

#define _BV(bit) (1 << (bit))

// 0x136 is heighest address og registers is ATMEGA2560
#define _HIGHEST_REGISTER_ADD	0x136

#ifdef __cplusplus
extern "C"
{
#endif
    extern uint8_t __avr_reg[ _HIGHEST_REGISTER_ADD ];
    extern double __requested_delay_us;
    extern void _delay_us( double delay_us );
#ifdef __cplusplus
}
#endif

#define _SFR_MEM8( mem_addr ) ( *( uint8_t * ) (&__avr_reg[mem_addr] ) )
#define _SFR_IO8(io_addr) (*(uint8_t *)(&__avr_reg[io_addr]))

#endif  /* FORCED_H_ */