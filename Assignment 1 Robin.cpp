
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


const int maxSt = 100;


int fileRead(string[], int[]);

void filePrint(string[], int[], int);

void selectionSort(string[], int[], int num);


int linearSearch(int[], int, int);


int main()
{
    int numStudents;
    string studentNames[maxSt];
    int studentID[maxSt];
    int guess = 0, result;

    numStudents = fileRead(studentNames, studentID);

    filePrint(studentNames, studentID, numStudents);

    selectionSort(studentNames,studentID, numStudents);

    cout << endl << endl;
    cout << "Names in A-Z Order: " << endl;
    filePrint(studentNames, studentID, numStudents);
    cout << endl;

    cout << "Input student ID: " << endl;
    cin >> guess;

    result = linearSearch(studentID, numStudents, guess);


    if(result != -1)
    {
        cout << "Student: " << studentNames[result];
    }
    else
    {
        cout << "No student was found with that ID." << endl;
    }



    //cout << "Number of students read (DEBUG): " << numStudents << endl;


    return 0;
}


int fileRead(string names[],int studentIdent[])
{
    int count = 0;
    int i = 0;
    ifstream studentFile;
    studentFile.open("students.txt");

    if (studentFile.fail())
    {
      cout << "Error opening file" << endl;
      exit(1);
    }


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
