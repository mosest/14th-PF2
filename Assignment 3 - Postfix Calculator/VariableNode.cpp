/* Tara Moses
 * Assignment 3: VariableNode class
 * October 30, 2015
 */

#include "VariableNode.h"
#include <iostream>
using namespace std;
 
VariableNode::VariableNode() {
	name = '\0';
	value = -1;
	next = NULL;
}

VariableNode::VariableNode(string n, int v) {
	name = n;
	value = v;
	next = NULL;
}

VariableNode::VariableNode(string n, int v, VariableNode* nextone) {
	name = n;
	value = v;
	next = nextone;
}

VariableNode::~VariableNode() {}

//getters
VariableNode* VariableNode::getNext() {
	return next;
}

string VariableNode::getName() {
	return name;
}

int VariableNode::getValue() {
	return value;
}

//setters
void VariableNode::setNext(VariableNode * n) {
	next = n;
}

void VariableNode::setName(string str) {
	name = str;
}

void VariableNode::setValue(int v) {
	value = v;
}
