/* 
 * Tara Moses
 * Assignment 2b: BookNode Class
 * September 17, 2015
 */

#include <iostream>
#include <iomanip>
#include "BookNode.h"

//------------------------------
//Constructor and Destructor
//------------------------------
BookNode::BookNode(string t, string a, string pu, int y, float pr) {
	title = t;
	author = a;
	publisher = pu;
	year = y;
	price = pr;
}

BookNode::BookNode() {
	title = "Unknown";
	author = "U. N. Known";
	publisher = "Unknown";
	year = 0;
	price = 0.0;
}

BookNode::~BookNode() {
	//do nothing, no dynamic memory lel
}

//------------------------------
//Getters (Accessors)
//------------------------------
string BookNode::getTitle() {
	return title;
}

string BookNode::getAuthor() {
	return author;
}

string BookNode::getPublisher() {
	return publisher;
}

int BookNode::getYear() {
	return year;
}

float BookNode::getPrice() {
	return price;
}

BookNode* BookNode::getNext() {
	return Next;
}

//------------------------------
//Setters (Mutators)
//------------------------------
void BookNode::setTitle(string t) {
	title = t;
}

void BookNode::setAuthor(string a) {
	author = a;
}

void BookNode::setPublisher(string p) {
	publisher = p;
}

void BookNode::setYear(int y) {
	year = y;
}

void BookNode::setPrice(float p) {
	price = p;
}

void BookNode::setNext(BookNode* n) {
	Next = n;
}

//------------------------------
//Other Functions
//------------------------------
void BookNode::print() {
	cout << title << " (" << year << ") by " << author << endl;
	cout << "Published by " << publisher << ". $";
	cout << setprecision(2) << fixed << price << endl;
	//cout << "Next points to " << (*Next).getTitle() << endl;
}
