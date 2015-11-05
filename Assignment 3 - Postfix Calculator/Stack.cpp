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
	
	top = 0; //we're starting at 0 if there are 0 things in the stack
}

Stack::~Stack() {
	cout << "Stack destructor" << endl;
}

//other methods! push/pop
void Stack::push(int n) {
	top++;
	if (top < 10) nums[top] = n;
}

int Stack::pop() {
	if (top > 0) {
		top--;
		return nums[top+1];
	} else cout << "nothing on the stack to pop! :(" << endl;
	return -999999;
}

void Stack::print() {
	cout << "Top: " << top << endl;
	for (int i = 0; i <= top; i++) {
		cout << nums[i] << " ";
	}
	cout << "end print" << endl;
}
