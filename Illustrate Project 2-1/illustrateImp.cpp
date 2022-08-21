#include <iostream>
#include "illustrate.h"
using namespace std;

int Illustrate::count = 0;
int Illustrate::y = 0;

void Illustrate::print() const
{
  cout << "x = " << x << " y = " << y << " count = " << count << endl;
}

void Illustrate::setX (int a) 
{
  x = a;
}

void Illustrate::incrementY()
{
  y++;
}

Illustrate::Illustrate(int a)
{
  x = a;
}








