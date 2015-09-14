//Tara Moses
//September 1, 2015
//Assignment 1: Books Header

#include <iostream>
using namespace std;

class Book {
	public:
		//Constructor and Destructor
		Book(string t, string a, string pu, int y, float pr);
		Book();
		~Book();
		
		//Getters
		string getTitle();
		string getAuthor();
		string getPublisher();
		int getYear();
		float getPrice();
		
		//Setters
		void setTitle(string title);
		void setAuthor(string author);
		void setPublisher(string publisher);
		void setYear(int year);
		void setPrice(float price);
		
		//Other functions
		void print();
		
	private:
		string title;
		string author;
		string publisher;
		int year;
		float price;
};
