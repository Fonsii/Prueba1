#include "Arbol.h"

Arbol::Arbol()
{
	Arbol::izq = nullptr;
	Arbol::root = nullptr;
	Arbol::der = nullptr;
}

Arbol::Arbol(std::string  phrase)
{
	Arbol::izq = nullptr;
	Arbol::root = new Node(phrase);
	Arbol::der = nullptr;
}


void Arbol::add(std::string  phrase)
{
	if (Arbol::root == nullptr) {
		Arbol::Arbol(phrase);
	}
	else {
		if (Arbol::root->palabra == phrase) {
			Arbol::root->ocurrencias++;
		}
		else {
			if (Arbol::root->palabra > phrase) {
				if (Arbol::izq == nullptr) {
					Arbol::izq = new Arbol(phrase);
				}
				else {
					Arbol::izq->add(phrase);
				}
			}
			else {
				if (Arbol::der == nullptr) {
					Arbol::der = new Arbol(phrase);
				}
				else {
					Arbol::der->add(phrase);
				}
			}
		}	
	}
}
