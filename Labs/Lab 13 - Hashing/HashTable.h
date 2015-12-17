//-----------------------------------------------------------
//  Purpose:    Header file for the HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include <iostream>
using namespace std;
const int NONE    = 0;
const int EMPTY   = -1;
const int DELETED = -2;

//-----------------------------------------------------------
// Define the HashTable class interface
//-----------------------------------------------------------
class HashTable
{
public:
   // Constructors
   HashTable(int size);
   HashTable(const HashTable & ht);
   ~HashTable();

   // Methods
   bool insert(int Key, int Value);
   bool search(int Key, int &Value);
   bool deleteValue(int Key);
   void print();

private:
   // Private methods
   int hash(int key);
   int hash2(int index);

   // Private data
   int size;
   int *value;
   int *key;
};