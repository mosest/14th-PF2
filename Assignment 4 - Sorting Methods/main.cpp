/* Tara Moses
 * Assignment 4: Sorting Methods
 * November 10, 2015
 */
 
#include <iostream>
#include <stdlib.h> 	//rand
#include <fstream> 		//file i/o
#include <string>
#include <time.h>		//time (for srand)
using namespace std;

//-------------------------------------------------------
// Global Variables
//-------------------------------------------------------
const int SIZE 		= 100;
const int MAX_VALUE	= 10000;

//-------------------------------------------------------
// Helper Functions
//-------------------------------------------------------
void print(int array[]) {
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << " ";
	}
}
 
void randomize(int array[]) {
	srand(time(NULL));
	
	for (int i = 0; i < SIZE; i++) {
		array[i] = rand() % MAX_VALUE + 1;
	}
}

void copyArray(int from[], int to[]) {
	for (int i = 0; i < SIZE; i++) {
		to[i] = from[i];
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
	int tempItem;
	
	do {
		//let's go left-to-right
		for (int i = low; i < high; i++) { //0 to high-1 corrects for us looking one to the right
			
			if (array[i] > array[i + 1]) {
				//we need to swap
				tempItem = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tempItem;
				
				//increment moveCounter!
				moveCount++;
			}
		}
		
		//we have to test if moveCount==0 after the LR pass. if it is, break
		if (moveCount == 0) break; //UGH I HATE BREAK STATEMENTS BUT I GUESS ITS NECESSARY IN THIS CONTEXT??
		
		//now let's go right-to-left
		moveCount = 0;
		for (int i = high; i > low; i--) { //going from high to 1 corrects for us looking one to the left
			
			if (array[i - 1] > array[i]) {
				//we need to swap
				tempItem = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tempItem;
				
				//increment moveCounter!
				moveCount++;
			}
		}		
	} while (moveCount != 0); //pass again until you pass with no moves!
} 

//-------------------------------------------------------
// Hi-Low Sort (let's make this recursive!!)
//-------------------------------------------------------
void hilowSort(int array[], int low, int high) {
	//variables
	int *smallest	= &array[low];
	int *biggest 	= &array[low];
	int tempItem;
	
	if (high - low > 0) {
		//find smallest num
		for (int i = low; i <= high; i++) {
			if (array[i] < *smallest) smallest = &array[i];
		}
		
		//swap smallest num with array[low]
		tempItem = *smallest;
		*smallest = array[low];
		array[low] = tempItem;
		
		//find biggest num
		for (int i = low; i <= high; i++) {
			if (array[i] > *biggest) biggest = &array[i];
		}
		
		//swap biggest num with array[high]
		tempItem = *biggest;
		*biggest = array[high];
		array[high] = tempItem;
		
		//change low and high
		high--;
		low++;
		
		//let's do it again
		hilowSort(array, low, high);
	}
}

//-------------------------------------------------------
// Main Function
//-------------------------------------------------------
int main() {
	//variables
	int cornNums[SIZE]; 	//100 ints between 1 and 10,000
	int hilowNums[SIZE];	//100 ints between 1 and 10,000
	
	//initialize nums! both arrays will have the same random nums
	randomize(cornNums);
	copyArray(cornNums, hilowNums);
	writeToFile(cornNums, "unsorted.txt");
	
	//let's test corn-sort!
	cornSort(cornNums, 0, SIZE - 1);
	writeToFile(cornNums, "cornSorted.txt");
	
	//let's test hilow-sort!
	hilowSort(hilowNums, 0, SIZE - 1);
	writeToFile(hilowNums, "hilowSorted.txt");
	
	return 0;
}
