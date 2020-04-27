#include "BalancedTree.h"

BalancedTree::BalancedTree()
{
	BalancedTree::left = nullptr;
	BalancedTree::root = nullptr;
	BalancedTree::right = nullptr;
}

BalancedTree::BalancedTree(std::string newWord)
{
	BalancedTree::left = nullptr;
	BalancedTree::root = new Node(newWord);
	BalancedTree::right = nullptr;
}

void BalancedTree::add(std::string newWord)
{
	if (BalancedTree::root == nullptr) {
		BalancedTree::BalancedTree(newWord);
	}
	else {
		if (BalancedTree::root->word == newWord) {
			BalancedTree::root->howMany++;
		}
		else {
			if (BalancedTree::root->word > newWord) {
				if (BalancedTree::left == nullptr) {
					BalancedTree::left = new BalancedTree(newWord);
				}
				else {
					BalancedTree::left->add(newWord);
				}
			}
			else {
				if (BalancedTree::right == nullptr) {
					BalancedTree::right = new BalancedTree(newWord);
				}
				else {
					BalancedTree::right->add(newWord);
				}
			}
		}	
	}
}
