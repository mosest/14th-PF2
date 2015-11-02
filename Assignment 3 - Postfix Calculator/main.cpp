/* Tara Moses
 * Assignment 3: Postfix Calculator
 * October 30, 2015
 */

#include <iostream>
#include "VariableList.cpp"
#include "Stack.cpp"
using namespace std;

void doSomethingWith(char c, bool & aVariableNeedsAssignment, Stack s) {
	if (token == '?') varList.print();
	
	//if token is a letter (variable!)
	else if (token > 64 && token < 92) {
		weAreAssigningSomethingToAVariable = true;
		VariableNode var = new VariableNode();
		var.setName(c);
	}
	
	//don't do anything if token is '=', it was already handled
	//when user input a letter (variable!)
	
	//if token is an operator! (make this better, i hate multiple OR statements '>_>)
	else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^' || token == '(' || token == ')') {
		//pop 2, do the operand, push regular num
		int result = s.pop() + s.pop();
	}
	
	//if token is a num
	else if (/*how to check if something is a num?????*/) {
		//push num
	}
}

int main() {
	//variables
	char token;
	char another = 'y';
	bool aVariableNeedsAssignment = false; //assume we're not doing anything with a var
	VariableList varList;
	string ops = "+-*/^()";
	Stack stackystack = new Stack();
	
	cout << "---POSTFIX CALCULATOR---" << endl << endl;
	cout << "Enter an expression ended with #." << endl;
	
	while (another == 'y' || another == 'Y') { //take in all expressions the user wants
		cout << "> ";
		
		while (cin >> token && token != '#') { //take in all chars of an expression
			cout << "You typed '" << token << "'" << endl;
			
			//do something with the current token!
			doSomethingWith(token, assign);
		}
			
		//also if a result is the only thing on the stack
		//(at the end of the expression)
		//then set it as the value for the variable if there is one!
		if (aVariableNeedsAssignment) {
			VariableNode mostRecentVariable = *(list.getLast());
			mostRecentVariable.setValue(stackystack.pop());
		}
		
		cout << "Input another expression (y/n)? ";
		cin >> another;
		cout << endl;
	}
	
	return 0;
}
