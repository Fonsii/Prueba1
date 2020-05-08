#pragma once

class NodeChar{

public:

	NodeChar(char val);
	NodeChar(NodeChar* tempNode);
	~NodeChar();

	char character;
	int howMuch;
};