/* Tara Moses
 * Assignment 3: Stack header
 * October 30, 2015
 */

using namespace std;

class Stack{
	public:
		Stack();
		~Stack();
		
		void push(int);
		int pop();
		
	private:
		const int size;
		int nums[size];
		int top;
};
