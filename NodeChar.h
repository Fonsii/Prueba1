#pragma once

// Algunos m�todos de esta clase fueron tomadas del codigo provisto por el profesor Javier Vasquez.
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