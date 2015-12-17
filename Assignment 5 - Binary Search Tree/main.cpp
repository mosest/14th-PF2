//Tara Moses
//Assignment 5: Quarterback BST
//December 6, 2015

#include <cstdlib> //atoi and atof
#include <fstream> //file i/o
#include "BinaryTree.h"
using namespace std;

//----------------------------
// Function that reads QB.txt
// into Quarterback objects
//----------------------------
void readQBInfo(BinaryTree* tree) {
    //variables
    fstream fin;
    
    string firstName;   
    string lastName;
    string strGame;     //takes in game as a string
    string strRating;   //takes in rating as a string   
    string no;          //this string is a placeholder for all the extra stuff
    
    //these variables are what actually make the QB object
    string playerName;  //firstname + lastname
    string team;
    int game;
    float rating;
    
    //open file
    fin.open("QB.txt");
    
    //ignore the header line
    getline(fin,no);
    
    //read stuff
    while (!fin.eof()) { //while there's still rows in the file
        //take in stuff
        fin >> firstName;
        fin >> lastName;
        playerName = firstName + " " + lastName;
        
        fin >> no; //just throw this value away
        fin >> team;
        
        fin >> strGame;
        game = atoi(strGame.c_str());
        
        fin >> no >> no >> no >> no >> no >> no;    //WHY IS THIS EVEN HERE
        fin >> no >> no >> no >> no >> no;          //PF2 TEACHERS W H Y
        fin >> strRating;
        rating = atof(strRating.c_str());
        
        //now add this guy to the tree!
        Quarterback* currentQB = new Quarterback(playerName,team,game,rating);
        tree->Insert(*currentQB);
    }
    
    //close file
    fin.close();
}

//----------------------------
// Main Function
//----------------------------
int main() {
    //variables
    BinaryTree* bst = new BinaryTree();
    float gameLow;
    float gameHigh;
    float ratingLow;
    float ratingHigh;
    
    //Part 1: read qb file and generate binary tree
    readQBInfo(bst);
    
    //Part 2: what? what??
    
    //Part 3: Prompt user for range of game and rating
    cout << "Program will print QBs with Game in range [a,b] and Rating in range [c,d]." << endl;
    
    cout << endl << "a: ";
    cin >> gameLow;
    
    cout << "b: ";
    cin >> gameHigh;
    
    cout << "c: ";
    cin >> ratingLow;
    
    cout << "d: ";
    cin >> ratingHigh;
    
    cout << endl << "Thank you. Printing..." << endl;
    
    //Part 4: Print whatever user asked for
    bst->QueryField(gameLow,gameHigh,ratingLow,ratingHigh);
    
    return 0;
}

