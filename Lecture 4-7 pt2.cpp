//simulation version 1
#include <iostream>
#include <unistd.h>
#include <ctime>
using namespace std;

int main()
{

    int tick = 0, entering = 0, leaving = 0;
    srand(time(0));
    while(tick < 30)
    {
        cout << "Minute: " << tick << endl;

        entering = rand() % 3;
        if(entering > 0)
        {
        cout << entering << " student(s) entering Raburn Hall." << endl;
        }

        leaving = rand() % 3;
        if(leaving > 0)
        {
        cout << leaving << " student(s) leaving Raburn Hall." << endl;
        }
        cout << endl;
        tick++;
        sleep(3);
    }
    return 0;
}
