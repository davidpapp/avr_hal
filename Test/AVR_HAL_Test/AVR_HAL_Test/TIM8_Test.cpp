#include "CppUTest/TestHarness.h"
#include "CppUTest/TestHarness_c.h"
//#include "CppUTestExt/MockSupport.h"


extern "C" {
#include <time.h> 
#include "tim8.h"
	static volatile TIM8_t _tim = { (TIM8_Control_t*)(__avr_reg + 0x44), (uint8_t*)(__avr_reg + 0x6E), (uint8_t*)(__avr_reg + 0x35) };
	
	void testCallback()
	{
	};
};

TEST_GROUP(TEST_TIM8)
{
	void setup()
	{
		memset(__avr_reg, 0, _HIGHEST_REGISTER_ADD);
		_tim.p_ovr_cb = NULL;
		_tim.p_compa_cb = NULL;
		_tim.p_compb_cb = NULL;
	}

	void teardown()
	{

	}

};

#pragma region WGM_TESTS

TEST(TEST_TIM8, IsSet_WGMCanBeCalled)
{
	TIM8_set_wgm(&_tim, TIM8_WGM_NORMAL);
}

TEST(TEST_TIM8, IsWGMCanBeSetToNormal)
{
	TIM8_set_wgm(&_tim, TIM8_WGM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x44]);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsWGMCanBeSetToPWM_PC_TOP)
{
	TIM8_set_wgm(&_tim, TIM8_WGM_PWM_PC_TOP);
	CHECK_EQUAL_C_UBYTE(0x01, __avr_reg[0x44]);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsWGMCanBeSetToCTC)
{
	TIM8_set_wgm(&_tim, TIM8_WGM_CTC);
	CHECK_EQUAL_C_UBYTE(0x02, __avr_reg[0x44]);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsWGMCanBeSetToFast_PWM_Top)
{
	TIM8_set_wgm(&_tim, TIM8_WGM_FAST_PWM_TOP);
	CHECK_EQUAL_C_UBYTE(0x03, __avr_reg[0x44]);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsWGMCanBeSetToPWM_PC_OCRA)
{
	TIM8_set_wgm(&_tim, TIM8_WGM_PWM_PC_OCRA);
	CHECK_EQUAL_C_UBYTE(0x01, __avr_reg[0x44]);
	CHECK_EQUAL_C_UBYTE(0x08, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsWGMCanBeSetToFast_PWM_OCRA)
{
	TIM8_set_wgm(&_tim, TIM8_WGM_FAST_PWM_OCRA);
	CHECK_EQUAL_C_UBYTE(0x03, __avr_reg[0x44]);
	CHECK_EQUAL_C_UBYTE(0x08, __avr_reg[0x45]);
}

TEST(TEST_TIM8, DoesSet_WGMToReserved_1SetToNormal)
{
	TIM8_set_wgm(&_tim, TIM8_WGM_RESERVED_1);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x44]);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x45]);
}

TEST(TEST_TIM8, DoesSet_WGMToReserved_2SetToNormal)
{
	TIM8_set_wgm(&_tim, TIM8_WGM_RESERVED_2);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x44]);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsWGMCanBeToggled)
{
	TIM8_set_wgm(&_tim, TIM8_WGM_FAST_PWM_OCRA);
	TIM8_set_wgm(&_tim, TIM8_WGM_CTC);
	CHECK_EQUAL_C_UBYTE(0x02, __avr_reg[0x44]);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x45]);
}

TEST(TEST_TIM8, DoesNotSet_WGMAlterOtherBits)
{
	__avr_reg[0x44] = 0xFF;
	__avr_reg[0x45] = 0xFF;
	TIM8_set_wgm(&_tim, TIM8_WGM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0xFC, __avr_reg[0x44]);
	CHECK_EQUAL_C_UBYTE(0xF7, __avr_reg[0x45]);
}

#pragma endregion //WGM_TESTS

#pragma region CS_Tests

TEST(TEST_TIM8, IsSet_CSCanBeCalled)
{
	TIM8_set_cs(&_tim, TIM8_CS_NO_CLK);
}

TEST(TEST_TIM8, IsCSCanBeSetToNoCLK)
{
	TIM8_set_cs(&_tim, TIM8_CS_NO_CLK);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x44]);
}

