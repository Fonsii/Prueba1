#pragma once
/*
	Autor: Luis Alfonso Jim�nez Aguilar
	Version 1.0
	Nodo para el arbol balanceado de caracteres
*/
class NodeChar{

public:

	NodeChar(char val);
	NodeChar(NodeChar* tempNode);
	~NodeChar();

	char character;
	int howMuch;
};