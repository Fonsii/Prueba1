#pragma once
#include <string>
#include <vector>
/*Autor: Alonso Moreno
Versión: 1.0
Descripción: clase que solicita números o strings para la utilización del menú*/
class Menu {

public:
	Menu();
	~Menu();

	// pide al usuario ingresar una opción númerica.
	int getUserEntryOption(std::vector<std::string> options, std::string message);

	// pide al usuario ingresar texto.
	std::string getUserEntryText(std::string message);
};
	