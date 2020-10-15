#include "debugger.h"
#include <iomanip>

namespace Debug
{

	namespace //Private Variables
	{
		bool m_enabled;
		bool m_stepsEnabled;
		bool m_mvEnabled;

		bool m_mv_flags[6];
		BYTE m_mv_registers[3];
		Buffer m_mv_memory;

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
		if (m_enabled)
		{
			std::cout << std::endl << "----------------------" << std::endl;
		}
		
	}

	void Enable()
	{ m_mvEnabled = true; }
	void Disable()
	{ m_mvEnabled = false; }

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
		BYTE m_mv_registers[3],
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
				<< "A: " << std::setfill('0') << std::setw(2) << std::hex << (int)m_mv_registers[0] << "|"
				<< "X: " << std::setfill('0') << std::setw(2) << std::hex << (int)m_mv_registers[1] << "|"
				<< "Y: " << std::setfill('0') << std::setw(2) << std::hex << (int)m_mv_registers[2] << "|"
				<< "PC: " << std::setfill('0') << std::setw(4) << std::hex << (int)pc << "|";


			//Flags
			std::cout
				<< (m_mv_flags[0] ? "N" : "n")
				<< (m_mv_flags[1] ? "V" : "v")
				<< "-"
				<< (m_mv_flags[2] ? "B" : "b")
				<< (m_mv_flags[3] ? "D" : "d")
				<< (m_mv_flags[4] ? "I" : "i")
				<< (m_mv_flags[5] ? "Z" : "z")
				<< (m_mv_flags[6] ? "C" : "c");

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

