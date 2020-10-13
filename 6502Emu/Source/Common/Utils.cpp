#include "Utils.h"
#include <sstream>
#include <iomanip>
namespace Utils
{
	std::string hexString(BYTE data)
	{
		std::stringstream ss;
		ss << std::hex << std::setfill('0') << std::setw(2) << (int)data;
		return ss.str();
	}

	std::string hexString(BIT_16 data)
	{
		std::stringstream ss;
		ss << std::hex << std::setfill('0') << std::setw(4) << (int)data;
		return ss.str();
	}
}