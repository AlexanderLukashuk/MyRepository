#ifdef _WIN32
#define cls() system("cls")
#else
#define cls() system("clear")
#endif
#include <iostream>
#include <list>
#include <string>
using namespace std;

bool check(string str, list<string> &list)
{
    int count = 0;

    for (auto elem : list)
    {
        if (str == elem)
        {
            return true;
        }
    }

    return false;
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

            if (!shopingList.empty())
            {
                cout << "Enter product name which want buy: ";
                getline(cin, product);
                if (check(product, shopingList) == true)
                {
                    shopingList.remove(product);
                    cls();
                    cout << "Thank you for your purchase" << endl;
                    cout << "Press enter to continue...";
                    cin.get();
                    cls();
                }
                else
                {
                    cout << "Such product is not listed" << endl;
                    cout << "Press enter to continue...";
                    cin.get();
                    cls();
                }
            }
            else
            {
                cout << "Your shoping list is empty" << endl;
                cout << "Press enter to continue...";
                cin.get();
                cls();
            }
            break;
        }
        case 3:
        {
            int num = 1;

            if (!shopingList.empty())
            {
                cout << "Your product shopingList: " << endl;
                for (auto elem : shopingList)
                {
                    cout << num << ")" << elem << endl;
                    num++;
                }
            }
            else if (shopingList.empty() == 1)
            {
                cout << "You shopingList is empty" << endl;
            }

            cout << "Press enter to continue...";
            cin.get();
            cls();
            break;
        }
        case 4:
        {
            if (shopingList.empty())
            {
                cls();
                cout << "Thank you for visiting our store" << endl;
            }
            else
            {
                cout << "You must buy products" << endl;
                option = -1;
                cout << "Press enter to continue...";
                cin.get();
                cls();
            }
            break;
        }
        }
    }
}

int main()
{
    cls();
    menu();
}