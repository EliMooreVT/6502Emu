#include "FileLoader.h"


std::string FileLoader::getExtension(std::string fileName)
{
	int pos = fileName.find('.');
	if (pos == -1)
	{
		return "";
	}
	std::string extension = fileName.substr(pos);
	return extension;
}

std::string FileLoader::rmExtension(std::string fileName)
{
	int pos = fileName.find('.');
	if (pos == -1)
	{
		return "";
	}
	return fileName.substr(0, pos);
}

std::vector<BYTE> FileLoader::loadFile(std::string fileName)
{
	Debug::printBr();
	Debug::println("Checking bin file");
	if (FileLoader::getExtension(fileName) == ".bin")
	{
		Debug::println("Bin file recognized");
		std::ifstream file;
		Debug::println("Opening file");
		file.open(fileName, std::ios::in | std::ios::binary);
		Debug::println("Checking file good");
		if (file.good())
		{
			Debug::println("File good");
			std::vector<BYTE> inputBuffer;
			char currentByte[1];
			Debug::print("Reading Files");
			while (file.good())
			{
				Debug::print(".");
				file.read(currentByte,1);
				inputBuffer.push_back(*currentByte);
			}
			Debug::println("");
			Debug::println("Files read");

			return inputBuffer;
		}
		else
		{
			Debug::println("File not good");
			file.close();
			return std::vector<BYTE>();//TODO: Error Handling
		}
	}
	else
	{
		Debug::println("Bin file undetected");
		return std::vector<BYTE>();//TODO: Error Handling
	}
}