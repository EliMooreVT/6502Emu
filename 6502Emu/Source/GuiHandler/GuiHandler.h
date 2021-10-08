#pragma once
#include "App.h"
#include "Common/TypeDec.h"
#include <functional>


extern void SetGui();

namespace GuiData
{
	namespace Function
	{
		extern void(*initSystem)();
		extern void(*OpenFile)(std::string);
		extern Buffer(*GetMemory)();
		extern BIT_16(*GetPC)();
	}
}

class GuiHandler
{
public:


private:
	GuiHandler() {};
	
	int m_id = 0;
};

