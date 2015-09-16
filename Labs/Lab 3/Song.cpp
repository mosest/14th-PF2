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
string Song::getName() {
	 return name;
}

string Song::getArtist() {
	return artist;
}

string Song::getLyrics() {
	return lyrics;
}

int Song::getLength() {
	return lengthInSeconds;
}

int Song::getNumOfDownloads() {
	return numOfDownloads;
}
 
//setters
void Song::setName(const string& str) {
	name = str;
}

void Song::setArtist(const string& str) {
	artist = str;
}

void Song::setLyrics(const string& str) {
	lyrics = str;
}

void Song::setLength(const int& num) {
	lengthInSeconds = num;
}

void Song::setNumOfDownloads(const int& num) {
	numOfDownloads = num;
}
 
//other
void Song::print() {
	cout << "Name: " << name << endl
		 << "Artist: " << artist << endl
		 << "Lyrics: " << lyrics << endl
		 << "Length (secs): " << lengthInSeconds << endl
		 << "Number of Times Downloaded: " << numOfDownloads << endl;
}
