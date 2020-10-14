#include "stdIncludes.h"
#include "Emu.h"

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
