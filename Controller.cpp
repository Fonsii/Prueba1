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

// DEFINICION DE VARIABLES

const std::string dir = "Archivos/";
std::string outputFilename;
std::vector<std::string> exceptions;
BalancedTree* wordTree = new BalancedTree(); // TODO: delete al final.

// mensajes predefinidos.
const std::vector<std::string> OPTIONS_1 = {
	"1) Editar Excepciones.",
	"2) Consultar Ocurrencias (Todo).",
	"3) Consultar Ocurrencias (Palabra específica).",
	"4) Consultar Ocurrencias (Carácter específico).",
	"5) Definir Archivo de Salida.",
	"6) Salir"
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
	exceptions = file->readFromFile(dir + "excepciones.txt", exceptions);
}

void saveExceptions(std::vector<std::string> exceptions) {
	std::unique_ptr<FileManager> file(new FileManager());
	file->writeToFile(dir + "excepciones.txt", exceptions);
	exceptions.clear();
	loadExceptions();
}

void loadTree() {
	std::unique_ptr<FileManager> file(new FileManager());
}

void editExceptions(std::shared_ptr<Menu> menu) {
	bool finished = false;
	do {
		system("cls");
		int optionSelected = menu->getUserEntryOption(OPTIONS_2, "Seleccione una de las opciones.");
		std::string exception = "";
		switch (optionSelected)
		{
		case 1:
			// agregar excepción.
			exception = menu->getUserEntryText("Ingrese la palabra a agregar como excepción.");
			exceptions.push_back(exception);
			break;
		case 2:
			// modificar excepción.

			break;
		case 3:
			// eliminar excepción.
			break;
		case 4:
			// ver excepciones.
			std::cout << "Excepciones: " << std::endl;
			exceptions.clear();
			loadExceptions();
			printVector(exceptions);
			break;
		case 5:
			finished = true;
			break;
		}
		saveExceptions(exceptions);

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

	// Cargar Datos.
	loadConfig();
	loadExceptions();
	loadTree();

	// -----------------------------------------------

	setlocale(LC_ALL, "spanish");
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
			// Consultar Ocurrencias - Todo.
			break;
		case 3:
			// Consultar Ocurrencias - Palabra.
			break;
		case 4:
			// Consultar Ocurrencias - Caracter.
			break;
		case 5:
			// Definir Archivo de Salida.
			break;
		case 6:
			finished = true;
			break;
		}
	} while (!finished);
}