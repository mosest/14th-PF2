/* 
 * File:   main.cpp
 * Author: tara-chan
 *
 * Created on December 9, 2015, 11:10 AM
 */

#include <cstdlib>
#include <stdlib.h> //rand
#include "HashTable.h"
using namespace std;

int main() {
    //variables
    int size = 40;
    int count = 50;
    int max = 100;
    int key = 0;
    int value = 0;
    
    //get user input
    /*cout << "Size = ";
    cin >> size;
    
    cout << "Count = ";
    cin >> count;
    
    cout << "Max = ";
    cin >> max;*/
    
    //create hash and insert
    HashTable* newTable = new HashTable(size);
    
    //insert!
    for (int i = 0; i < count; i++) {
        //generate random key/value pairs
        key = rand() % max;
        value = rand() % max;
        
        //insert them
        newTable->insert(key,value);
    }
    
    newTable->print();
    
    return 0;
}

