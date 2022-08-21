//Struct example

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
const int MAX_INVOICES = 100;
const double FLORENCE_TAX_RATE = 0.095;


struct InvoiceType
{
    int invoiceID;
    string custFirstName, custLastName, itemDescription;
    double itemUnitCost;
    int quantity;
};
                    //function prototypes
void readInvoices (InvoiceType inv[], int &num);
void printSingleInvoice (InvoiceType inv);
void printAllInvoices (InvoiceType inv[], int num);
double findTotalCost (InvoiceType inv);
void newInvoice (InvoiceType inv[], int &num);
void writeInvoices (InvoiceType inv[], int num);
void sortByLastName (InvoiceType inv[], int num);

int main()
{
    int numInvoices = 0;
    InvoiceType invoice[MAX_INVOICES];
    readInvoices(invoice, numInvoices);
    sortByLastName(invoice, numInvoices);
    printAllInvoices(invoice, numInvoices);
    //cout << endl << endl << "Sorted by last Name: " << endl << endl;
    newInvoice(invoice, numInvoices);
    printAllInvoices(invoice, numInvoices);
    writeInvoices(invoice, numInvoices);


    return 0;
}

double findTotalCost (InvoiceType inv)
{
    double total = 0;
    total = inv.itemUnitCost * inv.quantity;
    total = total * (1 + FLORENCE_TAX_RATE);
    return total;
}

void printSingleInvoice (InvoiceType inv)
{
    cout << left << setw(10) << inv.invoiceID << "   ";
    cout << setw(10) << inv.custFirstName;
    cout << setw(10) << inv.custLastName;
    cout << setw(20) << inv.itemDescription;
    cout << right << setw(10) << fixed << setprecision(2) << inv.itemUnitCost;
    cout << setw(10) << inv.quantity;
    cout << setw(10) << findTotalCost(inv) << endl;
}

void newInvoice (InvoiceType inv[], int &num)
{
    cout << "Invoice ID?: ";
    cin >> inv[num].invoiceID;
    cout << "Customer first?: ";
    cin >> ws;
    getline(cin, inv[num].custFirstName);
    cout << "Customer last?: ";
    getline(cin, inv[num].custLastName);
    cout << "Item Description?: ";
    getline(cin, inv[num].itemDescription);
    cout << "Item Unit Cost?: ";
    cin >> inv[num].itemUnitCost;
    cout << "Quantity?: ";
    cin >> inv[num].quantity;
    num++;
}

void printAllInvoices (InvoiceType inv[], int num)
{
    cout << "Invoice ID   first     last      Description          unit cost  quantity     Total" << endl;
    for(int i = 0; i < num; i++)
    {
        printSingleInvoice(inv[i]);
    }
}

void writeInvoices (InvoiceType inv[], int num)
{
    ofstream output("invoices.txt");
    for (int i = 0; i < num; i++)
    {
        output << inv[i].invoiceID << endl;
        output << inv[i].custFirstName << endl;
        output << inv[i].custLastName << endl;
        output << inv[i].itemDescription << endl;
        output << inv[i].itemUnitCost << endl;
        output << inv[i].quantity << endl;
    }
    output.close();
}

void sortByLastName (InvoiceType inv[], int num)
{
    InvoiceType temp;
    int minIndex = 0;
    for(int i = 0; i < num-1; i++)
    {
        minIndex = i;
        for(int j = i+1; j < num; j++)
        {
            if(inv[j].custLastName < inv[minIndex].custLastName)
            {
                minIndex = j;
            }
        }
        temp = inv[i];          //Swap structs at positions i and minIndex
        inv[i] = inv[minIndex];
        inv[minIndex] = temp;
    }

}

void readInvoices (InvoiceType inv[], int &num)
{
    num = 0;
    ifstream input("invoices.txt");
    input >> inv[num].invoiceID;
    while(!input.eof())
    {
        input >> ws;
        getline(input, inv[num].custFirstName);
        getline(input, inv[num].custLastName);
        getline(input, inv[num].itemDescription);
        input >> inv[num].itemUnitCost;
        input >> inv[num].quantity;
        num++;
        input >> inv[num].invoiceID;    //ends while loop
    }
    input.close();
}
