/*
 * Tara Moses
 * Lab 3a: 
 * September 16, 2015
 */

#include <iostream>
#include "Song.cpp"
using namespace std;

int main() {
	cout << "=== Lab 3 starts === \n";

    Song song1; // your favorite song.

    // TODO: Set values for all attributes you defined.
    song1.setName("GINASFS");
    song1.setArtist("Fall Out Boyyy");
    song1.setLyrics("boop boop doop");
    song1.setLength(180);
    song1.setNumOfDownloads(1200001);

    Song song2; // another your favorite song. 

    // TODO: Set values for all attributes you defined.
    song2.setName("Death of a Bachelor");
    song2.setArtist("Panic! at! the Disco! !!!");
    song2.setLyrics("beep beep deep");
    song2.setLength(65);
    song2.setNumOfDownloads(130);

    // TODO: Print the name of song1.
    cout << "Song1 name: " << song1.getName() << endl;

    // TODO: Print the singer of song2.
    cout << "Song2 artist: " << song1.getArtist() << endl;

    // TODO: call song1's print function.
    song1.print();

    // TODO: call song2's print function.
    song2.print();

    cout << "=== Lab 3 ends === \n";
	
	return 0;
}
