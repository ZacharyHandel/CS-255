#pragma once
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <random>
#include <fstream>
class Customer
{
private:
    int arrivalTime;
    int departureTime;
    int serviceTime;
    int processTime;
public:
    Customer();
    void setArrivalTime(int Atime);
    void setDepartureTime(int Dtime);
    void setServiceTime(int Stime);
    void setProcessTime(int Ptime);
    int getArrivalTime();
    int getDepartureTime();
    int getServiceTime();
    int getProcessTime();
};

