#pragma once
#include <string>
#include <vector>
/*Autor: Alonso Moreno
Versi�n: 1.0
Descripci�n: clase que solicita n�meros o strings para la utilizaci�n del men�*/
class Menu {

public:
	Menu();
	~Menu();

	// pide al usuario ingresar una opci�n n�merica.
	int getUserEntryOption(std::vector<std::string> options, std::string message);

	// pide al usuario ingresar texto.
	std::string getUserEntryText(std::string message);
};
	