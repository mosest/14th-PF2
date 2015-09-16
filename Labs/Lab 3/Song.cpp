/*
 * Tara Moses
 * Lab 3: Song Header
 * September 16, 2015
 */

#include <iostream>
#include "Song.h"
using namespace std;

//constructors and destructors
Song::Song() {
 
}

Song::~Song() {
 
}

//getters
 string getName() {
	 return name;
}

string getArtist() {
	return artist;
}

string getLyrics() {
	return lyrics;
}

int getLength() {
	return lengthInSeconds;
}

int getNumOfDownloads() {
	return numOfDownloads;
}
 
//setters
void setName(const string& str) {
	name = str;
}

void setArtist(const string& str) {
	artist = str;
}

void setLyrics(const string& str) {
	lyrics = str;
}

void setLength(const int& num) {
	lengthInSeconds = num;
}

void setNumOfDownloads(const int& num) {
	numOfDownloads = num;
}
 
//other
void print() {
	cout << "Name: " << name << endl
		 << "Artist: " << artist << endl
		 << "Lyrics: " << lyrics << endl
		 << "Length (secs): " << lengthInSeconds << endl
		 << "Number of Times Downloaded: " << numOfDownloads << endl;
}
