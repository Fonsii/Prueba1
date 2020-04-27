#pragma once
#include <string>


class Node {

public:
	Node();
	Node(std::string world);
	Node(int ocurrencias, std::string word);


	int ocurrencias;
	std::string word;

};