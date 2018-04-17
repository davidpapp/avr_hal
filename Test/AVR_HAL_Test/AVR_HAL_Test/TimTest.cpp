#include "CppUTest/TestHarness.h"
#include "CppUTest/TestHarness_c.h"
//#include "CppUTestExt/MockSupport.h"


extern "C" {
#include <time.h> 
#include "../../../Code/AVR_HAL/AVR_HAL/HAL/tim16.h"
	uint8_t __avr_reg[_HIGHEST_REGISTER_ADD];
	double __requested_delay_us = 0.0;
};

TEST_GROUP(TEST_TIM)
{
	void setup( )
	{

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
