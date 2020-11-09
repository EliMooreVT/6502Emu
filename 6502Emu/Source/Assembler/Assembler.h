#pragma once
#include <string>
#include <vector>

typedef unsigned char BYTE;
typedef unsigned short BIT_16;
typedef BYTE* Buffer;

struct defPair
{
	std::string name;
	std::string definition;
};

struct label
{
	std::string name;
	BIT_16 location;
};

class CodeHandler
{
public:
	void addLine(std::string line);
	void startConversion(BIT_16 pc_index);
private:
	void removeComments(std::string &str);
	void addDefinition(std::vector<std::string> words);
	BIT_16 addressToBit_16(std::string);
	std::vector<std::string> splitToVector(std::string str);

	std::vector<label> m_labels;
	std::vector<defPair> m_definitions;
	std::vector<std::string> m_text;
	Buffer m_code;
};

namespace Assembler
{
	void assembleFromFile(std::string fileName, BIT_16 pc_index);
}