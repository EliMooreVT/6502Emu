#include "ConsoleWriter.h"

ConsoleWriter::ConsoleWriter(int screenWidth, int screenHeight)
{
	nScreenHeight = screenHeight;
	nScreenWidth = screenWidth;
	m_screenBuffer = new wchar_t[screenWidth * screenHeight];
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	dwBytesWritten = 0;

	m_screenBuffer[nScreenWidth * nScreenHeight - 1] = '\0';

	for (int i = 0; i < nScreenHeight * nScreenWidth - 1; i++)
	{
		m_screenBuffer[i] = L' ';
	}
}

ConsoleWriter::~ConsoleWriter()
{
	delete[] m_screenBuffer;
}

void ConsoleWriter::write(int x, int y, wchar_t letter)
{
	if (x > nScreenWidth || y > nScreenHeight || x < 0 || y < 0)
	{
		//Error
	}
	else
	{
		int index = y * nScreenWidth + x;
		m_screenBuffer[index] = letter;
	}
}

void ConsoleWriter::clear(int x, int y)
{
	if (x > nScreenWidth || y > nScreenHeight || x < 0 || y < 0)
	{
		//Error
	}
	else
	{
		int index = y * nScreenWidth + x;
		m_screenBuffer[index] = L' ';
	}
}

void ConsoleWriter::update()
{
	WriteConsoleOutputCharacter(hConsole, m_screenBuffer, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
}




Box::Box(int x, int y, int length, int width, ConsoleWriter* cw)
{
	m_x = x;
	m_y = y;
	m_length = length;
	m_width = width;
	m_cw = cw;
}

void Box::write(int x, int y, char letter)
{
	if (x < m_width && y < m_length && x >= 0 && y >= 0)
	{
		m_cw->write(x + m_x, y + m_y, (wchar_t)letter);
	}

}

void Box::write(int x, int y, std::string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (x < m_width && y < m_length && x >= 0 && y >= 0)
		{
			m_cw->write(x + m_x, y + m_y, (wchar_t)s[i]);
		}
		x++;
	}
}

LogBox::LogBox(int x, int y, int length, int width, ConsoleWriter* m_cw)
{
	m_x = x;
	m_y = y;
	m_length = length;
	m_width = width;
	m_b = new Box(x, y, length, width, m_cw);
	m_cursorX = 0;
	m_cursorY = 0;

}

LogBox::~LogBox()
{
	delete m_b;
}

void LogBox::print(std::string s)
{
	for (char c : s)
	{
		if (c == '\n')
		{
			m_cursorY++;
			m_cursorX = 0;
		}
		else
		{
			m_b->write(m_cursorX, m_cursorY, c);
			if (m_cursorX >= m_length - 1)
			{
				m_cursorX = 0;
				m_cursorY++;
			}
			else
			{
				m_cursorX++;
			}
		}

	}
}

void LogBox::println(std::string s)
{
	print(s + '\n');
}