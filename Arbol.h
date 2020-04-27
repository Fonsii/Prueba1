#pragma once
#include "Node.h"
#include <string>
#include <locale>

class Arbol {

public:

	Arbol();
	Arbol(std::string  phrase);


	void add(std::string  phrase);


	Arbol* izq;
	Node* root;
	Arbol* der;
};
