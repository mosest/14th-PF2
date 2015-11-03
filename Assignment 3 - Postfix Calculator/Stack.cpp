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
	
	top = -1; //we're starting at -1 if the stack starts out empty
}

Stack::~Stack() {
	cout << "Stack destructor" << endl;
}

//other methods! push/pop
void Stack::push(int n) {
	top++;
	nums[top] = n;
}

int Stack::pop() {
	if (top > -1) {
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
