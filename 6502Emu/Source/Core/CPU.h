#pragma once
#include "Common\TypeDec.h"
#include "stdIncludes.h"


namespace CPU {



	typedef struct SRegisters
	{
		//Main
		BYTE a;

		//Index
		BYTE x, y;

		//Stack Pointer
		BYTE sp;

	} Registers;

	enum FLAG
	{
		F_NEGATIVE,
		F_OVERFLOW,
		F_DECIMAL,
		F_INTERRUPT,
		F_ZERO,
		F_CARRY
	};

	void initCPU();
	void destrCPU();

	class C6502
	{
	public:
		C6502();

		void run();

		
		BYTE getRegister_a();
		BYTE getRegister_x();
		BYTE getRegister_y();
		BYTE getRegister_sp();
		
		void setRegister_a(BYTE b);
		void setRegister_x(BYTE b);
		void setRegister_y(BYTE b);
		void setRegister_sp(BYTE b);

		bool getFlag(int flag);
		void setFlag(int flag, bool b);

		void fetchInstruction();
		BYTE readInstruction();
		void execute();


		
	protected:
		BYTE m_instructionRegister;
		Registers m_registers;
		bool m_flags[6];

		//Instructions
		void nop();

		void lda_imm();
		void lda_zp();

		void sta_zp();
		void sta_abs();

		void sec();
		void clc();

		void adc_imm();
		void inx();

		void bcs_rel();

		void jmp_abs();

	};
}