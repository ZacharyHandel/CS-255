/*
Name- Zachary Handel
Assignment- Assignment 8
Due Date- March 9th, 2022
Description- This is the implimentation file for Assignment 8
*/
#include <iostream>
#include <iomanip>
#include "Pets.h"
using namespace std;

/*
Name- Pets()
Description- Default Constructor
Input- None
Output- Default Values
Return- None
*/
Pets::Pets()
{
	name = " ";
	type = " ";
	age = 0;
	link = nullptr;
}

/*
Name- Pets(string inName, string inType, int inAge, PetsPtr inLink)
Description- Constructor
Input- Name, type, age, and link
Output- Values for members in class
Return- Non
*/
Pets::Pets(string inName, string inType, int inAge, PetsPtr inLink)
{
	name = inName;
	type = inType;
	age = inAge;
	link = inLink;

	//cout << "DEBUGGING FOR CONSTRUCTOR: " << endl << "inName: " << inName << endl << "inType: " << inType << endl
		 //<< "inAge: " << inAge << endl;
}

/*
Name- PrintAvgRec(PetsPtr ptr)
Description- Finds average of pet ages using recursion
Input- Pointer
Output- None
Return- Sum + function recursion
*/
int PrintAvgRec(PetsPtr ptr)
{
	int count = 0;
	int sum = 0;
	int avg = 0;

	if(ptr != nullptr)
	{
		count++;
		cout << "Count: " << count << endl;
		sum += ptr->getAge();
		return PrintAvgRec(ptr->getLink()) / count;
	}
	else
	{
		return 0;
	}
}

/*
Name- PrintAvgIt(PetsPtr head)
Description- Finds average of pet ages using iteration
Input- Head pointer
Output- None
Return- Average of pet ages
*/
int PrintAvgIt(PetsPtr head)
{
	PetsPtr temp = head;
	int count = 0;
	int sum = 0;
	while (temp != nullptr)
	{
		count++;
		sum += temp->getAge();
		temp = temp->getLink();
	}
	return sum / count;
}

