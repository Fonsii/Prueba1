#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Menu.h"

/*
	Autor: Jesús Alonso Moreno Montero.
	Version: 1.0
	Clase controlador.
*/

class Controller {

public:
	Controller();
	virtual ~Controller();

	void start();
	std::shared_ptr<Menu> menu;
};