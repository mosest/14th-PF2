/* Tara Moses
 * Assignment 3: Postfix Calculator
 * October 30, 2015
 */

#include <iostream>
#include "VariableList.cpp"
#include "Stack.cpp"
#include <cmath>
#include <cstdlib>		//atoi
#include <cstring> 		//used in helper functions
#include <string> 		//string.size()
#include <ctype.h> 		//isAlpha and isDigit
using namespace std;

//------------------------------------
// Global Variables
//------------------------------------
VariableList* varList = new VariableList();
Stack* s = new Stack();
bool isValid = true;

//------------------------------------
// Helper Functions
//------------------------------------
bool isAWord(string str) {
	const char* cStr = str.c_str();
	
	for (int i = 0; i < strlen(cStr); i++) {
		if (!isalpha(cStr[i])) return false;
	}
	
	return true;
}

void putStrIntoStrArray(string & str, string array[]) {
	int arrayNumItems = -1;
	string temp = "";
	
	//convert string to cstring
	const char* cStr = str.c_str();
	
	//take the first thing from cstring into array
	for (int i = 0; i < strlen(cStr); i++) {
		while (cStr[i] != ' ') temp += cStr[i];
	}
	arrayNumItems++;
	array[arrayNumItems] = temp;
	
	//go through cstring looking for anything that has a space before it.
	for (int i = 0; i < strlen(cStr); i++) {
		if (cStr[i] == ' ') {
			for (int j = i + 1; j < strlen(cStr); j++) {
				if (cStr[j] != ' ') temp += cStr[j];
			}
		}
		
		//when you find one, put it into array and make array's 'size' ++
		arrayNumItems++;
		array[arrayNumItems] = temp;	
	}
	
	//let's print out the array just for good measure
	cout << "the array is..." << endl;
	for (int i = 0; i < arrayNumItems; i++) {
		cout << array[i] << " ";
	}
}

//------------------------------------
// Function That Computes Expression
//------------------------------------
void handleExpression(string exp[]) {
	//exp[0] is letter, exp[1] is equal sign, exp[2] is where exp starts
	//so do the actual stackwork, then figure out what to do with result.
	//(either send it to an existing variable, or make a new var with it)
	
	//parse the actual expression (minus the 'var = ' part!)
	for (int i = 2; i < sizeof(exp); i++) {
		string token = exp[i];
		
		//if token is a letter (variable!)
		if (isAWord(token)) {
			//if variable is unknown, then expression is invalid
			if (varList->search(token) == 0) isValid = false;
			
			//otherwise: look it up, and push its value on stack :D
			else s->push(varList->search(token)->getValue());
		}
		
		//if token is a num, just push it (salt'n'peppa style)
		else if (atoi(token.c_str())) {
			int intToken = atoi(token.c_str());
			s->push(intToken);
		}
		
		//if token is an operator! (i hate multiple OR statements '>_>)
		else if (token.compare("+") == 0 || token.compare("-") == 0 || token.compare("*") == 0 || token.compare("/") == 0 || token.compare("^") == 0) {
			//pop 2, do the operand, push result
			int result = 0;
			
			if (token.compare("+") == 0) result = s->pop() + s->pop();
			else if (token.compare("-") == 0) result = -1.0 * (s->pop() - s->pop());
			else if (token.compare("*") == 0) result = s->pop() * s->pop();
			else if (token.compare("/") == 0) result = (1.0/s->pop()) * s->pop();
			else if (token.compare("^") == 0) {
				int exp = s->pop();
				int base = s->pop();
				result = pow(base,exp);
			}
			
			s->push(result);
		}
		
		//handle '?'
		else if (exp[0].compare("?") == 0) varList->print();
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

//------------------------------------
// Main Function
//------------------------------------
int main() {
	//variables
	string tempStr;
	string expression[1];	
	
	cout << "---POSTFIX CALCULATOR---" << endl << endl;
	cout << "Enter # to quit." << endl;
	
	do {
		//take in input
		cout << "> ";
		getline(cin, tempStr);
		
		//turn input into array of string tokens!
		const int lengthOfExpression = tempStr.size();
		string expression[lengthOfExpression];
		cout << "length of expression is: " << lengthOfExpression << endl;
		putStrIntoStrArray(tempStr, expression);
		
		cout << "You input '" << tempStr << "'" << endl;
		
		//handle the expression
		if (sizeof(expression) < 3) isValid = false;
		if (isValid) handleExpression(expression);
	} while (expression[0].compare("#") == 0); //take in all expressions the user wants
	
	return 0;
}