TEST(TEST_TIM8, IsCSCanBeSetToCLK_DIV1)
{
	TIM8_set_cs(&_tim, TIM8_CS_CLK_DIV1);
	CHECK_EQUAL_C_UBYTE(0x01, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsCSCanBeSetToCLK_DIV8)
{
	TIM8_set_cs(&_tim, TIM8_CS_CLK_DIV8);
	CHECK_EQUAL_C_UBYTE(0x02, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsCSCanBeSetToCLK_DIV64)
{
	TIM8_set_cs(&_tim, TIM8_CS_CLK_DIV64);
	CHECK_EQUAL_C_UBYTE(0x03, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsCSCanBeSetToCLK_DIV256)
{
	TIM8_set_cs(&_tim, TIM8_CS_CLK_DIV256);
	CHECK_EQUAL_C_UBYTE(0x04, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsCSCanBeSetToCLK_DIV1024)
{
	TIM8_set_cs(&_tim, TIM8_CS_CLK_DIV1024);
	CHECK_EQUAL_C_UBYTE(0x05, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsCSCanBeSetToEXT_Falling)
{
	TIM8_set_cs(&_tim, TIM8_CS_EXT_FALLING);
	CHECK_EQUAL_C_UBYTE(0x06, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsCSCanBeSetToEXT_Rising)
{
	TIM8_set_cs(&_tim, TIM8_CS_EXT_RISING);
	CHECK_EQUAL_C_UBYTE(0x07, __avr_reg[0x45]);
}

TEST(TEST_TIM8, IsCSCanBeToggled)
{
	TIM8_set_cs(&_tim, TIM8_CS_EXT_RISING);
	TIM8_set_cs(&_tim, TIM8_CS_NO_CLK);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x45]);
}

TEST(TEST_TIM8, DoesSet_CSNotAlterAnyOtherBit)
{
	__avr_reg[0x45] = 0xFF;
	TIM8_set_cs(&_tim, TIM8_CS_NO_CLK);
	CHECK_EQUAL_C_UBYTE(0xF8, __avr_reg[0x45]);
}

#pragma endregion //CS_Tests

#pragma region COM_Tests

TEST(TEST_TIM8, IsSet_COMCanBeCalled)
{
	TIM8_set_com(&_tim, TIM8_OCR_A, TIM8_COM_NORMAL);
}

TEST(TEST_TIM8, IsChannelACanBeSetNormal)
{
	TIM8_set_com(&_tim, TIM8_OCR_A, TIM8_COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x44]);
}

TEST(TEST_TIM8, IsChannelBCanBeSetNormal)
{
	TIM8_set_com(&_tim, TIM8_OCR_B, TIM8_COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x44]);
}

TEST(TEST_TIM8, IsChannelACanBeSetToggle)
{
	TIM8_set_com(&_tim, TIM8_OCR_A, TIM8_COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0x40, __avr_reg[0x44]);
}

TEST(TEST_TIM8, IsChannelBCanBeSetToggle)
{
	TIM8_set_com(&_tim, TIM8_OCR_B, TIM8_COM_TOGGLE);
	CHECK_EQUAL_C_UBYTE(0x10, __avr_reg[0x44]);
}

TEST(TEST_TIM8, IsChannelACanBeSetClear)
{
	TIM8_set_com(&_tim, TIM8_OCR_A, TIM8_COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0x80, __avr_reg[0x44]);
}

TEST(TEST_TIM8, IsChannelBCanBeSetClear)
{
	TIM8_set_com(&_tim, TIM8_OCR_B, TIM8_COM_CLEAR);
	CHECK_EQUAL_C_UBYTE(0x20, __avr_reg[0x44]);
}

TEST(TEST_TIM8, IsChannelACanBeSetSET)
{
	TIM8_set_com(&_tim, TIM8_OCR_A, TIM8_COM_SET);
	CHECK_EQUAL_C_UBYTE(0xC0, __avr_reg[0x44]);
}

TEST(TEST_TIM8, IsChannelBCanBeSetSET)
{
	TIM8_set_com(&_tim, TIM8_OCR_B, TIM8_COM_SET);
	CHECK_EQUAL_C_UBYTE(0x30, __avr_reg[0x44]);
}

TEST(TEST_TIM8, IsChannelACanBeToggled)
{
	TIM8_set_com(&_tim, TIM8_OCR_A, TIM8_COM_SET);
	TIM8_set_com(&_tim, TIM8_OCR_A, TIM8_COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x44]);
}

TEST(TEST_TIM8, IsChannelBCanBeToggled)
{
	TIM8_set_com(&_tim, TIM8_OCR_B, TIM8_COM_SET);
	TIM8_set_com(&_tim, TIM8_OCR_B, TIM8_COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x00, __avr_reg[0x44]);
}

TEST(TEST_TIM8, DoesSetChannelANotAlterAnyOtherBit)
{
	__avr_reg[0x44] = 0xFF;
	TIM8_set_com(&_tim, TIM8_OCR_A, TIM8_COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0x3F, __avr_reg[0x44]);
}

TEST(TEST_TIM8, DoesSetChannelBNotAlterAnyOtherBit)
{
	__avr_reg[0x44] = 0xFF;
	TIM8_set_com(&_tim, TIM8_OCR_B, TIM8_COM_NORMAL);
	CHECK_EQUAL_C_UBYTE(0xCF, __avr_reg[0x44]);
}

#pragma endregion //COM_Tests

#pragma region Enable_IRQ_Tests

TEST(TEST_TIM8, IsEnable_IRQCanBeCalled)
{
	TIM8_enable_interrupt(&_tim, TIM8_IRQ_OVERFLOW);
}

TEST(TEST_TIM8, IsOverflowIrqEnabled)
{
	TIM8_enable_interrupt(&_tim, TIM8_IRQ_OVERFLOW);
	CHECK_EQUAL_C_UBYTE(0x01, __avr_reg[0x6E]);
}

TEST(TEST_TIM8, IsOcrAMatchIrqEnabled)
{
	TIM8_enable_interrupt(&_tim, TIM8_IRQ_OCR_A_MATCH);
	CHECK_EQUAL_C_UBYTE(0x02, __avr_reg[0x6E]);
}

TEST(TEST_TIM8, IsOcrBMatchIrqEnabled)
{
	TIM8_enable_interrupt(&_tim, TIM8_IRQ_OCR_B_MATCH);
	CHECK_EQUAL_C_UBYTE(0x04, __avr_reg[0x6E]);
}

TEST(TEST_TIM8, DoeOverflowIrqEnableNotAlterAnyOtherBits)
{
	__avr_reg[0x6E] = 0xFE;
	TIM8_enable_interrupt(&_tim, TIM8_IRQ_OVERFLOW);
	CHECK_EQUAL_C_UBYTE(0xFF, __avr_reg[0x6E]);
}

TEST(TEST_TIM8, DoeOcrAMatchIrqEnableNotAlterAnyOtherBits)
{
	__avr_reg[0x6E] = 0xFD;
	TIM8_enable_interrupt(&_tim, TIM8_IRQ_OCR_A_MATCH);
	CHECK_EQUAL_C_UBYTE(0xFF, __avr_reg[0x6E]);
}

TEST(TEST_TIM8, DoeOcrBMatchIrqEnableNotAlterAnyOtherBits)
{
	__avr_reg[0x6E] = 0xFB;
	TIM8_enable_interrupt(&_tim, TIM8_IRQ_OCR_B_MATCH);
	CHECK_EQUAL_C_UBYTE(0xFF, __avr_reg[0x6E]);
}

#pragma endregion //Enable_IRQ_Tests

#pragma region Disable_IRQ_Tests

TEST(TEST_TIM8, IsDisable_IRQCanBeCalled)
{
	TIM8_disable_interrupt(&_tim, TIM8_IRQ_OVERFLOW);
}

TEST(TEST_TIM8, IsOverflowIrqDisabled)
{
	__avr_reg[0x6E] = 0xFF;
	TIM8_disable_interrupt(&_tim, TIM8_IRQ_OVERFLOW);
	CHECK_EQUAL_C_UBYTE(0xFE, __avr_reg[0x6E]);
}

TEST(TEST_TIM8, IsMatchOcraAIrqDisabled)
{
	__avr_reg[0x6E] = 0xFF;
	TIM8_disable_interrupt(&_tim, TIM8_IRQ_OCR_A_MATCH);
	CHECK_EQUAL_C_UBYTE(0xFD, __avr_reg[0x6E]);
}

TEST(TEST_TIM8, IsMatchOcraBIrqDisabled)
{
	__avr_reg[0x6E] = 0xFF;
	TIM8_disable_interrupt(&_tim, TIM8_IRQ_OCR_B_MATCH);
	CHECK_EQUAL_C_UBYTE(0xFB, __avr_reg[0x6E]);
}

#pragma endregion //Disable_IRQ_Tests

#pragma region Set_IRQ_Callback_Tests

TEST(TEST_TIM8, CanSet_IRQ_CallbackBeCalled)
{
	TIM8_set_interrupt_callback(&_tim, TIM8_IRQ_OVERFLOW, NULL);
}

TEST(TEST_TIM8, DoesOVRCallbackSetCorrectly)
{	
	TIM8_set_interrupt_callback(&_tim, TIM8_IRQ_OVERFLOW, testCallback);
	CHECK_EQUAL_C_POINTER(testCallback, _tim.p_ovr_cb);
	CHECK_EQUAL_C_POINTER(NULL, _tim.p_compa_cb);
	CHECK_EQUAL_C_POINTER(NULL, _tim.p_compb_cb);
}

TEST(TEST_TIM8, DoesCompACallbackSetCorrectly)
{
	TIM8_set_interrupt_callback(&_tim, TIM8_IRQ_OCR_A_MATCH, testCallback);
	CHECK_EQUAL_C_POINTER(testCallback, _tim.p_compa_cb);
	CHECK_EQUAL_C_POINTER(NULL, _tim.p_ovr_cb);
	CHECK_EQUAL_C_POINTER(NULL, _tim.p_compb_cb);
}

TEST(TEST_TIM8, DoesCompBCallbackSetCorrectly)
{
	TIM8_set_interrupt_callback(&_tim, TIM8_IRQ_OCR_B_MATCH, testCallback);
	CHECK_EQUAL_C_POINTER(testCallback, _tim.p_compb_cb);
	CHECK_EQUAL_C_POINTER(NULL, _tim.p_ovr_cb);
	CHECK_EQUAL_C_POINTER(NULL, _tim.p_compa_cb);
}


#pragma endregion //Set_IRQ_Callback_Tests

