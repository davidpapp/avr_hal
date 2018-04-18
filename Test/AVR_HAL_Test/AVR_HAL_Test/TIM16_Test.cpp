#include "CppUTest/TestHarness.h"
#include "CppUTest/TestHarness_c.h"
//#include "CppUTestExt/MockSupport.h"


extern "C" {
#include <time.h> 
#include "tim16.h"
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

TEST(TEST_TIM , TIM16_TIM16_set_WGMCanBeCalled)
{
	TIM16_set_wgm(_tim , WGM_NORMAL);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToNormal)
{
	TIM16_set_wgm(_tim , WGM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPc8)
{
	TIM16_set_wgm(_tim , WGM_PWM_PC_8);
	CHECK_EQUAL_C_UBYTE(0x01 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPc9)
{
	TIM16_set_wgm(_tim , WGM_PWM_PC_9);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPc10)
{
	TIM16_set_wgm(_tim , WGM_PWM_PC_10);
	CHECK_EQUAL_C_UBYTE(0x03 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToCtcOcra)
{
	TIM16_set_wgm(_tim , WGM_CTC_OCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x08 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToFastPwm8)
{
	TIM16_set_wgm(_tim , WGM_FAST_PWM_8);
	CHECK_EQUAL_C_UBYTE(0x01 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x08 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToFastPwm9)
{
	TIM16_set_wgm(_tim , WGM_FAST_PWM_9);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x08 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToFastPwm10)
{
	TIM16_set_wgm(_tim , WGM_FAST_PWM_10);
	CHECK_EQUAL_C_UBYTE(0x03 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x08 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPfcIcr)
{
	TIM16_set_wgm(_tim , WGM_PWM_PFC_ICR);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x10 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPfcOcra)
{
	TIM16_set_wgm(_tim , WGM_PWM_PFC_OCRA);
	CHECK_EQUAL_C_UBYTE(0x01 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x10 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPcIcr)
{
	TIM16_set_wgm(_tim , WGM_PWM_PC_ICR);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x10 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToPwmPcOcra)
{
	TIM16_set_wgm(_tim , WGM_PWM_PC_OCRA);
	CHECK_EQUAL_C_UBYTE(0x03 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x10 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToCtcIcr)
{
	TIM16_set_wgm(_tim , WGM_CTC_ICR);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x18 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToFastPwmIcr)
{
	TIM16_set_wgm(_tim , WGM_FAST_PWM_ICR);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x18 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMCanBeSetToFastPwmOcra)
{
	TIM16_set_wgm(_tim , WGM_FAST_PWM_OCRA);
	CHECK_EQUAL_C_UBYTE(0x03 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x18 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_WGMToResevedIsSameAsNormal)
{
	TIM16_set_wgm(_tim , WGM_RESERVED);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}

TEST(TEST_TIM , GWMCanBeReset)
{
	TIM16_set_wgm(_tim , WGM_FAST_PWM_ICR);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x18 , _tim->TCCRB);

	TIM16_set_wgm(_tim , WGM_PWM_PC_9);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);

	TIM16_set_wgm(_tim , WGM_RESERVED);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);

	TIM16_set_wgm(_tim , WGM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}
#pragma endregion

#pragma region CS_Tests

TEST(TEST_TIM , TIM16_set_CSCanBeCalled)
{
	TIM16_set_cs(_tim , CS_NO_CLK);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToNoCLK)
{
	TIM16_set_cs(_tim , CS_NO_CLK);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToCLKDiv1)
{
	TIM16_set_cs(_tim , CS_CLK_DIV1);
	CHECK_EQUAL_C_UBYTE(0x01 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToCLKDiv8)
{
	TIM16_set_cs(_tim , CS_CLK_DIV8);
	CHECK_EQUAL_C_UBYTE(0x02 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToCLKDiv64)
{
	TIM16_set_cs(_tim , CS_CLK_DIV64);
	CHECK_EQUAL_C_UBYTE(0x03 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToCLKDiv256)
{
	TIM16_set_cs(_tim , CS_CLK_DIV256);
	CHECK_EQUAL_C_UBYTE(0x04 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToCLKDiv1024)
{
	TIM16_set_cs(_tim , CS_CLK_DIV1024);
	CHECK_EQUAL_C_UBYTE(0x05 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToExtFalling)
{
	TIM16_set_cs(_tim , CS_EXT_FALLING);
	CHECK_EQUAL_C_UBYTE(0x06 , _tim->TCCRB);
}

TEST(TEST_TIM , TIM16_set_CSCanBeSetToExtRising)
{
	TIM16_set_cs(_tim , CS_EXT_RISING);
	CHECK_EQUAL_C_UBYTE(0x07 , _tim->TCCRB);
}

TEST(TEST_TIM , SCSCanBeReset)
{
	TIM16_set_cs(_tim , CS_EXT_FALLING);
	CHECK_EQUAL_C_UBYTE(0x06 , _tim->TCCRB);

	TIM16_set_cs(_tim , CS_CLK_DIV256);
	CHECK_EQUAL_C_UBYTE(0x04 , _tim->TCCRB);

	TIM16_set_cs(_tim , CS_NO_CLK);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRB);
}
#pragma endregion

#pragma region COM_Tests

TEST(TEST_TIM , TIM16_set_COMCanBeCalled)
{
	TIM16_set_com(_tim , OCR_A, COM_NORMAL);
}

TEST(TEST_TIM , ChannelACanBeSetNormal)
{
	TIM16_set_com(_tim , OCR_A , COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelBCanBeSetNormal)
{
	TIM16_set_com(_tim , OCR_B , COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelCCanBeSetNormal)
{
	TIM16_set_com(_tim , OCR_C , COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelACanBeSetToToggle)
{
	TIM16_set_com(_tim , OCR_A , COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0x40 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelBCanBeSetToToggle)
{
	TIM16_set_com(_tim , OCR_B , COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0x10 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelCCanBeSetToToggle)
{
	TIM16_set_com(_tim , OCR_C , COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0x04 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelACanBeSetToClear)
{
	TIM16_set_com(_tim , OCR_A , COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0x80 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelBCanBeSetToClear)
{
	TIM16_set_com(_tim , OCR_B , COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0x20 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelCCanBeSetToClear)
{
	TIM16_set_com(_tim , OCR_C , COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0x08 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelACanBeSetToSet)
{
	TIM16_set_com(_tim , OCR_A , COM_SET);
	CHECK_EQUAL_C_UBYTE(0xC0 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelBCanBeSetToSet)
{
	TIM16_set_com(_tim , OCR_B , COM_SET);
	CHECK_EQUAL_C_UBYTE(0x30 , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelCCanBeSetToSet)
{
	TIM16_set_com(_tim , OCR_C , COM_SET);
	CHECK_EQUAL_C_UBYTE(0x0C , _tim->TCCRA);
}

TEST(TEST_TIM , ChannelSetIsIndependent)
{
	TIM16_set_com(_tim , OCR_A , COM_SET);
	CHECK_EQUAL_C_UBYTE(0xC0 , _tim->TCCRA);

	TIM16_set_com(_tim , OCR_B , COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0xD0 , _tim->TCCRA);

	TIM16_set_com(_tim , OCR_C , COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0xD8 , _tim->TCCRA);

	TIM16_set_com(_tim , OCR_A , COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x18 , _tim->TCCRA);
}
#pragma endregion


