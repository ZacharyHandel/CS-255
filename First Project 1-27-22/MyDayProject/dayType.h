#include <string>
using namespace std;
class dayType
{
    private:
        string weekDay;
    public:
        void setWeekDay(string day);
        string getWeekDay() const;
        dayType();  //Constructor
        dayType(string day);
        string nextDay() const;
};
