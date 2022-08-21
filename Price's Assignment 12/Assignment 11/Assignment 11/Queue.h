const int MAX_QUEUE_SIZE=5;
#include "Customer.h"
using namespace std;
class Queue
{
private:
    int front;
    int rear;
    int count;
    int rejectedCustomer;
    int acceptedCustomer;
    int customerNumber;
    double averageWaitTime;
    Customer customerArray[MAX_QUEUE_SIZE];
public:
    Queue();
    ~Queue();
    bool queueFull();
    bool queueEmpty();
    void Enqueue(int arriveTime, int serviceTime);
    double Dequeue();
    void Update(int clockTick,int &incomingCustomers);
    void printToFile(double queueReturn);
    int getRejectedCustomer();
    int getAcceptedCustomer();
    void updateRejectedCustomer();
    void updateAcceptedCustomer();
    double getAverageWaitTime();
    ofstream outFile;
};
