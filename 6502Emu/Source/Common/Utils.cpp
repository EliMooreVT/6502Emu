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

	BIT_16 concBytes(BYTE a, BYTE b)
	{
		BIT_16 result = a;
		result = result << 8;
		result += b;
		return result;
	}


}