/*
Name- DeleteNode(PetsPtr& head, string target)
Description- This function will delete a node of the linked list given a pet name
Input- Head node, target name
Output- Prompt that node was deleted
Return- None
*/
void DeleteNode(PetsPtr& head, string target)
{
	if (head == nullptr)
	{
		cout << "Cannot delete from empty list." << endl;
	}
	else
	{
		PetsPtr pred = head, temp = head->getLink();
		if (pred->getName() == target)
		{
			cout << "Deleted Item Successfully." << endl;
			head = temp;
			delete pred;
		}
		else
		{
			while ((temp->getName() != target) && (temp->getLink() != nullptr))
			{
				pred = temp;
				temp = temp->getLink();
			}
			if (temp->getName() == target)
			{
				pred->setLink(temp->getLink());
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

/*
Name- insert(PetsPtr afterMe, string inName, string inType, int inAge)
Description- insert function used for tail insert in order to determine nullptr detection
Input- ptr and animal data
Output- None
Return- None
*/
void insert(PetsPtr afterMe, string inName, string inType, int inAge)
{
	PetsPtr temp = nullptr;
	temp = new Pets(inName, inType, inAge, afterMe->getLink());
	afterMe->setLink(temp);
}

/*
Name- SearchType(PetsPtr head, string key)
Description- Searches a pet based on the type of animal inputted from the user
Input- Head Node and target animal
Output- Data matching type given
Return- None
*/
void SearchType(PetsPtr head, string key)
{
	PetsPtr temp = head;

	while (temp != nullptr)
	{
		if (temp->getType() == key)
		{
			cout << temp->getName() << ", " << temp->getAge() << endl;
		}
		else
		{
			cout << "This type of animal is not in the list" << endl;
		}
		temp = temp->getLink();
	}
}

/*
Name- TailInsert(PetsPtr& head, string inName, string inType, int inAge)
Description- inserts data to the tail of the list
Input- name, type, and age of animal; head node
Output- none
Return- none
*/
void TailInsert(PetsPtr& head, string inName, string inType, int inAge)
{
	if (head == nullptr)
	{
		head = new Pets(inName, inType, inAge, head);
	}
	else
	{
		PetsPtr temp = nullptr, next = nullptr;
		temp = head;
		next = head->getLink();
		while (next != nullptr)
		{
			temp = next;
			next = next->getLink();
		}
		insert(temp, inName, inType, inAge);
	}
}

/*
Name- Display(PetsPtr head)
Description- displays data in list
Input- head node
Output- list data
Return- none
*/
void Display(PetsPtr head)
{
	PetsPtr temp = head;
	cout << "Head: ";
	while (temp != nullptr)
	{
		cout << temp->getName() << ", " << temp->getType() << ", " << temp->getAge() << " -> ";
		temp = temp->getLink();
	}
	cout << endl;
}

/*
Name- HeadInsert(PetsPtr &head, string inName, string inType, int inAge)
Description- inserts data to the head of the list
Input- head node, name, type, and age of animal
Output- None
*/
void HeadInsert(PetsPtr &head, string inName, string inType, int inAge)
{
	head = new Pets(inName, inType, inAge, head);
	// << "DEBUGGING FOR Head Insert: " << endl;
	//cout << "Name: " <<  head->getName() << endl;
	//cout << "Type: " << head->getType() << endl;
	//cout << "Age: " << head->getAge() << endl;
	//DisplayList(head);
}

/*
Name- Display(PetsPtr head)
Description- displays data in list
Input- head node
Output- list data
Return- none
*/
void DisplayList(PetsPtr head)
{
	PetsPtr temp = head;
	//cout << "Debugging for Display List: " << endl;
	//cout << "List: " << endl;
	if (temp == nullptr)
	{
		cout << "You must add to list before you can display it." << endl;
	}
	else
	{
		while (temp != nullptr)
		{
			cout << temp->getName() << ", " << temp->getType() << ", " << temp->getAge() << " -> ";
			temp = temp->getLink();
		}
		cout << endl;
	}


}

/*
Name- ChooseMenuItem(PetsPtr head)
Description- Allows user to choose menu items displayed
Input- head node
Output- prompt for list choice
Return- none
*/
void ChooseMenuItem(PetsPtr head)
{

	int choice;
	string tempName, tempType;
	int tempAge;
	cin >> choice;
	if (choice == 1)
	{
		cout << "1" << endl;
		DisplayList(head);
	}
	else if (choice == 2)
	{
		cout << "insert the name, type, and age of the animal to the head of the list: " << endl;
		cin >> tempName >> tempType >> tempAge;
		HeadInsert(head, tempName, tempType ,tempAge);


	}
	else if (choice == 3)
	{
		cout << "insert the name, type, and age of the animal to the tail of the list: " << endl;
		cin >> tempName >> tempType >> tempAge;
		TailInsert(head, tempName, tempType, tempAge);
	}
	else if (choice == 4)
	{
		string key;
		cout << "Search for type of animal to display all names and ages of that type: " << endl;
		cin >> key;
		SearchType(head, key);
	}
	else if (choice == 5)
	{
		string tempTarget;
		cout << "Input pets name to delete it's information from the list: " << endl;
		cin >> tempTarget;
		DeleteNode(head, tempTarget); 
	}
	else if (choice == 6)
	{
		cout << "Average of Ages (Iterative): " << PrintAvgIt(head) << endl;
	}
	else if (choice == 7)
	{
		cout << "Average of Ages (Recursive): " << PrintAvgRec(head) << endl;
	}
	else if (choice == 8)
	{
		cout << "Goodbye!" << endl;
		exit(0);
	}
	else
	{
		cout << "Not an option." << endl;
		//DisplayMenu();
		//ChooseMenuItem();
	}
	DisplayMenu(head);
}

/*
Name- DisplayMenu(PetsPtr head)
Description- displays menu for user
Input- head node
Output- Menu
Return- None
*/
void DisplayMenu(PetsPtr head)
{
	cout << "Menu" << endl;
	cout << "1. Display List" << endl;
	cout << "2. Add to head of list" << endl;
	cout << "3. Add to tail of list" << endl;
	cout << "4. Search type of animal" << endl;
	cout << "5. Delete pet name" << endl;
	cout << "6. Display the average of pet age (iterative)" << endl;
	cout << "7. Display average age for all pets (recursive)" << endl;
	cout << "8. Quit" << endl;
	ChooseMenuItem(head);
}

/*
Name- setName(string inName)
Description- setter for name
Input- inName
Output- none
Return- none
*/
void Pets::setName(string inName)
{
	name = inName;
}

/*
Name- setType(string inType)
Description- setter for type
Input- inType
Output- none
Return- none
*/
void Pets::setType(string inType)
{
	type = inType;
}

/*
Name- setAge(int inAge)
Description- setter for age
Input- inAge
Output- none
Return- none
*/
void Pets::setAge(int inAge)
{
	age = inAge;
}
/*
Name- setLink(PetsPtr inLink)
Description- setter for link
Input- inLink
Output- none
Return- none
*/
void Pets::setLink(PetsPtr inLink)
{
	link = inLink;
}

/*
Name- getName()
Description- getter for name
Input- none
Output- none
Return- name
*/
string Pets::getName() const
{
	return name;
}

/*
Name- getType()
Description- getter for type
Input- none
Output- none
Return- type
*/
string Pets::getType() const
{
	return type;
}

/*
Name- getAge()
Description- getter for age
Input- none
Output- none
Return- age
*/
int Pets::getAge() const
{
	return age;
}

/*
Name- getLink()
Description- getter for link
Input- none
Output- none
Return- link
*/
PetsPtr Pets::getLink() const
{
	return link;
}

