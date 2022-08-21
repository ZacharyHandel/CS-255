#include "stringNode.h"
using namespace std;

stringNode::stringNode(string theData, stringNodePtr theLink)
{
	data = theData;
	link = theLink;
}
string stringNode::getData() const
{
	return data;
}
stringNodePtr stringNode::getLink() const
{
	return link;
}
void stringNode::setData(string theData)
{
	data = theData;
}
void stringNode::setLink(stringNodePtr theLink)
{
	link = theLink;
}
