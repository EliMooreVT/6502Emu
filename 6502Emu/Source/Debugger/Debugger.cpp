#include "debugger.h"
#include <iomanip>

namespace Debug
{

	namespace //Private Variables
	{
		bool m_printEnabled;
		bool m_stepsEnabled;
		bool m_mvEnabled;
	}

	void print(std::string str)
	{
		if (m_printEnabled)
		{
			std::cout << str;
		}
	}

	void printb(BYTE b)
	{
		if (m_printEnabled)
		{
			std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)b;
		}
	}

	void printad(BIT_16 b)
	{
		if (m_printEnabled)
		{
			std::cout << std::setfill('0') << std::setw(4) << std::hex << (int)b;
		}
	}

	void println(std::string str)
	{
		if (m_printEnabled)
		{
			std::cout << str << std::endl;
		}

	}

	void printBr()
	{
		if (m_printEnabled)
		{
			std::cout << std::endl << "----------------------" << std::endl;
		}
		
	}

	void enablePrint()
	{ m_printEnabled = true; }
	void disablePrint()
	{ m_printEnabled = false; }

	void enableSteps()
	{ m_stepsEnabled = true; }
	void disableSteps()
	{ m_stepsEnabled = false; }

	void mvEnable()
	{ m_mvEnabled = true; }
	void mvDisable()
	{ m_mvEnabled = false; }



	void updateMV(//MemViewer
		Buffer mem,
		bool flags[6],
		BYTE registers[3],
		BIT_16 pc,
		BIT_16 start,
		BIT_16 end,
		BYTE lineLength
	)
	{
		if (m_mvEnabled)
		{//TODO:Error Handling
			std::cout << std::endl << "\033[2J\033[0;0H";//New page
			std::cout << "-----------------Memory Viewer----------------" << std::endl;

			//Registers
			std::cout 
				<< "A: " << std::setfill('0') << std::setw(2) << std::hex << (int)registers[0] << " | "
				<< "X: " << std::setfill('0') << std::setw(2) << std::hex << (int)registers[1] << " | "
				<< "Y: " << std::setfill('0') << std::setw(2) << std::hex << (int)registers[2] << " | "
				<< "PC: " << std::setfill('0') << std::setw(4) << std::hex << (int)pc << " | ";


			//Flags
			std::cout
				<< (flags[0] ? "N" : "n")
				<< (flags[1] ? "V" : "v")
				<< "-"
				<< (flags[2] ? "D" : "d")
				<< (flags[3] ? "I" : "i")
				<< (flags[4] ? "Z" : "z")
				<< (flags[5] ? "C" : "c");

			std::cout << " | Inst: 0x" << std::setfill('0') << std::setw(2) << std::hex << (int)mem[pc];

			std::cout << std::endl;
			for (BIT_16 i = start; i < end; i++)
			{
				if (i % lineLength == 0)
				{
					std::cout << std::hex << std::endl << "0x" << std::setfill('0') << std::setw(4) << i << ": ";
				}

				std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)mem[i] << " | ";


			}
			std::cout << std::endl;
			if (m_stepsEnabled)
			{
				std::cin.get();
			}
		}
	}
}

