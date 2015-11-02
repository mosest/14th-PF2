/* Tara Moses
 * Assignment 3: Stack header
 * October 30, 2015
 */

#include "Stack.h"
using namespace std;

Stack::Stack() {
	for (int i = 0; i < size; i++) {
		nums[i] = 0;
	}
	
	top = -1; //we're starting at -1 if the stack starts out empty
}

Stack::~Stack() {
	cout << "Stack destructor" << endl;
}

//other methods! push/pop
void Stack::push(int n) {
	nums[top++] = n;
}

int Stack::pop() {
	if (top >= 0) return nums[top--];
	else return -999999;
}
