#include <iostream>
#include <ctime>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree bst;

    bst.insert(60);
    bst.insert(50);
    bst.insert(70);
    bst.insert(80);
    bst.insert(53);
    bst.insert(30);
    bst.insert(75);
    bst.insert(35);
    bst.insert(57);
    bst.insert(40);
    bst.insert(48);
    bst.insert(32);
    bst.insert(45);
    bst.insert(77);
/*
    srand(time(0));
    int items = 800, j = 0, k = 0;
    int array[items];
    int temp = 0;
    for(int i = 0; i < items; i++)
    {
        array[i] = i;
    }

    for(int i = 0; i < items/10; i++)
    {
        j = rand() % items;
        k = rand() % items;
        temp = array[j];
        array [j] = array[k];
        array[k] = temp;
    }

    for(int i = 0; i < items; i++)
    {
        bst.insert(array[i]);
    }
*/
    cout << "Tree height is: " << bst.findHeight() << endl;

    cout << "INORDER:" << endl;
    bst.print_inorder();

    cout << endl << endl;

    cout << "PREORDER:" << endl;
    bst.print_preorder();

    cout << endl << endl;

    cout << "POSTORDER:" << endl;
    bst.print_postorder();

    return 0;
}
