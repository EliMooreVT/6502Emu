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
		return fileName;
	}
	return fileName.substr(0, pos);
}

std::vector<BYTE> FileLoader::loadByteTextFile(std::string fileName)
{
	Debug::printBr();
	Debug::println("Converting " + fileName + " to bytes");

	std::ifstream inFile;
	Debug::println("Opening File");
	inFile.open(fileName, std::ios::in);
	if (inFile.good())
	{
		Debug::println("File Good");
		std::vector<BYTE> data;
		BYTE currentByte;
		std::string currentString;
		while (inFile.good())
		{
			inFile >> currentString;
			Debug::println("Read " + currentString + " to vector");
			currentByte = std::stoi(currentString, 0, 16);
			data.push_back(currentByte);
		}
		inFile.close();
		return data;
	}
	else
	{
		Debug::println("Could not find file: " + fileName);//TODO: Error Handling
		return std::vector<BYTE>();
	}
}

std::vector<BYTE> FileLoader::loadFile(std::string fileName)
{
	Debug::printBr();
	Debug::println("Loading File: " + fileName);
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

			Debug::println("Finished Loading File");
			Debug::printBr();
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