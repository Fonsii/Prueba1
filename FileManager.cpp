#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <regex>

#include "BalancedTree.h"

FileManager::FileManager() {}

FileManager::~FileManager() {}

/*pasa un string a minúscula, el el parámetro se pide la string*/
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

/*lee un archivo y carga los valores en un vector, primer par[ametro pide el nombre del archivo a abrir y el segundo el vector donde se va a guardar*/
std::vector<std::string> FileManager::readFromFile(std::string filename, std::vector<std::string> vector) {
	vector.clear();
	std::ifstream inputFile;
	inputFile.open(filename);
	std::string line;
	std::regex regularExpresion("[^\\s.,:;!?¿]+");

	while (getline(inputFile, line)) {
		auto lineBegin = std::sregex_iterator(line.begin(), line.end(), regularExpresion);
		auto lineEnd = std::sregex_iterator();
		for (std::sregex_iterator i = lineBegin; i != lineEnd; ++i) {
			vector.push_back(toLower((*i).str()));
		}
	}
	inputFile.close();
	return vector;
}
/*lee un archivo y carga los valores en un vector, en el parámetro se solicita el nombre del archivo*/
std::vector<std::string> FileManager::readFromFileVector(std::string filename) {
	std::vector<std::string> vector;
	std::ifstream inputFile;
	inputFile.open(filename);
	std::string line;
	while (getline(inputFile, line)) {
		vector.push_back(toLower(line));
	}
	inputFile.close();
	return vector;
}

/*lee un archivo y vuelve minúsculas los caracteres de la string, el parámetro solicita el nombre del archivo*/
std::string FileManager::readFromFile(std::string filename) {
	std::ifstream inputFile;
	inputFile.open(filename);
	std::string line;
	getline(inputFile, line);
	inputFile.close();
	return toLower(line);
}
/*guarda un archivo, el primer parámetro solicita el nombre del archivo donde se va a guardar, el segundo parámetro solicita el vector de strings con los datos*/
void FileManager::writeToFile(std::string filename, std::vector<std::string> data) {
	std::ofstream outputFile;
	outputFile.open(filename);
	std::vector<std::string>::iterator i;
	for (i = data.begin(); i != data.end(); i++) {
		outputFile << toLower(*i) << std::endl;
	}
	outputFile.close();
}
/*guarda el árbol en un archivo, el primer método pide el nombre donde se guarda el archivo, el segundo parámetro solicita el árbol*/
void FileManager::saveTree(std::string filename, std::string stringTree)
{
	std::ofstream outputFile;
	outputFile.open(filename);
	outputFile << stringTree;
	outputFile.close();
}
/*lee el archivo de ocurrencias, el parámetro solicita el nombre del archivo que tiene las ocurrencias*/
std::map<std::string, int> FileManager::readOcurrenceFileString(std::string filename)
{

	std::map<std::string, int> ocurrences;

	std::ifstream inputFile;
	inputFile.open(filename);	

	std::string line;
	std::string word;
	int cant;

	while (getline(inputFile, line, ':')) {
		word = line;
		getline(inputFile, line);
		cant = std::stoi(line);
		ocurrences.insert({word, cant});
	}
	inputFile.close();
	return ocurrences;
}