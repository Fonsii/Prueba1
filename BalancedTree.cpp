#include "BalancedTree.h"

BalancedTree::BalancedTree()
{
	BalancedTree::left = nullptr;
	BalancedTree::root = nullptr;
	BalancedTree::right = nullptr;
	balance_factor = 0;
}

BalancedTree::BalancedTree(std::string newWord)
{
	BalancedTree::left = nullptr;
	BalancedTree::root = new Node(newWord);
	BalancedTree::right = nullptr;
	balance_factor = 0;
}

BalancedTree::BalancedTree(BalancedTree* left, Node* root, BalancedTree* right) {
	BalancedTree::left = left;
	BalancedTree::root = root;
	BalancedTree::right = right;
	int pi = 0;
	int pd = 0;
	if (this->left != nullptr)
		pi = this->left->getHeight();
	if (this->right != nullptr)
		pd = this->right->getHeight();
	this->balance_factor = pi - pd;
}

BalancedTree::~BalancedTree() {
	this->root->~Node();
}

void BalancedTree::rotateR() {
	Node* tmp = new Node(this->left->root);
	BalancedTree* aBorrar1 = this->left->right;
	this->right = new BalancedTree(aBorrar1, this->root, this->right);
	this->left = this->left->left;
	delete aBorrar1;
	this->root = tmp;

}

/*
	Metodo para la rotacion derecha
*/
void BalancedTree::rotateL() {
	Node* tmp = new Node(this->right->root);
	BalancedTree* aBorrar1 = this->right->left;
	this->right = this->right->right;
	this->left = new BalancedTree(this->left, this->root, aBorrar1);
	delete aBorrar1;
	this->root = tmp;
}

/*
	Metodo para la rotacion izquierda-derecha
*/
void BalancedTree::rotateRL() {
	Node* tmp = new Node(this->right->left->root);
	BalancedTree* aBorrar1 = this->right->left->right;
	this->right->left = this->right->left->left;
	this->right->right = new BalancedTree(aBorrar1, this->right->root, this->right->right);
	delete aBorrar1;
	this->right->root = tmp;
	rotateL();
}

/*
	Metodo para la rotacion derecha-izquierda
*/
void BalancedTree::rotateLR() {
	Node* tmp = new Node(this->left->right->root);
	BalancedTree* aBorrar1 = this->left->right->left;
	this->left->right = this->left->right->right;
	this->left->left = new BalancedTree(this->left->left, this->left->root, aBorrar1);
	delete aBorrar1;
	this->left->root = tmp;
	rotateR();
}

int BalancedTree::getHeight() {
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

void BalancedTree::computeBalance() {
	int pi = (this->left == nullptr) ? 0 : this->left->getHeight() + 1;
	int pd = (this->right == nullptr) ? 0 : this->right->getHeight() + 1;
	int fb = pi - pd;

	switch (fb) {
	case 0:case 1:case -1:break;

	case 2:
		if (this->left != NULL && this->left->balance_factor == 1) {
			rotateR();
		}
		else {
			rotateLR();
		}
		break;
	case -2:
		if (this->right != NULL && this->right->balance_factor == -1) {
			rotateL();
		}
		else {
			rotateRL();
		}
		break;
	}
}

void BalancedTree::add(std::string newWord)
{
	if (this->root == nullptr){
		this->root = new Node(newWord);
	}
	else{
		if (this->root->word == newWord) {
			this->root->howMany++;
		}
		else if (this->root->word < newWord){
			if (this->right == nullptr){
				this->right = new BalancedTree(newWord);
			}
			else{
				this->right->add(newWord);
			}
		}
		else if(this->root->word > newWord){
				if (this->left == nullptr){
					this->left = new BalancedTree(newWord);
				}
				else{
					this->left->add(newWord);
				}
		}
	}
	this->computeBalance();
}

std::string BalancedTree::search(std::string toSearch){
	std::stringstream returnString;

	if (this != nullptr) {
		if (this->root->word == toSearch) {
			returnString << this->root->word;
			returnString << std::setw(2);
			returnString << this->root->howMany;
			returnString << std::endl;
		}
		else if (this->root->word < toSearch) {
				returnString << this->right->search(toSearch);
		}
		else if (this->root->word > toSearch) {
				returnString << this->left->search(toSearch);
		}
	}
	else {
		returnString << "Palabra no encontrada";
		returnString << std::endl;
	}
	return returnString.str();
}

std::string BalancedTree::toString() {
	std::stringstream returnString;

	if (this != nullptr) {
		returnString << this->root->word;
		returnString << std::setw(2);
		returnString << this->root->howMany;
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
