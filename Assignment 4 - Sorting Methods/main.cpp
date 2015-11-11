/* Tara Moses
 * Assignment 4: Sorting Methods
 * November 10, 2015
 */
 
#include <iostream>
#include <stdlib.h> 	//rand
#include <fstream> 		//file i/o
#include <string>
using namespace std;

//-------------------------------------------------------
// Global Variables
//-------------------------------------------------------
const int SIZE 		= 10;
const int MAX_VALUE	= 20;

//-------------------------------------------------------
// Helper Functions
//-------------------------------------------------------
void print(int array[]) {
	for (int i = 0; i < SIZE; i++) {
		cout << i << ": " << array[i] << endl;
	}
}
 
void randomize(int array[]) {
	for (int i = 0; i < SIZE; i++) {
		array[i] = rand() % MAX_VALUE + 1;
	}
}

//-------------------------------------------------------
// File I/O Functions
//-------------------------------------------------------
void writeToFile(int array[], string filename) {
	ofstream fout;
	fout.open(filename.c_str());
	
	//check for errors in creating the output file
	if (fout.fail()) {
		cout << "Error: could not open output file" << endl;
		exit(EXIT_FAILURE);
	}
	
	//go through array and print nums to file
	for (int i = 0; i < SIZE; i++) {
		fout << i << ": " << array[i] << endl;
	}	
	
	//close file
	fout.close();
}
 
//-------------------------------------------------------
// Corn Sort
//-------------------------------------------------------
void cornSort(int array[], int low, int high) {
	//variables!
	int moveCount	= 0;
	int left 		= low;
	int right 		= high;
	int leftItem;
	int rightItem;
	int tempItem;
	
	do {
		//let's go left-to-right
		for (int i = left; i < right - 1; i++) { //SIZE - 1 corrects for us looking one ahead (rightItem)
			leftItem = array[i];
			rightItem = array[i+1];
			
			if (leftItem > rightItem) {
				//we need to swap
				tempItem = leftItem;
				leftItem = rightItem;
				rightItem = tempItem;
				
				//increment moveCounter!
				moveCount++;
			}
		}
		
		//we have to test if moveCount==0 after the LR pass. if it is, break
		if (moveCount == 0) break; //UGH I HATE BREAK STATEMENTS BUT I GUESS ITS NECESSARY IN THIS CONTEXT??
	
		//now let's go right-to-left
		moveCount = 0;
		for (int i = right; i > left; i--) { //going from SIZE to 1 corrects for us looking one ahead (leftItem)
			leftItem = array[i - 1];
			rightItem = array[i];
			
			if (leftItem > rightItem) {
				//we need to swap
				tempItem = leftItem;
				leftItem = rightItem;
				rightItem = tempItem;
				
				//increment moveCounter!
				moveCount++;
			}
		}		
	} while (moveCount != 0); //pass again until you pass with no moves!
} 

//-------------------------------------------------------
// Hi-Low Sort
//-------------------------------------------------------
void hilowSort(int array[], int low, int high) {
	cout << "starting hilowSort" << endl;
}

//-------------------------------------------------------
// Main Function
//-------------------------------------------------------
int main() {
	//variables
	int nums[SIZE]; //100 ints between 1 and 10,000
	
	//initialize nums!
	randomize(nums);
	writeToFile(nums, "unsorted.txt");
	
	//let's test corn-sort!
	cornSort(nums, 0, SIZE);
	//writeToFile(nums, SIZE, "cornSorted.txt");
	//i'll make a file for it later, right now i want it on the screen
	print(nums);

	return 0;
}
