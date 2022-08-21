/*
Name- Zachary Handel
Assignment- Assignment 6
Date- 2/19/2022
Description-
*/
#include "BoardGame.h"
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

/*
Function Name- ostream
Description- overrides << operator
Incoming- stream, obj
Outgoing- output of all values
Return-stream
*/
ostream &operator << (ostream &stream, const BoardGame &obj)
{
    stream << "Description: " << obj.description << endl << "Minimum Players: " << obj.minPlayers
        << endl << "Max Players: " << obj.maxPlayers << endl << "Min Age: " << obj.minAge << endl <<
        "Price: " << obj.price << endl;
    return stream;
}

/*
Function Name- istream
Description- overrides >> operator
Incoming- stream, obj
Outgoing- None
Return-stream
*/
istream &operator >> (istream &stream, BoardGame &obj)
{
    double tempDouble;
    int temp;
    string tempString;
    cin >> ws;
    getline(stream, tempString);
    obj.setDescription(tempString);
    stream >> temp;
    obj.setMinPlayers(temp);
    stream >> temp;
    obj.setMaxPlayers(temp);
    stream >> temp;
    obj.setMinAge(temp);
    stream >> tempDouble;
    obj.setPrice(tempDouble);
    return stream;
}

/*
Function Name- Boardgame
Description- overrides + operator
Incoming- &right
Outgoing- all added values
Return-temp
*/
BoardGame BoardGame::operator + (const BoardGame &right)
{
    BoardGame temp;
    //temp.description = description + right.description;
    //return temp;
    temp.description = description + right.description;
    temp.maxPlayers = (maxPlayers + right.maxPlayers) / 2;
    temp.minPlayers = (minPlayers + right.minPlayers) / 2;
    temp.minAge = (minAge + right.minAge) / 2;
    temp.price = (price + right.price) / 2.0;
    return temp;
}

/*
Function Name- operator ==
Description- overrides == operator
Incoming- &right
Outgoing- bool status
Return-status
*/
bool BoardGame::operator == (const BoardGame &right)
{
    bool status = false;
    if(description == right.description)
    {
        status = true;
    }

    return status;
}

/*void printGames(BoardGame gms[], int numGames)
{
    for(int i = 0; i < numGames; i++)
    {
        cout << "PRINTING GAME #" << i+1 << endl;
        gms[i].print();
        cout << endl << endl;
    }

    cout << "UPDATED PRICE FOR 10% OFF!!!: " << endl;
    for(int j = 0; j < numGames; j++)
    {
        gms[j].updatePrice(0.9);
        gms[j].print();
        cout << endl;
    }
}

void readGameFromFile(BoardGame gms[], int &numGames)
{
    numGames = 0;
    ifstream gameFile;
    string dscript = "";
    int minPlr = 0, maxPlr = 0, minAg = 0;
    double prce = 0;
    gameFile.open("boardgames.txt");
    getline(gameFile, dscript);
    while(!gameFile.eof())
    {
        gameFile >> minPlr >> maxPlr >> minAg >> prce;
        gms[numGames].setBoardGame(dscript, minPlr, maxPlr, minAg, prce);
        numGames++;
        gameFile >> ws;
        getline(gameFile, dscript);
    }
    gameFile.close();
    ///DEBUGGING FOR FILE READ
    //cout << "readGameFromFile Trouble Shooting: " << endl;
    //cout << "dscript: " << dscript << endl;
    //cout << "minPlr: " << minPlr << endl;
    //cout << "maxPlr: " << maxPlr << endl;
    //cout << "minAg: " << minAg << endl;
    //cout << "prce: " << prce << endl;

}
*/

/*
Function Name- updatePrice
Description- update the price of all board games
Incoming- rate
Outgoing- new price
Return-None
*/
void BoardGame::updatePrice(double rate)
{
    price = price * rate;
}

/*
Function Name- setBoardGame
Description- sets values read in from file
Incoming- All values from file
Outgoing- All values from file
Return-None
*/
void BoardGame::setBoardGame(string setDescription, int setMinPlayers, int setMaxPlayers, int setMinAge, double setPrice)
{
    description = setDescription;
    minPlayers = setMinPlayers;
    maxPlayers = setMaxPlayers;
    minAge = setMinAge;
    price = setPrice;
}

