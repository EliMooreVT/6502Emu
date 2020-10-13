#pragma once
#include <string>
#include <iostream>

typedef unsigned char BYTE;
typedef unsigned short BIT_16;



namespace Debug
{

	void print(std::string str);
	void println(std::string str);
	void printBr();
	void Enable();
	void Disable();
}