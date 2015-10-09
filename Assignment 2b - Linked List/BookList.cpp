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

//setters (kind of). more like inserters
void BookList::insertHead(BookNode& node) {
	if (size > 0) node.setNext(head);
	head = &node;
	size++;
}

void BookList::insertTail(BookNode& node) {
	if (size == 0) head = &node;
	else {
		current = head;
		for (int i = 0; i < size - 1; i++) {
			current = (*current).getNext();
		}
		(*current).setNext(&node);
	}
	
	size++;
}

void BookList::insertSorted(BookNode& node) {
	//list is currently empty
	if (size == 0) insertHead(node);
	
	//list has one book in it!
	else if (size == 1) {
		if ((*head).getPrice() > node.getPrice()) insertHead(node);
		else insertTail(node);
		
	 //there's at least two books in this list <3
	} else {		
		/* current is SECOND book in the list. 
		 * prev is the first book :D 
		 * 
		 * basically, if the new node's price is
		 * the lowest we've encountered so far, 
		 * just insert it as the head. otherwise, 
		 * find where new node belongs and wedge it
		 * inbetween prev and current!
		 */
		current = (*head).getNext();
		BookNode* prev = head;
		
		if ((*head).getPrice() > node.getPrice()) insertHead(node);
		else {		
			//search through list until you find current.price > node.price
			for (int i = 0; i < size - 1 && (*current).getPrice() <= node.getPrice(); i++) {
				prev = current;
				current = (*current).getNext();
			}
			
			//wedge node between prev and current :3
			node.setNext(current);
			(*prev).setNext(&node);
			
			size++;
		}
	}
}

//other functions!
void BookList::deleteBook(string name) {
	current = (*head).getNext();
	BookNode* prev = head;	
	
	//check if the book to delete is at the head!
	if ((*head).getTitle().compare(name) == 0) {
		delete prev;
		head = current;
		
		current = (*head).getNext();
		prev = head;
	} else {
		//check if it's anywhere but the head
		for (int i = 0; i < size - 1 && (*current).getTitle().compare(name) != 0; i++) {
			prev = current;
			current = (*current).getNext();
		}
	}
	
	if (current != NULL && (*current).getTitle().compare(name) == 0) {
		//get rid of current by connecting prev and current.next
		(*prev).setNext((*current).getNext());
		delete current;
	}
	
	//we killed a book! decrement size
	size--;
}

void BookList::destroy() {
	current = (*head).getNext();
	BookNode* prev = head;
	
	for (int i = 0; i < size - 1; i++) {
		//delete the one behind you!
		delete prev;
		
		//jump forward one!
		prev = current;
		current = (*current).getNext();
	}
	//at the end of that for loop, next = NULL
	
	head = NULL;
	size = 0;  
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
