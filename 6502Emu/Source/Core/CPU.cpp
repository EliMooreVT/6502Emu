#include "stdIncludes.h"

void C6502::initCPU()
{
	g_cpu = new C6502();
}

void C6502::destrCPU()
{
	delete g_cpu;
	g_cpu = nullptr;
}

C6502::C6502()
{

}