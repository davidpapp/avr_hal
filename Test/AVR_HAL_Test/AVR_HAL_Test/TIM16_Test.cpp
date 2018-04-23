#include "CppUTest/TestHarness.h"
#include "CppUTest/TestHarness_c.h"
//#include "CppUTestExt/MockSupport.h"


extern "C" {
#include <time.h> 
#include "tim16.h"
	static volatile TIM16_t _tim = { (TIM16_Control_t*) (__avr_reg + 0x80), (uint8_t*) (__avr_reg + 0x71), (uint8_t*) (__avr_reg + 0x36) };
};

TEST_GROUP(TEST_TIM)
{
	void setup( )
	{
		memset(__avr_reg, 0, _HIGHEST_REGISTER_ADD);
	}

	void teardown( )
	{

	}

};

#pragma region WGM_Tests

TEST(TEST_TIM , TIM16_TIM16_set_WGMCanBeCalled)
{
	TIM16_set_wgm(&_tim , WGM_NORMAL);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToNormal)
{
	TIM16_set_wgm(&_tim , WGM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPc8)
{
	TIM16_set_wgm(&_tim , WGM_PWM_PC_8);
	CHECK_EQUAL_C_UBYTE(0x01 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPc9)
{
	TIM16_set_wgm(&_tim , WGM_PWM_PC_9);
	CHECK_EQUAL_C_UBYTE(0x02 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPc10)
{
	TIM16_set_wgm(&_tim , WGM_PWM_PC_10);
	CHECK_EQUAL_C_UBYTE(0x03 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToCtcOcra)
{
	TIM16_set_wgm(&_tim , WGM_CTC_OCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x08 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToFastPwm8)
{
	TIM16_set_wgm(&_tim , WGM_FAST_PWM_8);
	CHECK_EQUAL_C_UBYTE(0x01 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x08 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToFastPwm9)
{
	TIM16_set_wgm(&_tim , WGM_FAST_PWM_9);
	CHECK_EQUAL_C_UBYTE(0x02 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x08 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToFastPwm10)
{
	TIM16_set_wgm(&_tim , WGM_FAST_PWM_10);
	CHECK_EQUAL_C_UBYTE(0x03 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x08 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPfcIcr)
{
	TIM16_set_wgm(&_tim , WGM_PWM_PFC_ICR);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x10 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPfcOcra)
{
	TIM16_set_wgm(&_tim , WGM_PWM_PFC_OCRA);
	CHECK_EQUAL_C_UBYTE(0x01 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x10 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPcIcr)
{
	TIM16_set_wgm(&_tim , WGM_PWM_PC_ICR);
	CHECK_EQUAL_C_UBYTE(0x02 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x10 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPcOcra)
{
	TIM16_set_wgm(&_tim , WGM_PWM_PC_OCRA);
	CHECK_EQUAL_C_UBYTE(0x03 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x10 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToCtcIcr)
{
	TIM16_set_wgm(&_tim , WGM_CTC_ICR);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x18 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToFastPwmIcr)
{
	TIM16_set_wgm(&_tim , WGM_FAST_PWM_ICR);
	CHECK_EQUAL_C_UBYTE(0x02 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x18 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToFastPwmOcra)
{
	TIM16_set_wgm(&_tim , WGM_FAST_PWM_OCRA);
	CHECK_EQUAL_C_UBYTE(0x03 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x18 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_WGMToResevedIsSameAsNormal)
{
	TIM16_set_wgm(&_tim , WGM_RESERVED);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x81]);
}

TEST(TEST_TIM , GWMCanBeReset)
{
	TIM16_set_wgm(&_tim , WGM_FAST_PWM_ICR);
	CHECK_EQUAL_C_UBYTE(0x02 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x18 , __avr_reg[0x81]);

	TIM16_set_wgm(&_tim , WGM_PWM_PC_9);
	CHECK_EQUAL_C_UBYTE(0x02 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x81]);

	TIM16_set_wgm(&_tim , WGM_RESERVED);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x81]);

	TIM16_set_wgm(&_tim , WGM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x80]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x81]);
}
#pragma endregion

#pragma region CS_Tests

TEST(TEST_TIM , TIM16_set_CSCanBeCalled)
{
	TIM16_set_cs(&_tim , CS_NO_CLK);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToNoCLK)
{
	TIM16_set_cs(&_tim , CS_NO_CLK);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToCLKDiv1)
{
	TIM16_set_cs(&_tim , CS_CLK_DIV1);
	CHECK_EQUAL_C_UBYTE(0x01 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToCLKDiv8)
{
	TIM16_set_cs(&_tim , CS_CLK_DIV8);
	CHECK_EQUAL_C_UBYTE(0x02 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToCLKDiv64)
{
	TIM16_set_cs(&_tim , CS_CLK_DIV64);
	CHECK_EQUAL_C_UBYTE(0x03 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToCLKDiv256)
{
	TIM16_set_cs(&_tim , CS_CLK_DIV256);
	CHECK_EQUAL_C_UBYTE(0x04 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToCLKDiv1024)
{
	TIM16_set_cs(&_tim , CS_CLK_DIV1024);
	CHECK_EQUAL_C_UBYTE(0x05 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToExtFalling)
{
	TIM16_set_cs(&_tim , CS_EXT_FALLING);
	CHECK_EQUAL_C_UBYTE(0x06 , __avr_reg[0x81]);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToExtRising)
{
	TIM16_set_cs(&_tim , CS_EXT_RISING);
	CHECK_EQUAL_C_UBYTE(0x07 , __avr_reg[0x81]);
}

TEST(TEST_TIM , SCSCanBeReset)
{
	TIM16_set_cs(&_tim , CS_EXT_FALLING);
	CHECK_EQUAL_C_UBYTE(0x06 , __avr_reg[0x81]);

	TIM16_set_cs(&_tim , CS_CLK_DIV256);
	CHECK_EQUAL_C_UBYTE(0x04 , __avr_reg[0x81]);

	TIM16_set_cs(&_tim , CS_NO_CLK);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x81]);
}
#pragma endregion

#pragma region COM_Tests

TEST(TEST_TIM , TIM16_set_COMCanBeCalled)
{
	TIM16_set_com(&_tim , OCR_A, COM_NORMAL);
}

TEST(TEST_TIM , ChannelACanBeSetNormal)
{
	TIM16_set_com(&_tim , OCR_A , COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x80]);
}

TEST(TEST_TIM , ChannelBCanBeSetNormal)
{
	TIM16_set_com(&_tim , OCR_B , COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x80]);
}

TEST(TEST_TIM , ChannelCCanBeSetNormal)
{
	TIM16_set_com(&_tim , OCR_C , COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x80]);
}

TEST(TEST_TIM , ChannelACanBeSetToToggle)
{
	TIM16_set_com(&_tim , OCR_A , COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0x40 , __avr_reg[0x80]);
}

TEST(TEST_TIM , ChannelBCanBeSetToToggle)
{
	TIM16_set_com(&_tim , OCR_B , COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0x10 , __avr_reg[0x80]);
}

TEST(TEST_TIM , ChannelCCanBeSetToToggle)
{
	TIM16_set_com(&_tim , OCR_C , COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0x04 , __avr_reg[0x80]);
}

TEST(TEST_TIM , ChannelACanBeSetToClear)
{
	TIM16_set_com(&_tim , OCR_A , COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0x80 , __avr_reg[0x80]);
}

TEST(TEST_TIM , ChannelBCanBeSetToClear)
{
	TIM16_set_com(&_tim , OCR_B , COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0x20 , __avr_reg[0x80]);
}

TEST(TEST_TIM , ChannelCCanBeSetToClear)
{
	TIM16_set_com(&_tim , OCR_C , COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0x08 , __avr_reg[0x80]);
}

TEST(TEST_TIM , ChannelACanBeSetToSet)
{
	TIM16_set_com(&_tim , OCR_A , COM_SET);
	CHECK_EQUAL_C_UBYTE(0xC0 , __avr_reg[0x80]);
}

TEST(TEST_TIM , ChannelBCanBeSetToSet)
{
	TIM16_set_com(&_tim , OCR_B , COM_SET);
	CHECK_EQUAL_C_UBYTE(0x30 , __avr_reg[0x80]);
}

TEST(TEST_TIM , ChannelCCanBeSetToSet)
{
	TIM16_set_com(&_tim , OCR_C , COM_SET);
	CHECK_EQUAL_C_UBYTE(0x0C , __avr_reg[0x80]);
}

TEST(TEST_TIM , ChannelSetIsIndependent)
{
	TIM16_set_com(&_tim , OCR_A , COM_SET);
	CHECK_EQUAL_C_UBYTE(0xC0 , __avr_reg[0x80]);

	TIM16_set_com(&_tim , OCR_B , COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0xD0 , __avr_reg[0x80]);

	TIM16_set_com(&_tim , OCR_C , COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0xD8 , __avr_reg[0x80]);

	TIM16_set_com(&_tim , OCR_A , COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x18 , __avr_reg[0x80]);
}
#pragma endregion