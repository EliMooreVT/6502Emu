#include "ConsoleWriter.h"

ConsoleWriter::ConsoleWriter(int screenWidth, int screenHeight)
{
	nScreenHeight = screenHeight;
	nScreenWidth = screenWidth;
#if defined(_WIN32)
	m_screenBuffer = new wchar_t[screenWidth * screenHeight];
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	dwBytesWritten = 0;


	m_screenBuffer[nScreenWidth * nScreenHeight - 1] = '\0';

	for (int i = 0; i < nScreenHeight * nScreenWidth - 1; i++)
	{
		m_screenBuffer[i] = L' ';
	}
#endif
#ifdef __linux__
	initscr();
	noecho();
	nodelay(stdscr, true);
	//wtimeout(stdscr, 1);
	keypad(stdscr, true);
	
#endif
}

ConsoleWriter::~ConsoleWriter()
{
#ifdef _WIN32
	delete[] m_screenBuffer;
#endif
#ifdef __linux__
	endwin();
#endif
}

void ConsoleWriter::write(int x, int y, wchar_t letter)
{
	if (x > nScreenWidth || y > nScreenHeight || x < 0 || y < 0)
	{
		//Error
	}
	else
	{
#ifdef _WIN32
		int index = y * nScreenWidth + x;
		m_screenBuffer[index] = letter;
#endif
		mvwaddch(stdscr, y, x, char(letter));
	}
}

void ConsoleWriter::clearLetter(int x, int y)
{
	if (x > nScreenWidth || y > nScreenHeight || x < 0 || y < 0)
	{
		//Error
	}
	else
	{
#ifdef _WIN32
		int index = y * nScreenWidth + x;
		m_screenBuffer[index] = L' ';
#endif
#ifdef __linux__
		clear();
#endif
	}
}

void ConsoleWriter::update()
{
#ifdef _WIN32
	WriteConsoleOutputCharacter(hConsole, m_screenBuffer, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
#endif
#ifdef __linux__
	refresh();
#endif
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
#ifdef _WIN32
	for (int i = 0; i < s.length(); i++)
	{
		if (x < m_width && y < m_length && x >= 0 && y >= 0)
		{
			m_cw->write(x + m_x, y + m_y, (wchar_t)s[i]);
		}
		x++;
	}
#endif
#ifdef __linux__
	mvprintw(y,x, s.c_str());
#endif
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