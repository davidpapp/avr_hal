/*
 * SPI.h
 *
 * Created: 2018. 04. 19. 11:25:24
 *  Author: David
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

typedef volatile struct
{
	uint8_t SPI_SPCR;
	uint8_t SPI_SPSR;
	uint8_t SPI_SPDR;
}SPI_t;

typedef enum
{
	SPI_SCK_CLK_DIV4,
	SPI_SCK_CLK_DIV16,
	SPI_SCK_CLK_DIV64,
	SPI_SCK_CLK_DIV128,
	SPI_SCK_CLK_DIV2,
	SPI_SCK_CLK_DIV8,
	SPI_SCK_CLK_DIV32,
	SPI_SCK_CLK_DIV64_2X
}SPI_SCK_t;

typedef enum
{
	SPI_MODE_SAMPLE_RISING_SETUP_FALLING ,
	SPI_MODE_SETUP_RISING_SAMPLE_FALLING ,
	SPI_MODE_SAMPLE_FALLING_SETUP_RISING ,
	SPI_MODE_SETUP_FALLING_SAMPLE_RISING
}SPI_MODE_t;

void SPI_enable_interrupt(SPI_t* spi);
void SPI_disable_interrupt(SPI_t* spi);
void SPI_enable(SPI_t* spi);
void SPI_disable(SPI_t* spi);
void SPI_set_data_order_LSB(SPI_t* spi);
void SPI_set_data_order_MSB(SPI_t* spi);
void SPI_set_master(SPI_t* spi);
void SPI_set_slave(SPI_t* spi);
void SPI_set_mode(SPI_t* spi, SPI_MODE_t spi_mode);
void SPI_set_clock_rate(SPI_t* spi, SPI_SCK_t sck);
void SPI_set_callback(void(*cb)(void));


#endif /* SPI_H_ */