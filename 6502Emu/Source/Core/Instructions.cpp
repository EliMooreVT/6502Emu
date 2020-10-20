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
		case 0xea: nop();      break;
		case 0xa9: lda_imm();  break;
		case 0xa5: lda_zp();   break;
		case 0x85: sta_zp();   break;
		case 0x8d: sta_abs();  break;
		case 0x38: sec();      break;
		case 0x18: clc();      break;
		case 0x69: adc_imm();  break;
		case 0xe8: inx();      break;
		case 0xb0: bcs_rel();  break;
		case 0x4c: jmp_abs();  break;
		default:   nop();      break;
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
		setRegister_a(g_memory->getByte(Utils::concBytes(b2,b1)));
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
		else
		{
			setFlag(F_CARRY, false);
		}

		setRegister_a(byte + a);

		if (getRegister_a() == 0x00)
		{
			setFlag(F_ZERO, 1);
		}
		else
		{
			setFlag(F_ZERO, 0);
		}
		fetchInstruction();
	}
	void C6502::inx()
	{
		setRegister_x(getRegister_x() + 0x01);
		fetchInstruction();
	}

	void C6502::bcs_rel()
	{
		fetchInstruction();
		BYTE relLoc = readInstruction();
		if (getFlag(F_CARRY))
		{
			if (relLoc < 0x80)
			{
				g_pc += relLoc;
			}
			else
			{
				g_pc -= 0x0100 - relLoc;
			}

			
		}
		fetchInstruction();
	}
	void C6502::bcc_rel()
	{
		fetchInstruction();
		BYTE relLoc = readInstruction();
		if (!getFlag(F_CARRY))
		{
			if (relLoc < 0x80)
			{
				g_pc += relLoc;
			}
			else
			{
				g_pc -= 0x0100 - relLoc;
			}


		}
		fetchInstruction();
	}
	void C6502::beq_rel()
	{
		fetchInstruction();
		BYTE relLoc = readInstruction();
		if (getFlag(F_ZERO))
		{
			if (relLoc < 0x80)
			{
				g_pc += relLoc;
			}
			else
			{
				g_pc -= 0x0100 - relLoc;
			}


		}
		fetchInstruction();
	}
	void C6502::bne_rel()
	{
		fetchInstruction();
		BYTE relLoc = readInstruction();
		if (!getFlag(F_ZERO))
		{
			if (relLoc < 0x80)
			{
				g_pc += relLoc;
			}
			else
			{
				g_pc -= 0x0100 - relLoc;
			}


		}
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
	}
}