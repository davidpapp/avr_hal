#include "CppUTest/CommandLineTestRunner.h"

extern "C" {
	uint8_t __avr_reg[_HIGHEST_REGISTER_ADD];
};

int main( int ac, char** av )
{
    return CommandLineTestRunner::RunAllTests( ac, av );
}