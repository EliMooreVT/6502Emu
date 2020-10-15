#pragma once
#include "stdIncludes.h"

typedef unsigned char BYTE;
typedef unsigned short BIT_16;

class CMemory
{
public:
	CMemory(BIT_16 memoryCapacity);
	~CMemory();
	static void initMemory();
	static void destrMemory();

	BYTE getByte(BIT_16 address);
	void setByte(BIT_16 address, BYTE value);

	BIT_16 getCapacity();

	Buffer getBuffer();


	friend class CMemory;
protected:

	Buffer m_memory;
	BIT_16 m_memoryCapacity;


};