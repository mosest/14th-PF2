/* Tara Moses
 * Assignment 3: Stack header
 * October 30, 2015
 */

#include "Stack.h"
using namespace std;

Stack::Stack() {
	//initialize everything in the array to 0
	for (int i = 0; i < 10; i++) {
		nums[i] = 0;
	}
	
	numItems = 0; //we're starting at 0 if there are 0 things in the stack
}

Stack::~Stack() {
	cout << "Stack destructor" << endl;
}

//other methods! push/pop
bool Stack::push(int n) {
	if (numItems < 10) {
		nums[numItems] = n;
		numItems++;
		return true;
	}
	//stack overflow D:
	return false;
}

bool Stack::pop(int & n) {
	if (numItems > 0) {
		numItems--;
		n = nums[numItems];
		return true;
	}
	//stack underflow :(
	return false;
}

void Stack::print() {
	cout << "Number of Items: " << numItems << endl;
	for (int i = 0; i < numItems; i++) {
		cout << nums[i] << " ";
	}
	cout << "End print" << endl;
}
