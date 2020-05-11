#pragma once

#include <iostream>
#include <string>
#include <locale>
#include "Controller.h"
#include "FileManager.h"
#include "BalancedTree.h"
#include "Menu.h"
#include <Memory>
#include <locale.h>
#include <iterator>
#include <algorithm>
#include "CharTree.h"

// DEFINICION DE VARIABLES

const std::string dir = "Archivos/";
std::string outputFilename;
std::string inputFilename;
std::string inputString = "";
char inputChar = ' ';
std::vector<std::string> exceptions;
BalancedTree* wordTree = new BalancedTree(); // TODO: delete al final.
CharTree* charTree = new CharTree();

// mensajes predefinidos.
const std::vector<std::string> OPTIONS_1 = {
	"1) Editar Excepciones.",
	"2) Consultar Ocurrencias (Todo).",
	"3) Consultar Ocurrencias (Palabra específica).",
	"4) Consultar Ocurrencias (Carácter específico).",
	"5) Definir Archivo de Salida.",
	"6) Cargar Archivo.",
	"7) Salir"
};

const std::vector<std::string> OPTIONS_2 = {
	"1) Agregar Excepción.",
	"2) Modificar Excepción.",
	"3) Eliminar Excepción.",
	"4) Ver Excepciones.",
	"5) <- Volver."
};

// --------------------------------------------------

// Aquí van las declaraciones a funciones auxiliares.

std::string lower(std::string word)
{
	std::locale loc;
	std::string str = word;
	std::string result;
	for (std::string::size_type i = 0; i < str.length(); ++i) {
		result += std::tolower(str[i], loc);
	}
	return result;
}

void printVector(std::vector<std::string> vector) {
	std::vector<std::string>::iterator i;
	for (i = vector.begin(); i != vector.end(); i++) {
		std::cout << *i << std::endl;
	}
}

void loadConfig() {
	std::unique_ptr<FileManager> file(new FileManager());
	outputFilename = file->readFromFile(dir + "config.txt");
}

void loadExceptions() {
	std::unique_ptr<FileManager> file(new FileManager());
	exceptions = file->readFromFileVector(dir + "excepciones.txt");
}

void saveExceptions(std::vector<std::string> exceptions) {
	std::unique_ptr<FileManager> file(new FileManager());
	file->writeToFile(dir + "excepciones.txt", exceptions);
	exceptions.clear();
	loadExceptions();
}

void loadTree() {
	std::unique_ptr<FileManager> file(new FileManager());
	std::vector <std::string> vector;
	vector = file->readFromFile(dir + "prueba.txt", vector);
	std::vector<std::string>::iterator i;
	std::vector<std::string>::iterator i_found;
	for (i = vector.begin(); i != vector.end(); i++) {
		// busque en las excepciones y si lo encuentra, no lo añade.
		i_found = find(exceptions.begin(), exceptions.end(), *i);
		if (i_found == exceptions.end()) {
			wordTree->add(lower(*i));
		}
	}
}

void saveTree(std::string outputFilename) {
	std::unique_ptr<FileManager> file = std::make_unique<FileManager>();
	file->saveTree(outputFilename, wordTree->toString());
}

void showExceptions() {
	std::cout << "Excepciones: " << std::endl;
	exceptions.clear();
	loadExceptions();
	printVector(exceptions);
}

void editExceptions(std::shared_ptr<Menu> menu) {
	bool finished = false;
	do {
		int optionSelected = menu->getUserEntryOption(OPTIONS_2, "Seleccione una de las opciones.");
		std::string exception = "";
		std::string exceptionToReplace = "";
		std::string exceptionReplacement = "";
		std::vector<std::string>::iterator i;
		std::vector<std::string>::iterator j;
		bool valid = false;
		switch (optionSelected)
		{
		case 1:
			// agregar excepción.
			while (!valid) {
				exception = menu->getUserEntryText("Ingrese la palabra a agregar como excepción.");				
				i = find(exceptions.begin(), exceptions.end(), exception);

				if (i == exceptions.end()) {
					exceptions.push_back(exception);
					valid = true;
				}
				else {
					std::cout << "La excepción ya existe." << std::endl;
				}
			}
			break;
		case 2:
			showExceptions();
			// modificar excepción.
			while (!valid) {
				exceptionToReplace = lower(menu->getUserEntryText("Ingrese la excepción a modificar."));
				exceptionReplacement = lower(menu->getUserEntryText("Ingrese la nueva excepción."));
				i = find(exceptions.begin(), exceptions.end(), exceptionToReplace);
				if (i != exceptions.end()) {

					j = find(exceptions.begin(), exceptions.end(), exceptionReplacement);
					if (j == exceptions.end()) {
						*i = exceptionReplacement;
						valid = true;
					}
					else {
						std::cout << "La excepción modificada ya existe." << std::endl;
					}
				}
				else {
					std::cout << "La excepción a modificar no existe." << std::endl;
				}
			}
			break;
		case 3:
			showExceptions();
			// eliminar excepción.
			exceptionReplacement = lower(menu->getUserEntryText("Ingrese la excepción a borrar."));
			exceptions.erase(std::remove(exceptions.begin(), exceptions.end(), exceptionReplacement), exceptions.end());
			break;
		case 4:
			// ver excepciones.
			showExceptions();
			system("pause");
			break;
		case 5:
			finished = true;
			break;
		}
		saveExceptions(exceptions);
		//system("cls");

	} while (!finished);
}

// -------------------------------------------------

// Constructor y destructor
Controller::Controller() {
	this->menu = std::make_shared<Menu>();
}

Controller::~Controller() {}

// ---------------------------------------------------

void Controller::start(){

	setlocale(LC_ALL, "spanish");

	loadConfig();
	loadExceptions();
	loadTree();

	bool finished = false;
	do {
		system("cls");
		int optionSelected = this->menu->getUserEntryOption(OPTIONS_1, "Seleccione una de las opciones.");
		switch (optionSelected)
		{
		case 1:
			// Editar el archivo de excepciones.
			editExceptions(this->menu);
			break;
		case 2:
			// Consultar Ocurrencias - Todo
			std::cout << wordTree->toString();
			system("pause");
			break;
		case 3:
			// Consultar Ocurrencias - Palabra.
			std::cout << "Palabra a buscar: ";
			std::cin >> inputString;
			std::cout << wordTree->search(inputString) << std::endl;
			break;
			system("pause");
		case 4:
			// Consultar Ocurrencias - Caracter.
			std::cout << "Caracter a buscar: ";
			std::cin >> inputChar;
			charTree = new CharTree();
			charTree->getCharTree(wordTree);
			std::cout << charTree->search(inputChar) << std::endl;
			delete charTree;
			system("pause");
			break;
		case 5:
			// Definir Archivo de Salida.
			outputFilename = lower(menu->getUserEntryText("Ingrese el nombre del archivo .txt donde quierre guardar las ocurrencias."));
			saveTree(outputFilename);
			break;
			system("pause");
		case 6:
			// Definir Archivo de Carga.
			inputFilename = lower(menu->getUserEntryText("Ingrese el nombre del archivo .txt a cargar."));
			loadTree();
			break;
		default:
			finished = true;
			break;
		}
	} while (!finished);
}