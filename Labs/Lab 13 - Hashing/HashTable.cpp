//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "HashTable.h"

//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int newSize)
{
   size  = newSize;
   value = new int[size];
   key   = new int[size];

   for (int index = 0; index < size; index++)
   {
      value[index] = NONE;
      key[index]   = EMPTY;
   }
}

//-----------------------------------------------------------
// Copy constructor
//-----------------------------------------------------------
HashTable::HashTable(const HashTable & ht)
{
   size  = ht.size;
   value = new int[size];
   key   = new int[size];

   for (int index = 0; index < size; index++)
   {
      value[index] = ht.value[index];
      key[index]   = ht.key[index];
   }
}

//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
HashTable::~HashTable()
{
   delete[] value;
   delete[] key;
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
bool HashTable::insert(int Key, int Value)
{
   // Find desired key
   int index = hash(Key);
   for (int i = 0; i < size && (key[index] != Key) && (key[index] != EMPTY); i++)
      index = hash2(index); 

   // Insert value into hash table
   value[index] = Value;
   key[index]   = Key;
   return true;
}

//-----------------------------------------------------------
// Search method
//-----------------------------------------------------------
bool HashTable::search(int Key, int &Value)
{
   // Find desired key
   int index = hash(Key);
   while ((key[index] != Key) && (key[index] != EMPTY))
      index = hash2(index); 

   // Return value from hash table
   if (key[index] == Key)
      Value = value[index];
   return (key[index] == Key);
}

//-----------------------------------------------------------
// Delete method
//-----------------------------------------------------------
bool HashTable::deleteValue(int Key)
{
   // Find desired key
   int index = hash(Key);
   while ((key[index] != Key) && (key[index] != EMPTY))
      index = hash2(index); 

   // Delete value from hash table
   if (key[index] == Key)
   {
      value[index] = NONE;
      key[index]   = DELETED;
      return true;
   }
   return false;
}

//-----------------------------------------------------------
// Primary hash function
//-----------------------------------------------------------
int HashTable::hash(int key)
{
   return key % size;
}

//-----------------------------------------------------------
// Secondary hash function
//-----------------------------------------------------------
int HashTable::hash2(int index)
{
    cout << "Collision!" << endl;
   return (index+1) % size;
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::print()
{
   cout << "Index\t" << "Value\t" << "Key\n";
   for (int index=0; index < size; index++)
      cout << index << "\t"
           << value[index] << "\t" 
           << key[index] << "\n";
}