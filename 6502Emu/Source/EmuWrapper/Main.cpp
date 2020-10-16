#include "Core\Emu.h"
#include <iostream>

int main()
{

	Debug::mvEnable();
	Debug::enablePrint();
	Debug::enableSteps();
	Emu::startSystem();

	Emu::endSystem();
	
	
}