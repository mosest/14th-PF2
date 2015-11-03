/* Tara Moses
 * Assignment 3: Postfix Calculator
 * October 30, 2015
 */

#include <iostream>
#include "VariableList.cpp"
#include "Stack.cpp"
#include <cmath>
using namespace std;

//globals!
VariableList* varList = new VariableList();
Stack* s = new Stack();
bool aVariableNeedsAssignment = false; //assume we're not doing anything with a var

bool isANumber(int n) {
	//fix this eventually
	return true;
}

void doSomethingWith(char c) {
	//if token is a letter (variable!)
	if (c > 64 && c < 92) {
		aVariableNeedsAssignment = true;
		VariableNode* var = new VariableNode();
		var->setName(c);
	}
	
	//don't do anything if c is '=', it was already handled
	//when user input a letter (variable!)
	
	//if c is an operator! (make this better, i hate multiple OR statements '>_>)
	else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
		//pop 2, do the operand, push regular num
		int result;
		if (c == '+') result = s->pop() + s->pop();
		else if (c == '-') result = -1 * s->pop() + s->pop();
		else if (c == '*') result = s->pop() * s->pop();
		else if (c == '/') result = (1.0/s->pop()) * s->pop();
		else if (c == '^') {
			int exp = s->pop();
			int base = s->pop();
			result = pow(base,exp);
		}
		s->push(result);
	}
	
	//if c is a num
	else if (isANumber(c)) s->push(c);
}

int main() {
	//variables
	char token;
	char another = 'y';
	
	cout << "---POSTFIX CALCULATOR---" << endl << endl;
	cout << "Enter an expression ended with #." << endl;
	
	while (another == 'y' || another == 'Y') { //take in all expressions the user wants
		cout << "> ";
		
		while (cin >> token && token != '#') { //take in all chars of an expression
			cout << "You typed '" << token << "'" << endl;
			
			//do something with the current token!
			doSomethingWith(token);
		}
			
		//also if a result is the only thing on the stack
		//(at the end of the expression)
		//then set it as the value for the variable if there is one!
		if (aVariableNeedsAssignment) {
			VariableNode mostRecentVariable = *(varList->getLast());
			mostRecentVariable.setValue(s->pop());
		}
		
		cout << "Input another expression (y/n)? ";
		cin >> another;
		cout << endl;
	}
	
	return 0;
}
