/*
 Price Howard
 CS 255
 Program is designed to take customers into a queue, process them, and then remove the from the queue and print their information to a file.
07/28/19
 */
#include <iostream>
#include "Customer.h"
#include "Queue.h"
int main()
{
    Queue st;
    int tick=0,numberOfArrivals=0;
    default_random_engine generator;
    normal_distribution<double> arrivalDist(.8,2);
    while(tick<60)
    {
      // cout<< int(arrivalDist(generator))<<endl;
        numberOfArrivals=int(arrivalDist(generator));
        st.Update(tick,numberOfArrivals);//Passing the clock tick and the number of people arriving per tick.
        tick++;
    }
    cout<<endl<<"The Number Of Customers That Were rejected: "<<st.getRejectedCustomer()<<endl;
    cout<<"The Number Of Customers That Were Accepted: "<<st.getAcceptedCustomer()<<endl;
    cout<<"The Average Wait Time Was: "<<st.getAverageWaitTime()<<endl;
    return 0;
}
