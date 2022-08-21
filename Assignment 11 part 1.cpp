#include <iostream>
using namespace std;


//define the stack
class Stack
{
	private:
		int maxSize;
		int top;
		string* array;
	public:
		Stack(int inMaxSize);
		~Stack();
		void push(string inData);
		string pop();
		bool empty() const;
		bool full() const;
		void display();
};
