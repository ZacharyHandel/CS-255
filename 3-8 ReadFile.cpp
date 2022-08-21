//Binary vs Text/ASCII Files

	//Text/ASCII file is simply a bunch of characters
		//They are stored 1 byte per character
	//Biary Files are encoded into a specific format
		//Examples: Word, Excel, mp3, jpg, png, etc.
	//Advantages of using binary over text in C++
		//Less amount of code to read/write with binary files
		//Faster to execute when reading/writing with binary files
		//

#include<iostream>
#include<fstream>
using namespace std;

struct PersonType
{
	char first[10];
	char last[20];
	int age;
};

int main()
{
	fstream infile;
	PersonType person[30];



	infile.open("people.dat", ios::binary | ios::in);	// | means a bit-wise 'or' which makes it binary and output

	if (!infile)
	{
		cout << "Error: Could not create the file" << endl;
		exit(0);
	}

    int count = 0;
    while (!infile.eof())
    {
        infile.read(reinterpret_cast <char*>(&person[count]), sizeof(PersonType));
        if(!infile.eof())
        {
        cout << person[count].first << " " << person[count].last << " " << person[count].age << endl;
        count++;
        }
    }
    cout << "Number of persons: " << count << endl;



	infile.close();
	return 0;
}
