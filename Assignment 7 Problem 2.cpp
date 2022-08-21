/*
Zachary Handel
Assignment 7 pt. 2
February 28th
This program will sum up all the integers inputed from the user using recursion
*/
#include <iostream>
using namespace std;

/*
Name- sumDigits
Description- Adds up all of the numbers inputted using recursion
Input- Number from user
Output- None
Return- Sum of numbers inputed from user
*/
int sumDigits(int num)
{
	if (num <= 0)
	{
		return 0;
	}
	else
	{
		return num + sumDigits(num / 10);  //Gets remainder and adds remainder of next digit
	}
}

int main()
{
	int num;
	int sum = 0;
	cout << "Input an integer: " << endl;
	cin >> num;

	sum = sumDigits(num);

	cout << "The sum of all the integers of " << num << " is " << sum << endl;
}
