#pragma once
#include <string>
#include <vector>
#include <sstream>

class FileManager {
public:
	FileManager();
	virtual ~FileManager();

	std::vector<std::string> readFromFile(std::string, std::vector<std::string>);
	std::string readFromFile(std::string);
	void writeToFile(std::string, std::vector<std::string>);
};