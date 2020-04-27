#pragma once
#include <string>


class Node {

public:
	Node();
	Node(std::string newWord);
	Node(int howMany , std::string newWord);

	int howMany;
	std::string word;
};