//-----------------------------------------------------------
//  Purpose:    Header file for the Stack class. 
//-----------------------------------------------------------
#include <iostream>
using namespace std;

// Stack data node definition
class SNode
{
   public:
   int number;
   SNode *next;
};

class Stack
{
   public:
      // constructor functions
      Stack();
      ~Stack();

      // general stack operations
      void push(int number);
      void pop(int& number);
      void top(int& number);
      bool isFull();
      bool isEmpty();
      void print();

   private:
      SNode *head;
      int length;
};
