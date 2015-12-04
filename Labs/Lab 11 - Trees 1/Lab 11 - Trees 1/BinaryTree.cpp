//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "BinaryTree.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   root = NULL;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::searchHelper(int value, Node * tree)
{
   // Data value not found 
   if (tree == NULL)
      return false;

   // Data value found 
   else if (tree->value == value)
      return true;

   // Recursively search for data value
   else if (tree->value > value)
      return (searchHelper(value, tree->left));
   else if (tree->value < value)
      return (searchHelper(value, tree->right));
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::search(int value)
{
   // Call tree searching function
   return (searchHelper(value, root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::insertHelper(int value, Node * &tree)
{
   // Insert data into the tree
   if (tree == NULL)
   {
      tree = new Node;
      tree->value = value;
      tree->left  = NULL;
      tree->right = NULL;
      return true;
   }

   // Data value already inserted
   else if (tree->value == value)
      return false;     

   // Recursively search for insertion position
   else if (tree->value > value)
      return (insertHelper(value, tree->left));
   else if (tree->value < value)
      return (insertHelper(value, tree->right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::insert(int value)
{
   // Call tree insertion function
   return (insertHelper(value, root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::printHelper(Node * tree)
{
   // Check terminating condition
   if (tree != NULL)
   {
       cout << "(";
      // Print left subtree
      printHelper(tree->left);

      // Print node value
      cout << " " << tree->value << " ";

      // Print right subtree
      printHelper(tree->right);
      cout << ")";
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::print()
{
   // Call tree printing function
   printHelper(root);
   cout << endl;
}

//-----------------------------------------------------------
// Count helper function.
//-----------------------------------------------------------
void BinaryTree::countHelper(int & sumSoFar, Node * tree)
{
   // Check terminating condition
   if (tree != NULL)
   {
      countHelper(sumSoFar, tree->left);

      // Print node value
      sumSoFar++;

      // Print right subtree
      countHelper(sumSoFar, tree->right);
   }
}

//-----------------------------------------------------------
// Count number of things in binary tree
//-----------------------------------------------------------
int BinaryTree::count()
{
    int sum = 0;
    
   countHelper(sum, root);
   
   return sum;
}

//-----------------------------------------------------------
// Height helper function.
//-----------------------------------------------------------
int BinaryTree::heightHelper(Node * tree)
{
   // Check terminating condition
   if (tree == NULL) return 0;
   else
   {
      int leftSide = heightHelper(tree->left);

      //right subtree
      int rightSide = heightHelper(tree->right);
      
      //if there's more on the leftSide than on the rightSide
      if (leftSide > rightSide) return leftSide + 1;
      else return rightSide + 1;
   }
}

//-----------------------------------------------------------
// Finds height of the binary tree.
//-----------------------------------------------------------
int BinaryTree::height()
{
    int num = 0;
    
   // Call tree printing function
   num = heightHelper(root);
   
   return num;
}