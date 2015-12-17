//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
#include "Quarterback.h"
using namespace std;

//-----------------------------------------------------------
// BinaryTree data node definition
//-----------------------------------------------------------
class Node
{
    public:
      Quarterback Value;
      Node *Left;
      Node *Right;
};

//-----------------------------------------------------------
// Define the BinaryTree class interface 
//-----------------------------------------------------------
class BinaryTree
{
 public:
   // Constructor functions
   BinaryTree();
  ~BinaryTree();

   // General binary tree operations
   bool Search(Quarterback Value);
   bool Insert(Quarterback Value);
   bool Delete(Quarterback Value);
   void Print();
   void QueryField(float,float,float,float);

   // Special operation for tree_sort
   void Extract(int data[], int low, int high);
   void ExtractHelper(int data[], int &index, Node * Tree);

 private:
   // Helper functions
   void DestroyHelper(Node * Tree);
   bool SearchHelper(Quarterback Value, Node * Tree);
   bool InsertHelper(Quarterback Value, Node * &Tree);
   bool DeleteNode(Node * &Tree);
   bool DeleteHelper(Quarterback Value, Node * &Tree);
   void PrintHelper(Node * Tree);
   void QueryFieldHelper(Node*,float,float,float,float);

   // Tree pointer
   Node *Root;
};
