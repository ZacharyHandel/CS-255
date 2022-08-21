//Recursive Functions Cont.
#include <iostream>
using namespace std;

int numChars(string st, char ch, int spot = 0)
{
    if(st.length() == spot)
    {
        return 0;
    }
    else
    {
        if(st[spot] == ch)
        {
            return 1 + numChars(st, ch, spot + 1);
        }
        else
        {
            return numChars(st, ch, spot + 1);
        }
    }
}

int binarySearch(int array[], int first, int last, int key)
{
    if(first > last)
    {
        return -1;
    }
    else
    {
        int middle = (first + last)/2;
        if(array[middle] == key)
        {
            return middle;
        }
        if(array[middle < key])
        {
            return binarySearch(array, middle + 1, last, key);
        }
        else
        {
            return binarySearch(array, first, middle - 1, key);
        }
    }
}

int const MAX_INT = 10;
int main()
{
    string st = "acbacbacbacbacb";
    char ch = 'c';
    cout << numChars(st, ch) << endl;


    int array[MAX_INT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key;
    cout << "Input a key: " << endl;
    cin >> key;

    int position = binarySearch(array, 0, MAX_INT-1, key);
    if(position == -1)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Item was found at position " << position << endl;
    }

    return 0;
}
