#include "debugger.h"

namespace Debug
{

	namespace //Private Variables
	{
		bool m_enabled;
	}

	void print(std::string str)
	{
		if (m_enabled)
		{
			std::cout << str;
		}
	}

	void println(std::string str)
	{
		if (m_enabled)
		{
			std::cout << str << std::endl;
		}

	}

	void printBr()
	{
		std::cout << std::endl << "----------------------" << std::endl;
	}

	void Enable()
	{
		m_enabled = true;
	}

	void Disable()
	{
		m_enabled = false;
	}
}

