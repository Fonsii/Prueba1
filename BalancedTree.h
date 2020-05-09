#pragma once

#include "Node.h"
#include <string>
#include<sstream>
#include<iomanip>


class BalancedTree {

public:

	BalancedTree();
	BalancedTree(std::string  newWord);
	BalancedTree(BalancedTree* ptr);
	BalancedTree(BalancedTree* left, Node* root, BalancedTree* right);
	virtual ~BalancedTree();


	void add(std::string  newWord);
	void erase(std::string toErase);
	void rotateR();
	void rotateL();
	void rotateRL();
	void rotateLR(); 
	int getWeight();
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
