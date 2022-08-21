#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
const int MAX_QB = 500;


struct QBStats
{
    string qbFirst, qbLast;
    int attempts, completions, yardsPassing, touchdowns, interceptions;
};

void readStats(QBStats stats[], int &num);
double calcCompPercentage(QBStats stats);
double calcRate(QBStats stats);
void printSingle(QBStats stats);
void printAllStats(QBStats stats[], int num);
void sortLastName(QBStats stats[], int num);
void sortRating(QBStats stats[], int num);

int main()
{


    int numQB = 0;
    QBStats stats[MAX_QB];
    readStats(stats, numQB);

    printAllStats(stats, numQB);
    sortLastName(stats, numQB);
    cout << endl << endl;

    cout << "Organized Names: " << endl;
    printAllStats(stats, numQB);
    sortRating(stats, numQB);
    cout << endl << endl;

    //print list with organized rating
    cout << "Organized Ratings: " << endl;
    printAllStats(stats, numQB);
    return 0;
}



void printSingle(QBStats stats)
{

    //print contents of QBSTATS structure once
    cout << stats.qbFirst << endl;
    cout << stats.qbLast << endl;
    cout << stats.attempts << endl;
    cout << stats.completions << endl;
    cout << stats.yardsPassing << endl;
    cout << stats.touchdowns << endl;
    cout << stats.interceptions << endl;
}



void readStats(QBStats stats[], int &num)
{

    num = 0;

    //create variable to read in file
    ifstream input("football-in.txt");

    //prime file input
    getline(input, stats[num].qbFirst);

    //read until end of the file
    while(!input.eof())
    {
        getline(input, stats[num].qbLast);
        input >> stats[num].attempts;
        input >> stats[num].completions;
        input >> stats[num].yardsPassing;
        input >> stats[num].touchdowns;
        input >> stats[num].interceptions;
        num++;
        input >> ws;
        getline(input, stats[num].qbFirst); //ends loop
    }
    input.close();  //Close File
}



void printAllStats(QBStats stats[], int num)
{

    //create header
    cout << left;
    cout << setw(20) << "Quarterback"
    << setw(6) << "Att." << setw(7) << "Comp."
    << setw(6) << "Pct." << setw(7) << "Yards"
    << setw(4) << "TD" << setw(6) << "Int."
    << setw(8) << "Rating" << endl;
    cout << "------------------  ----  -----  ----  -----  --  ----  ------" << endl;

    //print contents of all quarterbacks
    for(int i = 0; i < num; i++)
    {
        cout << fixed << setprecision(1);
        cout << setw(20) << stats[i].qbFirst+" "+stats[i].qbLast
        << setw(6) << stats[i].attempts << setw(7) << stats[i].completions
        << setw(6) << calcCompPercentage(stats[i]) << setw(7) << stats[i].yardsPassing
        << setw(4) << stats[i].touchdowns << setw(6) << stats[i].interceptions
        << setw(8) << calcRate(stats[i]) << endl;


    }
}


double calcCompPercentage(QBStats stats)
{
    //calculate for the completion percentage
    double compPercentage;
    compPercentage = (double)stats.completions/(double)stats.attempts;
    compPercentage = compPercentage * 100;
    return compPercentage;
}


double calcRate(QBStats stats)
{
    //calculate for the rating
    double rating;
    rating = stats.completions * 4;
    rating = rating + (1.2 * stats.yardsPassing);
    rating = rating + (8 * stats.touchdowns);
    rating = rating /(stats.attempts + 6 * stats.interceptions);
    return rating;
}

void sortLastName(QBStats stats[], int num)
{
   QBStats temp;
    int minIndex = 0;
    for(int i = 0; i < num-1; i++)
    {
        minIndex = i;
        for(int j = i+1; j < num; j++)
        {
            if(stats[j].qbLast < stats[minIndex].qbLast)
            {
                minIndex = j;
            }
        }
        temp = stats[i];          //Swap structs at positions i and minIndex
        stats[i] = stats[minIndex];     //set new value into correct spot
        stats[minIndex] = temp;     //reset min index value
    }
}


void sortRating(QBStats stats[], int num)
{
    QBStats temp;


    //sorting the rating in descending order
    for(int i = 0; i < num; i++)
    {
        for(int j = i+1; j < num; j++)
        {
            if(calcRate(stats[i]) < calcRate(stats[j]))
            {
                temp = stats[i];
                stats[i] = stats[j];
                stats[j] = temp;
            }
        }
    }

}


