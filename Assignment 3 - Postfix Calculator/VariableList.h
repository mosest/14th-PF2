/* Tara Moses
 * Assignment 3: Variable Linked List header
 * October 30, 2015
 */
 
#include "VariableNode.cpp"

class VariableList {
	public:
		VariableList();
		VariableList(VariableNode *);
		~VariableList();
		
		void insert(VariableNode &);
		VariableNode* search(char);
		VariableNode* getLast();
		
		void print();
		
	private:
		VariableNode* head;
		VariableNode* current;
};
