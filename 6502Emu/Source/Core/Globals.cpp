#pragma once
#include "stdIncludes.h"

CPU::C6502*   g_cpu    = nullptr;
CSystem* g_system = nullptr;
CMemory* g_memory = nullptr;

BIT_16 g_pc = 0x0000;

