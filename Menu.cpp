#include "Menu.h"
#include <iostream>
#include <iterator>

Menu::Menu()
{}

Menu::~Menu() {}

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

