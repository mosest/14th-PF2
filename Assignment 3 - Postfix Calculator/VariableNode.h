/* Tara Moses
 * Assignment 3: VariableNode header
 * October 30, 2015
 */

#include <string>
using namespace std;

class VariableNode {
	public:
		VariableNode();
		VariableNode(string, int);
		VariableNode(string, int, VariableNode *);
		~VariableNode();
		
		VariableNode* getNext();
		string getName();
		int getValue();
		
		void setNext(VariableNode *);
		void setName(string);
		void setValue(int);
		
	private:
		int value;
		string name;
		VariableNode* next;
};
