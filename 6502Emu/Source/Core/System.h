#pragma once
#include "stdIncludes.h"

class CSystem
{
public:
	
	static void initSystem();
	static void destrSystem();
	void loadRom(std::string fileName, BIT_16 BufIdx);
private:
	CSystem();
};