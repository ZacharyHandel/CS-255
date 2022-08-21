#include<iostream>
#include "Customer.h"
using namespace std;
/*
 Name: Customer
 Purpose: Constructer setting the customers times to 0.
 Incoming: N/A
 Outgoing: N/A
 Return: Void
 */
Customer::Customer()
{
    arrivalTime=0;
    serviceTime=0;
    processTime=0;
    departureTime=0;
}
/*
 Name: setArrivalTime
 Purpose: To set the time of arrival equal to the incoming time.
 Incoming: Atime (Int)
 Outgoing: N/A
 Return: Void
 */
void Customer::setArrivalTime(int Atime)
{
    arrivalTime=Atime;
}
/*
 Name: setDepartureTime
 Purpose: To set the time of departure equal to the incoming time.
 Incoming: Dtime (Int)
 Outgoing: N/A
 Return: Void
 */
void Customer::setDepartureTime(int Dtime)
{
    departureTime=Dtime;
}
/*
 Name: setServiceTime
 Purpose: To set the time of service equal to the incoming time.
 Incoming: Stime (Int)
 Outgoing: N/A
 Return: Void
 */
void Customer::setServiceTime(int Stime)
{
    serviceTime=Stime;
}
/*
 Name: setProcessTime
 Purpose: To set the time of process equal to the incoming time.
 Incoming: Ptime (Int)
 Outgoing: N/A
 Return: Void
 */
void Customer::setProcessTime(int Ptime)
{
    processTime=Ptime;
}
/*
 Name: getArrivalTime
 Purpose: To return the arrival time.
 Incoming: N/A
 Outgoing: arrivalTime
 Return: Int
 */
int Customer::getArrivalTime()
{
    return arrivalTime;
}
/*
 Name: getDepartureTime
 Purpose: To return the departure time.
 Incoming: N/A
 Outgoing: departureTime
 Return: Int
 */
int Customer::getDepartureTime()
{
    return departureTime;
}
/*
 Name: getServiceTime
 Purpose: To return the service time.
 Incoming: N/A
 Outgoing: serviceTime
 Return: Int
 */
int Customer::getServiceTime()
{
    return serviceTime;
}
/*
 Name: getProcessTime
 Purpose: To return the process time.
 Incoming: N/A
 Outgoing: processTime
 Return: Int
 */
int Customer::getProcessTime()
{
    return processTime;
}

