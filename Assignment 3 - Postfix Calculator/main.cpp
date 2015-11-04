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
void printArray(string array[]) {
	cout << "|";
	for (int i = 0; i < sizeof(array); i++) {
		cout << array[i] << " ";
	}
	cout << "|" << endl;
}

bool isAWord(string str) {
	const char* cStr = str.c_str();
	
	for (int i = 0; i < strlen(cStr); i++) {
		if (!isalpha(cStr[i])) return false;
	}
	
	return true;
}

//-------------------------------------------
// Function That Takes Tokens out of String
//-------------------------------------------
void putStrIntoStrArray(string & str, string array[], int & numItems) {
	numItems = 0;
	string temp = "";
	
	//convert string to cstring
	const char* cStr = str.c_str();
	
	cout << "in pushStr: length of cStr = " << strlen(cStr) << endl;
	
	//take the first thing from cstring into array
	for (int i = 0; i < strlen(cStr) && cStr[i] != ' '; i++) {
		temp += cStr[i];
	}
	array[numItems] = temp;
	numItems++;
	
	//go through cstring looking for anything that has a space before it.
	for (int i = 0; i < strlen(cStr); i++) {
		if (cStr[i] == ' ') {
			temp = "";
			for (int j = i + 1; j < strlen(cStr) && cStr[j] != ' '; j++) {
				temp += cStr[j];
			}
				
			//when you find one, put it into array and make array's 'size' ++
			array[numItems] = temp;
			numItems++;
		}	
	}
}

//------------------------------------
// Function That Computes Expression
//------------------------------------
void handleExpression(string exp[], int numTokens) {
	//exp[0] is letter, exp[1] is equal sign, exp[2] is where exp starts
	//so do the actual stackwork, then figure out what to do with result.
	//(either send it to an existing variable, or make a new var with it)
	
	//parse the actual expression (minus the 'var = ' part!)
	for (int i = 2; i < numTokens; i++) {
		string token = exp[i];
		cout << "token = '" << token << "'" << endl;
		
		//if token is a letter (variable!)
		if (isAWord(token)) {
			cout << token << " is a word!" << endl;
			//if variable is unknown, then expression is invalid
			if (varList->search(token) == 0) {
				cout << "I don't know what " << token << " means. Invalid expression" << endl;
				return;
			}
			
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
	int numTokens = 0;
	
	cout << "---POSTFIX CALCULATOR---" << endl << endl;
	cout << "Enter # to quit." << endl;
	
	//take in input
	cout << "> ";
	getline(cin, tempStr);
	
	//turn input into array of string tokens!
	const int lengthOfExpression = tempStr.size();
	string expression[lengthOfExpression];
	putStrIntoStrArray(tempStr, expression, numTokens);
	
	while (expression[0].compare("#") != 0) { //take in all expressions the user wants
		//handle the expression
		if (expression[0].compare("?") == 0) cout << "varList->print()" << endl;
		else if (numTokens > 2) handleExpression(expression, numTokens);
		
		//ask for another
		cout << endl << "> ";
		getline(cin, tempStr);
		
		//turn input into array of string tokens!
		const int lengthOfExpression = tempStr.size();
		string expression[lengthOfExpression];
		putStrIntoStrArray(tempStr, expression, numTokens);
		
		printArray(expression);
	}
	
	return 0;
}
