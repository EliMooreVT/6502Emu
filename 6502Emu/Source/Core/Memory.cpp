#include "stdIncludes.h"

CMemory::CMemory(BIT_16 memoryCapacity)
{
	m_memoryCapacity = memoryCapacity;
	//---Initialize Memory---
	m_memory = new BYTE[m_memoryCapacity];

}

void CMemory::initMemory()
{
	//---Create Global Memory---

	g_memory = new CMemory(0x5ff);
}

void CMemory::destrMemory()
{
	delete g_memory;
	g_memory = nullptr;
}

BYTE CMemory::getByte(BIT_16 address)
{
	if (address <= g_memory->m_memoryCapacity) {
		return g_memory->m_memory[address];
	}
	else {
		return 0x00; //TODO: Error Handling
	}
}

void CMemory::setByte(BIT_16 address, BYTE value)
{
	if (address <= g_memory->m_memoryCapacity) {
		g_memory->m_memory[address] = value;
	}
	else {
		//TODO: Error Handling
	}
}