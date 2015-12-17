//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "BinaryTree.h"
#include <stdlib.h>

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   Root = NULL;
}

//-----------------------------------------------------------
// Destructor function helper function.
//-----------------------------------------------------------
void BinaryTree::DestroyHelper(Node * Tree)
{
   // Delete node and it's children
   if (Tree != NULL)
   {
      DestroyHelper(Tree->Left);
      DestroyHelper(Tree->Right);
      delete Tree;
   }
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
   // Call tree destroy function
   DestroyHelper(Root);
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(Quarterback Value, Node * Tree)
{
   // Data value not found 
   if (Tree == NULL)
      return false;

   // Data value found 
   else if (Tree->Value.compareByGame(Value) == 0)
      return true;

   // Recursively search for data value
   else if (Tree->Value.compareByGame(Value) == 1)
      return (SearchHelper(Value, Tree->Left));
   else if (Tree->Value.compareByGame(Value) == -1)
      return (SearchHelper(Value, Tree->Right));
   else
      return false;
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(Quarterback Value)
{
   // Call tree searching function
   return (SearchHelper(Value, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(Quarterback Value, Node * &Tree)
{
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new Node();
      Tree->Value = Value;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Recursively search for insertion position
   else if (Tree->Value.compareByGame(Value) == 1)
      return (InsertHelper(Value, Tree->Left));
   else 
      return (InsertHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(Quarterback Value)
{
   // Call tree insertion function
   return (InsertHelper(Value, Root));
}

//-----------------------------------------------------------
// Delete a single node from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::DeleteNode(Node * &Tree)
{
   Node *Temp = Tree;

   // Node has 0 children
   if ((Tree->Left == NULL) && (Tree->Right == NULL))
      Tree = NULL;

   // Node has 1 child
   else if (Tree->Left == NULL)
      Tree = Tree->Right;
   else if (Tree->Right == NULL)
      Tree = Tree->Left;


   // Node has 2 children
   else
   {
      // Find leftmost node in right subtree
      Node *Parent = Tree;
      Temp = Tree->Right;
      while (Temp->Left != NULL)
      {
	 Parent = Temp;
	 Temp = Parent->Left;
      }

      // Replace deleted data with leftmost value
      if (Parent == Tree)
	 Parent->Right = Temp->Right;
      else
	 Parent->Left = Temp->Right;
      Tree->Value = Temp->Value;
   }

   // Delete node
   delete Temp;
   return true;
}

//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
bool BinaryTree::DeleteHelper(Quarterback Value, Node * &Tree)
{
   // Data value not found
   if (Tree == NULL)
      return false;

   // Data value found and deleted
   else if (Tree->Value.compareByGame(Value) == 0)
      return (DeleteNode(Tree));

   // Recursively search for node to delete
   else if (Tree->Value.compareByGame(Value) == 1)
      return (DeleteHelper(Value, Tree->Left));
   else if (Tree->Value.compareByGame(Value) == -1)
      return (DeleteHelper(Value, Tree->Right));
   else
      return false;
}

//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Delete(Quarterback Value)
{
   // Call tree deletion function
   return (DeleteHelper(Value, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      cout << "(";
      PrintHelper(Tree->Left);

      // Print node value
      Tree->Value.print();

      // Print right subtree
      PrintHelper(Tree->Right);
      cout << ")";
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
   // Call tree printing function
   PrintHelper(Root);
   cout << endl;
}

//-----------------------------------------------------------
// QueryField helper function.
//-----------------------------------------------------------
void BinaryTree::QueryFieldHelper(Node * Tree, float a, float b, float c, float d)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      QueryFieldHelper(Tree->Left,a,b,c,d);

      // Print node value
      if (Tree->Value.getGame() >= a && Tree->Value.getGame() <= b) {
          if (Tree->Value.getRating() >= c && Tree->Value.getRating() <= d) {
              Tree->Value.print();
          }
      }

      // Print right subtree
      QueryFieldHelper(Tree->Right,a,b,c,d);
   }
}

//-----------------------------------------------------------
// Prints all records between a certain range of [low,high]
//-----------------------------------------------------------
void BinaryTree::QueryField(float low1, float high1, float low2, float high2) {
    if (low1 > high1 || low2 > high2) {
        cout << "No values in this range." << endl;
        return;
    }
    
    //now we know that [low1,high1] and [low2,high2]
    //are valid ranges! :9
    QueryFieldHelper(Root,low1,high1,low2,high2);
}

#ifdef TREE_MAIN
//-----------------------------------------------------------
// Main program tests the BinaryTree class.
//-----------------------------------------------------------
int main()
{
   // Create tree
   BinaryTree Tree;

   // Test binary tree insertion
   const int MAX = 10;
   for (int Count = 0; Count < MAX; Count++)
   {
      int Value = rand() % MAX;
      if (Tree.Insert(Value))
	 cout << "Insert " << Value << " ok\n";
      else
	 cout << "Insert " << Value << " failed\n";
      Tree.Print();
   }

   // Test binary tree search
   for (int Count = 0; Count < MAX; Count++)
   {
      int Value = rand() % MAX;
      if (Tree.Search(Value))
	 cout << "Search " << Value << " found\n";
      else
	 cout << "Search " << Value << " not found\n";
   }

   // Test binary tree deletion
   for (int Count = 0; Count < MAX; Count++)
   {
      int Value = rand() % MAX;
      if (Tree.Delete(Value))
	 cout << "Delete " << Value << " ok\n";
      else
	 cout << "Delete " << Value << " failed\n";
      Tree.Print();
   }
   return 0;
}
#endif
