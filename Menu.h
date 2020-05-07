#pragma once
#include <string>
#include <vector>

class Menu {

public:
	Menu();
	~Menu();

	// pide al usuario ingresar una opci�n n�merica.
	int getUserEntryOption(std::vector<std::string> options, std::string message);

	// pide al usuario ingresar texto.
	std::string getUserEntryText(std::string message);
};
	