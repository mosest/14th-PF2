/* Tara Moses
 * Assignment 2a: Recursion
 * September 15, 2015
 */
 
#include <iostream>
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
	if () return 0;
	else return reverse();
}

int main() {
	float b = 9;
	int e = 3;
	
	//test power()
	cout << b << "^" << e << " = " << power(b,e) << endl;
	
	return 0;
}
