#include "FileConverter.h"


namespace FileConverter{

	

	void OutputToBin(std::vector<BYTE> data, std::string fileName)
	{
		
		std::ofstream outFile;
		Debug::println("Opening File");
		outFile.open(FileLoader::rmExtension(fileName) + ".bin", std::ios::out | std::ios::trunc | std::ios::binary);
		Buffer dataArray = &data[0];
		Debug::println("Writing to file");
		for (int i = 0; i < data.size(); i++)
		{
			Debug::printb(data[i]);
			Debug::println("");
		}
		outFile.write((char*)dataArray, data.size());
		outFile.close();

	}
}
