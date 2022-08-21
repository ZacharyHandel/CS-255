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
#include<fstream>
using namespace std;

class stringNode;	//forward declaration

typedef stringNode* stringNodePtr;

class stringNode
{
	private:
		string data;
		stringNodePtr link;
	public:
		stringNode(string theData, stringNodePtr theLink) { data = theData; link = theLink; }	//define 'in house'
		string getData() const { return data; }
		void setData(string theData) { data = theData; }
		stringNodePtr getLink() const { return link; }
		void setLink(stringNodePtr theLink) { link = theLink; }

};

class Stack
{
	private:
		stringNodePtr top;
	public:
		Stack();
		~Stack();
		bool empty() const { return (top == nullptr); }
		bool full() const { return false; }
		void push(string stringData);
		string pop();	//returns item
		void clearStack();
};

Stack::~Stack()
{
    string dummy = "";
	while(!empty())
    {
        dummy = pop();
        ///Debug for destructor
        //cout << dummy << " is popped off the stack" << endl;
    }
}

void Stack::clearStack()
{
    string dummy = "";
	while(!empty())
    {
        dummy = pop();
    }
}

Stack::Stack()
{
	top = nullptr;

}

void Stack::push(string inData)
{
	if (!full())
	{
		//make temp equal a new node,
		stringNodePtr temp = new stringNode(inData, top);
		top = temp;
	}
	else
	{
		cout << "You cannot push onto a full stack." << endl;
	}
}

string Stack::pop()
{
	string value = "";
	if (empty())
	{
		cout << "You cannot pop from an empty stack." << endl;
	}
	else
	{
		value = top->getData();
		stringNodePtr temp = top;
		top = top->getLink();
		delete temp;
	}
	return value;
}

int main()
{
	Stack st;
	double gpa = 0, highGPA = -1;
    string name = "";
    ifstream infile("StudentGPAData.txt");
    while (infile >> gpa >> name)
    {
        if(gpa > highGPA)
        {
            st.clearStack();
            st.push(name);
            highGPA = gpa;
        }
        else if(gpa == highGPA)
        {
            if(!st.full())
            {
                st.push(name);
            }
            else
            {
                cout << "Stack is full... program terminating." << endl;
                exit(0);
            }
        }
    }
    infile.close();

    cout << "The highest GPA: " << highGPA << endl;
    cout << "Student(s) with that GPA: ";

    while(!st.empty())
    {
        cout << st.pop() << ", ";
    }
    cout << endl;

}

