/*
Name- Zachary Handel
Assignment- Assignment 9
Due Date- 3/14/22
Description- This program reads the data file created in the other program and displays it along with a header
             every 50 teams
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;


struct BowlType
{
    int bowlID;
    char teamName[30];
    int game1, game2, game3;
};


int main()
{
    int count = 0;
    fstream infile;
    BowlType bowler;

    infile.open("Bowling.dat", ios::binary | ios::in);    //makes it binary and output

    cout << left << setw(5) << "ID" << setw(25) << "Team Name: " << setw(6) << "G1" << setw(6) << "G2" << setw(6) << "G3" << endl;
    cout << "---------------------------------------------------" << endl;
    while(!infile.eof())
    {
        infile.read(reinterpret_cast<char*> (&bowler), sizeof(bowler));
        if(!infile.eof())
        {
            cout << setw(5) << bowler.bowlID << left << setw(25) << bowler.teamName <<
            setw(6) << bowler.game1 << setw(6) << bowler.game2 <<
            setw(6) << bowler.game3 << endl;
            count++;
            if(count == 50)
            {
                cout << left << setw(5) << "ID" << setw(25) << "Team Name: " << setw(6) << "G1" << setw(6) << "G2" << setw(6) << "G3" << endl;
                cout << "---------------------------------------------------" << endl;
                count = 0;
            }
        }
    }
    infile.close();
    return 0;
}

