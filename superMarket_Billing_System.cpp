#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#include "product.h"
#include "productData.h"

#define BLUE "\u001b[34m"
#define RED "\u001b[31m"
#define YELLOW "\u001b[33m"
using namespace std;

class GetUserInput
{
public:
    void getOptions(string options)
    {
        cout << "\t\t\t\t" << options;
    }

    void getError()
    {
        cout << RED "\t\t\t\tPlease enter valid option..... !";
    }
};

int main()
{
    GetUserInput getUserInput;
    ProductData productData;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout << setprecision(2);
    fstream tmp("temp.dat", ios::binary | ios::out);

home:
    system("cls");
    int user;

    // locating content at the center of the terminal
    gotoxy(25, 2);
    cout << BLUE "<<<<<<<<<<<<<<<<<<<< Welcome To Our Super Market >>>>>>>>>>>>>>>>>>>>\n\n"
         << endl;

    // gotoxy(25, 3);
    getUserInput.getOptions("Choose who you are ?\n\n");
    getUserInput.getOptions("1. Customer\n\n");
    getUserInput.getOptions("2. Admin\n\n");
    getUserInput.getOptions("3. Exit\n\n");
    getUserInput.getOptions("Select your option: ");
    cin >> user;

    if (user == 1)
    {

        int user;

    choose_section:
        system("cls");
        gotoxy(25, 2);
        cout << BLUE "<<<<<<<<<<<<<<<<<<<< Welcome To Our Super Market >>>>>>>>>>>>>>>>>>>>" << endl;

        gotoxy(5, 4);
        getUserInput.getOptions("Choose which section you want to visit ?\n\n");
        getUserInput.getOptions("1. Kitchen\n\n");
        getUserInput.getOptions("2. Clothes\n\n");
        getUserInput.getOptions("3. Electronic\n\n");
        getUserInput.getOptions("4. Cold Drinks\n\n");
        getUserInput.getOptions(RED "5. Back to home\n\n");
        getUserInput.getOptions(BLUE "Select your option: ");
        cin >> user;

        switch (user)
        {
        case 1:
        {
            int user;
            system("cls");
            gotoxy(25, 2);
            cout << BLUE "<<<<<<<<<<<<<<<<<<<< Kitchen Section >>>>>>>>>>>>>>>>>>>>" << endl;

            gotoxy(5, 4);
            getUserInput.getOptions("Choose which product you want to buy ?\n\n");
            productData.getKitchenProducts();
            getUserInput.getOptions("Select you product: ");

            cin >> user;
        }
        break;
        case 2:
        {
            int user;
            system("cls");
            gotoxy(25, 2);
            cout << BLUE "<<<<<<<<<<<<<<<<<<<< Clothes Section >>>>>>>>>>>>>>>>>>>>" << endl;

            gotoxy(5, 4);
            getUserInput.getOptions("Choose which product you want to buy ?\n\n");
            productData.getClothesProducts();
            getUserInput.getOptions("Select you product: ");

            cin >> user;
        }

        break;
        case 3:
        {
            int user;
            system("cls");
            gotoxy(25, 2);
            cout << BLUE "<<<<<<<<<<<<<<<<<<<< Electronic Section >>>>>>>>>>>>>>>>>>>>" << endl;

            gotoxy(5, 4);
            getUserInput.getOptions("Choose which product you want to buy ?\n\n");
            productData.getElectronicProducts();
            getUserInput.getOptions("Select you product: ");

            cin >> user;
        }

        break;
        case 4:
        {
            int user;
            system("cls");
            gotoxy(25, 2);
            cout << BLUE "<<<<<<<<<<<<<<<<<<<< Cold Drinks Section >>>>>>>>>>>>>>>>>>>>" << endl;

            gotoxy(5, 4);
            getUserInput.getOptions("Choose which product you want to buy ?\n\n");
            productData.getColdDrinkProducts();
            getUserInput.getOptions("Select you product: ");

            cin >> user;
        }
        break;
        case 5:
            goto home;

        default:
            cout << "\n\n";
            getUserInput.getError();

            cout << YELLOW "\n\n\t\t\t\t<<< Press any key to go back to section options >>>\n\n";
            getch();
            goto choose_section;
        }
    }
    else if (user == 2)
    {
        system("cls");

        int _user;
        gotoxy(25, 2);
        cout << "<<<<<<<<<<<<<<<<<<<< Admin Login >>>>>>>>>>>>>>>>>>>>\n\n";

        // gotoxy(22,3);
        getUserInput.getOptions("1. Login\n\n");
        getUserInput.getOptions("2. Back to home\n\n");
        getUserInput.getOptions("Select your option: ");
        cin >> _user;

        if (_user == 1)
        {
        login:
            system("cls");
            gotoxy(25, 2);
            cout << "<<<<<<<<<<<<<<<<<<<< Admin Login >>>>>>>>>>>>>>>>>>>>\n\n";

            string _adminName("supermarket@admin.com");
            string adminName;
            int _password = 123456, psw;

            getUserInput.getOptions("Enter email address: ");
            cin >> adminName;

            getUserInput.getOptions("Enter password: ");
            cin >> psw;

            if (adminName.compare(_adminName) == 0 && (psw == _password))
            {
            menu:
                system("cls");
                gotoxy(25, 2);
                cout << "<<<<<<<<<<<<<<<<<<<< Super Market Billing >>>>>>>>>>>>>>>>>>>>\n\n";

                cout << "\n\t\t1.Bill Report\n\n";
                cout << "\t\t2.Add/Remove/Edit Product\n\n";
                cout << "\t\t3.Show Product Details\n\n";
                cout << "\t\t4.Exit\n\n";
                cout << "\t\tPlease Enter Required Option: ";
                int ch, ff;
                float gtotal;
                cin >> ch;
                switch (ch)
                {
                case 1:
                ss:
                    system("cls");
                    gotoxy(25, 2);
                    cout << "Bill Details";
                    gotoxy(25, 3);
                    drawlines(15);
                    cout << "\n\t\t1.All Products\n\n";
                    cout << "\t\t2.Back to Main menu\n\n";
                    cout << "\t\tPlease Enter Required Option: ";
                    int cho;
                    cin >> cho;
                    if (cho == 1)
                    {
                        system("cls");
                        gotoxy(30, 3);
                        cout << " BILL DETAILS ";
                        gotoxy(3, 5);
                        cout << "Product NO";
                        gotoxy(13, 5);
                        cout << "NAME";
                        gotoxy(23, 5);
                        cout << "PRICE";
                        gotoxy(33, 5);
                        cout << "QUANTITY";
                        gotoxy(44, 5);
                        cout << "TAX %";
                        gotoxy(52, 5);
                        cout << "DISCOUNT %";
                        gotoxy(64, 5);
                        cout << "NET AMOUNT";
                        fin.open("Productstore.dat", ios::binary);
                        if (!fin)
                        {
                            cout << "\n\nFile Not Found...";
                            goto menu;
                        }
                        fin.seekg(0);
                        gtotal = 0;
                        while (!fin.eof())
                        {
                            fin.read((char *)&amt, sizeof(amt));
                            if (!fin.eof())
                            {
                                amt.report();
                                gtotal += amt.retnetamt();
                                ff = 0;
                            }
                            if (ff != 0)
                                gtotal = 0;
                        }
                        gotoxy(17, k);
                        cout << "\n\n\n\t\t\tGrand Total=" << gtotal;
                        getch();
                        fin.close();
                    }
                    if (cho == 2)
                    {
                        goto menu;
                    }
                    goto ss;
                case 2:
                db:
                    system("cls");
                    gotoxy(25, 2);
                    cout << "Bill Editor";
                    gotoxy(25, 3);
                    drawlines(15);
                    cout << "\n\n\n\t\t1.Add Product Details\n\n";
                    cout << "\t\t2.Edit Product Details\n\n";
                    cout << "\t\t3.Delete Product Details\n\n";
                    cout << "\t\t4.Back to Main Menu ";
                    int apc;
                    cin >> apc;
                    switch (apc)
                    {
                    case 1:
                        fout.open("Productstore.dat", ios::binary | ios::app);
                        amt.add();
                        cout << "\n\t\tProduct Added Successfully!";
                        getch();
                        goto db;

                    case 2:
                        int ino;
                        flag = 0;
                        cout << "\n\n\tEnter Product Number to be Edited :";
                        cin >> ino;
                        fin.open("Productstore.dat", ios::binary);
                        fout.open("Productstore.dat", ios::binary | ios::app);
                        if (!fin)
                        {
                            cout << "\n\nFile Not Found...";
                            goto menu;
                        }
                        fin.seekg(0);
                        r = 0;
                        while (!fin.eof())
                        {
                            fin.read((char *)&amt, sizeof(amt));
                            if (!fin.eof())
                            {
                                int x = amt.Product::retno();
                                if (x == ino)
                                {
                                    flag = 1;
                                    fout.seekp(r * sizeof(amt));
                                    system("cls");
                                    cout << "\n\t\tCurrent Details are\n";
                                    amt.show();
                                    cout << "\n\n\t\tEnter New Details\n";
                                    amt.add();
                                    cout << "\n\t\tProduct Details editted";
                                }
                            }
                            r++;
                        }
                        if (flag == 0)
                        {
                            cout << "\n\t\tProduct No does not exist...Please Retry!";
                            getch();
                            goto db;
                        }
                        fin.close();
                        getch();
                        goto db;

                    case 3:
                        flag = 0;
                        cout << "\n\n\tEnter Product Number to be deleted :";
                        cin >> ino;
                        fin.open("Productstore.dat", ios::binary);
                        if (!fin)
                        {
                            cout << "\n\nFile Not Found...";
                            goto menu;
                        }
                        //fstream tmp("temp.dat",ios::binary|ios::out);
                        fin.seekg(0);
                        while (fin.read((char *)&amt, sizeof(amt)))
                        {
                            int x = amt.Product::retno();
                            if (x != ino)
                                tmp.write((char *)&amt, sizeof(amt));
                            else
                            {
                                flag = 1;
                            }
                        }
                        fin.close();
                        tmp.close();
                        fout.open("Productstore.dat", ios::trunc | ios::binary);
                        fout.seekp(0);
                        tmp.open("temp.dat", ios::binary | ios::in);
                        if (!tmp)
                        {
                            cout << "Error in File";
                            goto db;
                        }
                        while (tmp.read((char *)&amt, sizeof(amt)))
                            fout.write((char *)&amt, sizeof(amt));
                        tmp.close();
                        fout.close();
                        if (flag == 1)
                            cout << "\n\t\tProduct Succesfully Deleted";
                        else if (flag == 0)
                            cout << "\n\t\tProduct does not Exist! Please Retry";
                        getch();
                        goto db;
                    case 4:
                        goto menu;
                    default:
                        cout << "\n\n\t\tWrong Choice!!! Retry";
                        getch();
                        goto db;
                    }
                case 3:
                    system("cls");
                    flag = 0;
                    int ino;
                    cout << "\n\n\t\tEnter Product Number :";
                    cin >> ino;
                    fin.open("Productstore.dat", ios::binary);
                    if (!fin)
                    {
                        cout << "\n\nFile Not Found...\nProgram Terminated!";
                        goto menu;
                    }
                    fin.seekg(0);
                    while (fin.read((char *)&amt, sizeof(amt)))
                    {
                        int x = amt.Product::retno();
                        if (x == ino)
                        {
                            amt.pay();
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                        cout << "\n\t\tProduct does not exist....Please Retry!";
                    getch();
                    fin.close();
                    goto menu;
                case 4:
                    system("cls");
                    gotoxy(20, 20);
                    cout << "ARE YOU SURE, YOU WANT TO EXIT (Y/N)?";
                    char yn;
                    cin >> yn;
                    if ((yn == 'Y') || (yn == 'y'))
                    {
                        gotoxy(12, 20);
                        system("cls");
                        cout << "************************** THANK YOU FOR VISITING **************************";
                        getch();
                        exit(0);
                    }
                    else if ((yn == 'N') || (yn == 'n'))
                        goto menu;
                    else
                    {
                        goto menu;
                    }
                default:
                    cout << "\n\n\t\tWrong Choice....Please Retry!";
                    getch();
                    goto menu;
                }
            }
            else
            {
                if (adminName.compare(_adminName) != 0)
                {
                    cout << "\n\n>>>> Invalid email..! <<<<\n\n";
                }
                else
                {
                    cout << "\n\n>>>> Invalid password <<<<\n\n";
                }
                cout << "<<<< press any key to return back to login screen >>>>";
                getch();
                goto login;
            }
        }
        else if (_user == 2)
        {
            goto home;
        }
    }
    else if (user == 3)
    {
        exit(1);
    }
    return 0;
}
