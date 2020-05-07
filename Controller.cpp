#include <iostream>
#include <string>
#include <locale>
#include "Controller.h"
#include "Menu.h"
#include <Memory>
#include <locale.h>


// mensajes predefinidos.
const std::vector<std::string> OPTIONS_1 = {
	"1) Editar Excepciones.",
	"2) Consultar Ocurrencias (Todo).",
	"3) Consultar Ocurrencias (Palabra espec�fica).",
	"4) Consultar Ocurrencias (Car�cter espec�fico).",
	"5) Definir Archivo de Salida.",
	"6) Salir"
};

const std::vector<std::string> OPTIONS_2 = {
	"1) Agregar Excepci�n.",
	"2) Modificar Excepci�n.",
	"3) Eliminar Excepci�n.",
	"4) Ver Excepciones.",
	"5) <- Volver."
};

// Aqu� van las declaraciones a funciones auxiliares.

std::string Controller::toLower(std::string word)
{
	std::locale loc;
	std::string str = word;
	std::string result;
	for (std::string::size_type i = 0; i < str.length(); ++i) {
		result += std::tolower(str[i], loc);
	}
	return result;
}

void editExceptions(std::shared_ptr<Menu> menu) {
	bool finished = false;
	do {
		system("cls");
		int optionSelected = menu->getUserEntryOption(OPTIONS_2, "Seleccione una de las opciones.");
		switch (optionSelected)
		{
		case 1:
			// agregar excepci�n.
			break;
		case 2:
			// modificar excepci�n.
			break;
		case 3:
			// eliminar excepci�n.
			break;
		case 4:
			// ver excepciones.
			break;
		case 5:
			finished = true;
			break;
		}
	} while (!finished);
}

// -------------------------------------------------

Controller::Controller() {
	this->menu = std::make_shared<Menu>();
}

Controller::~Controller() {}

void Controller::start(){
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
			// Consultar Ocurrencias - Caract�r.
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