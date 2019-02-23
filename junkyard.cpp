// Generate monthly sales report for Luxury Junkyard, Inc.
// Farhan Azad
// CSC 1610, Section 1
//12/4/2018
#include<iostream>
#include <fstream>
#include<iomanip>
#include<string>
using namespace std;

const string AUDI = "AUDI";
const string BMW = "BMW";
const string JAGUAR = "JAGUAR";
const string LEXUS = "LEXUS";


void printHead();
string carName(int choice);
float carPrice(int choice);
void printSummary(string n);

int main()
{
    ifstream inputFile;
    string name;
    name = "Junkyard.txt";
    inputFile.open(name);
    if (!inputFile)
    {
        cout<<"Error\n";
        inputFile.close();
    }
    else
    {
        printSummary(name);
        inputFile.close();
    }
    return 0;
}
void printHead()
{
    cout<<"Welcome to Luxury Junkyard, Inc. the end of month report\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"CURRENT SELLING PRICES\n";
    cout<<"------------------------\n";
    cout << carName(1) << setw(11) << fixed << setprecision(2) << carPrice(1) << endl;
    cout << carName(2) << setw(12) << fixed << setprecision(2) << carPrice(2) << endl;
    cout << carName(3) << setw(9) << fixed << setprecision(2) << carPrice(3) << endl;
    cout << carName(4) << setw(10) << fixed << setprecision(2) << carPrice(4) << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "SALESPERSON" << setw(9) << "MODEL" << setw(11) << "COUNT"
         << setw(22) << "TOTAL SOLD $$$" << endl;
    cout << setw(5) << "ID" << setw(18) << "DESCRIPTION" << setw(7)
         << "SOLD" << setw(22) << "PER MODEL" << endl;
    cout << "------------------------------------------------------" << endl;
}
string carName(int choice)
{
    if (choice == 1)
        return AUDI;
    else if (choice == 2)
        return BMW;
    else if (choice == 3)
        return JAGUAR;
    else if (choice == 4)
        return LEXUS;

}
float carPrice(int choice)
{
    float a = 8876.50;
    float b = 9909.89;
    float c = 10999.99;
    float d = 7776.69;
    if (choice == 1)
        return a;
    else if (choice == 2)
        return b;
    else if (choice == 3)
        return c;
    else if (choice == 4)
        return d;
}

void printSummary(string n)
{
    ifstream File;
    int num;
    float sum;
    int numT;
    int countS;
    float countP;
    int code;
    int sumC;
    float sumTotal = 0;
    int allA = 0;
    int allJ=0;
    int allL=0;
    int allB=0;
    int saleP = 0;
    float average;
    bool close = false;
    printHead();
    File.open(n);
    while (close == false)
    {
        File >> num;
        cout<<setw(6)<<num;
        File >> numT;
        sum = 0;
        sumC = 0;
        for (int i = 0; i < numT; i++)
        {
            cout << fixed << showpoint << setprecision(2);
            File>>code;
            File>>countS;
            countP = countS *carPrice(code);
            if (code == 1)
                allA +=countS;
            else if (code == 2)
                allB += countS;
            else if (code == 3)
                allJ += countS;
            else if (code == 4)
                allL += countS;
            if (i > 0)
                cout <<setw(20)<< carName(code)<< setw(8) <<countS<< setw(22)<<countP<<endl;
            else
                cout << setw(14) << carName(code)<< setw(8) <<countS<< setw(22)<<countP<<endl;
            sumC += countS;
            sum += countP;
        }
        cout<<"                      -----------------------------\n";
        cout<<setw(28)<<sumC<<setw(22)<<sum<<endl<<endl;
        sumTotal += sum;
        saleP++;
        if (num == 8125)
            close = true;
    }
    average = sumTotal / saleP;
    cout<<"OVARALL AUDI UNITS SOLD: \n";
    cout<<allA<<endl;
    cout<<"OVARALL BMW  UNITS SOLD: \n";
    cout<<allB<<endl;
    cout<<"OVARALL JAGUAR  UNITS SOLD: \n";
    cout<<allJ<<endl;
    cout<<"OVARALL LEXUS UNITS SOLD: \n";
    cout<<allL<<endl;
    cout<<"NUMBER SALESPERSONS: ";
    cout<<saleP<<endl;
    cout<<"OVERALL $$$ SOLD: ";
    cout<<sumTotal<<endl;
    cout<<"AVERAGE $$$ SOLD per SALESPERSON: ";
    cout<<average <<endl;
    cout<<"Good bye!";
    File.close();
}

