#include "Stack.h"
#include <iostream>

Stack::Stack(int inMaxSize)
{
	maxSize = inMaxSize;
	top = -1;
	array = new string[inMaxSize];
}

Stack::~Stack()
{
	delete array;
}

void Stack::push(string inData)
{
	top++;
	array[top] = inData;
}
string Stack::pop()
{
	string returnV;
	returnV = array[top];
	top--;
	return returnV;
}

bool Stack::empty() const
{
	if (top != -1)
		return false;
	else
		return true;
}

bool Stack::full() const
{
	if (top == maxSize - 1)
		return true;
	else
		return false;
}

void Stack::display()
{
	cout << "Contents of Array: " << endl;
	for (int i = 0; i <= top; i++)
	{
		cout << array[i] << endl;
	}
}

void displayMenu()
{
	cout << "Choose an item from the menu to manipulate the stack: " << endl;
	cout << "1. Push an item onto the stack." << endl;
	cout << "2. Pop an item from the stack." << endl;
	cout << "3. Display stack." << endl;
	cout << "4. Quit." << endl;
}


