#include <iostream>
#include "illustrate.h"
using namespace std;
int main() 
{
  Illustrate obj1, obj2(43);
  
  cout << "object #1: " << endl;
  obj1.print();
  cout << endl;

  cout << "object #2: " << endl;
  obj2.print();
  cout << endl;

  obj1.incrementY();
  obj2.incrementY();
 
  Illustrate::incrementY();
 
  Illustrate::count = 29;
 
  obj2.print();
  return 0;
}
