#include "NodeChar.h"

NodeChar::NodeChar(char val){
	NodeChar::character = val;
	NodeChar::howMuch = 1;
}

NodeChar::NodeChar(NodeChar* tempNode){
	NodeChar::character = tempNode->character;
	NodeChar::howMuch = tempNode->howMuch;
}

NodeChar::~NodeChar(){

}
