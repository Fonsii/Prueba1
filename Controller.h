#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Menu.h"

class Controller {

public:
	Controller();
	virtual ~Controller();

	void start();
	std::shared_ptr<Menu> menu;
};