#pragma once
#include "Common\TypeDec.h"
#include <string>
#include <fstream>
#include <vector>
#include "Debugger\Debugger.h"



namespace FileLoader
{
	std::vector<BYTE> loadFile(std::string fileName);
	std::string getExtension(std::string fileName);
	std::string rmExtension(std::string fileName);
};