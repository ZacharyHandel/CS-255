#include "dayType.h"
#include <string>
void dayType::setWeekDay(string inDay)
{
    weekDay = inDay;
}

string dayType::getWeekDay() const
{
    return weekDay;
}

dayType::dayType()
{
    weekDay = "Sunday";
}

dayType::dayType(string day)
{
   weekDay = day;
}

string dayType::nextDay() const
{
    const int DAYS_OF_WEEK = 7;
    static string weekDays[DAYS_OF_WEEK] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    //
    int theDay = 0;

    for (int i = 0; i < DAYS_OF_WEEK; i++)
    {
        if(weekDays[i] == weekDay)
        {
            theDay = i;
        }
    }
    return weekDays[(theDay + 1) % 7];


}
