#include "stdIncludes.h"

CMemory::CMemory()
{

}

void CMemory::initMemory()
{
	g_memory = new CMemory();
}

void CMemory::destrMemory()
{
	delete g_memory;
	g_memory = nullptr;
}