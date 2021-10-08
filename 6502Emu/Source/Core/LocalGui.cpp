#include "LocalGui.h"
#include "System.h"

void SetGui()
{
	GuiData::Function::initSystem = []() { CSystem::initSystem(); };
	GuiData::Function::OpenFile = [](std::string s) {g_system->loadRom(s, 0x0600);};
	GuiData::Function::GetMemory = []() {return g_memory->getBuffer(); };
	GuiData::Function::GetPC = []() { return g_pc; };
}
