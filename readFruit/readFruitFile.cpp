#include <iostream>
#include <fstream>                  // 1. Include fstream library
using namespace std;
const int MAX_FRUIT = 100;
int main()
{
  string fruit[MAX_FRUIT];
  int count=0;

  ifstream fruitFile;               // 2. Declare ifstream or ofstream variable
  fruitFile.open("fruit.txt");       // 3. Open the file
  if (fruitFile.fail())              // 4. Check to ensure file was opened
    {
      cout << "Error opening file" << endl;
      exit(1);
    }

/*
  while (!fruitFile.eof())
  {
    fruitFile >> fruit[count] >> ws;        // 5. Read or write data with the file
                                            // ws means read the white space so you can cont to next line
    count++;
  }


  fruitFile >> fruit[count];
  while (!fruitFile.eof())
  {
    count++;
    fruitFile >> fruit[count];        // 5. Read or write data with the file
  }
 */

  while (fruitFile >> fruit[count])
  {

    count++;

  }

  fruitFile.close();                  // 6. Close the file

  for (int i=0; i<count; i++)
    cout << i << " " << fruit[i] << endl;

  return 0;
}






