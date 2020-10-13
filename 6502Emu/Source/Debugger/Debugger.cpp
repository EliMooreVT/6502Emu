#include "debugger.h"

using namespace Debug;

void Debug::print(std::string str)
{
	std::cout << str;
}

void Debug::println(std::string str)
{
	std::cout << str << std::endl;
}