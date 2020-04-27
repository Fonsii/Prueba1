#include "Node.h"

Node::Node()
{
	Node::ocurrencias = 0;
	Node::word = nullptr;
}

Node::Node(std::string newWord)
{
	Node::word = word;
	Node::ocurrencias = 1;
}



Node::Node(int uso, std::string newWord)
{
	Node::word = word;
	Node::ocurrencias = uso;
}
