#include "NodeChar.h"

/*
	Constructor de la clase nodo de caracteres
	@param caracter que dentro del nodo
*/
NodeChar::NodeChar(char val){
	NodeChar::character = val;
	NodeChar::howMuch = 1;
}

/*
	Constructor de la clase nodo de caracteres que copia valores de otro nodo
	@param Nodo a copiar
*/
NodeChar::NodeChar(NodeChar* tempNode){
	NodeChar::character = tempNode->character;
	NodeChar::howMuch = tempNode->howMuch;
}

/*
	Destructor de la clase nodo de caracteres
*/
NodeChar::~NodeChar(){
}
