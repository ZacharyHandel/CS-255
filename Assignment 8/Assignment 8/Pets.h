/*
Name- Zachary Handel
Assignment- Assignment 8
Due Date- March 9th, 2022
Description- This is the header file for Assigment 8
*/
#include<iostream>
using namespace std;

class Pets;		//Forward Declaration
typedef Pets* PetsPtr;

class Pets
{
	private:
		string name;
		string type;
		int age;
		PetsPtr link;
	public:
		Pets();
		Pets(string inName, string inType, int inAge, PetsPtr inLink);
		void setName(string inName);
		void setType(string inType);
		void setAge(int inAge);
		void setLink(PetsPtr inLink);
		string getName() const;
		string getType() const;
		int getAge() const;
		PetsPtr getLink() const;
};

//prototypes
void Display(PetsPtr head);
void DisplayMenu(PetsPtr head);
void ChooseMenuItem(PetsPtr head);
void DisplayList(PetsPtr head);
void HeadInsert(PetsPtr& head, string inName, string inType, int inAge);
void TailInsert(PetsPtr& head, string inName, string inType, int inAge);
void SearchType(PetsPtr head, string key);
void DeleteNode(PetsPtr& head, string target);
int PrintAvgIt(PetsPtr head);
int PrintAvgRec(PetsPtr head);