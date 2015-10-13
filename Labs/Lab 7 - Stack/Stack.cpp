//-----------------------------------------------------------
//  Purpose:    Implementation of Stack class.
//-----------------------------------------------------------
#include "Stack.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
Stack::Stack()
{
   head   = NULL;
   length = 0;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
Stack::~Stack()
{
}

//-----------------------------------------------------------
// This checks to see if stack is full.
//-----------------------------------------------------------
bool Stack::isFull()
{
   return (false);
}

//-----------------------------------------------------------
// This checks to see if stack is empty.
//-----------------------------------------------------------
bool Stack::isEmpty()
{
   return (length == 0);
}

//-----------------------------------------------------------
// This routine pushes data into the stack.
//-----------------------------------------------------------
void Stack::push(int number)
{
   // Check for full stack
   if (isFull())
      return;

   // Allocate space for data
   SNode *temp = new SNode;
   if (temp == NULL)
      return;

   // Insert data at head of list
   temp->number = number;
   temp->next   = head;
   head         = temp;
   length++;
}

//-----------------------------------------------------------
// This routine pops data from the stack.
//-----------------------------------------------------------
void Stack::pop(int& number)
{
   // Check for empty stack
   if (isEmpty())
      return;

   // Extract information from node
   number = head->number;

   // Pop item from linked list
   SNode* temp = head;
   head        = head->next;
   delete temp;
   length--;
}

//-----------------------------------------------------------
// This routine returns the data from the front of the stack.
//-----------------------------------------------------------
void Stack::top(int& n)
{
	n = head->number;
}

//-----------------------------------------------------------
// This routine prints all records in the stack.
//-----------------------------------------------------------
void Stack::print()
{
   SNode* current = new SNode;
   current = head;
   
   while (current != NULL) {
	   cout << current->number << endl;
	   current = current->next;
   }
   cout << endl;
}

//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
int main()
{
   Stack* stack = new Stack;
   int nums[] = {3,1,4,1,5};
   int num;
   
   //push everything into filo stack
   for (int i = 0; i < 5; i++) {
	   stack->push(nums[i]);
	   cout << "push(" << nums[i] << ")" << endl;
	   stack->print();
   }
   
   return 0;
}
