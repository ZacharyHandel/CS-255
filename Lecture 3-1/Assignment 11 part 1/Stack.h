class Stack
{
	private:
		int maxSize;
		int top;
		double* array;
	public:
		Stack(int inMaxSize);
		~Stack();
		void push(double inData);
		double pop();
		bool empty() const;
		bool full() const;
		void display();
};
