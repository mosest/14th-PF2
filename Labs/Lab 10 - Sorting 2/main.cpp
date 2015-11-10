/* Tara Moses
 * Lab 10: Sorting, part 2
 * November 10, 2015
 */
 
#include <iostream>
#include <stdlib.h>
using namespace std;

//----------------------------------------------------------------
// Global variables
//----------------------------------------------------------------
int compareCounter;
int moveCounter;

//------------------------------------------------------------------
// Initialize data array with random values between 0 and range-1
//------------------------------------------------------------------
void randomData(int data[], int count, int range)
{
   // Put specified count of random numbers into data array
   for (int index = 0; index < count; index++)
      data[index] = rand() % range;
}

//------------------------------------------------------------------
// Shuffle data values inside data array 
//------------------------------------------------------------------
void shuffleData(int data[], int count, int shuffles)
{
   // Shuffle data by swapping random pairs of values
   for (int index = 0; index < shuffles; index++)
   {
      int pos1   = rand() % count;
      int pos2   = rand() % count;
      int temp   = data[pos1];
      data[pos1] = data[pos2];
      data[pos2] = temp;
   }
}

//----------------------------------------------------------------
// Insertion sort algorithm
//----------------------------------------------------------------
void insertionSort(int data[], int low, int high)
{
	compareCounter = 0;
	moveCounter = 0;
	
   // Insert each element of unsorted list into sorted list
   for (int unsorted = low+1; unsorted <= high; unsorted++)
   {
      // Select unsorted value to be inserted
      int value = data[unsorted];
      int posn  = unsorted;

      // Make room for new data value
      while ((posn > 0) && (data[posn - 1] > value))
      {
	 data[posn] = data[posn - 1];
	 posn--;
	 compareCounter++;
      }

      // Put new value into array
      data[posn] = value;
      moveCounter++;
  }
}

//----------------------------------------------------------------
// Partition function used by Quicksort.
//----------------------------------------------------------------
void partition(int data[], int low, int high, int &mid)
{
   // Select pivot value
   int pivot = data[high];
   int left  = low;
   int right = high;

   // Partition array into two parts
   while (left < right)
   {
      // Scan left to right
      while ((left < right) && (data[left] < pivot)) {
         left++;
         compareCounter++;
	 }

      // Scan right to left
      while ((left < right) && (data[right] >= pivot)) {
         right--;
         compareCounter++;
	 }

      // Swap data values
      int temp    = data[left];
      data[left]  = data[right];
      data[right] = temp;
      moveCounter++;
   }

   // Swap pivot to mid
   mid        = left;
   data[high] = data[mid];
   data[mid]  = pivot;
   moveCounter++;
}

//----------------------------------------------------------------
// Recursive Quicksort algorithm using basic partition function.
//----------------------------------------------------------------
void quickSort(int data[], int low, int high)
{
	// Check terminating condition
   if (low < high)
   {
      // Partition data into two parts
      int mid = 0;
      partition(data, low, high, mid);

      // Recursive calls to sort array
      quickSort(data, low, mid - 1);
      quickSort(data, mid + 1, high);
   }
}

//----------------------------------------------------------------
// Mergesort using secondary storage for data merging.
//----------------------------------------------------------------
void mergeSort(int data[], int low, int high)
{
	// Check terminating condition
   int range = high - low + 1;
   if (range > 1)
   {
      // Divide the array and sort both halves
      int mid = (low + high) / 2;
      mergeSort(data, low, mid);
      mergeSort(data, mid + 1, high);

      // Create temporary array for merged data
      int *copy = new int[range];

      // Initialize array indices
      int index1 = low;
      int index2 = mid + 1;
      int index = 0;

      // Merge smallest data elements into copy array
      while (index1 <= mid && index2 <= high)
      {
		if (data[index1] < data[index2]) copy[index++] = data[index1++];
		else copy[index++] = data[index2++];
		compareCounter++;
	    moveCounter++;
      }

      // Copy any remaining entries from the first half
      while (index1 <= mid) {
	 copy[index++] = data[index1++];
	  }

      // Copy any remaining entries from the second half
      while (index2 <= high) {
	 copy[index++] = data[index2++];
	  }

      // Copy data back from the temporary array
      for (index = 0; index < range; index++)
	 data[low + index] = copy[index];
      delete []copy;
   }
}

