/* Tara Moses
 * Assignment 3: Stack header
 * October 30, 2015
 */

using namespace std;

class Stack{
	public:
		Stack();
		~Stack();
		
		bool push(int);
		bool pop(int &);
		void print();
		
	private:
		int nums[10];
		int numItems;
};
