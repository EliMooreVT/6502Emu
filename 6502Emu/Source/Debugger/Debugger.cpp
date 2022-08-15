#include "Debugger.h"
#include <iomanip>
#include <InputHandler/Input.h>

#ifdef _WIN32
#define KEY_RIGHT VK_RETURN
#define KEY_ENTER VK_NEXT
#define KEY_ESCAPE VK_ESCAPE
#endif
#ifdef __linux__
#define KEY_ESCAPE 27
#endif


namespace Debug
{

	namespace //Private Variables
	{
		ConsoleWriter m_cw(120, 110);
		Box m_mvBox(1, 1, 25, 54, &m_cw);
		LogBox m_logBox(56, 1, 100, 63, &m_cw);
		bool m_printEnabled;
		bool m_stepsEnabled;
		bool m_mvEnabled;
	}

	void startDebugger()
	{
		
		BIT_16 startingLine = 0x0000;
		//Init mv
		m_mvBox.write(0,  0, "|-------------------Memory  Viewer-------------------|");
		for (int i = 0; i < 25; i++)
		{
			m_mvBox.write(1,i,'|');
			m_mvBox.write(53, i, '|');
		}
		m_mvBox.write(0, 24, "|----------------------------------------------------|");


		m_mvBox.write(1,  1, "A:  0x");
		m_mvBox.write(1,  2, "X:  0x");
		m_mvBox.write(1,  3, "Y:  0x");
		m_mvBox.write(1,  4, "PC: 0x");

		m_mvBox.write(15, 2, "N V - D I Z C");
		m_mvBox.write(15, 3, "    -        ");

		m_mvBox.write(1,  5,  "- - - - - - - - - - - - - - - - - - - - - - - - - - ");

		for (int i = 6; i < 24; i++)
		{
			m_mvBox.write(2, i, "0x" + Utils::hexString(startingLine) + ": ");
			startingLine += 0x0010;
		}

		BYTE zero = 0x00;

		for (int i = 6; i < 24; i++)
		{
			for (int j = 1; j < 17; j++)
			{
				m_mvBox.write(9 + j * 3, i, Utils::hexString(zero));
			}
		}

	}

	void endDebugger()
	{

	}

	void print(std::string str)
	{
		if (m_printEnabled)
		{
			m_logBox.print(str);
		}
	}

	void printb(BYTE b)
	{
		if (m_printEnabled)
		{
			m_logBox.print("0x" + Utils::hexString(b));
		}
	}

	void printad(BIT_16 b)
	{
		if (m_printEnabled)
		{
			m_logBox.print("0x" + Utils::hexString(b));
		}
	}

	void println(std::string str)
	{
		if (m_printEnabled)
		{
			m_logBox.println(str);
		}

	}

	void printBr()
	{
		if (m_printEnabled)
		{
			m_logBox.println("----------------------");
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

	void updateMemLoc(BIT_16 loc, BYTE byte)
	{
		if(loc < 0x0120 && loc >= 0x0000)
		m_mvBox.write(9 + (loc & 0x0f) * 3, 6 + ((loc & 0xf0) >> 4), Utils::hexString(byte));
	}

	void updateMV(
		bool flags[6],
		BYTE registers[3],
		BIT_16 pc
	)
	{
		if (m_mvEnabled)
		{

			m_mvBox.write(7, 1, Utils::hexString(registers[0]));
			m_mvBox.write(7, 2, Utils::hexString(registers[1]));
			m_mvBox.write(7, 3, Utils::hexString(registers[2]));
			m_mvBox.write(7, 4, Utils::hexString(pc));

			m_mvBox.write(15, 3, std::to_string(flags[0]));
			m_mvBox.write(17, 3, std::to_string(flags[1]));
			m_mvBox.write(21, 3, std::to_string(flags[2]));
			m_mvBox.write(23, 3, std::to_string(flags[3]));
			m_mvBox.write(25, 3, std::to_string(flags[4]));
			m_mvBox.write(27, 3, std::to_string(flags[5]));

			BIT_16 startingPos = 0x0000;
			

			//m_cw.write(0,0,"A:");
			//
			//m_cw.write(0, 0, "X:");
			//
			//m_cw.write(0, 0, "Y:");
			//
			//m_cw.write(0, 0, "PC:");

			m_cw.update();

			if (Input::getKeyOnce(KEY_ENTER))
			{
				m_stepsEnabled = true;
			}

			if (m_stepsEnabled)
			{
				while (!Input::getKeyOnce(KEY_RIGHT) && m_stepsEnabled && !Input::getKeyDown(KEY_ESCAPE))
				{
					if (Input::getKeyOnce(KEY_ENTER))
					{
						m_stepsEnabled = false;
					}
					m_cw.update();
				}
			}

		}
	}
}

