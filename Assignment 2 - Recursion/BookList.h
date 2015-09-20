/*
 * Tara Moses
 * Assignment 2b: BookList Header
 * September 17, 2015
 */

#include <iostream>
#include "BookNode.cpp"
using namespace std;

class BookList {
	public:
		//constructors and destructor
		BookList();
		BookList(BookNode);
		~BookList();
		
		//getters
		BookNode* getNodeAt(int);
		
		//setters
		void insertHead(BookNode&);
		void insertTail(BookNode&);
		void insertSorted(BookNode&);
		
		//other
		void deleteBook(string);
		void destroy();
		void print();
		
	private:
		BookNode* head;
		BookNode* current;
		int size;		
};
