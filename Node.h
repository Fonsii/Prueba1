#pragma once
#include <string>


class Node {

public:

	Node();
	Node(std::string palabra);
	Node(int ocurrencias, std::string palabra);


	int howMany;
	std::string palabra;

};