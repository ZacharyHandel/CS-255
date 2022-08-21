/*
Name- Zachary Handel
Course- CS-255
Assignment- Assignment 1
Due Date- Jan 12, 2022

Description- This program reads in a file containing students first names
followed by a 5-digit ID. The program will store this information using
parallel arrays. It will contain 4 functions: one that reads the file into
they array and updates the number of students read from the file. One will
print the contents of the arrays including column headings. One will sort
the arrays alphabetically using a swap method. One will search for a student
based on the ID. It will then return the position of the matching item
(-1 if it does not exist).
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


const int maxSt = 100;  //create size of array

/*
Name- fileRead
Incoming- string array for student names, int array for student ID
Outgoing- Number of students read from file

Return- number of names read
*/
int fileRead(string[], int[]);

/*
Name- filePrint
Incoming- string array, number of names read
Outgoing- N/A
Return- N/A
*/
void filePrint(string[], int[], int);

/*
Name- selectionSort
Incoming- string array for student names, int array for student ID,
int for number of students
Outgoing- N/A
Return- N/A
*/
void selectionSort(string[], int[], int num);

/*
Name- linearSearch
Incoming- int array, number of elements, key
Outgoing- position
Return- -1
*/

int linearSearch(int[], int, int);


int main()
{
    int numStudents;
    string studentNames[maxSt];
    int studentID[maxSt];
    int guess, result;

    numStudents = fileRead(studentNames, studentID);

    filePrint(studentNames, studentID, numStudents);

    selectionSort(studentNames,studentID, numStudents);

    cout << endl << endl;
    cout << "Names in A-Z Order: " << endl;
    filePrint(studentNames, studentID, numStudents);
    cout << endl;

    cout << "Input a student ID: " << endl;
    cin >> guess;


    //result = linearSearch(studentID, numStudents, guess);



    //cout << "Number of students read (DEBUG): " << numStudents << endl;

    /*cout << "Student Names Debug: " << endl;
    for(int i = 0; i < numStudents; i++)
    {
        cout << studentNames[i] << endl;
    }*/

    /*cout << "Student ID Debug" << endl;
    for(int j = 0; j < numStudents; j++)
    {
        cout << studentID[j] << endl;
    }*/




}


int fileRead(string names[],int studentIdent[])
{
    int count;
    int i = 0;
    ifstream studentFile;
    studentFile.open("students-1.txt");

    while(!studentFile.eof())
    {
        count++;
        studentFile >> names[i] >> studentIdent[i];
        i++;
    }

    return count;

}

void filePrint(string names[], int studentIdent[], int s)
{

    cout << setfill(' ') << "Names" << setw(7) << "ID" << endl; //Header

    for(int i = 0; i < s; i++)
    {
       cout << left << setw(10) << setfill(' ') << names[i] <<
       right << setw(5) << setfill('0') << studentIdent[i] << endl;
    }
}

void selectionSort(string names[], int studentID[], int num)
{
    string tempName;
    int temp = 0, minIndex = 0;
    for(int i = 0; i < num-1; i++)
    {
        minIndex = i;
        for(int j = i+1; j < num; j++)
        {
            if(names[j] < names[minIndex])
            {
                minIndex = j;
            }
        }
        tempName = names[i];
        temp = studentID[i];
        names[i] = names[minIndex];
        studentID[i] = studentID[minIndex];
        names[minIndex] = tempName;
        studentID[minIndex] = temp;
    }
}

int linearSearch(int data[], int numElements, int key)
{
    bool found = false;
    int position = 0;
    while (!found && position < numElements)
    {
        if(data[position] == key)
        {
            found = true;
        }
        else
        {
            position++;
        }
    }
    if(found)
    {
        return position;
    }
    else
    {
        return -1;
    }


    }
