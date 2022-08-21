/*
Name- Zachary Handel
CS- 255 Computer Science 2
Assignment- Assignment 3
Description- This program will store information about a board game inside a class.
The main driver will create at least 3 board game objects.
We do this in order to make sure all 11 member functions included are working correctly.
It will also include output statements that will clarify what is happening when the
program executes
Due Date- 1/26/2022
*/

#include<iostream>
using namespace std;

//board game class
class BoardGame
{
    private:
        string description;
        int minPlayers;
        int maxPlayers;
        int minAge;
        double price;
    public:
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

};

int main()
{
    //create objects
    BoardGame monopoly, uno, sorry;


    //set Monopoly information
    monopoly.setDescription("Monopoly is a real-estate board game where the goal is to \nremain financially solvent and to force other players into bankruptcy.");
    monopoly.setMinPlayers(2);
    monopoly.setMaxPlayers(8);
    monopoly.setMinAge(9);
    monopoly.setPrice(20.99);

    //set Uno information
    uno.setDescription("Uno is a classic card game where players take turns \nmatching a card in their hand with the current card shown on top of the deck \nby color or number.");
    uno.setMinPlayers(2);
    uno.setMaxPlayers(10);
    uno.setMinAge(7);
    uno.setPrice(7.99);


    //set Sorry! information
    sorry.setDescription("Sorry! is the game where players bump other players pawns in order to \nretrieve their players into their Safe Zone.");
    sorry.setMinPlayers(2);
    sorry.setMaxPlayers(4);
    sorry.setMinAge(6);
    sorry.setPrice(10.99);


    //display contents of objects
    cout << "MONOPOLY:" << endl;
    monopoly.print();
    cout << endl;
    cout << "UNO: " << endl;
    uno.print();
    cout << endl;
    cout << "SORRY!:" << endl;
    sorry.print();

    return 0;
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
    cout << "Price: $" << price << endl;
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
