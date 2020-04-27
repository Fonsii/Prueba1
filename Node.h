#pragma once
#include <string>


class Node {

public:

	Node();
	Node(std::string palabra);
	Node(int uso, std::string palabra);


	int uso;
	std::string palabra;

};