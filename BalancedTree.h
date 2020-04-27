#pragma once
#include "Node.h"
#include <string>
#include <locale>

class BalancedTree {

public:

	BalancedTree();
	BalancedTree(std::string  newWord);


	void add(std::string  newWord);


	BalancedTree* left;
	Node* root;
	BalancedTree* right;
};
