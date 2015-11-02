/* Tara Moses
 * Assignment 3: VariableNode header
 * October 30, 2015
 */

using namespace std;

class VariableNode{
	public:
		VariableNode(char, int);
		VariableNode(char, int, VariableNode *);
		~VariableNode();
		
		VariableNode* getNext();
		char getName();
		int getValue();
		
		void setNext(VariableNode *);
		
	private:
		int value;
		char name;
		VariableNode* next;
};
