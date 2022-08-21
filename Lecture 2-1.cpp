#include <iostream>
using namespace std;

void fun()
{
    int a = 0;
    static int b = 0;   //value does not start over every time we come back to the function
    a++;
    b++;
    cout << "a is " << a << endl << "b is " << b << endl;
}

int main()
{
    fun();
    fun();
    fun();
    return 0;
}
