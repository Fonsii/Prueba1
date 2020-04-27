#pragma once
#include <iostream>
#include <string>

class Controller {

public:
	Controller();
	virtual ~Controller();

	std::string toLower(std::string word);
};