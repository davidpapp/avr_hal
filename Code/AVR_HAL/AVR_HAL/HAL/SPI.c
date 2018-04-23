/*
 * SPI.c
 *
 * Created: 2018. 04. 19. 12:45:52
 *  Author: David
 */ 

 #include <stddef.h>
 #include <avr/interrupt.h>
 #include "SPI.h"

static void(*_spi_cb)(void) = NULL;

 void SPI_enable_interrupt(SPI_t* spi)
 {
	 spi->SPI_SPCR |= 0x80;
 }

 void SPI_disable_interrupt(SPI_t* spi)
 {
	 spi->SPI_SPCR &= 0x7F;
 }

 void SPI_enable(SPI_t* spi)
 {
	 spi->SPI_SPCR |= 0x40;
 }

 void SPI_disable(SPI_t* spi)
 {
	 spi->SPI_SPCR &= 0xBF;
 }

 void SPI_set_data_order_LSB(SPI_t* spi)
 {
	 spi->SPI_SPCR |= 0x20;
 }

 void SPI_set_data_order_MSB(SPI_t* spi)
 {
	 spi->SPI_SPCR &= 0xDF;
 }

 void SPI_set_master(SPI_t* spi)
 {
	 spi->SPI_SPCR |= 0x10;
 }

 void SPI_set_slave(SPI_t* spi)
 {
	 spi->SPI_SPCR &= 0xEF;
 }

 void SPI_set_mode(SPI_t* spi , SPI_MODE_t spi_mode)
 {
	 uint8_t buffer = spi->SPI_SPCR;
	 buffer &= 0xF3;
	 spi->SPI_SPCR = buffer | (spi_mode << 2);
 }

 void SPI_set_clock_rate(SPI_t* spi , SPI_SCK_t sck)
 {
	 uint8_t buffer = spi->SPI_SPCR;
	 buffer &= 0xFC;
	 spi->SPI_SPCR = buffer | (sck & 0x03);
	 buffer = spi->SPI_SPSR;
	 buffer &= 0xFE;
	 spi->SPI_SPSR = buffer | ((sck & 0x04) >> 2);
 }

 void SPI_set_callback(void(*cb)(void))
 {
	 _spi_cb = cb;
 }

#ifndef _TestHarness

 ISR(SPI_STC_vect)
 {
	 if (_spi_cb != NULL)
	 {
		 _spi_cb();
	 }
 }

#endif // !_TestHarness