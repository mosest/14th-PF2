/* Tara Moses
 * Assignment 3: VariableList class
 * October 30, 2015
 */

#include "VariableList.h"
#include <iostream>
using namespace std;

VariableList::VariableList() {
	head = NULL;
	current = head;
}

VariableList::~VariableList() {}

void VariableList::insert(VariableNode & node) { //inserts at head b/c easiest :^)
	if (head == NULL) head = &node;
	else {
		node.setNext(head);
		head = &node;
	}
}

VariableNode* VariableList::search(string varName) {
	if (head != NULL) {
		current = head;
		
		do {
			if ((*current).getName().compare(varName) == 0) return current;
			
			current = (*current).getNext();
		} while (current != NULL);
	}
	return NULL;
}

void VariableList::print() {
	cout << "---BEGIN PRINT---" << endl;
	
	current = head;
	while (current != NULL) {
		cout << (*current).getName() << " = " << (*current).getValue() << endl;
		current = (*current).getNext();
	}
	
	cout << "---END PRINT---" << endl;
}
