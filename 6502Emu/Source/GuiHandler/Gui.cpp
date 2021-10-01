#include "Gui.h"

Gui * g_gui = nullptr;

void Gui::createInstance()
{
	g_gui = new Gui();
}

Gui * Gui::getInstance()
{
	CheckInstance();
	return g_gui;
}

void Gui::addWindow()
{
	CheckInstance();


	//wxIdManager::
	//g_gui->m_id++;
	//frame->Show(true);

	
}
void Gui::test()
{
	CheckInstance();

}

void Gui::CheckInstance()
{
	if (g_gui == nullptr)
	{
		createInstance();
	}
}
