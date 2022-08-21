/*
Name- Zachary Handel
Assignment- Assignment 9
Due Date- 3/14/22
Description- This program creates a data file that will create 10000 different bowling teams and their scores.
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//create number of bowlers constant
const int NUMBER_OF_BOWLERS = 10000;


//create class for bowler
struct BowlType
{
    int bowlID;
    char teamName[30];
    int game1, game2, game3;
};


int main()
{
    //create outfile and bowler object
    fstream outfile;
    BowlType bowler;

    //create randomizer
    char part1[5][10] = {"Crazy", "Silly", "Wacky", "Boastful", "Goofy"};   //5 pieces with 10 characters
    char part2[5][10] = {"Blue", "Purple", "Red", "Gold", "Yellow"};
    char part3[5][10] = {"Ducks", "Seagulls", "Hawks", "Toucans", "Owls"};

    outfile.open("Bowling.dat", ios::binary | ios::out);    //makes it binary and output

    for (int i = 0; i < NUMBER_OF_BOWLERS; i++)
    {
        bowler.bowlID = 1000 + rand()%9000;
        sprintf(bowler.teamName, "%s %s %s", part1[rand()%5], part2[rand()%5], part3[rand()%5]);
        bowler.game1 = 100+ rand()%151;
        bowler.game2 = 100+ rand()%151;
        bowler.game3 = 100+ rand()%151;
        outfile.write(reinterpret_cast<char*> (&bowler), sizeof(bowler));
    }
    cout << "Bowler data was created successfully using Bowling.dat" << endl;
    outfile.close();
    return 0;
}

