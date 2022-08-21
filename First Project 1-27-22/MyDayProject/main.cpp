#include <iostream>
#include "dayType.h"    //includes the class implementation
using namespace std;

int main()
{
    dayType today("Tuesday");
    cout << "Tomorrow is " << today.nextDay() << endl;
/*
    dayType newDay;
    cout << newDay.getWeekDay() << endl;

    dayType otherDay("Thursday");
    cout << otherDay.getWeekDay() << endl;

    otherDay.setWeekDay("Friday");
    cout << otherDay.getWeekDay() << endl;

*/
    return 0;
}
