//Tara Moses
//September 1, 2015
//Assignment 1: Book Class

#include <iostream>
#include <iomanip>
#include "Book.h"

//------------------------------
//Constructor and Destructor
//------------------------------
Book::Book(string t, string a, string pu, int y, float pr) {
	title = t;
	author = a;
	publisher = pu;
	year = y;
	price = pr;
}

Book::Book() {
	title = "Unknown";
	author = "U. N. Known";
	publisher = "Unknown";
	year = 0;
	price = 0.0;
}

Book::~Book() {
	//do nothing, no dynamic memory lel
}

//------------------------------
//Getters (Accessors)
//------------------------------
string Book::getTitle() {
	return title;
}

string Book::getAuthor() {
	return author;
}

string Book::getPublisher() {
	return publisher;
}

int Book::getYear() {
	return year;
}

float Book::getPrice() {
	return price;
}

//------------------------------
//Setters (Mutators)
//------------------------------
void Book::setTitle(string t) {
	title = t;
}

void Book::setAuthor(string a) {
	author = a;
}

void Book::setPublisher(string p) {
	publisher = p;
}

void Book::setYear(int y) {
	year = y;
}

void Book::setPrice(float p) {
	price = p;
}

//------------------------------
//Other Functions
//------------------------------
void Book::print() {
	cout << title << " (" << year << ") by " << author << endl;
	cout << "Published by " << publisher << ". $";
	cout << setprecision(2) << fixed << price << endl;
}




















