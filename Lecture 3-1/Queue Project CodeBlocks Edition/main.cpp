#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
	Queue queue;
	queue.enqueue("Steve");
	queue.enqueue("Jill");
	queue.display();
	cout << queue.dequeue() << endl;
	queue.display();
	return 0;
}
