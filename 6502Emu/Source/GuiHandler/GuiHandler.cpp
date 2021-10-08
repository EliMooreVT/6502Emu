#include "GuiHandler.h"
#define NMSPC GuiData::Function

extern void(*NMSPC::initSystem)() = nullptr;
extern void(*NMSPC::OpenFile)(std::string) = nullptr;
extern Buffer(*NMSPC::GetMemory)() = nullptr;
extern BIT_16(*NMSPC::GetPC)() = nullptr;
