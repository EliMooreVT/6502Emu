#include "Core\Emu.h"
#include <iostream>

int main()
{
	
	Debug::Enable();
	Debug::mvEnable();
	Debug::enableSteps();
	Emu::startSystem();

	Emu::endSystem();
	
	
}