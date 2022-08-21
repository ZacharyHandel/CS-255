#include<iostream>
#include"Stack.h"

using namespace std;

int main()
{
    int numElements;
    double userInput;
    cout << "How many decimal numbers?: ";
    cin >> numElements;

    Stack st(numElements);

    for(int i = 0; i < numElements; i++)
    {
        cout << "Input #" << i+1 << "?";
        cin >> userInput;
        st.push(userInput);
    }
    cout << "Output: ";
    st.display();
}
