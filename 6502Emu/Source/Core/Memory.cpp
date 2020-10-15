#include "stdIncludes.h"

CMemory::CMemory(BIT_16 memoryCapacity)
{
	m_memoryCapacity = memoryCapacity;
	//---Initialize Memory---
	m_memory = new BYTE[m_memoryCapacity];

}

CMemory::~CMemory()
{
	delete[] m_memory;
	m_memory = nullptr;
}

void CMemory::initMemory()
{
	//---Create Global Memory---

	g_memory = new CMemory(0xffff);

	for (BIT_16 i = 0x0000; i < 0xffff; i++)
	{
		g_memory->setByte(i,0x00);
	}
}

void CMemory::destrMemory()
{
	delete g_memory;
	g_memory = nullptr;
}

BYTE CMemory::getByte(BIT_16 address)
{
	if (address <= m_memoryCapacity) {
		return m_memory[address];
	}
	else {
		return 0x00; //TODO: Error Handling
	}
}

void CMemory::setByte(BIT_16 address, BYTE value)
{
	if (address <= m_memoryCapacity) {
		m_memory[address] = value;
	}
	else {
		//TODO: Error Handling
	}
}

BIT_16 CMemory::getCapacity()
{
	return m_memoryCapacity;
}

Buffer CMemory::getBuffer()
{
	return m_memory;
}