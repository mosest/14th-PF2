//------------------------------------------------------------
// Purpose: Implementation of integer Heap class.
//------------------------------------------------------------
#include "Heap.h"

//------------------------------------------------------------
// Constructor function.
//------------------------------------------------------------
Heap::Heap(int maxSize)
{
   heap = new int [maxSize];
   size = maxSize + 1;
   count = 0;
   
   for (int index = 0; index < maxSize; index++)
      heap[index] = -1;
}

//------------------------------------------------------------
// Destructor function.
//------------------------------------------------------------
Heap::~Heap()
{
    delete[] heap;
    heap = NULL;
}

//------------------------------------------------------------
// Insert an element into the heap.
//------------------------------------------------------------
bool Heap::insert(int num)
{
   // Check for full heap
   if (isFull())
      return false;

   // Shuffle data up the heap
   count++;
   int child = count;
   int parent = child / 2;
   while ((child > 1) && (heap[parent] < num))
   {
      heap[child] = heap[parent];
      child       = parent;
      parent      = child / 2;
   }

   // Insert new entry in heap
   heap[child] = num;
   return true;
}

//------------------------------------------------------------
// Remove an element from the heap.
//------------------------------------------------------------
bool Heap::remove(int &num)
{
   // Check for empty heap
   if (isEmpty())
      return false;

   // Save top of heap
   num = heap[1];

   // Swap last value into root position
   heap[1]     = heap[count];
   heap[count] = -1;
   count--;

   // Shuffle data down the heap
   int parent  = 1;
   int largest = 0;
   while (parent != largest)
   {
      // Check left node
      largest  = parent;
      int left = parent * 2;
      if ((left <= count) && (heap[left] > heap[largest]))
	 largest = left;

      // Check right node
      int right = left + 1;
      if ((right <= count) && (heap[right] > heap[largest]))
	 largest = right;

      // Swap data values if needed
      if (parent != largest)
      {
	 int temp      = heap[parent];
	 heap[parent]  = heap[largest];
	 heap[largest] = temp;
	 parent        = largest;
	 largest       = 0;
      }
   }
   return true;
}

//------------------------------------------------------------
// Print the contents of the heap.
//------------------------------------------------------------
void Heap::print()
{
   for (int index = 1; index <= count; index++)
      cout << heap[index] << " ";
   cout << endl;
}

//------------------------------------------------------------
// Check if the heap is empty
//------------------------------------------------------------
bool Heap::isEmpty()
{
   return count == 0;
}

//------------------------------------------------------------
// Check if the heap is full
//------------------------------------------------------------
bool Heap::isFull()
{
   return (count == size);
}