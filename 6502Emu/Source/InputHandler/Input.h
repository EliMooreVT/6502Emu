#pragma once
#include <unordered_map>



namespace Input
{
	namespace
	{
		std::unordered_map<unsigned short, bool> m_keysHeld;
	}

	bool getKeyDown(char key);
	bool getKeyDown(int code);

	bool getKeyOnce(char key);
	bool getKeyOnce(int code);
}