//----------------------------------------------------------------
// Main function
//----------------------------------------------------------------
int main() {
	//variables
	int smallArray[10];
	int medArray[100];
	int largeArray[1000];	
	
	//MERGESORT LET'S GO
	cout << "~~~~~~~ IT'S TIME FOR MERGESORT ~~~~~~~" << endl;
	
	//small array
	cout << "--- N = 10 ---" << endl;
	
	compareCounter = 0;
	moveCounter = 0;
	randomData(smallArray, 10, 100);	
	mergeSort(smallArray, 0, 10); //smallArray unsorted at this point
	cout << "Unsorted: compareCounter = " << compareCounter << endl;
	cout << "Unsorted: moveCounter = " << moveCounter << endl;
	
	compareCounter = 0;
	moveCounter = 0;
	shuffleData(smallArray, 10, 5);
	mergeSort(smallArray, 0, 10); //smallArray semisorted at this point
	cout << "Semi-sorted: compareCounter = " << compareCounter << endl;
	cout << "Semi-sorted: moveCounter = " << moveCounter << endl;
	
	compareCounter = 0;
	moveCounter = 0;
	mergeSort(smallArray, 0, 10); //smallArray is already sorted at this point
	cout << "Sorted: compareCounter = " << compareCounter << endl;
	cout << "Sorted: moveCounter = " << moveCounter << endl << endl;
	
	//medium array
	cout << "--- N = 100 ---" << endl;
	
	compareCounter = 0;
	moveCounter = 0;
	randomData(medArray, 100, 100);	
	mergeSort(medArray, 0, 100); //medArray unsorted at this point
	cout << "Unsorted: compareCounter = " << compareCounter << endl;
	cout << "Unsorted: moveCounter = " << moveCounter << endl;
	
	compareCounter = 0;
	moveCounter = 0;	
	shuffleData(medArray, 100, 50);
	mergeSort(medArray, 0, 100); //medArray semisorted at this point
	cout << "Semi-sorted: compareCounter = " << compareCounter << endl;
	cout << "Semi-sorted: moveCounter = " << moveCounter << endl;
	
	compareCounter = 0;
	moveCounter = 0;	
	mergeSort(medArray, 0, 100); //medArray is already sorted at this point
	cout << "Sorted: compareCounter = " << compareCounter << endl;
	cout << "Sorted: moveCounter = " << moveCounter << endl << endl;
	
	//large array
	cout << "--- N = 1000 ---" << endl;
	
	compareCounter = 0;
	moveCounter = 0;
	randomData(largeArray, 1000, 100);	
	mergeSort(largeArray, 0, 1000); //largeArray unsorted at this point
	cout << "Unsorted: compareCounter = " << compareCounter << endl;
	cout << "Unsorted: moveCounter = " << moveCounter << endl;
	
	compareCounter = 0;
	moveCounter = 0;
	shuffleData(largeArray, 1000, 500);
	mergeSort(largeArray, 0, 1000); //largeArray semisorted at this point
	cout << "Semi-sorted: compareCounter = " << compareCounter << endl;
	cout << "Semi-sorted: moveCounter = " << moveCounter << endl;	
	
	compareCounter = 0;
	moveCounter = 0;
	mergeSort(largeArray, 0, 1000); //largeArray is already sorted at this point
	cout << "Sorted: compareCounter = " << compareCounter << endl;
	cout << "Sorted: moveCounter = " << moveCounter << endl << endl;
	
	//QUICKSORT TIME EYYY
	cout << "~~~~~~~ GUESS WHAT NOW IT'S QUICKSORT TIME ~~~~~~~" << endl;
	
	//small array
	cout << "--- N = 10 ---" << endl;
	
	compareCounter = 0;
	moveCounter = 0;
	randomData(smallArray, 10, 100);	
	quickSort(smallArray, 0, 10); //smallArray unsorted at this point
	cout << "Unsorted: compareCounter = " << compareCounter << endl;
	cout << "Unsorted: moveCounter = " << moveCounter << endl;
	
	compareCounter = 0;
	moveCounter = 0;	
	shuffleData(smallArray, 10, 5);
	quickSort(smallArray, 0, 10); //smallArray semisorted at this point
	cout << "Semi-sorted: compareCounter = " << compareCounter << endl;
	cout << "Semi-sorted: moveCounter = " << moveCounter << endl;
	
	compareCounter = 0;
	moveCounter = 0;	
	quickSort(smallArray, 0, 10); //smallArray is already sorted at this point
	cout << "Sorted: compareCounter = " << compareCounter << endl;
	cout << "Sorted: moveCounter = " << moveCounter << endl << endl;
	
	//medium array
	cout << "--- N = 100 ---" << endl;
	
	compareCounter = 0;
	moveCounter = 0;
	randomData(medArray, 100, 100);	
	quickSort(medArray, 0, 100); //medArray unsorted at this point
	cout << "Unsorted: compareCounter = " << compareCounter << endl;
	cout << "Unsorted: moveCounter = " << moveCounter << endl;
	
	compareCounter = 0;
	moveCounter = 0;	
	shuffleData(medArray, 100, 50);
	quickSort(medArray, 0, 100); //medArray semisorted at this point
	cout << "Semi-sorted: compareCounter = " << compareCounter << endl;
	cout << "Semi-sorted: moveCounter = " << moveCounter << endl;
	
	compareCounter = 0;
	moveCounter = 0;	
	quickSort(medArray, 0, 100); //medArray is already sorted at this point
	cout << "Sorted: compareCounter = " << compareCounter << endl;
	cout << "Sorted: moveCounter = " << moveCounter << endl << endl;
	
	//large array
	cout << "--- N = 1000 ---" << endl;
	
	compareCounter = 0;
	moveCounter = 0;	
	randomData(largeArray, 1000, 100);	
	quickSort(largeArray, 0, 1000); //largeArray unsorted at this point
	cout << "Unsorted: compareCounter = " << compareCounter << endl;
	cout << "Unsorted: moveCounter = " << moveCounter << endl;
	
	compareCounter = 0;
	moveCounter = 0;	
	shuffleData(largeArray, 1000, 500);
	quickSort(largeArray, 0, 1000); //largeArray semisorted at this point
	cout << "Semi-sorted: compareCounter = " << compareCounter << endl;
	cout << "Semi-sorted: moveCounter = " << moveCounter << endl;
	
	compareCounter = 0;
	moveCounter = 0;	
	quickSort(largeArray, 0, 1000); //largeArray is already sorted at this point
	cout << "Sorted: compareCounter = " << compareCounter << endl;
	cout << "Sorted: moveCounter = " << moveCounter << endl << endl;
	
	return 0;
}
