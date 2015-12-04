//------------------------------------------------------------
// Purpose: Header file for the Heap class.
//------------------------------------------------------------
#include <iostream>
using namespace std;

//------------------------------------------------------------
// The Heap class definition for a heap of integers 
//------------------------------------------------------------
class Heap
{
 public:
   // Constructor functions
   Heap(int);
   ~Heap();

   // General heap operation
   bool insert(int num);
   bool remove(int &num);
   bool isEmpty();
   bool isFull();
   void print();

 private:
   int count;
   int* heap;
   int size;
};