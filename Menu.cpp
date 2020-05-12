#include "Menu.h"
#include <iostream>
#include <iterator>

Menu::Menu()
{}

Menu::~Menu() {}
/*Método que devuelve un número, el primer parámetro despliega un menú de un vector, el segundo parámetro despliega un mensaje para ingresar un número*/
int Menu::getUserEntryOption(std::vector<std::string> options, std::string message) {

	int reply = -1;
	bool validEntry = false;
	while (!validEntry) {
		std::cout << "\n" << message << std::endl;		
		std::vector<std::string>::iterator i;
		for (i = options.begin(); i != options.end(); i++) {
			std::cout << *i << std::endl;
		}
		std::cin >> reply;
		if (reply != -1) {
			validEntry = true;
		}
	}
	return reply;
}
/*Método que devuelve una string, en el parámetro se despliega un mensaje para indicar la string que se solicita*/
std::string Menu::getUserEntryText(std::string message) {
	std::string reply;
	bool validEntry = false;
	while (!validEntry) {
		std::cout << "\n" << message << std::endl;
		std::cin >> reply;
		if (!reply.empty()) {
			validEntry = true;
		}
	}
	return reply;
}

