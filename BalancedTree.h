#pragma once

#include "Node.h"
#include <string>
#include<sstream>
#include<iomanip>


// Algunos métodos de esta clase fueron tomadas del codigo provisto por el profesor Javier Vasquez.
/*
	Autor: Luis Alfonso Jiménez Aguilar
	Version 1.0
	Arbol Binario Balanceado de palabras
*/
class BalancedTree {

public:

	BalancedTree();
	BalancedTree(std::string  newWord);
	BalancedTree(std::string newWord, int howMuch);
	BalancedTree(BalancedTree* ptr);
	BalancedTree(BalancedTree* left, Node* root, BalancedTree* right);
	virtual ~BalancedTree();


	void add(std::string  newWord);
	void add(std::string newWord, int howMuch);
	void rotateR();
	void rotateL();
	void rotateRL();
	void rotateLR(); 
	std::string getMajorLess();
	std::string getLessMajor();
	void computeBalance();
	int getHeight();
	std::string search(std::string toSearch);
	std::string toString();

	BalancedTree* left;
	Node* root;
	BalancedTree* right;

};
