#pragma once
#include <string>

class Menu {

public:
	Menu();
	~Menu();

	int getUserEntryOption(std::string message); // pide al usuario ingresar una opción númerica.
	std::string getUserEntryText(std::string message); // pide al usuario ingresar texto.
};