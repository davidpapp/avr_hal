#include "CppUTest/TestHarness.h"
#include "CppUTest/TestHarness_c.h"
//#include "CppUTestExt/MockSupport.h"


extern "C"
{
	#include <avr/io.h>
	#include "SPI.h"

	static SPI_t *_spi = (SPI_t*)(__avr_reg + 0x2C);
};

TEST_GROUP(TEST_SPI)
{
	void setup( )
	{
		memset(__avr_reg , 0 , _HIGHEST_REGISTER_ADD);
	}

	void teardown( )
	{

	}

};

#pragma region Interrupt_Tests

TEST(TEST_SPI , EnableInteruptCanBeCalled)
{
	SPI_enable_interrupt(_spi);
}

TEST(TEST_SPI , EnableInteruptSetBitCorrectly)
{
	SPI_enable_interrupt(_spi);
	CHECK_EQUAL_C_UBYTE(0x80 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , DisableInteruptCanBeCalled)
{
	SPI_disable_interrupt(_spi);
}

TEST(TEST_SPI , DisableInteruptSetBitCorrectly)
{
	_spi->SPI_SPCR = 0xFF;
	SPI_disable_interrupt(_spi);
	CHECK_EQUAL_C_UBYTE(0x7F , _spi->SPI_SPCR);
}

TEST(TEST_SPI , InterruptCanBeToggled)
{
	SPI_enable_interrupt(_spi);
	CHECK_EQUAL_C_UBYTE(0x80 , _spi->SPI_SPCR);

	SPI_disable_interrupt(_spi);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);

	SPI_enable_interrupt(_spi);
	CHECK_EQUAL_C_UBYTE(0x80 , _spi->SPI_SPCR);

	SPI_disable_interrupt(_spi);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , SettingInterruptIsIndependent)
{
	_spi->SPI_SPCR = 0x0F;
	SPI_enable_interrupt(_spi);
	CHECK_EQUAL_C_UBYTE(0x8F , _spi->SPI_SPCR);

	SPI_disable_interrupt(_spi);
	CHECK_EQUAL_C_UBYTE(0x0F , _spi->SPI_SPCR);

	_spi->SPI_SPCR = 0x33;
	SPI_enable_interrupt(_spi);
	CHECK_EQUAL_C_UBYTE(0xB3 , _spi->SPI_SPCR);

	SPI_disable_interrupt(_spi);
	CHECK_EQUAL_C_UBYTE(0x33 , _spi->SPI_SPCR);
}

#pragma endregion

#pragma region Enable_Disable_Tests

TEST(TEST_SPI , EnableCanBeCalled)
{
	SPI_enable(_spi);
}

