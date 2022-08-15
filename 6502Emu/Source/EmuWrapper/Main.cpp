#include "Core/Emu.h"
#include <iostream>
#include <Assembler/Assembler.h>
#include <Common/Utils.h>

int main()
{

	Debug::startDebugger();
	Debug::mvEnable();
	Debug::enablePrint();
	Debug::disableSteps();

	//Assembler::assembleFromFile("Code.asm");

	Emu::startSystem();

	Emu::endSystem();
	
	
}