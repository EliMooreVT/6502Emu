#include "Core\Emu.h"
#include <iostream>

int main()
{
	
	Debug::Enable();
	Emu::startSystem();

	Emu::endSystem();
	
	
}