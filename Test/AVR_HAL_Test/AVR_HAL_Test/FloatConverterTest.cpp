#include "CppUTest/TestHarness.h"
#include "CppUTest/TestHarness_c.h"
//#include "CppUTestExt/MockSupport.h"


extern "C" {
#include <time.h> 
#include <avr/io.h>
#include "float_converter.h"
};

TEST_GROUP(TEST_FLOAT)
{
	void setup()
	{
		memset(__avr_reg, 0, _HIGHEST_REGISTER_ADD);
	}

	void teardown()
	{

	}

};

#pragma region GET_INTEGER_TESTS

TEST(TEST_FLOAT, IsGetFractionCanBeCalled)
{
	float_converter_get_fraction(1.4, 1);
}

TEST(TEST_FLOAT, DoesGetIntegerReturnOIfInputNoOfDigitsIs0)
{
	uint16_t test_result = float_converter_get_fraction(1.5, 0);
	CHECK_EQUAL_C_UINT(0, test_result);

	test_result = float_converter_get_fraction(465.495, 0);
	CHECK_EQUAL_C_UINT(0, test_result);

	test_result = float_converter_get_fraction(51465.785, 0);
	CHECK_EQUAL_C_UINT(0, test_result);
}

TEST(TEST_FLOAT, DoesGetIntegerReturnCorrectIfNoOfDigitsIs1)
{
	uint16_t test_result = float_converter_get_fraction(1.5, 1);
	CHECK_EQUAL_C_UINT(5, test_result);

	test_result = float_converter_get_fraction(-35.2, 1);
	CHECK_EQUAL_C_UINT(2, test_result);

	test_result = float_converter_get_fraction(761246.9, 1);
	CHECK_EQUAL_C_UINT(9, test_result);
}

TEST(TEST_FLOAT, DoesGetIntegerReturnCorrectIfNoOfDigitsIs2)
{
	uint16_t test_result = float_converter_get_fraction(1.52, 2);
	CHECK_EQUAL_C_UINT(52, test_result);

	test_result = float_converter_get_fraction(-35.24, 2);
	CHECK_EQUAL_C_UINT(24, test_result);

	test_result = float_converter_get_fraction(76124.69, 2);
	CHECK_EQUAL_C_UINT(69, test_result);
}


TEST(TEST_FLOAT, DoesGetIntegerReturnCorrectIfNoOfDigitsIs3)
{
	uint16_t test_result = float_converter_get_fraction(1.527, 3);
	CHECK_EQUAL_C_UINT(527, test_result);

	test_result = float_converter_get_fraction(-35.246, 3);
	CHECK_EQUAL_C_UINT(246, test_result);

	test_result = float_converter_get_fraction(76124.697, 3);
	CHECK_EQUAL_C_UINT(695, test_result);
}

TEST(TEST_FLOAT, DoesGetIntegerReturnCorrectIfNoOfDigitsIs4)
{
	uint16_t test_result = float_converter_get_fraction(1.524237, 4);
	CHECK_EQUAL_C_UINT(5242, test_result);

	test_result = float_converter_get_fraction(-35.24678, 4);
	CHECK_EQUAL_C_UINT(2468, test_result);

	test_result = float_converter_get_fraction(7612.4697, 4);
	CHECK_EQUAL_C_UINT(4697, test_result);

	test_result = float_converter_get_fraction(7612.0, 4);
	CHECK_EQUAL_C_UINT(0000, test_result);
}


TEST(TEST_FLOAT, DoesGetIntegerReturnCorrectIfNoOfDigitsIsHigherThan4)
{
	uint16_t test_result = float_converter_get_fraction(1.524237, 5);
	CHECK_EQUAL_C_UINT(5242, test_result);

	test_result = float_converter_get_fraction(-35.24678238, 6);
	CHECK_EQUAL_C_UINT(2468, test_result);

	test_result = float_converter_get_fraction(76.124697, 7);
	CHECK_EQUAL_C_UINT(1247, test_result);
}

#pragma endregion
