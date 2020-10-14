#include "FileConverter.h"


namespace FileConverter{
	void ConvertToBin(std::string fileName)
	{
		Debug::printBr();
		Debug::println("Converting " + fileName + " to binary file");
		
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
			std::ofstream outFile;
			Debug::println("Opening File");
			outFile.open(FileLoader::rmExtension(fileName) + ".bin", std::ios::out | std::ios::trunc | std::ios::binary);
			Buffer dataArray = &data[0];
			Debug::println("Writing to file");
			outFile.write((char*)dataArray, data.size());
			outFile.close();
		}
		else
		{
			Debug::println("Could not find file: " + fileName);//TODO: Error Handling
		}

	}
}
