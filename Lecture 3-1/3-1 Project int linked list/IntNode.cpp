#include<iostream>
#include "IntNode.h"
using namespace std;

int recursiveSearchAndCount(IntNodePtr ptr, int key)
{
    if(ptr == nullptr)
    {
        return 0;
    }
    else
    {
        if(ptr->getData() == key)
        {
            return 1 + recursiveSearchAndCount(ptr->getLink(), key);
        }
        else
        {
            return /*0 +*/ recursiveSearchAndCount(ptr->getLink(), key);
        }
    }
}

int searchAndCount(IntNodePtr head, int key)
{
    IntNodePtr temp = head;
    int count = 0;
    while(temp != nullptr)
    {
        if(temp->getData() == key)
        {
            count++;
        }
        temp = temp->getLink();
    }
    return count;
}

int recursiveCountNodes(IntNodePtr ptr)
{
    if(ptr == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + recursiveCountNodes(ptr->getLink());
    }
}

int countNodes(IntNodePtr head)
{
    IntNodePtr temp = head;
    int count = 0;
    while(temp != nullptr)
    {
        count++;
        temp = temp ->getLink();
    }
    return count;
}

void deleteNode(IntNodePtr &head, int target)
{
    if(head == nullptr)                     //1. Empty List
    {
        cout << "Cannot delete from empty list." << endl;
    }
    else
    {
        IntNodePtr pred = head, temp = head -> getLink();
        if(pred -> getData() == target)     //2. Delete 1st item
        {
            cout << "Deleted item successfully." << endl;
            head = temp;    //head now points to second item in the list
            delete pred;
        }
        else
        {
            while((temp -> getData() != target) && (temp -> getLink() != nullptr))
            {
                pred = temp;
                temp = temp -> getLink();
            }
            if(temp -> getData() == target)
            {
                pred -> setLink(temp -> getLink());
                delete temp;
                cout << "Deleted item successfully." << endl;
            }
            else
            {
                cout << "Item was not found in the list." << endl;
            }
        }
    }
}

void insert(IntNodePtr afterMe, int theData)
{
    IntNodePtr temp = nullptr;
    temp = new IntNode(theData, afterMe -> getLink());
    afterMe -> setLink(temp);

    //afterMe -> setLink(new IntNode(theData, afterMe -> getLink()));
}

void tailInsert(IntNodePtr &head, int theData) //head has to point to inserted item
{
    if(head == nullptr)                     //Empty list???
    {
        head = new IntNode(theData, head);
    }
    else                                    //Normal case
    {
        IntNodePtr temp = nullptr, next = nullptr;
        temp = head;                        //points to 1st node in the list
        next = head -> getLink();           //points to 2nd node in the list
        while(next != nullptr)
        {
            temp = next;
            next = next -> getLink();
        }
        insert(temp, theData);  //calls insert function
    }

}


void display(IntNodePtr head)
{
    IntNodePtr temp = head;
    cout << "Head:";
    while(temp !=nullptr)
    {
        cout << " -> " << temp -> getData();
        temp = temp -> getLink();
    }
    cout << endl;
}

void headInsert(IntNodePtr &head, int theData)
{
    head = new IntNode(theData, head);
}

IntNode::IntNode()
{
    data = 0;
    link = nullptr;
}

IntNode::IntNode(int theData, IntNodePtr theLink)
{
    data = theData;
    link = theLink;
}

void IntNode::setData(int theData)
{
    data = theData;
}

void IntNode::setLink(IntNodePtr theLink)
{
    link = theLink;
}

int IntNode::getData() const
{
    return data;
}

IntNodePtr IntNode::getLink() const
{
    return link;
}


