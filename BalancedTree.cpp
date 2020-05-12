#include "BalancedTree.h"
#include <iostream>
#include<locale>

/*
	Constructor primario de la clase BalancedTree donde todo esta null
*/
BalancedTree::BalancedTree()
{
	BalancedTree::left = nullptr;
	BalancedTree::root = nullptr;
	BalancedTree::right = nullptr;
}

/*
	Constructor del arbol para el metodo add
	@param palabra que va en la raiz
*/
BalancedTree::BalancedTree(std::string newWord)
{
	BalancedTree::left = nullptr;
	BalancedTree::root = new Node(newWord);
	BalancedTree::right = nullptr;
}

/*
	Constructor del arbol para el metodo add para cuando se carga un archivo con ocurrencias
	@param palabra y ocurrencia
*/
BalancedTree::BalancedTree(std::string newWord,int howMuch)
{
	BalancedTree::left = nullptr;
	BalancedTree::root = new Node(newWord);
	BalancedTree::root->howMany = howMuch;
	BalancedTree::right = nullptr;
}

/*
	Constructor del arbol para las diversas rotaciones
	@param arbol
*/
BalancedTree::BalancedTree(BalancedTree* ptr) {
	this->left = ptr->left;
	this->root = ptr->root;
	this->right = ptr->right;

}

/*
	Constructor del arbol para las diversas rotaciones
	@param rama izquierda, raiz y rama derecha
*/
BalancedTree::BalancedTree(BalancedTree* left, Node* root, BalancedTree* right) {
	BalancedTree::left = left;
	BalancedTree::root = root;
	BalancedTree::right = right;
}

/*
	Destructor del arbol
*/
BalancedTree::~BalancedTree() {
	
	if (this->left != nullptr) {
		this->left->~BalancedTree();
	}
	if (this->right != nullptr) {
		this->right->~BalancedTree();
	}
	this->root->~Node();
	this->root = nullptr;
}

/*
	Metodo para la rotacion izquierda
*/
void BalancedTree::rotateR() {
	Node* tmp = new Node(this->left->root);
	BalancedTree* aBorrar1 = this->left->right;
	delete this->left->right;
	delete this->left->root;
	this->right = new BalancedTree(aBorrar1, this->root, this->right);
	this->left = this->left->left;
	this->root = tmp;
}

/*
	Metodo para la rotacion derecha
*/
void BalancedTree::rotateL() {
	Node* tmp = new Node(this->right->root);
	BalancedTree* aBorrar1 = this->right->left;
	delete this->right->left;
	delete this->right->root;
	this->right = this->right->right;
	this->left = new BalancedTree(this->left, this->root, aBorrar1);
	this->root = tmp;
}

/*
	Metodo para la rotacion izquierda-derecha
*/
void BalancedTree::rotateRL() {
	if (this->right->left) {
		Node* tmp = new Node(this->right->left->root);
		BalancedTree* aBorrar1 = this->right->left->right;
		delete this->right->left->right;
		delete this->right->left->root;
		this->right->left = this->right->left->left;
		this->right->right = new BalancedTree(aBorrar1, this->right->root, this->right->right);
		this->right->root = tmp;
		rotateL();
	}
}

/*
	Metodo para la rotacion derecha-izquierda
*/
void BalancedTree::rotateLR() {
	Node* tmp = new Node(this->left->right->root);
	BalancedTree* aBorrar1 = this->left->right->left;
	delete this->left->right->left;
	delete this->left->right->root;
	this->left->right = this->left->right->right;
	this->left->left = new BalancedTree(this->left->left, this->left->root, aBorrar1);
	this->left->root = tmp;
	rotateR();
}

/*
	Metodo para la conseguir los pesos del arbol 
	@return peso de la raiz que llamo al metodo
*/
int BalancedTree::getHeight() {
	int p = 0;
	int pi = 0;
	int pd = 0;

	if (this) {
		if (!this->left) {
			pi = pi + this->left->getHeight() + 1;
		}
		else {
			pi = 0;
		}

		if (!this->right) {
			pd = pd + this->right->getHeight() + 1;
		}
		else {
			pd = 0;
		}
	}

	p = (pi > pd) ? pi : pd;
	return p;
}

/*
	Metodo para saber que rotacion hay que realizar
*/
void BalancedTree::computeBalance() {
	if (this->root != nullptr) {
		int pi = (this->left == nullptr) ? 0 : this->left->getHeight() + 1;
		int pd = (this->right == nullptr) ? 0 : this->right->getHeight() + 1;
		int balance_factor = pi - pd;

		switch (balance_factor) {
		case 0:case 1:case -1:break;

		case 2:
			if (this->left != nullptr && balance_factor == 2 && this->left->getHeight() == 1) {
				rotateR();
			}
			else {
				rotateLR();
			}
			break;
		case -2:
			if (this->right != nullptr && balance_factor == -2 && this->right->getHeight() == -1) {
				rotateL();
			}
			else {
				rotateRL();
			}
			break;
		}
	}
}

/*
	Metodo de agregado con solo una palabra
	@param Palabra a agregar en el arbol
*/
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

/*
	Metodo de agregado con palabra y ocurrencia
	@param palabra y ocurrencia
*/
void BalancedTree::add(std::string newWord, int howMuch)
{
	if (this->root == nullptr) {
		this->root = new Node(newWord);
		this->root->howMany = howMuch;
	}
	else {
		if (this->root->word < newWord) {
			if (this->right == nullptr) {
				this->right = new BalancedTree(newWord,howMuch);
			}
			else {
				this->right->add(newWord, howMuch);
			}
		}
		else if (this->root->word > newWord) {
			if (this->left == nullptr) {
				this->left = new BalancedTree(newWord,howMuch);
			}
			else {
				this->left->add(newWord, howMuch);
			}
		}
	}
	this->computeBalance();
}

/*
	Metodo para conseguir el mayor de los menores
	@return la palabra mas grande de la rama izquierda
*/
std::string BalancedTree::getMajorLess() {
	std::string major = "";
	BalancedTree* iter = this->left;
	bool continue1 = true;
	while ((iter->root != nullptr) && (continue1)) {
		major = iter->root->word;
		if (iter->right != nullptr)
			iter = iter->right;
		else
			continue1 = false;
	}
	return major;
}

/*
	Metodo para conseguir el menor de los mayores
	@return la palabra mas pequeña de la rama derecha
*/
std::string BalancedTree::getLessMajor(){
	std::string less = "";
	BalancedTree* iter = this->right;
	bool continue1 = true;
	while ((iter->root != nullptr) && (continue1)) {
		less = iter->root->word;
		if (iter->left != nullptr) {
			iter = iter->left;
		}else{
			continue1 = false;
		}
	}
	return less;
}

/*
	Metodo de busqueda de una palabra en el arbol
	@param palabra a buscar
	@return si se encuentra la palabra la devuelve y las ocurrencias, si no devuelve "Palabra no encontrada"
*/
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

/*
	Metodo para imprimir todo el arbol
	@return string con todas las palabras y sus ocurrencias
*/
std::string BalancedTree::toString() {
	std::stringstream returnString;

	if (this != nullptr) {
		returnString << this->root->word;
		returnString << ":";
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