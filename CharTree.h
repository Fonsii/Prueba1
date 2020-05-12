#pragma once

#include "BalancedTree.h"
#include "NodeChar.h"
#include <sstream>
#include <iomanip>

/*
	Autor: Luis Alfonso Jim�nez Aguilar
	Version 1.0
	Arbol Binario Balanceado de caracteres
*/
class CharTree {
	
public:

	CharTree();
	CharTree(char newWord);
	CharTree(CharTree* left, NodeChar* root, CharTree* right);
	virtual ~CharTree();

	void rotateR();
	void rotateRL();
	void rotateL();
	void rotateLR();
	int getHeight();
	void computeBalance();
	void add(char newWord);
	void getCharTree(BalancedTree* tree);
	std::string search(char toSearch);
	std::string toString();

	CharTree* left;
	NodeChar* root;
	CharTree* right;
};