/*
Function Name- BoardGame::BoardGame
Description- DEFAULT CONSTRUCTOR SETTER
Incoming- Default values
Outgoing- Default values
Return-None
*/
BoardGame::BoardGame(string inDescription, int inMinPlayers, int inMaxPlayers, int inMinAge, double inPrice)
{
    description = inDescription;
    minPlayers = inMinPlayers;
    maxPlayers = inMaxPlayers;
    minAge = inMinAge;
    price = inPrice;
}

/*
Function Name- BoardGame::BoardGame
Description- DEFAULT CONSTRUCTOR
Incoming- None
Outgoing- Default values
Return-None
*/
BoardGame::BoardGame()    //default constructor
{
    description = "TBA";
    minPlayers = 0;
    maxPlayers = 0;
    minAge = 0;
    price = 0;

}

/*
Function Name- BoardGame::~BoardGame
Description- DESTRUCTOR
Incoming- None
Outgoing- None
Return-None
*/
BoardGame::~BoardGame()
{
    //cout << "Board game has been destroyed" << endl;
}




/*
Function Name- print
Description- prints contents of class
Incoming- BoardGame class
Outgoing- class private variables description, minPlayers, maxPlayers, minAge, and price
Return-None
*/
void BoardGame::print() const
{
    cout << "Description: " << description << endl;
    cout << "Minimum Players: " << minPlayers << endl;
    cout << "Maximum Players: " << maxPlayers << endl;
    cout << "Minimum Age: " << minAge << endl;
    cout << "Price: $" <<setprecision(2) << fixed << price << endl;
}

/*
Function Name-setDescription
Description- sets board game description
Incoming- string of description
Outgoing- description
Return- None
*/
void BoardGame::setDescription(string inDescription)
{
    description = inDescription;
}

/*
Function Name-getDescription
Description- gives the description to the description private class variable
Incoming- BoardGame class
Outgoing- None
Return- description
*/
string BoardGame::getDescription() const
{
    return description;
}

/*
Function Name- setMinPlayers
Description- sets the minimum players of board game
Incoming- integer of minimum players
Outgoing- minimum players
Return- None
*/
void BoardGame::setMinPlayers(int inMinPlayers)
{
    minPlayers = inMinPlayers;
}

/*
Function Name- getMinPlayers
Description- gives minimum players to minPlayers private class variable
Incoming- BoardGame class
Outgoing- None
Return- minPlayers
*/
int BoardGame::getMinPlayers() const
{
    return minPlayers;
}

/*
Function Name- setMaxPlayers
Description- sets the maximum number of players
Incoming- integer of max number of players
Outgoing- maxPlayers
Return- None
*/
void BoardGame::setMaxPlayers(int inMaxPlayers)
{
    maxPlayers = inMaxPlayers;
}

/*
Function Name- getMaxPlayers
Description- gives maximum number of players to the maxPlayers private class varible
Incoming- BoardGame class
Outgoing- None
Return- maxPlayers
*/
int BoardGame::getMaxPlayers() const
{
    return maxPlayers;
}

/*
Function Name- setMinAge
Description- sets the minimum age of board game
Incoming- integer of the minimum age
Outgoing- minAge
Return- none
*/
void BoardGame::setMinAge(int inMinAge)
{
    minAge = inMinAge;
}

/*
Function Name- getMinAge
Description- gives the minimum age to the private class variable minAge
Incoming- BoardGame Class
Outgoing- None
Return- minAge
*/
int BoardGame::getMinAge() const
{
    return minAge;
}

/*
Function Name- setPrice
Description- sets the price of the given board game object
Incoming- double value of price
Outgoing- price
Return- none
*/
void BoardGame::setPrice(double inPrice)
{
    price = inPrice;
}

/*
Function Name- getPrice
Description- gives price of board game to private class variable price
Incoming- BoardGame class
Outgoing- None
Return- price
*/
double BoardGame::getPrice() const
{
    return price;
}

