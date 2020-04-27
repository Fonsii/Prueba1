#include "Node.h"

Node::Node()
{
	Node::uso = 0;
	Node::palabra = nullptr;
}

Node::Node(std::string palabra)
{
	Node::palabra = palabra;
	Node::uso = 1;
}



Node::Node(int uso, std::string palabra)
{
	Node::palabra = palabra;
	Node::uso = uso;
}
