#include "stdIncludes.h"

void CSystem::initSystem()
{
	g_system = new CSystem();
}

void CSystem::destrSystem()
{
	Debug::println("Destroy System");
	delete g_system;
	g_system = nullptr;
}

CSystem::CSystem()
{
	Debug::println("Create System");
}