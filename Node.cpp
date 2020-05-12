#include "Node.h"

/*
	Constructor primario de la clase nodo
*/
Node::Node()
{
	Node::howMany = 0;
	Node::word = nullptr;
}

/*
	Constructor de la clase nodo para diversas rotaciones y adds
	@param palabra que va en el nodo
*/
Node::Node(std::string newWord)
{
	Node::word = newWord;
	Node::howMany = 1;
}

/*
	Constructor de la clase nodo para uno de los adds
	@param palabra que va en el nodo y ocurrencias
*/
Node::Node(int howMany, std::string newWord)
{
	Node::word = newWord;
	Node::howMany = howMany;
}

/*
	Constructor de la clase nodo para diversas rotaciones 
	@param nodo
*/
Node::Node(Node* tempNode) {
	Node::word = tempNode->word;
	Node::howMany = tempNode->howMany;
}

/*
	Destructor de la clase nodo
*/
Node::~Node() {
	word.~basic_string();
	howMany = NULL;
}
