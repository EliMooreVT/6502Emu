#pragma once
#include "TypeDec.h"
#include <string>
#include <iostream>

namespace Utils
{
	std::string hexString(BYTE data);
	std::string hexString(BIT_16 data);
	BIT_16 concBytes(BYTE a, BYTE b);
	static void test()
	{
		std::cout << "TestTest";
	}
}