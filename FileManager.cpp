#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <locale>

FileManager::FileManager() {}

FileManager::~FileManager() {}

// pasa un string a minúscula.
std::string toLower(std::string word)
{
	std::locale loc;
	std::string str = word;
	std::string result;
	for (std::string::size_type i = 0; i < str.length(); ++i) {
		result += std::tolower(str[i], loc);
	}
	return result;
}

// lee un archivo y carga los valores en un vector.
std::vector<std::string> FileManager::readFromFile(std::string filename, std::vector<std::string> vector) {
	vector.clear();
	std::ifstream inputFile;
	inputFile.open(filename);
	std::string line;
	while (getline(inputFile, line)) {
		vector.push_back(toLower(line));
	}
	inputFile.close();
	return vector;
}

std::string FileManager::readFromFile(std::string filename) {
	std::ifstream inputFile;
	inputFile.open(filename);
	std::string line;
	getline(inputFile, line);
	inputFile.close();
	return toLower(line);
}

void FileManager::writeToFile(std::string filename, std::vector<std::string> data) {
	std::ofstream outputFile;
	outputFile.open(filename);
	std::vector<std::string>::iterator i;
	for (i = data.begin(); i != data.end(); i++) {
		outputFile << toLower(*i) << std::endl;
	}
	outputFile.close();
}