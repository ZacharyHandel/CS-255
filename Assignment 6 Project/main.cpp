/*
Name- Zachary Handel
Assignment- Assignment 6
Date- 2/19/2022
Description- This is the main driver that will test out all over-ridden operators
within the Boardgame.h header file (+ == << >>)
*/


#include <iostream>
#include <fstream>
#include "BoardGame.h"
using namespace std;

int const MAX_GAMES = 50;


int main()
{
    BoardGame monopoly, uno, sorry, life, combinedGames;

    //set Monopoly Information
    monopoly.setDescription("Monopoly");
    monopoly.setMinPlayers(2);
    monopoly.setMaxPlayers(8);
    monopoly.setMinAge(9);
    monopoly.setPrice(20.99);

    //set Uno information
    uno.setDescription("Uno");
    uno.setMinPlayers(2);
    uno.setMaxPlayers(10);
    uno.setMinAge(7);
    uno.setPrice(7.99);


    //set Sorry! information
    sorry.setDescription("Sorry!");
    sorry.setMinPlayers(2);
    sorry.setMaxPlayers(4);
    sorry.setMinAge(6);
    sorry.setPrice(10.99);


    //Showing Contents in Console
    cout << "DEBUG CONTENTS: " << endl;
    monopoly.print();
    cout << endl;
    sorry.print();
    cout << endl;
    uno.print();
    cout << "*************************************************" << endl;
    cout << endl;
    cout << endl;


    //Testing over-ridden + operator
    cout << "Testing '+' operator: " << endl;
    cout << "Monopoly + Sorry:" << endl;
    combinedGames = monopoly + sorry;
    combinedGames.print();
    cout << endl;
    cout << "Uno + Monopoly: " << endl;
    combinedGames = uno + monopoly;
    combinedGames.print();
    cout << endl;

    //testing over-ridden == operator
    cout << "Testing '==' operator: " << endl;
    cout << "Monopoly == Monopoly? " << endl;

    if(monopoly == monopoly)
    {
        cout << "These Match!" << endl;
    }
    else
    {
        cout << "These Don't Match!" << endl;
    }
    cout << endl;

    cout << "Monopoly == Uno? " << endl;

    if(monopoly == uno)
    {
        cout << "These Match!" << endl;
    }
    else
    {
        cout << "These Don't Match!" << endl;
    }
    cout << endl;

    //testing over-ridden << and >> operators
    cout << "Testing Input and Output: " << endl;
    cout << "Input the information for the game 'Life!' (Name, Min-Players, Max-Players, Min-Age, Price): " << endl;
    cin >> life;
    cout << life;

    return 0;
}
