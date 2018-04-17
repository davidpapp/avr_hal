#include "CppUTest/TestHarness.h"
#include "CppUTest/TestHarness_c.h"
//#include "CppUTestExt/MockSupport.h"


extern "C" {
#include <time.h> 
#include "../../../Code/AVR_HAL/AVR_HAL/HAL/Gpio.h"
};

TEST_GROUP(TEST_GPIO)
{
	void setup( )
	{

	}

	void teardown( )
	{

	}

};

#pragma region gpio_memoy_mapping
TEST(TEST_GPIO , GPIOAIsDefined)
{
	GPIOA;
}

TEST(TEST_GPIO , GPIOGIsDefined)
{
	GPIOG;
}

TEST(TEST_GPIO , GPIOHIsDefined)
{
	GPIOH;
}

TEST(TEST_GPIO , GPIOLIsDefined)
{
	GPIOL;
}

TEST(TEST_GPIO , GPIOAAddressesAreCorrect)
{

	CHECK_EQUAL_C_ULONG(0x20 , (uint32_t) &(GPIOA->PIN));
	CHECK_EQUAL_C_ULONG(0x21 , (uint32_t) &(GPIOA->DDR));
	CHECK_EQUAL_C_ULONG(0x22 , (uint32_t) &(GPIOA->PORT));
}

TEST(TEST_GPIO , GPIOHAddressesAreCorrect)
{

	CHECK_EQUAL_C_ULONG(0x100 , (uint32_t) &(GPIOH->PIN));
	CHECK_EQUAL_C_ULONG(0x101 , (uint32_t) &(GPIOH->DDR));
	CHECK_EQUAL_C_ULONG(0x102 , (uint32_t) &(GPIOH->PORT));
}
#pragma endregion
