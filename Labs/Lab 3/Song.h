/*
* Tara Moses
* Lab 3: Song Header
* September 16, 2015
*/

#include <iostream>
using namespace std;

class Song {
	public:
		//constructors and destructors
		Song();
		~Song();
		
		//getters
		string getName();
		string getArtist();
		string getLyrics();
		int getLength();
		int getNumOfDownloads();
		
		//setters
		void setName(const string&);
		void setArtist(const string&);
		void setLyrics(const string&);
		void setLength(const int&);
		void setNumOfDownloads(const int&);
		
		//other
		void print();
		
	private:
		string name;
		string artist;
		string lyrics;
		int lengthInSeconds;
		int numOfDownloads;
};
