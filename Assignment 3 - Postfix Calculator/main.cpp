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

//-------------------------------------------
// Function That Takes Tokens out of String 
// (One at a Time)
//-------------------------------------------
bool getTokens(string & input, string & token) {
	token = "";
	const char* cStrInput = input.c_str();
	
	//find first token :D
	for (int i = 0; i < strlen(cStrInput) && cStrInput[i] != ' '; i++) {
		token += cStrInput[i];
	}
	
	//take token out of input. if there's a space in the string, then
	//(since there's always going to be a token after the space)
	//get whatever's after the string. otherwise, string is useless now
	if (input.find(' ') != -1) input = input.substr(input.find(' ')+1);
	else input = "";
	
	if (token.compare("") == 0) return false;
	return true;
}

//------------------------------------
// Function that Computes Expression
//------------------------------------
bool handleShit(string expression) {
	//get tokens one at a time, but do the first two without a loop
	//because you know what those are going to be: a variable name 
	//and '='. 
	
	string varName;
	string equalSign;
	string tempToken;
	if (!getTokens(expression, varName)) return false;
	
	//expression is now shorter, varName has a variable name in it. 
	//Let's call getTokens again just to get rid of the equal sign
	if (!getTokens(expression, equalSign)) return false;
	
	//now let's loop through to do actual calculations with the num/op tokens
	while (getTokens(expression, tempToken)) {
		//if tempToken is a word (variable): look up / create
		if (isAWord(tempToken)) {
			cout << tempToken << " is a word!" << endl;
			//if variable is unknown, then expression is invalid
			if (varList->search(tempToken) == 0) {
				cout << "I don't know what " << tempToken << " means. Invalid expression" << endl;
				return false;
			}
			
			//otherwise: look it up, and push its value on stack :D
			else s->push(varList->search(tempToken)->getValue());
		}
		
		//if tempToken is a number: push it
		else if (atoi(tempToken.c_str())) {
			int intToken = atoi(tempToken.c_str());
			s->push(intToken);
		}
		
		//if tempToken is an operator: pop 2, operate, push
		else if (tempToken.compare("+") == 0 || tempToken.compare("-") == 0 || tempToken.compare("*") == 0 || tempToken.compare("/") == 0 || tempToken.compare("^") == 0) {
			//pop 2, do the operand, push result
			int result = 0;
			
			if (tempToken.compare("+") == 0) result = s->pop() + s->pop();
			else if (tempToken.compare("-") == 0) result = -1.0 * (s->pop() - s->pop());
			else if (tempToken.compare("*") == 0) result = s->pop() * s->pop();
			else if (tempToken.compare("/") == 0) result = (1.0/s->pop()) * s->pop();
			else if (tempToken.compare("^") == 0) {
				int exp = s->pop();
				int base = s->pop();
				result = pow(base,exp);
			}
			
			s->push(result);
		}
	}
	
	//now assign result to (perhaps new) variable!
	if (varList->search(varName) == 0) {
		//create a new spot for it
		VariableNode* var = new VariableNode();
		var->setName(varName);
		var->setValue(s->pop());
		
		//add this var to the varList!
		varList->insert(*var);
	} 
	
	//otherwise, variable already exists (so just edit its value)
	else varList->search(varName)->setValue(s->pop());
	
	//print result of expression!
	cout << varName << " = " << varList->search(varName)->getValue() << endl;
	
	return true;
}

//------------------------------------
// Main Function
//------------------------------------
int main() {
	//variables
	string tempStr;
	const char* expression;
	
	cout << "---POSTFIX CALCULATOR---" << endl << endl;
	cout << "Enter # to quit." << endl;
	
	//take in input
	cout << "> ";
	getline(cin, tempStr);
	
	expression = tempStr.c_str();
	
	//turn input into array of string tokens!
	/*const int lengthOfExpression = tempStr.size();
	string expression[lengthOfExpression];
	putStrIntoStrArray(tempStr, expression, numTokens);
		
	printArray(expression);*/
	
	while (expression[0] != '#') { //take in all expressions the user wants
		//handle the expression
		if (expression[0] == '?') varList->print();
		else handleShit(tempStr);
		
		//ask for another
		cout << endl << "> ";
		getline(cin, tempStr);
		
		expression = tempStr.c_str();
		
		//turn input into array of string tokens!
		/*const int lengthOfExpression = tempStr.size();
		string expression[lengthOfExpression];
		putStrIntoStrArray(tempStr, expression, numTokens);
		
		printArray(expression);*/
	}
	
	return 0;
}
