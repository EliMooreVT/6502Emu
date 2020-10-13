#pragma once
#include "Common\TypeDec.h"
#include "stdIncludes.h"

typedef struct SRegisters
{
	BYTE a,x,y;
} Registers;

class C6502
{
public:
	C6502();

	static void initCPU();
	static void destrCPU();

	void run();
private:
	Registers m_registers;
};