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
	string floatStr; //reusable string to use with atof. eg "3.14"
	int year;
	float price;
	int numBooks = 0;
	
	ifstream fin;
	BookList shelf;
	
	int choice;
	char again;
	
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
		
		//atoi and atof only take in c-strings, so convert
		year = atoi(intStr.c_str());
		price = atof(floatStr.c_str());
		
		//attach data to book, then shelve
		BookNode currentBook(title, author, publisher, year, price);
		bookArray[i] = currentBook;
		shelf.insertSorted(bookArray[i]);
	}
	
	//------------------------------
	//User Interface
	//------------------------------
	cout << "Choose what you'd like to do with the bookshelf!" << endl;
	cout << "(1) Destroy the list" << endl;
	cout << "(2) Print the list" << endl;
	cout << "(3) Add a book to the list" << endl;
	cout << "(4) Delete a book from the list" << endl;
	
	do {
		//ask for choice
		cout << endl << "Input a number: ";
		getline(cin, intStr);
		
		//check if user gave useful input
		while (!atoi(intStr.c_str()) || atoi(intStr.c_str()) > 5) { //while it's not a number OR it's the wrong number
			cout << "Please try again. Input a number: ";
			getline(cin, intStr);
		}
		
		choice = atoi(intStr.c_str());
		
		if (choice == 1) {
			cout << "Destroying..." << endl;
			shelf.destroy();
		} else if (choice == 2) {
			cout << "Printing..." << endl;
			shelf.print();			
		} else if (choice == 3) {
			cout << "Title: ";
			getline(cin,title);
			cout << "Author: ";
			getline(cin,author);
			cout << "Publisher: ";
			getline(cin,publisher);
			cout << "Year: ";
			getline(cin,intStr); //take in year as a string
			
			//make sure year is actually a number ;_;
			while (!atoi(intStr.c_str())) {
				cout << "Year: ";
				getline(cin, intStr);
			}
			
			cout << "Price: ";
			getline(cin,floatStr); //take in price as a string
			
			//make sure price is actually a number ;_;
			while (!atof(floatStr.c_str())) {
				cout << "Price: ";
				getline(cin, floatStr);
			}
			
			//atoi and atof only take in c-strings, so convert
			year = atoi(intStr.c_str());
			price = atof(floatStr.c_str());
						
			BookNode temp(title, author, publisher, year, price);
			shelf.insertSorted(temp);
		} else if (choice == 4) {
			cout << "Title of book to delete: ";
			getline(cin, title);
			shelf.deleteBook(title);
		}
		
		//ask user to go again
		cout << endl << "Do something else with the list? (y/n): ";
		cin >> again;
		cin.ignore();
	} while (again == 'y' || again=='Y');
	
	cout << "Thank you for using the bookshelf!" << endl;
	
	return 0;
}
