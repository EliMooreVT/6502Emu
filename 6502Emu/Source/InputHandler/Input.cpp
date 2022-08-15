#include "Input.h"

// WINDOWS
#if defined(_WIN32)
#include <Windows.h>

bool Input::getKeyDown(char key)
{
	return GetAsyncKeyState((unsigned short)key) & 0x8000;
}

bool Input::getKeyDown(int code)
{
	return GetAsyncKeyState((unsigned short)code) & 0x8000;
}

bool Input::getKeyOnce(char key)
{
	if (GetAsyncKeyState((unsigned short)key) & 0x8000)
	{
		if (m_keysHeld[key] == false)
		{
			m_keysHeld[key] = true;
			return true;
		}
		return false;

	}
	else
	{
		m_keysHeld[key] = false;
		return false;
	}
}

bool Input::getKeyOnce(int code)
{
	if (GetAsyncKeyState((unsigned short)code) & 0x8000)
	{
		if (m_keysHeld[code] == false)
		{
			m_keysHeld[code] = true;
			return true;
		}
		return false;

	}
	else
	{
		m_keysHeld[code] = false;
		return false;
	}
}
#endif

//LINUX
#ifdef __linux__
#include "ncurses.h"


bool Input::getKeyDown(char key)
{
	return wgetch(stdscr) == key;
}

bool Input::getKeyDown(int code)
{
	return wgetch(stdscr) == code;
}

bool Input::getKeyOnce(char key)
{
	if(currentChar!=key)
	{
		currentChar = wgetch(stdscr);
		return true;
	}
	return false;
}


bool Input::getKeyOnce(int code)
{
	if(currentChar!=code)
	{
		currentChar = wgetch(stdscr);
		return true;
	}
	return false;
}
#endif
