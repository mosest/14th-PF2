/*
 * Tara Moses
 * Assignment 2b: BookList Driver
 * September 17, 2015
 */

#include <iostream>
#include <fstream>
#include <fstream> //necessary to read txt files
#include <cstdlib> //necessary for atoi and atof??
#include "BookList.cpp"
using namespace std;

int main() {
	//------------------------------
	//Variables
	//------------------------------
	string title;
	string author;
	string publisher;
	string intStr; //reusable string to use with atoi. eg "34"
	string floatStr; //reusable string to use with atoif. eg "3.14"
	int year;
	float price;
	int numBooks = 0;
	
	ifstream fin;
	BookList shelf;
	
	//------------------------------
	//Open, Read, Close File
	//------------------------------
	fin.open("books.txt");
	getline(fin,intStr); //get the number of books in the file
	numBooks = atoi(intStr.c_str());
	BookNode bookArray[numBooks];
	
	for (int i = 0; i < numBooks && !fin.eof(); i++) {
		getline(fin,title);
		getline(fin,author);
		getline(fin,publisher);
		getline(fin,intStr); //take in year as a string
		getline(fin,floatStr); //take in price as a string
		fin.ignore(); //ignore the blank line after each set of book info
		
		//atoi and atof only take in c-strings, so convert strings to c-strings
		year = atoi(intStr.c_str());
		price = atof(floatStr.c_str());
		
		//attach data to book, then shelve
		BookNode currentBook(title, author, publisher, year, price);
		bookArray[i] = currentBook;
		//cout << "address of bookArray[" << i << "]: " << &bookArray[i] << endl;
		shelf.insertSorted(bookArray[i]);
	}
	cout << "done adding stuff!" << endl;
	shelf.print();
	fin.close();
	
	return 0;
}