TEST(TEST_SPI , EnableSetsBitCorrectly)
{
	SPI_enable(_spi);
	CHECK_EQUAL_C_UBYTE(0x40 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , EnableIsIndependent)
{
	_spi->SPI_SPCR = 0x8F;
	SPI_enable(_spi);
	CHECK_EQUAL_C_UBYTE(0xCF , _spi->SPI_SPCR);
}

TEST(TEST_SPI , DisableCanBeCalled)
{
	SPI_disable(_spi);
}

TEST(TEST_SPI , DisableSetsBitCorrectly)
{
	_spi->SPI_SPCR = 0x40;
	SPI_disable(_spi);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , DisableIsIndependent)
{
	_spi->SPI_SPCR = 0xFF;
	SPI_disable(_spi);
	CHECK_EQUAL_C_UBYTE(0xBF , _spi->SPI_SPCR);
}

TEST(TEST_SPI , EanbleCanBeToggled)
{
	SPI_enable(_spi);
	CHECK_EQUAL_C_UBYTE(0x40 , _spi->SPI_SPCR);

	SPI_disable(_spi);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);

	SPI_enable(_spi);
	CHECK_EQUAL_C_UBYTE(0x40 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , EnableTogglingIsIndependent)
{
	_spi->SPI_SPCR = 0xBB;
	SPI_enable(_spi);
	CHECK_EQUAL_C_UBYTE(0xFB , _spi->SPI_SPCR);

	SPI_disable(_spi);
	CHECK_EQUAL_C_UBYTE(0xBB , _spi->SPI_SPCR);

	SPI_enable(_spi);
	CHECK_EQUAL_C_UBYTE(0xFB , _spi->SPI_SPCR);
}

#pragma endregion

#pragma region Data_Order_Tests

TEST(TEST_SPI , SetDataOrderLSBCanBeCalled)
{
	SPI_set_data_order_LSB(_spi);
}

TEST(TEST_SPI , SetDataOrderLSBSetsBitCorrectly)
{
	SPI_set_data_order_LSB(_spi);
	CHECK_EQUAL_C_UBYTE(0x20 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , SetDataOrderLSBIsIndependent)
{
	_spi->SPI_SPCR = 0x99;
	SPI_set_data_order_LSB(_spi);
	CHECK_EQUAL_C_UBYTE(0xB9 , _spi->SPI_SPCR);

	_spi->SPI_SPCR = 0xCC;
	SPI_set_data_order_LSB(_spi);
	CHECK_EQUAL_C_UBYTE(0xEC , _spi->SPI_SPCR);
}

TEST(TEST_SPI , SetDataOrderMSBCanBeCalled)
{
	SPI_set_data_order_MSB(_spi);
}

TEST(TEST_SPI , SetDataOrderMSBSetsBitCorrectly)
{
	_spi->SPI_SPCR = 0x20;
	SPI_set_data_order_MSB(_spi);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , SetDataOrderMSBIsIndependent)
{
	_spi->SPI_SPCR = 0xB9;
	SPI_set_data_order_MSB(_spi);
	CHECK_EQUAL_C_UBYTE(0x99 , _spi->SPI_SPCR);

	_spi->SPI_SPCR = 0xEC;
	SPI_set_data_order_MSB(_spi);
	CHECK_EQUAL_C_UBYTE(0xCC , _spi->SPI_SPCR);
}

TEST(TEST_SPI , DataOrderCanBeToggled)
{
	SPI_set_data_order_LSB(_spi);
	CHECK_EQUAL_C_UBYTE(0x20 , _spi->SPI_SPCR);

	SPI_set_data_order_MSB(_spi);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);

	SPI_set_data_order_LSB(_spi);
	CHECK_EQUAL_C_UBYTE(0x20 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , DataOrderTogglingIsIndependent)
{
	_spi->SPI_SPCR = 0xDF;
	SPI_set_data_order_LSB(_spi);
	CHECK_EQUAL_C_UBYTE(0xFF , _spi->SPI_SPCR);

	SPI_set_data_order_MSB(_spi);
	CHECK_EQUAL_C_UBYTE(0xDF , _spi->SPI_SPCR);

	SPI_set_data_order_LSB(_spi);
	CHECK_EQUAL_C_UBYTE(0xFF , _spi->SPI_SPCR);
}

#pragma endregion

#pragma region Master_Slave_Tests

TEST(TEST_SPI , SetMasterCanBeCalled)
{
	SPI_set_master(_spi);
}

TEST(TEST_SPI , SetMasterSetsBitCorrectly)
{
	SPI_set_master(_spi);
	CHECK_EQUAL_C_UBYTE(0x10 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , SetMasterIsIndependent)
{
	_spi->SPI_SPCR = 0x81;
	SPI_set_master(_spi);
	CHECK_EQUAL_C_UBYTE(0x91 , _spi->SPI_SPCR);

	_spi->SPI_SPCR = 0xEF;
	SPI_set_master(_spi);
	CHECK_EQUAL_C_UBYTE(0xFF , _spi->SPI_SPCR);
}

TEST(TEST_SPI , SetSlaveCanBeCalled)
{
	SPI_set_slave(_spi);
}

TEST(TEST_SPI , SetSlaveSetsBitCorrectly)
{
	_spi->SPI_SPCR = 0x10;
	SPI_set_slave(_spi);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , SetSlaveIsIndependent)
{
	_spi->SPI_SPCR = 0x91;
	SPI_set_slave(_spi);
	CHECK_EQUAL_C_UBYTE(0x81 , _spi->SPI_SPCR);

	_spi->SPI_SPCR = 0xFF;
	SPI_set_slave(_spi);
	CHECK_EQUAL_C_UBYTE(0xEF , _spi->SPI_SPCR);
}

TEST(TEST_SPI , MasterSlaveCanBeToggled)
{
	SPI_set_master(_spi);
	CHECK_EQUAL_C_UBYTE(0x10 , _spi->SPI_SPCR);

	SPI_set_slave(_spi);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);

	SPI_set_master(_spi);
	CHECK_EQUAL_C_UBYTE(0x10 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , MasterSlaveTogglingIsIndependent)
{
	_spi->SPI_SPCR = 0xEF;
	SPI_set_master(_spi);
	CHECK_EQUAL_C_UBYTE(0xFF , _spi->SPI_SPCR);

	SPI_set_slave(_spi);
	CHECK_EQUAL_C_UBYTE(0xEF , _spi->SPI_SPCR);

	SPI_set_master(_spi);
	CHECK_EQUAL_C_UBYTE(0xFF , _spi->SPI_SPCR);
}

#pragma endregion

#pragma region Mode_Tests

TEST(TEST_SPI , SetModeCanBeCalled)
{
	SPI_set_mode(_spi, SPI_MODE_SAMPLE_FALLING_SETUP_RISING);
}

TEST(TEST_SPI , ModeCanBeSetTo0)
{
	SPI_set_mode(_spi , SPI_MODE_SAMPLE_RISING_SETUP_FALLING);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , ModeCanBeSetTo1)
{
	SPI_set_mode(_spi , SPI_MODE_SETUP_RISING_SAMPLE_FALLING);
	CHECK_EQUAL_C_UBYTE(0x04 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , ModeCanBeSetTo2)
{
	SPI_set_mode(_spi , SPI_MODE_SAMPLE_FALLING_SETUP_RISING);
	CHECK_EQUAL_C_UBYTE(0x08 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , ModeCanBeSetTo3)
{
	SPI_set_mode(_spi , SPI_MODE_SETUP_FALLING_SAMPLE_RISING);
	CHECK_EQUAL_C_UBYTE(0x0C , _spi->SPI_SPCR);
}

TEST(TEST_SPI , ModeCanBeToggled)
{
	SPI_set_mode(_spi , SPI_MODE_SETUP_FALLING_SAMPLE_RISING);
	CHECK_EQUAL_C_UBYTE(0x0C , _spi->SPI_SPCR);

	SPI_set_mode(_spi , SPI_MODE_SAMPLE_RISING_SETUP_FALLING);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);

	SPI_set_mode(_spi , SPI_MODE_SAMPLE_FALLING_SETUP_RISING);
	CHECK_EQUAL_C_UBYTE(0x08 , _spi->SPI_SPCR);

	SPI_set_mode(_spi , SPI_MODE_SETUP_RISING_SAMPLE_FALLING);
	CHECK_EQUAL_C_UBYTE(0x04 , _spi->SPI_SPCR);
}

TEST(TEST_SPI , SetModeIsIndependent)
{
	_spi->SPI_SPCR = 0xFF;
	SPI_set_mode(_spi , SPI_MODE_SAMPLE_RISING_SETUP_FALLING);
	CHECK_EQUAL_C_UBYTE(0xF3 , _spi->SPI_SPCR);

	SPI_set_mode(_spi , SPI_MODE_SETUP_RISING_SAMPLE_FALLING);
	CHECK_EQUAL_C_UBYTE(0xF7 , _spi->SPI_SPCR);

	SPI_set_mode(_spi , SPI_MODE_SAMPLE_FALLING_SETUP_RISING);
	CHECK_EQUAL_C_UBYTE(0xFB , _spi->SPI_SPCR);

	SPI_set_mode(_spi , SPI_MODE_SETUP_FALLING_SAMPLE_RISING);
	CHECK_EQUAL_C_UBYTE(0xFF , _spi->SPI_SPCR);
}

#pragma endregion

#pragma region Set_Clock_Rate_Tests

TEST(TEST_SPI , SetClockRateCanBeCalled)
{
	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV4);
}

TEST(TEST_SPI , ClockCanBeSetTo0)
{
	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV4);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPSR);
}

TEST(TEST_SPI , ClockCanBeSetTo1)
{
	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV16);
	CHECK_EQUAL_C_UBYTE(0x01 , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPSR);
}

