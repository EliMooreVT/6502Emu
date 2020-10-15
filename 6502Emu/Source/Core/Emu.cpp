#include "Emu.h"
#include "CPU.h"
#include "stdIncludes.h"


using namespace Emu;
void Emu::startSystem()
{
	CSystem::initSystem();
}

void Emu::endSystem()
{
	CSystem::destrSystem();
	CPU::destrCPU();
	CMemory::destrMemory();
}
