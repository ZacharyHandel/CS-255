#include "Queue.h"
#include "Customer.h"
#include <iostream>
using namespace std;
/*
 Name: Queue
 Purpose: Constructer setting the variables in the queue to 0 except for rear set to -1 and also opening the file.
 Incoming: N/A
 Outgoing: N/A
 Return: Void
 */
Queue::Queue()
{
    rejectedCustomer=0;
    acceptedCustomer=0;
    customerNumber=1;
    averageWaitTime=0;
    front=0;
    rear=-1;
    count=0;
    outFile.open("QueueOutput.txt");
}
/*
 Name: ~Queue
 Purpose: Deconstructer that emptys the queue and closes the file..
 Incoming: None
 Outgoing: N/A
 Return: Void
 */
Queue::~Queue()
{
    outFile.close();
    while(count!=0)
    {
        Dequeue();
    }
}
/*
 Name: queueFull
 Purpose: To return true if the queue is full and false if its not full.
 Incoming: None
 Outgoing: True or False
 Return: Bool
 */
bool Queue::queueFull()
{
    if((count)==MAX_QUEUE_SIZE)
        return true;
    else
        return false;
}
/*
 Name: queueEmpty
 Purpose: To return true if the queue is empty and false if its not empty.
 Incoming: None
 Outgoing: True or False
 Return: Bool
 */
bool Queue::queueEmpty()
{
    if(count==0)
        return true;
    else
        return false;
}
/*
 Name: Enqueue
 Purpose: To input a customer into the queue.
 Incoming: arriveTime (Int), serveTime (Int).
 Outgoing: N/A
 Return: Void
 */
void Queue::Enqueue(int arriveTime, int serveTime)
{
        if(serveTime<=0)
        {
            serveTime=1;
    
        }
        rear=((rear+1)%MAX_QUEUE_SIZE);
        customerArray[rear].setArrivalTime(arriveTime);
        customerArray[rear].setServiceTime(serveTime);
        customerArray[rear].setProcessTime(0);
        count++;
}
/*
 Name: Dequeue
 Purpose: To remove a customer from the queue if the process time equals the service time. It will calculate the   wait time of the customer. It will also call the dump to file function to print it to the file.
 Incoming: N/A
 Outgoing: customerWaitTime
 Return: Double
 */
double Queue::Dequeue()
{
    double customerWaitTime=0;
    if(queueEmpty())
    {
        cout<<"Queue is Empty!";
    }
    else
    {
        customerWaitTime=(customerArray[front].getDepartureTime() - customerArray[front].getArrivalTime() - customerArray[front].getServiceTime());
        printToFile(customerWaitTime);
        count--;
    }
    return customerWaitTime;
}
/*
 Name: Update
 Purpose: This function is designed to take a clock tick input and the number of customers from main and calculate a service time. It will then see if the queue is full if it isnt it will add to process time of the front customer in the queue. It will then check to see if that customers process time is equal to the service time. If it is it will call dequeue add one to accepted customers and update front. If its not it will check to see if more than one customer was inputed. If there is it will check if full. If the queue is full it'll output the queue is full and call rejected customers. If its not full it will enqueue the customer into the queue.
 Incoming: clockTick (Int), invomingCustomers (& Int)
 Outgoing: N/A
 Return: Void
 */
void Queue::Update(int clockTick,int &incomingCustomers)
{
    default_random_engine generator;
    normal_distribution<double> serviceTimeDist(6,6);
    if(incomingCustomers<0) // Can't have negative customers.
    {
        incomingCustomers=0;
    
    }
    if(!queueEmpty())
    {
        customerArray[front].setProcessTime(customerArray[front].getProcessTime()+1);
        if(customerArray[front].getProcessTime()==customerArray[front].getServiceTime())
        {
            customerArray[front].setDepartureTime(clockTick);
            Dequeue();
            updateAcceptedCustomer();
            front++;
            if(front+1==MAX_QUEUE_SIZE)// Checking if front is at the highest it can be in the queue.
            {
                front=((front+1)%MAX_QUEUE_SIZE);
            }
        }
    }
        while(incomingCustomers>=1) // Checking if there is more than one customer per tick.
        {
            if(queueFull())
            {
                cout<<"The queue is full and cannot take anymore customers as of now. Please come again!"<<endl;
                updateRejectedCustomer();
            }
            else
            {
                Enqueue(clockTick, serviceTimeDist(generator));
            }
                incomingCustomers--;
    }
}
/*
 Name: dumpToFile
 Purpose: To print the queue to the file.
 Incoming: waitTimeReturnFromDequeue (double)
 Outgoing: Printing the queue information to the file.
 Return: Void
 */
void Queue::printToFile(double waitTimeReturnFromDequeue)
{
    outFile<<"Customer #: "<<customerNumber<<endl<<
    "Arrival: "<<customerArray[front].getArrivalTime()<<endl<<
    "Departure: "<<customerArray[front].getDepartureTime()<<endl<<
    "Service: "<<customerArray[front].getServiceTime()<<endl<<
    "Process: "<<customerArray[front].getProcessTime()<<endl<<
    "Wait Time: "<<waitTimeReturnFromDequeue<<endl<<endl;
    customerNumber++; // Adding one to the number of customers the queue has gone through.
    averageWaitTime+=waitTimeReturnFromDequeue;
}
/*
 Name: getRejectedCustomer
 Purpose: To return the number of rejected customers.
 Incoming: N/A
 Outgoing: Printing the number of customers that were rejectedto the file.
 Return: Int
 */
int Queue::getRejectedCustomer()
{
    outFile<<endl<<"The Number Of Customers That Were Rejected: "<<rejectedCustomer<<endl;
    return rejectedCustomer;
}
/*
 Name: getAcceptedCustomer
 Purpose: To return the number of accepted customers.
 Incoming: N/A
 Outgoing: Printing the number of accepted customers to the file.
 Return: Int
 */
int Queue::getAcceptedCustomer()
{
    outFile<<"The Number Of Customers That Were Accepted: "<<acceptedCustomer<<endl;
    return acceptedCustomer;
}
/*
 Name: updateRejectedCustomers
 Purpose: To add one to rejected customers.
 Incoming: N/A
 Outgoing: N/A
 Return: Void
 */
void Queue::updateRejectedCustomer()
{
    rejectedCustomer++;
}
/*
 Name: updateAcceptedCustomer
 Purpose: To add one to accepted customers.
 Incoming: N/A
 Outgoing: N/A
 Return: Void
 */
void Queue::updateAcceptedCustomer()
{
    acceptedCustomer++;
}
/*
 Name: getAverageWaitTime
 Purpose: To calculate the average wait time and print it out to a file and return it.
 Incoming: N/A
 Outgoing: Printing the average wait time to the file, averageWaitTime.
 Return: Double
 */
double Queue::getAverageWaitTime()
{
    averageWaitTime/=acceptedCustomer;
    outFile<<"The Average Wait Time Was: "<<averageWaitTime<<endl;
    return averageWaitTime;
}