TEST(TEST_SPI , ClockCanBeSetTo2)
{
	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV64);
	CHECK_EQUAL_C_UBYTE(0x02 , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPSR);
}

TEST(TEST_SPI , ClockCanBeSetTo3)
{
	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV128);
	CHECK_EQUAL_C_UBYTE(0x03 , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPSR);
}

TEST(TEST_SPI , ClockCanBeSetTo4)
{
	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV2);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0x01 , _spi->SPI_SPSR);
}

TEST(TEST_SPI , ClockCanBeSetTo5)
{
	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV8);
	CHECK_EQUAL_C_UBYTE(0x01 , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0x01 , _spi->SPI_SPSR);
}

TEST(TEST_SPI , ClockCanBeSetTo6)
{
	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV32);
	CHECK_EQUAL_C_UBYTE(0x02 , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0x01 , _spi->SPI_SPSR);
}

TEST(TEST_SPI , ClockCanBeSetTo7)
{
	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV64_2X);
	CHECK_EQUAL_C_UBYTE(0x03 , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0x01 , _spi->SPI_SPSR);
}

TEST(TEST_SPI , ClockCanBeToggled)
{
	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV64_2X);
	CHECK_EQUAL_C_UBYTE(0x03 , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0x01 , _spi->SPI_SPSR);

	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV4);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPSR);

	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV32);
	CHECK_EQUAL_C_UBYTE(0x02 , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0x01 , _spi->SPI_SPSR);

	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV16);
	CHECK_EQUAL_C_UBYTE(0x01 , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0x00 , _spi->SPI_SPSR);
}

TEST(TEST_SPI , ClockSetIsIndependent)
{
	_spi->SPI_SPCR = 0xFF;
	_spi->SPI_SPSR = 0xFF;
	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV4);
	CHECK_EQUAL_C_UBYTE(0xFC , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0xFE , _spi->SPI_SPSR);

	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV2);
	CHECK_EQUAL_C_UBYTE(0xFC , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0xFF , _spi->SPI_SPSR);

	SPI_set_clock_rate(_spi , SPI_SCK_CLK_DIV128);
	CHECK_EQUAL_C_UBYTE(0xFF , _spi->SPI_SPCR);
	CHECK_EQUAL_C_UBYTE(0xFE , _spi->SPI_SPSR);
}

#pragma endregion

#pragma region Callback_Tests

TEST(TEST_SPI , SetCallbackCanBeCalled)
{
	SPI_set_callback(NULL);
}

#pragma endregion
