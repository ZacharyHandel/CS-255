#include<iostream>
#include"Stack.h"

using namespace std;

int main()
{
	Stack st(6);
	int menuChoice = 0;
	while(menuChoice != 4)
	{ 
		displayMenu();
		cin >> menuChoice;
		if (menuChoice == 1)
		{
			if (st.full())
			{
				cout << "Stack is full." << endl;
			}
			else
			{
				string userString;
				cout << "Enter a new string." << endl;
				cin >> userString;
				st.push(userString);
			}
		}
		if (menuChoice == 2)
		{
			if (st.empty())
			{
				cout << "The stack is empty." << endl;
			}
			else
			{
				string item;
				item = st.pop();
				cout << item << " was popped from the stack." << endl;
			}
		}
		if (menuChoice == 3)
		{
			if (st.empty())
			{
				cout << "Cant display an empty stack." << endl;
			}
			else
			{
				st.display();
			}
		}
	}
	cout << "Goodbye!" << endl;
	exit(0);
}