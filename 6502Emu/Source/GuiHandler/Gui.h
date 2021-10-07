#pragma once
#include "App.h"


class Gui
{
public:
	static void createInstance();
	static Gui * getInstance();
	static void addWindow();
	static void test();
private:
	static void CheckInstance();
	Gui() {};
	
	int m_id = 0;
};

