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

	void C6502::fetchInstruction()
	{
		m_instructionRegister = g_memory->getByte(g_pc);
		g_pc++;
	}

	BYTE C6502::readInstruction()
	{
		return m_instructionRegister;
	}

	void C6502::run()
	{
		Debug::println("Run CPU");
		//Debug::Enable();
		Debug::disableSteps();
		//Debug::mvDisable();

		//BYTE a = 0x12;
		//BYTE b = 0x34;

		//BIT_16 c = a << 8;

		//BIT_16 result = Utils::concBytes(a,b);

		//std::cout << std::hex << c + b;

		fetchInstruction();
		while (readInstruction() != 0x00)
		{
			execute();
		}
	}

	

	C6502::C6502()
	{
		//Reset Registers
		setRegister_a(0x00);
		setRegister_x(0x00);
		setRegister_y(0x00);

		m_instructionRegister = 0xea;

		//Set flags to 0
		for (int i = 0; i < 6; i++)
		{ m_flags[i] = 0; }



	}

	//Register Getters
	BYTE C6502::getRegister_a()
	{ return m_registers.a; }
	BYTE C6502::getRegister_x()
	{ return m_registers.x; }
	BYTE C6502::getRegister_y()
	{ return m_registers.y; }
	BYTE C6502::getRegister_sp()
	{ return m_registers.sp; }

	//Register Setters
	void C6502::setRegister_a(BYTE b)
	{ m_registers.a = b; }
	void C6502::setRegister_x(BYTE b)
	{ m_registers.x = b; }
	void C6502::setRegister_y(BYTE b)
	{ m_registers.y = b; }
	void C6502::setRegister_sp(BYTE b)
	{ m_registers.a = b; }

	//Flag Getter
	bool C6502::getFlag(int flag)
	{ return g_cpu->m_flags[flag]; }
	//Flag Setter
	void C6502::setFlag(int flag, bool b)
	{ g_cpu->m_flags[flag] = b; }




}