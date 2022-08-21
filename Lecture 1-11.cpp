//Struct example

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
const int MAX_INVOICES = 100;


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

int main()
{
    int numInvoices = 0;
    InvoiceType invoice[MAX_INVOICES];
    readInvoices(invoice, numInvoices);
    printSingleInvoice(invoice[0]);
    return 0;
}

void printSingleInvoice (InvoiceType inv)
{
    cout << setw(10) << inv.invoiceID;
    cout << setw(10) << inv.custFirstName;
    cout << setw(10) << inv.custLastName;
    cout << setw(10) << inv.itemDescription;
    cout << setw(10) << inv.itemUnitCost;
    cout << setw(10) << inv.quantity << endl;
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
