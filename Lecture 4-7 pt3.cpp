//Poisson Distribution
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main()
{
    default_random_engine generator(time(0));

    normal_distribution<double> exams(70, 10);

    double score = 0;

    for(int i = 0; i < 10; i++)
    {
    score = exams(generator);
    cout << score << endl;
    }


    return 0;
}
