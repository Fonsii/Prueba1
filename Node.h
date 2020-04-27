#pragma once
#include <string>


class Node {

public:

	Node();
	Node(std::string palabra);
	Node(int howMany, std::string palabra);


	int howMany;
	std::string palabra;

};