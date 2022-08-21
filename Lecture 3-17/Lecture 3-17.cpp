//Stacks
	//Think of adding things to the top of a table
	//When we add things onto a stack, we 'push' them
		//push(item)
	//to remove things from a stack, you would 'pop' them
		//item = pop
	//Stacks work LIFO (last in, first out)
	//Stacks are also considered abstract data types (just like linked lists)
		//item = st.pop() or st.push()
	//We always have to see if the stack is empty, empty()?
	//Stacks can also get full, full()?
	//The way we make a stack is the implimentation

#include<iostream>
using namespace std;

class IntNode;	//forward declaration

typedef IntNode* IntNodePtr;

class IntNode
{
	private:
		int data;
		IntNodePtr link;
	public:
		IntNode(int theData, IntNodePtr theLink) { data = theData; link = theLink; }	//define 'in house'
		int getData() const { return data; }
		void setData(int theData) { data = theData; }
		IntNodePtr getLink() const { return link; }
		void setLink(IntNodePtr theLink) { link = theLink; }

};

class Stack
{
	private:
		IntNodePtr top;
	public:
		Stack();
		~Stack();
		bool empty() const { return (top == nullptr); }
		bool full() const { return false; }
		void push(int intData);
		int pop();	//returns item
};

Stack::~Stack()
{
    int dummy = 0;
	while(!empty())
    {
        dummy = pop();
        ///Debug for destructor
        //cout << dummy << " is popped off the stack" << endl;
    }
}

Stack::Stack()
{
	top = nullptr;

}

void Stack::push(int inData)
{
	if (!full())
	{
		//make temp equal a new node,
		IntNodePtr temp = new IntNode(inData, top);
		top = temp;
	}
	else
	{
		cout << "You cannot push onto a full stack." << endl;
	}
}

int Stack::pop()
{
	int value = 0;
	if (empty())
	{
		cout << "You cannot pop from an empty stack." << endl;
	}
	else
	{
		value = top->getData();
		IntNodePtr temp = top;
		top = top->getLink();
		delete temp;
	}
	return value;
}

int main()
{
	Stack st;
	st.push(23);
	st.push(67);
	st.push(85);
	st.push(99);

	//int item = st.pop();
	//cout << item << " was just poped off the stack." << endl;
	return 0;
}

