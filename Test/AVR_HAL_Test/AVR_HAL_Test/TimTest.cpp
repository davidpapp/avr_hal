#include "CppUTest/TestHarness.h"
#include "CppUTest/TestHarness_c.h"
//#include "CppUTestExt/MockSupport.h"


extern "C" {
#include <time.h> 
#include "../../../Code/AVR_HAL/AVR_HAL/HAL/tim16.h"
	uint8_t __avr_reg[_HIGHEST_REGISTER_ADD];
	TIM16_t *_tim = (TIM16_t*)(__avr_reg + 80);
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

#pragma region tim_memoy_mapping
TEST(TEST_TIM , Tim1Defined)
{
	Tim16_1;
}

TEST(TEST_TIM , Tim3Defined)
{
	Tim16_3;
}

TEST(TEST_TIM , Tim4Defined)
{
	Tim16_4;
}

TEST(TEST_TIM , Tim5Defined)
{
	Tim16_5;
}

TEST(TEST_TIM , Tim1AddressesAreCorrect)
{
	
	CHECK_EQUAL_C_ULONG(0x80 , (uint32_t) &(Tim16_1->TCCRA));
	CHECK_EQUAL_C_ULONG(0x81 , (uint32_t) &(Tim16_1->TCCRB));
	CHECK_EQUAL_C_ULONG(0x82 , (uint32_t) &(Tim16_1->TCCRC));
	CHECK_EQUAL_C_ULONG(0x84 , (uint32_t) &(Tim16_1->TCNT));
	CHECK_EQUAL_C_ULONG(0x86 , (uint32_t) &(Tim16_1->ICR));
	CHECK_EQUAL_C_ULONG(0x88 , (uint32_t) &(Tim16_1->OCRA));
	CHECK_EQUAL_C_ULONG(0x8A , (uint32_t) &(Tim16_1->OCRB));
	CHECK_EQUAL_C_ULONG(0x8C , (uint32_t) &(Tim16_1->OCRC));
}

#pragma endregion

#pragma region WGM_Tests

TEST(TEST_TIM , Set_WGMCanBeCalled)
{
	set_wgm(_tim , WGM_NORMAL);
}

TEST(TEST_TIM , Set_WGMCanBeSetToNormal)
{
	set_wgm(_tim , WGM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToPwmPc8)
{
	set_wgm(_tim , WGM_PWM_PC_8);
	CHECK_EQUAL_C_UBYTE(0x01 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToPwmPc9)
{
	set_wgm(_tim , WGM_PWM_PC_9);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToPwmPc10)
{
	set_wgm(_tim , WGM_PWM_PC_10);
	CHECK_EQUAL_C_UBYTE(0x03 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToCtcOcra)
{
	set_wgm(_tim , WGM_CTC_OCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x08 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToFastPwm8)
{
	set_wgm(_tim , WGM_FAST_PWM_8);
	CHECK_EQUAL_C_UBYTE(0x01 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x08 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToFastPwm9)
{
	set_wgm(_tim , WGM_FAST_PWM_9);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x08 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToFastPwm10)
{
	set_wgm(_tim , WGM_FAST_PWM_10);
	CHECK_EQUAL_C_UBYTE(0x03 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x08 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToPwmPfcIcr)
{
	set_wgm(_tim , WGM_PWM_PFC_ICR);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x10 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToPwmPfcOcra)
{
	set_wgm(_tim , WGM_PWM_PFC_OCRA);
	CHECK_EQUAL_C_UBYTE(0x01 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x10 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToPwmPcIcr)
{
	set_wgm(_tim , WGM_PWM_PC_ICR);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x10 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToPwmPcOcra)
{
	set_wgm(_tim , WGM_PWM_PC_OCRA);
	CHECK_EQUAL_C_UBYTE(0x03 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x10 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToCtcIcr)
{
	set_wgm(_tim , WGM_CTC_ICR);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x18 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToFastPwmIcr)
{
	set_wgm(_tim , WGM_FAST_PWM_ICR);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x18 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMCanBeSetToFastPwmOcra)
{
	set_wgm(_tim , WGM_FAST_PWM_OCRA);
	CHECK_EQUAL_C_UBYTE(0x03 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x18 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_WGMToResevedIsSameAsNormal)
{
	set_wgm(_tim , WGM_RESERVED);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}

TEST(TEST_TIM , GWMCanBeReset)
{
	set_wgm(_tim , WGM_FAST_PWM_ICR);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x18 , _tim->TCCRB);

	set_wgm(_tim , WGM_PWM_PC_9);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);

	set_wgm(_tim , WGM_RESERVED);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);

	set_wgm(_tim , WGM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}
#pragma endregion

#pragma region CS_Tests

TEST(TEST_TIM , Set_CSCanBeCalled)
{
	set_cs(_tim , CS_NO_CLK);
}

TEST(TEST_TIM , Set_CSCanBeSetToNoCLK)
{
	set_cs(_tim , CS_NO_CLK);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_CSCanBeSetToCLKDiv1)
{
	set_cs(_tim , CS_CLK_DIV1);
	CHECK_EQUAL_C_UBYTE(0x01 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_CSCanBeSetToCLKDiv8)
{
	set_cs(_tim , CS_CLK_DIV8);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_CSCanBeSetToCLKDiv64)
{
	set_cs(_tim , CS_CLK_DIV64);
	CHECK_EQUAL_C_UBYTE(0x03 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_CSCanBeSetToCLKDiv256)
{
	set_cs(_tim , CS_CLK_DIV256);
	CHECK_EQUAL_C_UBYTE(0x04 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_CSCanBeSetToCLKDiv1024)
{
	set_cs(_tim , CS_CLK_DIV1024);
	CHECK_EQUAL_C_UBYTE(0x05 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_CSCanBeSetToExtFalling)
{
	set_cs(_tim , CS_EXT_FALLING);
	CHECK_EQUAL_C_UBYTE(0x06 , _tim->TCCRB);
}

TEST(TEST_TIM , Set_CSCanBeSetToExtRising)
{
	set_cs(_tim , CS_EXT_RISING);
	CHECK_EQUAL_C_UBYTE(0x07 , _tim->TCCRB);
}

TEST(TEST_TIM , SCSCanBeReset)
{
	set_cs(_tim , CS_EXT_FALLING);
	CHECK_EQUAL_C_UBYTE(0x06 , _tim->TCCRB);

	set_cs(_tim , CS_CLK_DIV256);
	CHECK_EQUAL_C_UBYTE(0x04 , _tim->TCCRB);

	set_cs(_tim , CS_NO_CLK);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}
#pragma endregion

#pragma region COM_Tests

TEST(TEST_TIM , Set_COMCanBeCalled)
{
	set_com(_tim , OCR_A, COM_NORMAL);
}

TEST(TEST_TIM , ChannelACanBeSetNormal)
{
	set_com(_tim , OCR_A , COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelBCanBeSetNormal)
{
	set_com(_tim , OCR_B , COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelCCanBeSetNormal)
{
	set_com(_tim , OCR_C , COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelACanBeSetToToggle)
{
	set_com(_tim , OCR_A , COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0x40 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelBCanBeSetToToggle)
{
	set_com(_tim , OCR_B , COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0x10 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelCCanBeSetToToggle)
{
	set_com(_tim , OCR_C , COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0x04 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelACanBeSetToClear)
{
	set_com(_tim , OCR_A , COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0x80 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelBCanBeSetToClear)
{
	set_com(_tim , OCR_B , COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0x20 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelCCanBeSetToClear)
{
	set_com(_tim , OCR_C , COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0x08 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelACanBeSetToSet)
{
	set_com(_tim , OCR_A , COM_SET);
	CHECK_EQUAL_C_UBYTE(0xC0 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelBCanBeSetToSet)
{
	set_com(_tim , OCR_B , COM_SET);
	CHECK_EQUAL_C_UBYTE(0x30 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelCCanBeSetToSet)
{
	set_com(_tim , OCR_C , COM_SET);
	CHECK_EQUAL_C_UBYTE(0x0C , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelSetIsIndependent)
{
	set_com(_tim , OCR_A , COM_SET);
	CHECK_EQUAL_C_UBYTE(0xC0 , _tim->TCCRA);

	set_com(_tim , OCR_B , COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0xD0 , _tim->TCCRA);

	set_com(_tim , OCR_C , COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0xD8 , _tim->TCCRA);

	set_com(_tim , OCR_A , COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x18 , _tim->TCCRA);
}
#pragma endregion


