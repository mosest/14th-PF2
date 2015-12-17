//Tara Moses
//Assignment 5: Quarterback Source
//December 6, 2015

#include "Quarterback.h"
using namespace std;

//--------------------------------
// Constructors and Destructors
//--------------------------------
Quarterback::Quarterback() {
    //hello
}

Quarterback::Quarterback(string n, string t, int g, float r) {
    name = n;
    team = t;
    game = g;
    rating = r;
}

Quarterback::~Quarterback() {
    //nothing hehe
}

//--------------------------------
// Getters
//--------------------------------
string Quarterback::getName() {
    return name;
}

string Quarterback::getTeam() {
    return team;
}

int Quarterback::getGame() {
    return game;
}

float Quarterback::getRating() {
    return rating;
}

//--------------------------------
// Setters
//--------------------------------
void Quarterback::setName(string s) {
    name = s;
}

void Quarterback::setTeam(string s) {
    team = s;
}

void Quarterback::setGame(int n) {
    game = n;
}

void Quarterback::setRating(float n) {
    rating = n;
}

//--------------------------------
// Other Functions
//--------------------------------
void Quarterback::print() {
    cout << "Player: " << name          << endl;
    cout << "Team:   " << team          << endl;
    cout << "Game:   " << game          << endl;
    cout << "Rating: " << rating        << endl << endl;
}

int Quarterback::compareByGame(Quarterback other) {
    if (game > other.getGame()) return 1;
    else if (game == other.getGame()) return 0;
    else return -1;
}
