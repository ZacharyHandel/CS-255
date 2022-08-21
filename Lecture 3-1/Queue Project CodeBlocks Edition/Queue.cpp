#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
}
void Queue::enqueue(string theItem)
{
	if (full())
	{
		cout << "Cannot add to the queue since it is full" << endl;
	}
	else
	{
		stringNodePtr temp = new stringNode(theItem, nullptr);
		if (empty())	//no nodes in the queue
		{
			front = temp;
		}
		else	//atleast one node is in the queue
		{
			rear->setLink(temp);
		}
		rear = temp;
	}
}
string Queue::dequeue()
{
	string item = "";
	if (empty())
	{
		cout << "Cannot remove an item from an empty queue." << endl;
	}
	else
	{
		stringNodePtr temp = front;
		item = temp->getData();		//OR	item = front->getData();
		front = temp->getLink();	//OR	front = front->getLink();
		delete temp;
		if (front == nullptr)	//we removed the only item in the queue
		{
			rear = nullptr;
		}
	}
	return item;
}
bool Queue::empty()
{
	if (front == nullptr)	//return front == nullptr
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Queue::full()	//only if program runs out of memory
{
	return false;
}
void Queue::display()
{
	if (empty())
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
	    cout << "FRONT ";
		stringNodePtr temp = front;
		while (temp != nullptr)
		{
			cout << temp->getData() << " <- ";
			temp = temp->getLink();
		}
		cout << "BACK";
	}
}
