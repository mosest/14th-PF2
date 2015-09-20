/* 
 * Tara Moses
 * Assignment 2b: BookNode Header
 * September 17, 2015
 */

#include <iostream>
using namespace std;

class BookNode {
	public:
		//Constructor and Destructor
		BookNode(string t, string a, string pu, int y, float pr);
		BookNode();
		~BookNode();
		
		//Getters
		string getTitle();
		string getAuthor();
		string getPublisher();
		int getYear();
		float getPrice();
		BookNode* getNext();
		
		//Setters
		void setTitle(string title);
		void setAuthor(string author);
		void setPublisher(string publisher);
		void setYear(int year);
		void setPrice(float price);
		void setNext(BookNode* n);
		
		//Other functions
		void print();
		
	private:
		string title;
		string author;
		string publisher;
		int year;
		float price;
		BookNode* Next;
};
