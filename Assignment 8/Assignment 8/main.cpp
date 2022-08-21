/*
Name- Zachary Handel
Assignment- Assignment 8
Due Date- March 9th, 2022
Description- This program uses a series of functions in order to utilize a linked list. It will give
			 the user the ability to choose from a menu and pick a variety of different options to 
			 manipulate the linked list. The list will contain pet names, types, and ages
*/
#include <iostream>
#include "Pets.h"
using namespace std;

int main()
{
	PetsPtr head = nullptr;
	DisplayMenu(head);
	return 0;
}
	///DEBUGGING NOTES||| IGNORE!!!!
	//Testinng Head Insert
	/*
	HeadInsert(head, "spot", "dog", 11);
	HeadInsert(head, "pluto", "cat", 12);
	HeadInsert(head, "greg", "bird", 14);
	DisplayList(head);
	*/


	//Testing User Input WORKS!!!!!!
	/*
	string tempName, tempType;
	int tempAge = 0;
	cout << "This is from the Main Driver. Input a name, type, and age of the dog: " << endl;
	cin >> tempName;
	cin >> tempType;
	cin >> tempAge;
	HeadInsert(head, tempName, tempType, tempAge);
	cout << "List after user input:" << endl;
	DisplayList(head);
	*/

	//cout << "Display List IN MAIN::" << endl;
	//HeadInsert(head, "Spot", "Dog", 99);
	//DisplayList(head);