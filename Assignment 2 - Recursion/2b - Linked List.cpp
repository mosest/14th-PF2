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
	string y;
	string p;
	int year;
	float price;
	
	ifstream fin;
	BookList shelf;
	
	//------------------------------
	//Open, Read, Close File
	//------------------------------
	fin.open("books.txt");
	getline(fin,y); //ignore the number of books in the file
	
	while (!fin.eof()) {
		getline(fin,title);
		getline(fin,author);
		getline(fin,publisher);
		getline(fin,y);
		getline(fin,p);
		fin.ignore(); //ignore the blank line after each set of book info
		
		//atoi and atof only take in c-strings, so convert y and p to c-strings
		year = atoi(y.c_str());
		price = atof(p.c_str());
		
		//attach data to book, then shelve
		BookNode currentBook(title, author, publisher, year, price);
		//currentBook.print();
		//cout << endl;
		shelf.insertTail(currentBook);
	}
	shelf.print();
	fin.close();
	
	return 0;
}
