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
#include<cstring>
using namespace std;

struct PersonType
{
	char first[10];
	char last[20];
	int age;
};

int main()
{
	fstream outfile;
	PersonType person[30];

	strcpy(person[0].first, "Mickey");
	strcpy(person[0].last, "Mouse");
	person[0].age = 37;

	strcpy(person[1].first, "Minnie");
	strcpy(person[1].last, "Mouse");
	person[0].age = 35;

	strcpy(person[2].first, "Donald");
	strcpy(person[2].last, "Duck");
	person[0].age = 42;

	strcpy(person[3].first, "Scooby");
	strcpy(person[3].last, "Doo");
	person[0].age = 24;

	outfile.open("people.dat", ios::binary | ios::out);	// | means a bit-wise 'or' which makes it binary and output

	if (!outfile)
	{
		cout << "Error: Could not create the file" << endl;
		exit(0);
	}

	outfile.write(reinterpret_cast <char*>(&person[0]), sizeof(PersonType));
	outfile.write(reinterpret_cast <char*>(&person[1]), sizeof(PersonType));
	outfile.write(reinterpret_cast <char*>(&person[2]), sizeof(PersonType));
	outfile.write(reinterpret_cast <char*>(&person[3]), sizeof(PersonType));

	outfile.close();
	return 0;
}
