#include <iostream>
#include "Arbol.h"
#include <iostream>

int main() {
	Arbol* arbol;
	arbol = new Arbol();

	arbol->toLower("LUIS");
	arbol->toLower("ALONSO");

	std::cout << arbol->raiz->palabra << std::endl << arbol->raiz->ocurrencias;
	std::cout << arbol->izq->raiz->palabra << std::endl << arbol->izq->raiz->ocurrencias;

}