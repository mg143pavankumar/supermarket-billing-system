#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

//global variable declaration
int k = 7, r = 0, flag = 0;

//For moving cursor to a specific location in the terminal
COORD coord = {0, 0};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// file handling object declaration
ofstream fout;
ifstream fin;

struct date
{
    int dd, mm, yy;
};

// <============================ Product class ========================================> //
class Product
{
    int product_no;
    char product_name[25];
    date d;

public:
    void add()
    {
        cout << "\n\n\tProduct No: ";
        cin >> product_no;

        cout << "\n\n\tProduct Name: ";
        cin >> product_name;

        cout << "\n\n\tManufacturing data (dd-mm-yy): ";
        cin >> d.dd >> d.mm >> d.yy;
    }

    void show()
    {
        cout << "\n\tProduct No: " << product_no;
        cout << "\n\n\tProduct Name: " << product_name;
        cout << "\n\n\tDate: " << d.dd << "-" << d.mm << "-" << d.yy;
    }

    void report()
    {
        gotoxy(3, k);
        cout << product_no;

        gotoxy(13, k);
        puts(product_name);
    }

    int retno()
    {
        return (product_no);
    }
};

// <============================ Amount class ========================================> //

class Amount : public Product
{
    float price, qty, tax, gross, dis, netamt;

public:
    void add();
    void show();
    void report();
    void calculate();
    void pay();
    float retnetamt()
    {
        return (netamt);
    }
} amt;

void Amount::add()
{

    Product::add();
    cout << "\n\n\tPrice: ";
    cin >> price;
    cout << "\n\n\tQuantity: ";
    cin >> qty;
    cout << "\n\n\tTax percent: ";
    cin >> tax;
    cout << "\n\n\tDiscount percent: ";
    cin >> dis;
}

void Amount::calculate()
{
    gross = price + (price * (tax / 100));
    netamt = qty * (gross - (gross * (dis / 100)));
}
void Amount::show()
{
    fin.open("productstore.dat", ios::binary);
    fin.read((char *)&amt, sizeof(amt));
    Product::show();
    cout << "\n\n\tNet amount: ";
    cout << netamt;
    fin.close();
}

void Amount::report()
{
    Product::report();
    gotoxy(23, k);
    cout << price;
    gotoxy(33, k);
    cout << qty;
    gotoxy(44, k);
    cout << tax;
    gotoxy(52, k);
    cout << dis;
    gotoxy(64, k);
    cout << netamt;
    k = k + 1;
    if (k == 50)
    {
        gotoxy(25, 50);
        cout << "PRESS ANY KEY TO CONTINUE...";
        getch();
        k = 7;
        system("cls");
        gotoxy(30, 3);
        cout << " ITEM DETAILS ";
        gotoxy(3, 5);
        cout << "NUMBER";
        gotoxy(13, 5);
        cout << "NAME";
        gotoxy(23, 5);
        cout << "PRICE";
        gotoxy(33, 5);
        cout << "QUANTITY";
        gotoxy(44, 5);
        cout << "TAX";
        gotoxy(52, 5);
        cout << "DEDUCTION";
        gotoxy(64, 5);
        cout << "NET AMOUNT";
    }
}

void Amount::pay()
{
    show();
    cout << "\n\n\n\t\t*********************************************";
    cout << "\n\t\t                 DETAILS                  ";
    cout << "\n\t\t*********************************************";
    cout << "\n\n\t\tPRICE                     :" << price;
    cout << "\n\n\t\tQUANTITY                  :" << qty;
    cout << "\n\t\tTAX PERCENTAGE              :" << tax;
    cout << "\n\t\tDISCOUNT PERCENTAGE         :" << dis;
    cout << "\n\n\n\t\tNET AMOUNT              :Rs." << netamt;
    cout << "\n\t\t*********************************************";
}
