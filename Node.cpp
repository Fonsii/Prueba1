#include "Node.h"

Node::Node()
{
	Node::howMany = 0;
	Node::palabra = nullptr;
}

Node::Node(std::string palabra)
{
	Node::palabra = palabra;
	Node::howMany = 1;
}



Node::Node(int howMany, std::string palabra)
{
	Node::palabra = palabra;
	Node::howMany = uso;
}
