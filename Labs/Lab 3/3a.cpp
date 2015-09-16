/*
 * Tara Moses
 * Lab 3a: 
 * September 16, 2015
 */

#include <iostream>
#include "Song.h"
using namespace std;

int main() {
	cout << "=== Lab 3 starts === \n";

    Song song1(); // your favorite song.

    // TODO: Set values for all attributes you defined.
    Song1.setName("GINASFS");
    Song1.setArtist("Fall Out Boyyy");
    Song1.setLyrics("boop boop doop");
    Song1.setLength(180);
    Song1.setNumOfDownloads(1200001);

    Song song2(); // another your favorite song. 

    // TODO: Set values for all attributes you defined.
    Song2.setName("Death of a Bachelor");
    Song2.setArtist("Panic! at! the Disco! !!!");
    Song2.setLyrics("beep beep deep");
    Song2.setLength(65);
    Song2.setNumOfDownloads(130);

    // TODO: Print the name of song1.
    cout << "Song1 name: " << Song1.getName() << endl;

    // TODO: Print the singer of song2.
    cout << "Song2 artist: " << Song1.getArtist() << endl;

    // TODO: call song1's print function.
    Song1.print();

    // TODO: call song2's print function.
    Song2.print();

    cout << "=== Lab 3 ends === \n";
	
	return 0;
}
