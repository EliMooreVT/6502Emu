#pragma once
#include "Common/Utils.h"
#include <string>
#include <iostream>
#include "ConsoleWriter.h"


namespace Debug
{

	void startDebugger();
	void endDebugger();

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

	void updateMemLoc(BIT_16 loc, BYTE byte);

	void updateMV(//MemViewer
		bool flags[6],
		BYTE registers[3],
		BIT_16 pc
		);
	
}


//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//