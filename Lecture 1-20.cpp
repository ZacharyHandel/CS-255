#include <iostream>
#include <fstream>
using namespace std;
const int MAX_BOXES = 100;

///CREATING A CLASS
class Rectangle
{
	private:
		double length;
		double width;
		string color;
    public: //programmer can interact with
        //setters and getter functions
        void setLength(double);
        void setWidth(double);
        void setColor(string);
        void setRectangle(double inLength, double inWidth, string inColor);
        double getWidth() const;	//protects from modification
        //const means functoin wll not modify data
        double getLength() const;
        string getColor() const;
        double getArea() const;
        void grow(double);
        void print() const;
        Rectangle();    //constructor - used to initialize an object - automatically void
        Rectangle(double, double, string);  //2nd constructor - you can pass values to constructors
        ~Rectangle();   //destructor - called when object goes out of scope - clean up activities like free up memory
};

void readBoxesFromFile(Rectangle box[], int &numBoxes);
void printBoxes(Rectangle box[], int numBoxes);

int main()
{
    //define object
    Rectangle box, box2;    //Instantiation of a class - creating objects
    Rectangle box3 (14.9, 11.3, "green");

    int numBoxes = 0;
    Rectangle rect[MAX_BOXES];
    readBoxesFromFile(rect, numBoxes);
    printBoxes(rect, numBoxes);
/*
    cout << "box3:" << endl;
    box3.print();
    cout << endl;

    cout << "Box 3 after growing by 20:" << endl;
    box3.grow(20);
    box3.print();
    cout << endl;

    cout << "box:" << endl;
    box.print();
    cout << endl;

    cout << "box after setters are called:" << endl;
    box.setLength(44.7);
    box.setWidth(23.9);
    box.setColor("Green");
    box.print();
    cout << endl;

    cout << "box2 after color changed to blue:" << endl;
    box2.setColor("Blue");
    box2.print();


    //box.Length = 99; CANNOT ACCESS A PRIVATE MEMBER!!!

    //box.print();
    //cout << "Box length is " << box.getLength() << endl;
    //cout << "Box area is " << box.getArea() << endl;
    */
    return 0;
}

void printBoxes(Rectangle box[], int numBoxes)
{
    for(int i = 0; i < numBoxes; i++)
    {
        cout << "Box # " << i+1 << ": " << endl;
        box[i].print();
        cout << endl;
    }
}

void readBoxesFromFile(Rectangle box[], int &numBoxes)
{
    numBoxes = 0;
    ifstream boxFile;
    double lngth = 0, wdth = 0;
    string clr ="";
    boxFile.open("boxes.txt");
    boxFile >> lngth >> wdth;
    while(!boxFile.eof())
    {
        boxFile >> ws;
        getline(boxFile, clr);
        box[numBoxes].setRectangle(lngth, wdth, clr);
        numBoxes++;
        boxFile >> lngth >> wdth;
    }
    boxFile.close();
}

void Rectangle::grow(double amount)
{
    length += amount;
    width += amount;
}

Rectangle::~Rectangle()
{
    //cout << "Rectangle object is destroyed." << endl;
}

Rectangle::Rectangle(double inLength, double inWidth, string inColor)
{
    length = inLength;
    width = inWidth;
    color = inColor;
}

void Rectangle::setRectangle(double inLength, double inWidth, string inColor)
{
    length = inLength;
    width = inWidth;
    color = inColor;
}

Rectangle::Rectangle()  //Default constructtor
{                       //Constructor is automatically called when the object is declared
    length = 0;
    width = 0;
    color = "White";
}

void Rectangle::print() const
{
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    cout << "Color: " << color << endl;
}

void Rectangle::setLength(double inLength)
{
    length = inLength;
}

void Rectangle::setWidth(double inWindth)
{
    width = inWindth;
}

void Rectangle::setColor(string inColor)
{
    color = inColor;
}

double Rectangle::getLength() const
{
    return length;
}

double Rectangle::getWidth() const
{
    return width;
}

string Rectangle::getColor() const
{
    return color;
}

double Rectangle::getArea() const
{
    double area = 0;
    area = length * width;
    return area;
}
