/*
 * SPI.h
 *
 * Created: 2018. 04. 19. 11:25:24
 *  Author: David
 */ 


#ifndef SPI_H_
#define SPI_H_

typedef volatile struct
{
	uint8_t SPCR;
	uint8_t SPSR;
	uint8_t SPDR;
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

SPI_enable_interrupt(SPI_t spi);
SPI_disable_interrupt(SPI_t spi);
SPI_enable(SPI_t spi);
SPI_disable(SPI_t spi);
SPI_set_data_order_LSB(SPI_t spi);
SPI_set_data_order_MSB(SPI_t spi);
SPI_set_master(SPI_t spi);
SPI_set_slave(SPI_t spi);
SPI_set_polarity_rising_falling(SPI_t spi);
SPI_set_polarity_falling_rising(SPI_t spi);
SPI_set_phase_sample_setup(SPI_t spi);
SPI_set_phase_setup_sample(SPI_t spi);
SPI_set_clock_rate(SPI_t spi, SPI_SCK_t sck);


#endif /* SPI_H_ */