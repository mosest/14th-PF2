/* 
 * Tara Moses
 * Lab 4: Recursion part 1
 * September 22, 2015
 */
 
#include <iostream>
using namespace std;

int factorial(int num) {
	int ret = 1;
	
	cout << "Entering factorial, num = " << num << endl;	
	if (num != 1) ret = num * factorial(num-1);	
	cout << "Leaving factorial, Return = " << ret << endl;
	
	return ret;	
}

int fibonacci(int num) {
	int ret = 1;
	
	cout << "Entering Fibonacci, num = " << num << endl;
	if (num >= 3) ret = fibonacci(num-1) + fibonacci(num-2);
	cout << "Leaving Fibonacci, Return = " << ret << endl; 
	
	return ret;
}

int main() {
	int n;
	
	/* Testing factorial(n)
	cout << "Give me an integer: ";
	cin >> n;
	cout << n << "! = " << factorial(n);
	*/
	
	/*Testing fibonacci(n)*/
	cout << "Give me an integer: ";
	cin >> n;
	cout << "The " << n << "th digit of the Fibonacci sequence is " << fibonacci(n);
	
	return 0;
}
