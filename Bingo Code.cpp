#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX=75;

void init (bool called[]);
int pickNumber(bool called[]);
char getLetter(int number);

int main()
{
  bool called[MAX+1];
  srand(time(0));
  int number=0;
  char winner='N', letter=' ';
  init(called);
  while (toupper(winner) == 'N')
  {
    number = pickNumber(called);
    letter = getLetter(number);
    cout << letter << "-" << number << endl;
    cout << "Any winners (Y/N)? ";
    cin >> winner;
  }
  return 0;
}

int pickNumber(bool called[])
{
  int number=0;
  do
  {
    number=1+rand()%MAX;
  } while (called[number]);
  called[number] = true;
  return number;
}

char getLetter(int number)
{
  char letter=' ';
  if (number>=1 && number <=15)
    letter = 'B';
  else if (number>=16 && number <=30)
    letter = 'I';
  else if (number>=31 && number <=45)
    letter = 'N';
  else if (number>=46 && number <=60)
    letter = 'G';
  else
    letter = 'O';
  return letter;
}

void init (bool called[])
{
  for (int i=1; i<=MAX; i++)
    called[i] = false;
}
