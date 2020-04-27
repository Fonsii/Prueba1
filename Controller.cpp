#include <iostream>
#include <string>
#include <locale>
#include "Controller.h"

Controller::Controller() {}
Controller::~Controller() {}

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