#include "Arbol.h"

Arbol::Arbol()
{
	Arbol::izq = nullptr;
	Arbol::raiz = nullptr;
	Arbol::der = nullptr;
}

Arbol::Arbol(std::string palabra)
{
	Arbol::izq = nullptr;
	Arbol::raiz = new Node(palabra);
	Arbol::der = nullptr;
}

void Arbol::toLower(std::string palabra)
{
	std::locale loc;
	std::string str = palabra;
	std::string return1;
	for (std::string::size_type i = 0; i < str.length(); ++i){
		return1 += std::tolower(str[i], loc);
	}
	this->add(return1);
}

void Arbol::add(std::string palabra)
{
	if (raiz == nullptr) {
		Arbol::Arbol(palabra);
	}
	else {
		if (Arbol::raiz->palabra == palabra) {
			Arbol::raiz->uso++;
		}
		else {
			if (Arbol::raiz->palabra > palabra) {
				if (Arbol::izq == nullptr) {
					Arbol::izq = new Arbol(palabra);
				}
				else {
					Arbol::izq->add(palabra);
				}
			}
			else {
				if (Arbol::der == nullptr) {
					Arbol::der = new Arbol(palabra);
				}
				else {
					Arbol::der->add(palabra);
				}
			}
		}	
	}
}
