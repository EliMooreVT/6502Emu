#pragma once
#include "stdIncludes.h"

typedef unsigned char BYTE;
typedef unsigned short BIT_16;

class CMemory
{
public:
	CMemory(BIT_16 memoryCapacity);
	static void initMemory();
	static void destrMemory();

	static BYTE getByte(BIT_16 address);
	static void setByte(BIT_16 address, BYTE value);


	friend class CMemory;
protected:

	BYTE * m_memory;
	BIT_16 m_memoryCapacity;


};