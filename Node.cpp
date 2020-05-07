#include "Node.h"

Node::Node()
{
	Node::howMany = 0;
	Node::word = nullptr;
}

Node::Node(std::string newWord)
{
	Node::word = newWord;
	Node::howMany = 1;
}

Node::Node(int howMany, std::string newWord)
{
	Node::word = newWord;
	Node::howMany = howMany;
}

Node::Node(Node* tempNode) {
	Node::word = tempNode->word;
	Node::howMany = tempNode->howMany;
}

Node::~Node() {

}
