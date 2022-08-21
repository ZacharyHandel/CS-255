#include "stringNode.h"
#include <iostream>
using namespace std;

class Queue
{
	private:
		stringNodePtr front, rear;
	public:
		Queue();		//constructor
		void enqueue(string theItem);
		string dequeue();
		bool empty();
		bool full();
		void display();
};
