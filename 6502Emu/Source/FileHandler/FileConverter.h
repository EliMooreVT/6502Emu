#pragma once
#include "Common\TypeDec.h"
#include "FileLoader.h"
#include "Debugger\Debugger.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace FileConverter
{
	void OutputToBin(std::vector<BYTE> data, std::string fileName);
}