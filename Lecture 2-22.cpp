///Lecture 2-22
/*
Recursion- when a function calls itself
    Used when a problem can be broken down into successive problems that are identical to the overall problem
*/

//Example 1
/*
#include <iostream>
using namespace std;

void response()
{
    static int n = 0;   //MUST BE STATIC SO IT CAN CHANGE!
    cout << n++ << " Welcome to recursion!" << endl;
    response();
}

int main()
{
    response();
    return 0;
}
*/

//Example 2
/*
#include <iostream>
using namespace std;

void message(int times)
{
    if(times > 0)
    {
        cout << "Enter function " << times << endl;
        message(times - 1);
        cout << "Exiting function " << times << endl;
    }
}

int main()
{
    message(5);
    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int factorial (int num)
{
    if(num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num-1);
    }
}

int factorial2 (int num)
{
    int temp = 1;
    for (int i = num; i > 0; i--)
    {
        temp *= i;
    }

    return temp;
}


int main()
{
    cout << "5 Factorial is " << factorial(5) << endl;
    cout << "5 Factorial is " << factorial2(5) << endl;
    return 0;
}
*/

//Example 4
/*
#include <iostream>
using namespace std;

int fib (int num)
{
    if (num == 1)
    {
        return 1;
    }
    else
    {
        if(num==2)
        {
            return 1;
        }
        else
        {
            return fib(num-2) + fib(num-1);
        }
    }
}

int main()
{
    int n = 0;
    cout << "Enter n for Fibonacci sequence: " << endl;
    cin >> n;
    cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl;
    return 0;
}
*/

#include <iostream>
using namespace std;

void moveDisks(int numDisks, int fromTower, int targetTower, int spareTower)
{
    static int count = 1;
    if(numDisks > 0)
    {
        moveDisks(numDisks-1, fromTower, spareTower, targetTower);
        cout << count++ << " Move disk from tower #" << fromTower << " to tower #" << targetTower<< endl;
        moveDisks(numDisks - 1, spareTower, targetTower, fromTower);
    }
}

int main()
{
    int numDisks = 9;
    moveDisks(numDisks, 1, 3, 2);   //move 5 disks from tower 1 to tower 3 using
    return 0;                       //tower 2 as the intermediate tower
}
