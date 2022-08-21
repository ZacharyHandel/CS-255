#include <iostream>
#include "IntNode.h"
using namespace std;


int main()
{
    IntNodePtr head = nullptr;

    headInsert(head, 63);
    headInsert(head, 25);
    headInsert(head, 25);
    headInsert(head, 25);
    headInsert(head, 25);
    headInsert(head, 47);   //points to whatever head was pointing to
    tailInsert(head, 13);
    display(head);

    cout << countNodes(head) << " items in the list." << endl;
    cout << recursiveCountNodes(head) << " items in the list (recursive)." << endl;

    deleteNode(head, 47);
    display(head);
    cout << countNodes(head) << " items in the list." << endl;
    cout << recursiveCountNodes(head) << " items in the list (recursive)." << endl;

    cout << "47 appears in the list this many times: " << searchAndCount(head, 25) << endl;
    cout << "88 appears in the list this many times: " << searchAndCount(head, 88) << endl;

    cout << "REC: 47 appears in the list this many times: " << recursiveSearchAndCount(head, 25) << endl;
    cout << "REC: 88 appears in the list this many times: " << recursiveSearchAndCount(head, 88) << endl;


    return 0;
}
