/*
Name- Zachary Handel
Assignment- Assignment 6
Date- 2/19/2022
Description- This is the header file for Assignment 6. It includes all of the operator
override members needed for this assignment
*/
#include <iostream>
using namespace std;

class BoardGame; //Forward Declaration


ostream &operator << (ostream &stream, const BoardGame &obj);
istream &operator >> (istream &stream, BoardGame &obj);

//create class
class BoardGame
{
    private:
        string description;
        int minPlayers;
        int maxPlayers;
        int minAge;
        double price;
    public:
        void average();
         //description
        void setDescription(string);
        string getDescription() const;
        //minimum players
        void setMinPlayers(int);
        int getMinPlayers() const;
        //maximum players
        void setMaxPlayers(int);
        int getMaxPlayers() const;
        //minimum age
        void setMinAge(int);
        int getMinAge() const;
        //price
        void setPrice(double);
        double getPrice() const;
        void print() const;
        BoardGame();    //constructor
        BoardGame(string, int, int, int, double);
        ~BoardGame();   //destructor
        void setBoardGame(string, int, int, int, double);
        void updatePrice(double);
        //overload members
        BoardGame operator + (const BoardGame &);
        bool operator == (const BoardGame &);
        friend istream &operator >> (istream &, const BoardGame &);
        friend ostream &operator << (ostream &, const BoardGame &);
};
