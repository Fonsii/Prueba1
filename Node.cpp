#include "Node.h"

Node::Node()
{
	Node::ocurrencias = 0;
	Node::palabra = nullptr;
}

Node::Node(std::string palabra)
{
	Node::palabra = palabra;
	Node::ocurrencias = 1;
}



Node::Node(int uso, std::string palabra)
{
	Node::palabra = palabra;
	Node::ocurrencias = uso;
}
