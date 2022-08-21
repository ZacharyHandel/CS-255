#include "Stack.h"
#include <iostream>
using namespace std;


Stack::Stack(int inMaxSize)
{
	maxSize = inMaxSize;
	top = -1;
	array = new double[inMaxSize];
}

Stack::~Stack()
{
	delete array;
}

void Stack::push(double inData)
{
	top++;
	array[top] = inData;
}
double Stack::pop()
{
	double returnV;
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
	for (int i = top; i >-1; i--)
	{
		cout << array[i] << " ";
	}
}
