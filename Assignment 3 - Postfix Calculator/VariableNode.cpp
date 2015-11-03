/* Tara Moses
 * Assignment 3: VariableNode class
 * October 30, 2015
 */

#include "VariableNode.h"
using namespace std;
 
VariableNode::VariableNode() {
	name = '\0';
	value = -1;
	next = NULL;
}

VariableNode::VariableNode(char n, int v) {
	name = n;
	value = v;
	next = NULL;
}

VariableNode::VariableNode(char n, int v, VariableNode* nextone) {
	name = n;
	value = v;
	next = nextone;
}

VariableNode::~VariableNode() {
	cout << "VNode destructor" << endl;
}

//getters
VariableNode* VariableNode::getNext() {
	return next;
}

char VariableNode::getName() {
	return name;
}

int VariableNode::getValue() {
	return value;
}

//setters
void VariableNode::setNext(VariableNode * n) {
	next = n;
}

void VariableNode::setName(char n) {
	name = n;
}

void VariableNode::setValue(int v) {
	value = v;
}
