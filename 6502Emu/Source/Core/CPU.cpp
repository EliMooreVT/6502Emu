#include "stdIncludes.h"

namespace CPU {

	void initCPU()
	{
		g_cpu = new C6502();
	}

	void destrCPU()
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
		//Reset Registers
		m_registers.a, m_registers.x,
			m_registers.y, m_registers.sp = 0x00;



	}
}