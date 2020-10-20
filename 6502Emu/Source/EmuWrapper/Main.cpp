#include "Core\Emu.h"
#include <iostream>

int main()
{

	Debug::mvEnable();
	Debug::enablePrint();
	Debug::disableSteps();
	Emu::startSystem();

	Emu::endSystem();
	
	
}