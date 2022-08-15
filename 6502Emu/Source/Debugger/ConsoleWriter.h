#pragma once


#if defined(_WIN32)
#include <Windows.h>
#endif

#if defined(__linux__)
#include "curses.h"
#include <string>
#endif

#include <unordered_map>


class ConsoleWriter
{
public:
	ConsoleWriter(int screenWidth, int screenHeight);
	~ConsoleWriter();

	void write(int x, int y, wchar_t letter);
	void clearLetter(int x, int y);

	void update();


private:
#if defined(_WIN32)
	wchar_t* m_screenBuffer;
	HANDLE hConsole;
	DWORD dwBytesWritten;
#endif
	int nScreenWidth = 120;
	int nScreenHeight = 40;
};

class Box
{
public:
	Box(int x, int y, int length, int width, ConsoleWriter* cw);

	void write(int x, int y, char letter);
	void write(int x, int y, std::string s);

private:
	int m_x;
	int m_y;
	int m_length;
	int m_width;
	ConsoleWriter* m_cw;
};

class LogBox
{
public:
	LogBox(int x, int y, int length, int width, ConsoleWriter* m_cw);
	~LogBox();

	void print(std::string s);
	void println(std::string s = "");

private:
	int m_x;
	int m_y;
	int m_length;
	int m_width;
	Box* m_b;
	int m_cursorX;
	int m_cursorY;
};