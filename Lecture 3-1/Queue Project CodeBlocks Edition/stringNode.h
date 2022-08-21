#include <iostream>
using namespace std;
class stringNode;
typedef stringNode* stringNodePtr;

class stringNode
{
	private:
		string data;
		stringNodePtr link;
	public:
		stringNode(string theData, stringNodePtr theLink);	//constructor
		string getData() const;
		stringNodePtr getLink() const;
		void setData(string theData);
		void setLink(stringNodePtr theLink);
};
