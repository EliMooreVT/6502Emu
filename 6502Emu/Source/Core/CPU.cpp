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

void C6502::run()
{
	Debug::println("Run CPU");
}

C6502::C6502()
{
	m_registers.a, m_registers.x, m_registers.y = 0x00;
}