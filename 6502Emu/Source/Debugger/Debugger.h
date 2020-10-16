#pragma once
#include "Common/Utils.h"
#include <string>
#include <iostream>


namespace Debug
{

	void print(std::string str);
	void printb(BYTE b);
	void printad(BIT_16 b);
	void println(std::string str);
	void printBr();

	void enablePrint();
	void disablePrint();

	void enableSteps();
	void disableSteps();

	void mvEnable();
	void mvDisable();
	void updateMV(//MemViewer
		Buffer mem,
		bool flags[6],
		BYTE registers[3],
		BIT_16 pc,
		BIT_16 start, 
		BIT_16 end, 
		BYTE lineLength
		);
	
}