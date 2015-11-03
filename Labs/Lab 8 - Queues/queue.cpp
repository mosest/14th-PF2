//-----------------------------------------------------------
//  Purpose:    Implementation of Queue class.
//-----------------------------------------------------------
#include "queue.h"

//-----------------------------------------------------------
Queue::Queue()
{
   end = -1;
   start = 0;
   length = 0;
}

//-----------------------------------------------------------
Queue::~Queue()
{
}

//-----------------------------------------------------------
bool Queue::IsFull()
{
   return (length == QUEUE_SIZE);
}

//-----------------------------------------------------------
bool Queue::IsEmpty()
{
   return (length == 0);
}

//-----------------------------------------------------------
void Queue::EnQueue(int item)
{
   // check if full
   if (IsFull())
      cout << "queue overflow\n";

   else
        end++;                    // Move the 'end' iterator
        if(end >= QUEUE_SIZE)     // Check to see if we need to wrap around
                end = 0;          // Perform the wrap around
        Data[end] = item;         // Insert the item into the queue
        length++;                 // We now have more elements in the queue
}

//-----------------------------------------------------------
int Queue::DeQueue()
{
   // check if empty
    if (IsEmpty())
    {
        cout << "queue underflow\n";
        return -1; 
    }

   else
   {
        int item = Data[start++]; // Remove the item from the queue
        if(start >= QUEUE_SIZE)   // Check to see if we need to wrap around
            start = 0;            // Perform the wrap around
        length--;                 // We have fewer elements in the queue now
        return item;              // Return what was at the front of the queue
   }
}

int Queue::Front()
{
    if(IsEmpty()) return -1;
    else return Data[0];
}

int Queue::GetQueueLength()
{
   return (end+1);
}

//-----------------------------------------------------------
void Queue::Print()
{
   cout << end + 1 << " : ";
   for (int i = 0; i <= end; i++)
      cout << setw(2) << Data[i] << " ";
   cout << endl;
}

