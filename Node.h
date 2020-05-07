#pragma once
#include <string>


class Node {

public:
	Node();
	Node(std::string newWord);
	Node(int howMany , std::string newWord);
	Node(Node* tempNode);
	virtual ~Node();

	int howMany;
	std::string word;
};