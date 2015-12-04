//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;

// Data node definition
class Node
{
   public:
   int value;
   Node *left;
   Node *right;
};

//-----------------------------------------------------------
// Define the binary tree class interface. 
//-----------------------------------------------------------
class BinaryTree
{
 public:
   // Constructor functions
   BinaryTree();
  ~BinaryTree();

   // General binary tree operations
   bool search(int value);
   bool insert(int value);
   bool deleteValue(int value);
   void print();
   int count();
   int height();

 private:
   // Helper functions
   bool searchHelper(int value, Node * tree);
   bool insertHelper(int value, Node * &tree);
   bool deleteNode(Node * tree);
   bool deleteHelper(int value, Node * tree);
   void printHelper(Node * tree);
   void countHelper(int &, Node * tree);
   int heightHelper(Node * tree);

   // Tree pointer
   Node *root;
};