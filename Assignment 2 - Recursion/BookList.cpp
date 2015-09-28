/*
 * Tara Moses
 * Assignment 2b: BookList Class
 * September 18, 2015
 */

#include <iostream>
#include "BookList.h"
using namespace std;

//constructors and destructor
BookList::BookList() {
	head = NULL;
	current = head;
	size = 0;
}

BookList::BookList(BookNode first) {
	head = &first;
	current = head;
	size = 1;
}

BookList::~BookList() {
	//do killing stuff i guess
}

//getters!
BookNode* BookList::getNodeAt(int index) {
	current = head;
	for (int i = 0; i < size && i < index; i++) {
		current = (*current).getNext();
	}
	return current;
}

int BookList::getSize() {
	return size;
}

//setters (kind of). more like inserters
void BookList::insertHead(BookNode& node) {
	//cout << "insertHead(" << &node << ")" << endl;
	
	if (size > 0) node.setNext(head);
	head = &node;
	size++;
}

void BookList::insertTail(BookNode& node) {
	if (size > 0) (*getNodeAt(size - 1)).setNext(&node);
	else head = &node;
	size++;
}

void BookList::insertSorted(BookNode& node) {
	//cout << "insertSorted(" << &node << ")" << endl;
	if (size == 0) insertHead(node); //no books to sort through
	else if (size == 1) { //only one book to sort through
		if ((*head).getPrice() > node.getPrice()) insertHead(node);
		else insertTail(node);
	} else { //there's at least two books in this list!	
		current = head; 
		
		if ((*head).getPrice() > node.getPrice()) insertHead(node);
		else {		
			//search through list until you find current.price > node.price
			for (int i = 0; i < size && (*getNodeAt(i)).getPrice() <= node.getPrice(); i++) {
				current = getNodeAt(i);
			}
			//loop stops when current.price is the LAST ONE with price <= node.price
			
			//wedge node between current and current.next :3
			cout << "Setting " << (*current).getPrice() << " > ";
			cout << node.getPrice() << " > ";
			cout << (*(*current).getNext()).getPrice() << endl << endl;
			
			node.setNext((*current).getNext());
			(*current).setNext(&node);
			
			size++;
		}
	}
	cout << "added book!" << endl;
}

//other functions!
void BookList::deleteBook(string title) {
	
}

void BookList::destroy() {
	
}

void BookList::print() {
	current = head;
	for (int i = 0; i < size; i++) {
		cout << "BOOK #" << i << ":" << endl;
		(*current).print();
		cout << endl;
		current = (*current).getNext();
	}
}
