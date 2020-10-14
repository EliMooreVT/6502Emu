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

	enum FLAGS
	{

	};

	static void initCPU();
	static void destrCPU();

	class C6502
	{
	public:
		C6502();

		void run();

		struct getRegister
		{
			BYTE a();
			BYTE x();
			BYTE y();
			BYTE sp();
		};
		void getFlag();
		void setFlag();

	private:
		Registers m_registers;
		bool m_flags[6];

	};
}