#include "Menu.h"

Menu::Menu()
{
}

void Menu::toLower(std::string  phrase)
{
	std::locale loc;
	std::string str = phrase;
	std::string return1;
	for (std::string::size_type i = 0; i < str.length(); ++i) {
		return1 += std::tolower(str[i], loc);
	}

