#include "Input.h"
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
