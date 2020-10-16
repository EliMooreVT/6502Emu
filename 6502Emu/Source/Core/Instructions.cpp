#include "Common\Utils.h"
#include <iostream>
#include "stdIncludes.h"
namespace CPU
{
	void C6502::execute()
	{
		BYTE regs[3] = {
				getRegister_a(),
				getRegister_x(),
				getRegister_y()
		};
		Debug::updateMV(
			g_memory->getBuffer(),
			m_flags,
			regs,
			g_pc - 1,
			0x0000,
			0x00ff,
			0x0f
		);
		switch (m_instructionRegister)
		{
		case 0xea: nop();     break;
		case 0xa9: lda_imm(); break;
		case 0xa5: lda_zp();  break;
		case 0x85: sta_zp();  break;
		case 0x8d: sta_abs(); break;
		case 0x38: sec();     break;
		case 0x18: clc();     break;
		case 0x69: adc_imm(); break;
		case 0x4c: jmp_abs(); break;
		default: nop(); break;
		}
	}

	void C6502::nop()
	{
		fetchInstruction();
	}

	void C6502::lda_imm()
	{
		fetchInstruction();
		setRegister_a(readInstruction());
		fetchInstruction();
	}
	void C6502::lda_zp()
	{
		fetchInstruction();
		setRegister_a(g_memory->getByte(readInstruction()));
		fetchInstruction();
	}

	void C6502::sta_zp()
	{
		fetchInstruction();
		BYTE byte = readInstruction();
		g_memory->setByte(byte, getRegister_a());
		fetchInstruction();
	}
	void C6502::sta_abs()
	{
		fetchInstruction();
		BYTE b1 = readInstruction();
		fetchInstruction();
		BYTE b2 = readInstruction();
		setRegister_a(Utils::concBytes(b2,b1));
	}

	void C6502::sec()
	{
		setFlag(F_CARRY, true);
		fetchInstruction();
	}
	void C6502::clc()
	{
		setFlag(F_CARRY, false);
		fetchInstruction();
	}

	void C6502::adc_imm()
	{
		fetchInstruction();
		BYTE byte = readInstruction();
		BYTE a = getRegister_a();
		BIT_16 sum = a + byte;
		
		if (sum > 0xff)
		{
			setFlag(F_CARRY, true);
		}

		setRegister_a(byte + a);
		fetchInstruction();
	}

	void C6502::jmp_abs()
	{
		fetchInstruction();
		BYTE b1 = readInstruction();
		fetchInstruction();
		BYTE b2 = readInstruction();
		g_pc = Utils::concBytes(b2,b1);
		fetchInstruction();
		g_pc--;
	}
}