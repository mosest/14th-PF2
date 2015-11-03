/* Tara Moses
 * Assignment 3: Postfix Calculator
 * October 30, 2015
 */

#include <iostream>
#include "VariableList.cpp"
#include "Stack.cpp"
#include <cmath>
#include <cstring> //strlen i think
#include <ctype.h> //isAlpha and isDigit
using namespace std;

//globals!
VariableList* varList = new VariableList();
Stack* s = new Stack();
bool isValid = true;

void handleExpression(const char* exp) {
	//exp[0] is letter, exp[2] is equal sign, exp[4] is where exp starts
	//so do the actual stackwork, then figure out what to do with result.
	//(either send it to an existing variable, or make a new var with it)
	
	//parse the actual expression (minus the 'var = ' part!)
	for (int i = 4; i < strlen(exp); i += 2) {
		char c = exp[i];
		
		//if token is a letter (variable!)
		if (isalpha(c)) {
			//if we don't know what the variable in the expression is,
			//then we're just going to QUIT EVERYTHING }:<
			if (varList->search(c) == 0) isValid = false;
			
			//otherwise: look it up, and push its value on stack :D
			else s->push(varList->search(c)->getValue());
		}
		
		//if c is a num, just push it (salt'n'peppa style)
		else if (isdigit(c)) s->push(c - '0');
		
		//if c is an operator! (i hate multiple OR statements '>_>)
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
			//pop 2, do the operand, push result
			int result = 0;
			
			if (c == '+') result = s->pop() + s->pop();
			else if (c == '-') result = (s->pop() - s->pop());
			else if (c == '*') result = s->pop() * s->pop();
			else if (c == '/') result = (1.0/s->pop()) * s->pop();
			else if (c == '^') {
				int exp = s->pop();
				int base = s->pop();
				result = pow(base,exp);
			}
			
			s->push(result);
		}
	}
	
	//if the starting variable is new
	if (varList->search(exp[0]) == 0) {
		//create a new spot for it
		VariableNode* var = new VariableNode();
		var->setName(exp[0]);
		var->setValue(s->pop());
		
		//add this var to the varList!
		varList->insert(*var);
	} 
	
	//otherwise, variable already exists (so just edit its value)
	else varList->search(exp[0])->setValue(s->pop());
	
	//print out the result!
	cout << exp[0] << " = " << varList->search(exp[0])->getValue() << endl;
}

int main() {
	//variables
	string tempStr;
	const char* expression;
	
	cout << "---POSTFIX CALCULATOR---" << endl << endl;
	cout << "Enter # to quit." << endl;
	
	do {
		cout << "> ";
		getline(cin, tempStr);
		expression = tempStr.c_str();
		
		cout << "You input '" << expression << "'" << endl;
		
		//handle '?'
		if (expression[0] == '?') varList->print();
		
		//handle everything else
		if (strlen(expression) < 5) isValid = false;
		if (isValid) handleExpression(expression);
	} while (expression[0] != '#'); //take in all expressions the user wants
	
	return 0;
}
