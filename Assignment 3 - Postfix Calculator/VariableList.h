/* Tara Moses
 * Assignment 3: Variable Linked List header
 * October 30, 2015
 */
#include <string>
#include "VariableNode.h"
using namespace std;

class VariableList {
	public:
		VariableList();
		~VariableList();
		
		void insert(VariableNode &);
		VariableNode* search(string);
		
		void print();
		
	private:
		VariableNode* head;
		VariableNode* current;
};
