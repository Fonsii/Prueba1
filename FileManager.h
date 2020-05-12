#pragma once
#include <string>
#include <vector>
#include <iterator> 
#include <map>
#include <sstream>

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