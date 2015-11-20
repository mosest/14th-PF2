/* 
 * File:   main.cpp
 * Author: tara-chan
 *
 * Created on November 17, 2015, 1:50 PM
 */

#include <cstdlib>
#include <iostream>
#include "BinaryTree.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    BinaryTree tree;
    BinaryTree tree2;
    BinaryTree tree3;
    
    for (int i = 0; i < 1025; i++) {
        int numToAdd = rand() % 1025;
        tree.insert(numToAdd);
        tree2.insert(i);
        tree3.insert(1024-i);
        
        /*
         cout << "Trying to add " << numToAdd << ": ";
        
        if (tree.insert(numToAdd)) cout << "Insert succeeded!" << endl;    
        else cout << "Insert failed." << endl;
       */
    }
    
    cout << "Tree 1: " << tree.height() << endl;
    
    cout << "Tree 2: " << tree2.height() << endl;
}

