/*
Name- Zachary Handel
CS- 255 Computer Science 2
Assignment- Assignment 6
Description- This program will test operator overload on a program from assignment 3 and 4
Due Date- 1/26/2022
*/

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int const MAX_GAMES = 50;

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
        BoardGame();    //constructor
        BoardGame(string, int, int, int, double);
        ~BoardGame();
        void setBoardGame(string, int, int, int, double);
        void updatePrice(double);
       // BoardGame operator + (const BoardGame &right);

};

//prototypes
void readGameFromFile(BoardGame gms[], int &numGames);
void printGames(BoardGame gms[], int numGames);



int main()
{
    //create objects
    BoardGame monopoly, uno, sorry;

    string testString;

    BoardGame games[MAX_GAMES];
    int numGames = 0;
   /* //set Monopoly information
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


    //display contents of objects
   // monopoly.print();
    //cout << endl;
    //uno.print();
    //cout << endl;
    //sorry.print();
    */


    //cout << "FILE READ: " << endl;
    readGameFromFile(games, numGames);
    printGames(games, numGames);



    return 0;
}

//BoardGame BoardGame::operator + (const BoardGame &right)
//{

//}


void printGames(BoardGame gms[], int numGames)
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
    cout << "Board game has been destroyed" << endl;
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


