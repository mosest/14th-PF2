/* 
 * File:   main.cpp
 * Author: tingxiny
 *
 * Created on March 13, 2015, 2:10 PM
 */

#include <cstdlib>
#include "queue.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

   Queue q;
   q.Print();
   
   q.EnQueue(3);
   q.EnQueue(1);
   q.EnQueue(4);
   q.Print();
   
   q.DeQueue();
   q.DeQueue();
   q.Print();
   
   q.EnQueue(7);
   q.EnQueue(5);
   q.EnQueue(9);
   q.EnQueue(10);
   q.Print();
   
   q.DeQueue();
   q.DeQueue();
   q.Print();
  
   q.DeQueue();
   q.DeQueue();
   q.DeQueue();
   q.Print();
   
   int range = 2015;
   for(int i = 0; i < QUEUE_SIZE; i++)
   {
        int value = rand() % range;
        q.EnQueue(value);
   }
      for(int i = 0; i < QUEUE_SIZE; i++)
   {
        q.DeQueue();
   }
   

    return 0;
}

