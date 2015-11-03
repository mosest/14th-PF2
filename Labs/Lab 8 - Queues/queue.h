/* 
 * File:   queue.h
 * Author: tingxiny
 *
 * Created on March 13, 2015, 12:50 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

//-----------------------------------------------------------
//  Purpose:    Header file for the Queue class.
//-----------------------------------------------------------
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

const int QUEUE_SIZE = 20;

//-----------------------------------------------------------
// Define the queue class interface. 
//-----------------------------------------------------------
class Queue
{
 public:
   // constructor functions
   Queue();
   ~Queue();

   // general queue operations
   bool IsFull();
   bool IsEmpty();
   void EnQueue(int);
   int DeQueue();
   int Front();
   int GetQueueLength();
   void Print();

 private:
   int Data[QUEUE_SIZE];
   int end;
   int start;
   int length;
};


#endif	/* QUEUE_H */

