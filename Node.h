#pragma once
#include <string>

/*
	Autor: Luis Alfonso Jiménez Aguilar
	Version 1.0
	Nodo para el arbol balanceado de palabras
*/
class Node {

public:
	Node();
	Node(std::string newWord);
	Node(int howMany , std::string newWord);
	Node(Node* tempNode);
	virtual ~Node();

	int howMany;
	std::string word;
};