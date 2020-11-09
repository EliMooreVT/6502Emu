#include "assembler.h"
#include <fstream>
#include <FileHandler\FileUtils.h>
#include <Debugger\Debugger.h>


void CodeHandler::addLine(std::string line)
{
	m_text.push_back(line);
}

void CodeHandler::addDefinition(std::vector<std::string> words)
{
	if (words.size() > 3)
	{
		//Throw error
	}
	defPair d;
	d.name = words[1];
	d.definition = words[2];

	m_definitions.push_back(d);
	
}

void CodeHandler::startConversion(BIT_16 pc_index)
{
	pc_index--;
	for (std::string str : m_text)
	{
		pc_index++;
		removeComments(str);
		std::vector<std::string> words = splitToVector(str);
		if (words.front() == "define")
		{
			addDefinition(words);
			continue;
		}
		if (words.front().back() = ":" && words.size() == 1)
		{
			
		}

		
	}
}

std::vector<std::string> CodeHandler::splitToVector(std::string str)
{
	std::vector<std::string> words;
	int inx;
	do {
		inx = str.find(" ");
		std::string subs = str.substr(0, inx);
		if (subs != "")
		{
			words.push_back(subs);
		}
		str = str.substr(inx + 1);

	} while (inx != -1);
	return words;
}



void CodeHandler::removeComments(std::string & str)
{
	int commentPos = str.find(";");
	str = str.substr(0,commentPos);
}

namespace Assembler
{
	void assembleFromFile(std::string fileName, BIT_16 pc_index)
	{
		std::ifstream inFile;
		if (FileLoader::getExtension(fileName) == ".asm")
		{
			Debug::println("Opening file...");
			inFile.open(fileName, std::ios::in);
			if (inFile.good())
			{
				Debug::println("File opened");
				CodeHandler ch;
				while (inFile.good())
				{
					std::string line;
					std::getline(inFile, line);
					ch.addLine(line);
				}
				Debug::println("Starting Conversion");
				ch.startConversion(pc_index);
			}
			else
			{
				Debug::println("File not good");
			}
		}
		else
		{
			Debug::println("File not asm format: " + fileName);
			//Error handling
		}
		
	}
}

