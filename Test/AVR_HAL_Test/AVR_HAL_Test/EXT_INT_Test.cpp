#include "CppUTest/TestHarness.h"
#include "CppUTest/TestHarness_c.h"
//#include "CppUTestExt/MockSupport.h"


extern "C" {
#include <time.h> 
#include "EXT_INT.h"
#include <avr/io.h>

	void do_nothing(uint8_t n);
};

void do_nothing(uint8_t n)
{

}

TEST_GROUP(TEST_EINT)
{
	void setup( )
	{
		memset(__avr_reg , 0 , _HIGHEST_REGISTER_ADD);
	}

	void teardown( )
	{

	}

};

#pragma region Enable_Tests

TEST(TEST_EINT , EXT_INT_EnableCanBeCalled)
{
	EXT_INT_enable(EXT_INT_0);
}

TEST(TEST_EINT , EXT_INT_0CanBeEnabled)
{
	EXT_INT_enable(EXT_INT_0);
	CHECK_EQUAL_C_UBYTE(0x01 , __avr_reg[0x3D]);
}


TEST(TEST_EINT , EXT_INT_1CanBeEnabled)
{
	EXT_INT_enable(EXT_INT_1);
	CHECK_EQUAL_C_UBYTE(0x02 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_2CanBeEnabled)
{
	EXT_INT_enable(EXT_INT_2);
	CHECK_EQUAL_C_UBYTE(0x04 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_3CanBeEnabled)
{
	EXT_INT_enable(EXT_INT_3);
	CHECK_EQUAL_C_UBYTE(0x08 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_4CanBeEnabled)
{
	EXT_INT_enable(EXT_INT_4);
	CHECK_EQUAL_C_UBYTE(0x10 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_5CanBeEnabled)
{
	EXT_INT_enable(EXT_INT_5);
	CHECK_EQUAL_C_UBYTE(0x20 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_6CanBeEnabled)
{
	EXT_INT_enable(EXT_INT_6);
	CHECK_EQUAL_C_UBYTE(0x40 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_7CanBeEnabled)
{
	EXT_INT_enable(EXT_INT_7);
	CHECK_EQUAL_C_UBYTE(0x80 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EnableIsIndependent)
{
	EXT_INT_enable(EXT_INT_4);
	CHECK_EQUAL_C_UBYTE(0x10 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_0);
	CHECK_EQUAL_C_UBYTE(0x11 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_3);
	CHECK_EQUAL_C_UBYTE(0x19 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_7);
	CHECK_EQUAL_C_UBYTE(0x99 , __avr_reg[0x3D]);
}

#pragma endregion

#pragma region Disable_Tests

TEST(TEST_EINT , EXT_INT_DisableCanBeCalled)
{
	EXT_INT_disable(EXT_INT_0);
}

TEST(TEST_EINT , EXT_INT_0CanBeDisabled)
{
	__avr_reg[0x3D] = 0xFF;
	EXT_INT_disable(EXT_INT_0);
	CHECK_EQUAL_C_UBYTE(0xFE , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_1CanBeDisabled)
{
	__avr_reg[0x3D] = 0xFF;
	EXT_INT_disable(EXT_INT_1);
	CHECK_EQUAL_C_UBYTE(0xFD , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_2CanBeDisabled)
{
	__avr_reg[0x3D] = 0xFF;
	EXT_INT_disable(EXT_INT_2);
	CHECK_EQUAL_C_UBYTE(0xFB , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_3CanBeDisabled)
{
	__avr_reg[0x3D] = 0xFF;
	EXT_INT_disable(EXT_INT_3);
	CHECK_EQUAL_C_UBYTE(0xF7 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_4CanBeDisabled)
{
	__avr_reg[0x3D] = 0xFF;
	EXT_INT_disable(EXT_INT_4);
	CHECK_EQUAL_C_UBYTE(0xEF , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_5CanBeDisabled)
{
	__avr_reg[0x3D] = 0xFF;
	EXT_INT_disable(EXT_INT_5);
	CHECK_EQUAL_C_UBYTE(0xDF , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_6CanBeDisabled)
{
	__avr_reg[0x3D] = 0xFF;
	EXT_INT_disable(EXT_INT_6);
	CHECK_EQUAL_C_UBYTE(0xBF , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_7CanBeDisabled)
{
	__avr_reg[0x3D] = 0xFF;
	EXT_INT_disable(EXT_INT_7);
	CHECK_EQUAL_C_UBYTE(0x7F , __avr_reg[0x3D]);
}

TEST(TEST_EINT , DisableIsIndependent)
{
	__avr_reg[0x3D] = 0xFF;
	EXT_INT_disable(EXT_INT_4);
	CHECK_EQUAL_C_UBYTE(0xEF , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_3);
	CHECK_EQUAL_C_UBYTE(0xE7 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_1);
	CHECK_EQUAL_C_UBYTE(0xE5 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_5);
	CHECK_EQUAL_C_UBYTE(0xC5 , __avr_reg[0x3D]);
}

#pragma endregion

#pragma region EnableDisableTransition_Tests

TEST(TEST_EINT , EXT_INT_0CanBeToggled)
{
	EXT_INT_enable(EXT_INT_0);
	CHECK_EQUAL_C_UBYTE(0x01 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_0);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_0);
	CHECK_EQUAL_C_UBYTE(0x01 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_0);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_1CanBeToggled)
{
	EXT_INT_enable(EXT_INT_1);
	CHECK_EQUAL_C_UBYTE(0x02 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_1);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_1);
	CHECK_EQUAL_C_UBYTE(0x02 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_1);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_2CanBeToggled)
{
	EXT_INT_enable(EXT_INT_2);
	CHECK_EQUAL_C_UBYTE(0x04 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_2);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_2);
	CHECK_EQUAL_C_UBYTE(0x04 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_2);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_3CanBeToggled)
{
	EXT_INT_enable(EXT_INT_3);
	CHECK_EQUAL_C_UBYTE(0x08 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_3);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_3);
	CHECK_EQUAL_C_UBYTE(0x08 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_3);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_4CanBeToggled)
{
	EXT_INT_enable(EXT_INT_4);
	CHECK_EQUAL_C_UBYTE(0x10 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_4);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_4);
	CHECK_EQUAL_C_UBYTE(0x10 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_4);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_5CanBeToggled)
{
	EXT_INT_enable(EXT_INT_5);
	CHECK_EQUAL_C_UBYTE(0x20 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_5);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_5);
	CHECK_EQUAL_C_UBYTE(0x20 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_5);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_6CanBeToggled)
{
	EXT_INT_enable(EXT_INT_6);
	CHECK_EQUAL_C_UBYTE(0x40 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_6);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_6);
	CHECK_EQUAL_C_UBYTE(0x40 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_6);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , EXT_INT_7CanBeToggled)
{
	EXT_INT_enable(EXT_INT_7);
	CHECK_EQUAL_C_UBYTE(0x80 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_7);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_7);
	CHECK_EQUAL_C_UBYTE(0x80 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_7);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);
}

TEST(TEST_EINT , ToggleIsIndependent)
{
	EXT_INT_enable(EXT_INT_6);
	CHECK_EQUAL_C_UBYTE(0x40 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_3);
	CHECK_EQUAL_C_UBYTE(0x48 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_6);
	CHECK_EQUAL_C_UBYTE(0x08 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_7);
	CHECK_EQUAL_C_UBYTE(0x88 , __avr_reg[0x3D]);

	EXT_INT_enable(EXT_INT_2);
	CHECK_EQUAL_C_UBYTE(0x8C , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_3);
	CHECK_EQUAL_C_UBYTE(0x84 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_2);
	CHECK_EQUAL_C_UBYTE(0x80 , __avr_reg[0x3D]);

	EXT_INT_disable(EXT_INT_7);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x3D]);
}

#pragma endregion

#pragma region Set_sense_Tests

TEST(TEST_EINT , Set_SenseCanBeCalled)
{
	EXT_INT_set_sense(EXT_INT_0 , EXT_INT_ISC_ANY);
}

TEST(TEST_EINT , EINT0CanBeSetToLow)
{
	EXT_INT_set_sense(EXT_INT_0 , EXT_INT_ISC_LOW);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT0CanBeSetToAny)
{
	EXT_INT_set_sense(EXT_INT_0 , EXT_INT_ISC_ANY);
	CHECK_EQUAL_C_UBYTE(0x01 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT0CanBeSetToFalling)
{
	EXT_INT_set_sense(EXT_INT_0 , EXT_INT_ISC_FALLING);
	CHECK_EQUAL_C_UBYTE(0x02 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT0CanBeSetToRising)
{
	EXT_INT_set_sense(EXT_INT_0 , EXT_INT_ISC_RISING);
	CHECK_EQUAL_C_UBYTE(0x03 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT1CanBeSetToLow)
{
	EXT_INT_set_sense(EXT_INT_1 , EXT_INT_ISC_LOW);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT1CanBeSetToAny)
{
	EXT_INT_set_sense(EXT_INT_1 , EXT_INT_ISC_ANY);
	CHECK_EQUAL_C_UBYTE(0x04 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT1CanBeSetToFalling)
{
	EXT_INT_set_sense(EXT_INT_1 , EXT_INT_ISC_FALLING);
	CHECK_EQUAL_C_UBYTE(0x08 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT1CanBeSetToRising)
{
	EXT_INT_set_sense(EXT_INT_1 , EXT_INT_ISC_RISING);
	CHECK_EQUAL_C_UBYTE(0x0C , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT2CanBeSetToLow)
{
	EXT_INT_set_sense(EXT_INT_2 , EXT_INT_ISC_LOW);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT2CanBeSetToAny)
{
	EXT_INT_set_sense(EXT_INT_2 , EXT_INT_ISC_ANY);
	CHECK_EQUAL_C_UBYTE(0x10 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT2CanBeSetToFalling)
{
	EXT_INT_set_sense(EXT_INT_2 , EXT_INT_ISC_FALLING);
	CHECK_EQUAL_C_UBYTE(0x20 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT2CanBeSetToRising)
{
	EXT_INT_set_sense(EXT_INT_2 , EXT_INT_ISC_RISING);
	CHECK_EQUAL_C_UBYTE(0x30 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT3CanBeSetToLow)
{
	EXT_INT_set_sense(EXT_INT_3 , EXT_INT_ISC_LOW);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT3CanBeSetToAny)
{
	EXT_INT_set_sense(EXT_INT_3 , EXT_INT_ISC_ANY);
	CHECK_EQUAL_C_UBYTE(0x40 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT3CanBeSetToFalling)
{
	EXT_INT_set_sense(EXT_INT_3 , EXT_INT_ISC_FALLING);
	CHECK_EQUAL_C_UBYTE(0x80 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT3CanBeSetToRising)
{
	EXT_INT_set_sense(EXT_INT_3 , EXT_INT_ISC_RISING);
	CHECK_EQUAL_C_UBYTE(0xC0 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT4CanBeSetToLow)
{
	EXT_INT_set_sense(EXT_INT_4 , EXT_INT_ISC_LOW);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT4CanBeSetToAny)
{
	EXT_INT_set_sense(EXT_INT_4 , EXT_INT_ISC_ANY);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x01 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT4CanBeSetToFalling)
{
	EXT_INT_set_sense(EXT_INT_4 , EXT_INT_ISC_FALLING);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x02 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT4CanBeSetToRising)
{
	EXT_INT_set_sense(EXT_INT_4 , EXT_INT_ISC_RISING);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x03 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT5CanBeSetToLow)
{
	EXT_INT_set_sense(EXT_INT_5 , EXT_INT_ISC_LOW);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT5CanBeSetToAny)
{
	EXT_INT_set_sense(EXT_INT_5 , EXT_INT_ISC_ANY);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x04 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT5CanBeSetToFalling)
{
	EXT_INT_set_sense(EXT_INT_5 , EXT_INT_ISC_FALLING);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x08 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT5CanBeSetToRising)
{
	EXT_INT_set_sense(EXT_INT_5 , EXT_INT_ISC_RISING);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x0C , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT6CanBeSetToLow)
{
	EXT_INT_set_sense(EXT_INT_6 , EXT_INT_ISC_LOW);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT6CanBeSetToAny)
{
	EXT_INT_set_sense(EXT_INT_6 , EXT_INT_ISC_ANY);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x10 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT6CanBeSetToFalling)
{
	EXT_INT_set_sense(EXT_INT_6 , EXT_INT_ISC_FALLING);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x20 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT6CanBeSetToRising)
{
	EXT_INT_set_sense(EXT_INT_6 , EXT_INT_ISC_RISING);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x30 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT7CanBeSetToLow)
{
	EXT_INT_set_sense(EXT_INT_7 , EXT_INT_ISC_LOW);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT7CanBeSetToAny)
{
	EXT_INT_set_sense(EXT_INT_7 , EXT_INT_ISC_ANY);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x40 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT7CanBeSetToFalling)
{
	EXT_INT_set_sense(EXT_INT_7 , EXT_INT_ISC_FALLING);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x80 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , EINT7CanBeSetToRising)
{
	EXT_INT_set_sense(EXT_INT_7 , EXT_INT_ISC_RISING);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0xC0 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , SetIsIndependent)
{
	EXT_INT_set_sense(EXT_INT_7 , EXT_INT_ISC_RISING);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0xC0 , __avr_reg[0x6A]);

	EXT_INT_set_sense(EXT_INT_0 , EXT_INT_ISC_ANY);
	CHECK_EQUAL_C_UBYTE(0x01 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0xC0 , __avr_reg[0x6A]);

	EXT_INT_set_sense(EXT_INT_1 , EXT_INT_ISC_FALLING);
	CHECK_EQUAL_C_UBYTE(0x09 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0xC0 , __avr_reg[0x6A]);

	EXT_INT_set_sense(EXT_INT_4 , EXT_INT_ISC_RISING);
	CHECK_EQUAL_C_UBYTE(0x09 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0xC3 , __avr_reg[0x6A]);
}

TEST(TEST_EINT , CanBeReset)
{
	EXT_INT_set_sense(EXT_INT_6 , EXT_INT_ISC_RISING);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x30 , __avr_reg[0x6A]);

	EXT_INT_set_sense(EXT_INT_6 , EXT_INT_ISC_ANY);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x10 , __avr_reg[0x6A]);

	EXT_INT_set_sense(EXT_INT_6 , EXT_INT_ISC_FALLING);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x20 , __avr_reg[0x6A]);

	EXT_INT_set_sense(EXT_INT_0 , EXT_INT_ISC_RISING);
	CHECK_EQUAL_C_UBYTE(0x03 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x20 , __avr_reg[0x6A]);

	EXT_INT_set_sense(EXT_INT_4 , EXT_INT_ISC_ANY);
	CHECK_EQUAL_C_UBYTE(0x03 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x21 , __avr_reg[0x6A]);

	EXT_INT_set_sense(EXT_INT_0 , EXT_INT_ISC_LOW);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x21 , __avr_reg[0x6A]);

	EXT_INT_set_sense(EXT_INT_6 , EXT_INT_ISC_LOW);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x01 , __avr_reg[0x6A]);

	EXT_INT_set_sense(EXT_INT_4 , EXT_INT_ISC_LOW);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x69]);
	CHECK_EQUAL_C_UBYTE(0x00 , __avr_reg[0x6A]);
}

#pragma endregion

#pragma region Callback_Tests

TEST(TEST_EINT , Set_CallbackCanBeCalled)
{
	EXT_INT_set_callback(do_nothing);
}

#pragma endregion
