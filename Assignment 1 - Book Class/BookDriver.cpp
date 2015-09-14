//Tara Moses
//September 1, 2015
//Assignment 1: Books Driver

#include <iostream>
#include <iomanip> //necessary to use setprecision
#include <fstream> //necessary to read txt files
#include <cstdlib> //necessary for atoi and atof??
#include "Book.cpp"
using namespace std;

//------------------------------
//Helpful Functions
//------------------------------
void searchByTitle(string titleQuery, Book array[], int size) {
	int foundBooks = 0;
	
	for (int i = 0; i < size; i++) {
		if (array[i].getTitle().compare(titleQuery) == 0) {
			foundBooks++;
			array[i].print();
			cout << endl;
		}
	}
	
	if (foundBooks == 0) cout << "Sorry, nothing matches your search." << endl << endl;
}

void searchByYear(int yearQuery, Book array[], int size) {
	int foundBooks = 0;
	
	for (int i = 0; i < size; i++) {
		if (array[i].getYear() <= yearQuery) {
			foundBooks++;
			array[i].print();
			cout << endl;
		}
	}
	
	if (foundBooks == 0) cout << "Sorry, nothing matches your search." << endl << endl;
}

//------------------------------
//Main Function
//------------------------------
int main() {
	//------------------------------
	//Variables
	//------------------------------
	fstream fin;
	string title;
	string author;
	string publisher;
	string y;
	string p;
	int year;
	float price;
	int totalBooksToShelve;
	
	string c;
	int choice;
	char again;
	
	//------------------------------
	//Open, Read, Close File
	//------------------------------
	fin.open("books.txt");
	
	fin >> totalBooksToShelve;
	fin.ignore();
	Book shelf[totalBooksToShelve];
	
	for(int i = 0; i < totalBooksToShelve && !fin.eof(); i++) {
		getline(fin,title);
		getline(fin,author);
		getline(fin,publisher);
		getline(fin,y);
		getline(fin,p);
		fin.ignore(); //ignore the blank line after each set of book info
		
		//atoi and atof only take in c-strings, so convert y and p to c-strings
		year = atoi(y.c_str());
		price = atof(p.c_str());
		
		//attach data to book!
		Book currentBook(title, author, publisher, year, price);
		shelf[i] = currentBook;
	}
	fin.close();
	
	//print all the books on the shelf!
	/*for (int i = 0; i < totalBooksToShelve; i++) {
		shelf[i].print();
		cout << endl;
	}*/
	
	//------------------------------
	//User Interaction <3
	//------------------------------
	cout << "Choose how you'd like to search the bookshelf!" << endl;
	cout << "(1) Input a title and receive all books that match that title, or" << endl;
	cout << "(2) Input a year and receive all books published by that year." << endl;
	
	do {
		//ask for choice
		cout << endl << "Input a 1 or 2: ";
		getline(cin, c);
		
		//check if user gave useful input
		while (!atoi(c.c_str()) || (c.compare("1") != 0 && c.compare("2") != 0)) { //while it's not a number OR it's the wrong number
			cout << "Please try again. 1 or 2? ";
			getline(cin, c);
		}
		
		choice = atoi(c.c_str());
		
		//search
		if (choice == 1) {
			cout << "Input capitalization-correct title: ";
			getline(cin, title); //getline is helpful here because what if multi-word string
			cout << endl;
			
			searchByTitle(title, shelf, totalBooksToShelve);
		} else {
			cout << "Input year: ";
			getline(cin, y);
			
			//check if they actually input a year
			while (!atoi(y.c_str())) {
				cout << "Not a year. Input a year: ";
				getline(cin, y);
			}
			
			year = atoi(y.c_str());			
			cout << endl;
			
			searchByYear(year, shelf, totalBooksToShelve); 
		}
		
		//ask user to search again
		cout << "Search again? (y/n): ";
		cin >> again;
		cin.ignore();
	} while (again == 'y' || again=='Y');
	
	cout << endl << "Thank you for searching the bookshelf." << endl;
	
	return 0;
}
