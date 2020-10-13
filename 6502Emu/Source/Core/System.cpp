#include "Common\Utils.h"
#include "stdIncludes.h"

void CSystem::initSystem()
{
	g_system = new CSystem();
	CMemory::initMemory();
	C6502::initCPU();
	
	g_system->loadRom("Code.txt", 0x06ff);
	g_pc = 0x06ff;

	g_cpu->run();
	
	
}

void CSystem::destrSystem()
{
	Debug::println("Destroy System");
	delete g_system;
	g_system = nullptr;
}

CSystem::CSystem()
{
	Debug::println("Create System");
}


void CSystem::loadRom(std::string fileName, BIT_16 BufIdx)
{
	Debug::printBr();
	Debug::println("Loading Rom");
	Debug::println("Converting to binary file");
	FileConverter::ConvertToBin(fileName);
	Debug::println("Loading file into vector");
	std::vector<BYTE> rom = FileLoader::loadFile(FileLoader::rmExtension(fileName) + ".bin");

	Debug::println("Loading vector into memory");
	if (rom.size() + BufIdx <= g_memory->getCapacity())
	{
		for (int i = 0; i < rom.size(); i++)
		{
			g_memory->setByte(i + BufIdx,rom[i]);
		}
		Debug::println("Finish");
	}
	else
	{
		Debug::println("Not enough space for rom");
		//TODO: Error Handling
	}
	
}