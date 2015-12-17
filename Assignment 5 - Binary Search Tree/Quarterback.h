//Tara Moses
//Assignment 5: Quarterback Header
//December 6, 2015

#include <iostream>
#include <string>
using namespace std;

class Quarterback {
    public:
        //constructors and destructors
        Quarterback();
        Quarterback(string, string, int, float);
        ~Quarterback();
        
        //getters
        string getName();
        string getTeam();
        int getGame();
        float getRating();
        
        //setters
        void setName(string);
        void setTeam(string);
        void setGame(int);
        void setRating(float);
        
        //other functions!
        void print();
        int compareByGame(Quarterback); //game is primary criterion
        
    private:
        string name;
        string team;
        int game;
        float rating;
};