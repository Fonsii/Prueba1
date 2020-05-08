#include "CharTree.h"
#include <iostream>

CharTree::CharTree() {
	CharTree::left = nullptr;
	CharTree::root = nullptr;
	CharTree::right = nullptr;
}

CharTree::CharTree(char newWord){
	CharTree::left = nullptr;
	CharTree::root = new NodeChar(newWord);
	CharTree::right = nullptr;
}

CharTree::CharTree(CharTree* left, NodeChar* root, CharTree* right){
	CharTree::left = left;
	CharTree::root = root;
	CharTree::right = right;
}


CharTree::~CharTree() {
	if (this->left != nullptr) {
		this->left->~CharTree();
	}
	if (this->right != nullptr) {
		this->right->~CharTree();
	}
	this->root->~NodeChar();
}

void CharTree::rotateR() {
	NodeChar* tmp = new NodeChar(this->left->root);
	CharTree* aBorrar1 = this->left->right;
	this->right = new CharTree(aBorrar1, this->root, this->right);
	this->left = this->left->left;
	this->root = tmp;

}

/*
	Metodo para la rotacion derecha
*/
void CharTree::rotateL() {
	NodeChar* tmp = new NodeChar(this->right->root);
	CharTree* aBorrar1 = this->right->left;
	this->right = this->right->right;
	this->left = new CharTree(this->left, this->root, aBorrar1);
	this->root = tmp;
}

/*
	Metodo para la rotacion izquierda-derecha
*/
void CharTree::rotateRL() {
	NodeChar* tmp = new NodeChar(this->right->left->root);
	CharTree* aBorrar1 = this->right->left->right;
	this->right->left = this->right->left->left;
	this->right = new CharTree(aBorrar1, this->right->root, this->right->right);
	this->right->root = tmp;
	rotateL();
}

/*
	Metodo para la rotacion derecha-izquierda
*/
void CharTree::rotateLR() {
	NodeChar* tmp = new NodeChar(this->left->right->root);
	CharTree* aBorrar1 = this->left->right->left;
	this->left->right = this->left->right->right;
	this->left->left = new CharTree(this->left->left, left->root, aBorrar1);
	this->left->root = tmp;
	rotateR();
}

int CharTree::getHeight() {
	int p = 0;
	int pi = 0;
	int pd = 0;

	if (this->left == nullptr) {
		pi = 0;
	}
	else {
		pi = pi + this->left->getHeight() + 1;
	}

	if (this->right == nullptr) {
		pd = 0;
	}
	else {
		pd = pd + this->right->getHeight() + 1;
	}

	p = (pi > pd) ? pi : pd;
	return p;
}

void CharTree::computeBalance() {
	int pi = (this->left == nullptr) ? 0 : this->left->getHeight() + 1;
	int pd = (this->right == nullptr) ? 0 : this->right->getHeight() + 1;
	int balance_factor = pi - pd;

	switch (balance_factor) {
	case 0:case 1:case -1:break;

	case 2:
		if (this->left != nullptr && balance_factor == 2) {
			rotateR();
		}
		else {
			rotateLR();
		}
		break;
	case -2:
		if (this->right != nullptr && balance_factor == -2) {
			rotateL();
		}
		else {
			rotateRL();
		}
		break;
	}
}

void CharTree::add(char newWord){
	if (this->root == nullptr) {
		this->root = new NodeChar(newWord);
	}
	else {
		if (this->root->character == newWord) {
			this->root->howMuch++;
		}
		else if (this->root->character < newWord) {
			if (this->right == nullptr) {
				this->right = new CharTree(newWord);
			}
			else {
				this->right->add(newWord);
			}
		}
		else if (this->root->character > newWord) {
			if (this->left == nullptr) {
				this->left = new CharTree(newWord);
			}
			else {
				this->left->add(newWord);
			}
		}
	}
	this->computeBalance();
}

void CharTree::getCharTree(BalancedTree* Tree) {
	if (Tree->root != nullptr) {
		for (int position = 0; position < Tree->root->word.size()-1; position++) {
			this->add(Tree->root->word.at(position));
		}
	}
	if (Tree->left != nullptr) {
		this->getCharTree(Tree->left);
	}
	if (Tree->right != nullptr) {
		this->getCharTree(Tree->right);
	}
}

std::string CharTree::toString() {
	std::stringstream returnString;

	if (this != nullptr) {
		returnString << this->root->character;
		returnString << std::setw(2);
		returnString << this->root->howMuch;
		returnString << std::endl;
	}
	if (this->left != nullptr) {
		returnString << this->left->toString();
	}
	if (this->right != nullptr) {
		returnString << this->right->toString();
	}

	return returnString.str();
}