#ifdef _WIN32
#define cls() system("cls")
#else
#define cls() system("clear")
#endif
#include <iostream>
#include <list>
#include <string>
using namespace std;

bool check(string str, list<string> list)
{
    int count = 0;

    for (auto elem : list)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == elem[i])
            {
                count++;
            }
        }
    }

    if (count == str.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void menu()
{
    list<string> shopingList;

    int option = -1;
    string product;

    while (option != 4)
    {
        cout << "Choose option: " << endl;
        cout << "1)Add product" << endl;
        cout << "2)Buy product" << endl;
        cout << "3)Show all shopingList" << endl;
        cout << "4)Exit" << endl;
        cin >> option;
        cin.get();

        switch (option)
        {
        case 1:
        {
            cout << "Enter product name which want buy: ";
            getline(cin, product);
            shopingList.push_back(product);
            cls();
            break;
        }
        case 2:
        {
            cout << "Enter product name which want buy: ";
            getline(cin, product);

            if (check(product, shopingList))
            {
                shopingList.remove(product);
                cls();
                cout << "Thank you for your purchase" << endl;
                cout << "Press enter t continue...";
                cin.get();
                cls();
            }
            else
            {
                cout << "Such product is not listed" << endl;
                cout << "Press enter t continue...";
                cin.get();
                cls();
            }
            break;
        }
        case 3:
        {
            int num = 1;

            cout << "Your product shopingList: " << endl;
            for (auto elem : shopingList)
            {
                cout << num << ")" << elem << endl;
                num++;
            }
            cout << "Press enter t continue...";
            cin.get();
            cls();
            break;
        }
        case 4:
        {
            cout << "Thank you for visiting our store" << endl;
            break;
        }
        }
    }
}

int main()
{
    menu();
}