/* Tara Moses
 * Assignment 2a: Recursion
 * September 15, 2015
 */
 
#include <iostream>
#include <cmath>
using namespace std;

/*
 * Computes base^exp recursively
 */
float power(float base, int exp) {
	if (exp == 0) return 1; //base case
	else return base*power(base, exp-1); //recursive case
}

/*
 * recursively reverses int
 * ex: reverse(3241) returns 1423
 */
int reverse(int num) {
	int numDigits = 1;
	
	if (num / 10 == 0) return num; //base case: only one digit
	else {
		//find first digit in num, find number of digits in num
		while (num / int(pow(10, numDigits)) != 0) {
			numDigits++;
		}
		int firstDigit = num / pow(10, numDigits-1);
		return firstDigit + 10 * reverse(num % int(pow(10, numDigits-1)));
	}
}

/*
 * recursively searches through array nums[], and
 * returns index of the first appearance of int n
 */
int binarySearch(int nums[], int low, int high, int n) {
	if (low > high) return -1; //base case: size of nums[] = 0
	else {
		int mid = (low + high) / 2; //currently checking nums[mid] ?=? 
		
		if (nums[mid] == n && (mid == 0 || nums[mid - 1] < n)) return mid;
		else if (nums[mid] >= n) return binarySearch(nums, low, mid-1, n);
		else return binarySearch(nums, mid+1, high, n);
	}
}

int main() {
	float b = 10;
	int e = 3;
	int n = 1497;
	int nums[] = {19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19};
	int size = 18;
	int numToFind = 19;
	
	//test power()
	cout << b << "^" << e << " = " << power(b,e) << endl;
	
	//test reverse()
	cout << n << " backwards is " << reverse(n) << endl;
	
	//test binarySearch()
	cout << "nums[" << binarySearch(nums,0,size-1,numToFind) << "] = " << numToFind << endl;
	
	return 0;
}
