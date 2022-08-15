#pragma once
#include <unordered_map>



namespace Input
{
	namespace
	{
#ifdef _WIN32
		std::unordered_map<unsigned short, bool> m_keysHeld;
#endif
#ifdef __linux__
		char currentChar;
#endif
	}

	bool getKeyDown(char key);
	bool getKeyDown(int code);

	bool getKeyOnce(char key);
	bool getKeyOnce(int code);
}