#pragma once
#include <string>
#include <vector>
#include <iterator> 
#include <map>
#include <sstream>

/*Autor: Alonso Moreno y Victor Mora
Versi�n: 1.0
Descripci�n: clase para leer y guardar los archivos*/

class FileManager {
public:
	FileManager();
	virtual ~FileManager();

	std::vector<std::string> readFromFile(std::string, std::vector<std::string>);
	std::vector<std::string> readFromFileVector(std::string);
	std::string readFromFile(std::string);
	void writeToFile(std::string, std::vector<std::string>);
	void saveTree(std::string, std::string);
	std::map<std::string, int> readOcurrenceFileString(std::string);
};