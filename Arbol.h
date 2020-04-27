#pragma once
#include "Node.h"
#include <string>
#include <locale>

class Arbol {

public:

	Arbol();
	Arbol(std::string palabra);

	void toLower(std::string palabra);
	void add(std::string palabra);


	Arbol* izq;
	Node* raiz;
	Arbol* der;
};
