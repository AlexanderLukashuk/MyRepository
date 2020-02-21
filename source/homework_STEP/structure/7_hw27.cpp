#include <iostream>
#include <vector>
using namespace std;

struct Man
{
    char surname[50];
    char name[50];
    int age;
    int bithDay;
    int bithMonth;
    int bithYear;
};

void addMan(Man*& man, int& size)
{
    if (man == nullptr)
    {
        size++;
        man = new Man[size];

        cout << "Enter surname: ";
        cin.getline(man->surname, 50);
        cout << "Enter name: ";
        cin.getline(man->name, 50);
        cout << "Enter age: ";
        cin >> man->age;
        cin.get();
        cout << "Enter bithday day: ";
        cin >> man->bithDay;
        cin.get();
        cout << "Enter bithday month: ";
        cin >> man->bithMonth;
        cin.get();
        cout << "Enter bithday year: ";
        cin >> man->bithYear;
        cin.get();
    }
    else
    {
        size++;
        Man* newMan = new Man[size];

        for (int i = 0; i < size - 1; i++)
        {
            newMan[i] = man[i];
        }

        cout << "Enter surname: ";
        cin.getline(newMan[size - 1].surname, 50);
        cout << "Enter name: ";
        cin.getline(newMan[size - 1].name, 50);
        cout << "Enter age: ";
        cin >> newMan[size - 1].age;
        cin.get();
        cout << "Enter bithday day: ";
        cin >> newMan[size - 1].bithDay;
        cin.get();
        cout << "Enter bithday month: ";
        cin >> newMan[size - 1].bithMonth;
        cin.get();
        cout << "Enter bithday year: ";
        cin >> newMan[size - 1].bithYear;
        cin.get();

        delete[]man;
        man = newMan;
    }
}

void deleteMan(Man*& man, int& size, int index)
{
    if (man == nullptr)
    {
        cout << "There no any man" << endl;
        return;
    }
    else
    {
        size--;
        Man* newMan = new Man[size];

        for (int i = 0, j = 0; i < size + 1; i++)
        {
            if (i != index)
            {
                newMan[j] = man[i];
                j++;
            }
        }

        delete[]man;
        man = newMan;
    }
}

void showMan(Man * man, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Man " << i + 1 << ":" << endl;
        cout << "Surname: " << man[i].surname << endl;
        cout << "Name: " << man[i].name << endl;
        cout << "Age: " << man[i].age << endl;
        cout << "Bith date: " << man[i].bithDay
            << "." << man[i].bithMonth
            << "." << man[i].bithYear << endl;
    }
}

void sortSurname(Man* mans, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (mans[j].surname[0] > mans[j + 1].surname[0])
            {
                Man temp = mans[j];
                mans[j] = mans[j + 1];
                mans[j + 1] = temp;
            }
        }
    }
}

void sortName(Man* mans, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (mans[j].name[0] > mans[j + 1].name[0])
            {
                Man temp = mans[j];
                mans[j] = mans[j + 1];
                mans[j + 1] = temp;
            }
        }
    }
}

void searchMan(Man* mans, int size, char* searchSurname, char* searchName)
{
    for (int i = 0; i < size; i++)
    {
        int temp1 = strcmp(mans[i].surname, searchSurname);
        int temp2 = strcmp(mans[i].name, searchName);
        if (temp1 == 0 && temp2 == 0)
        {
            cout << "The desired man:" << endl;
            cout << "Surname: " << mans[i].surname << endl;
            cout << "Name: " << mans[i].name << endl;
            cout << "Age: " << mans[i].age << endl;
            cout << "Bith date: " << mans[i].bithDay << "." << mans[i].bithMonth 
                << "." << mans[i].bithYear << endl;
        }
    }
}

void editMan(Man*& man, int index, int size)
{
    Man* newMan = new Man[1];
    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            cout << "Make changes: " << endl;
            cout << "Enter surname: ";
            cin.getline(newMan[0].surname, 50);
            cout << "Enter name: ";
            cin.getline(newMan[0].name, 50);
            cout << "Enter age: ";
            cin >> newMan[0].age;
            cin.get();
            cout << "Enter bithday day: ";
            cin >> newMan[0].bithDay;
            cin.get();
            cout << "Enter bithday month: ";
            cin >> newMan[0].bithMonth;
            cin.get();
            cout << "Enter bithday year: ";
            cin >> newMan[0].bithYear;
            cin.get();
        }
    }

    man[index] = newMan[0];
    delete[]newMan;
}

void bithday(Man* mans, int size, int month)
{
    for (int i = 0; i < size; i++)
    {
        if (month == mans[i].bithMonth)
        {
            cout << "Bithday man in this month: " << mans[i].name << endl;
            cout << "Bithday date: " << mans[i].bithDay << "."
                << mans[i].bithMonth << "." << mans[i].bithYear << endl;
        }
    }
}

int main()
{
    int size = 0, num, index, month;
    char strSurname[50];
    char strName[50];
    Man* mans = nullptr;

    cout << "Choose option: " << endl;
    cout << "1)Add man" << endl;
    cout << "2)Delete man" << endl;
    cout << "3)Show all man" << endl;
    cout << "4)Search Man" << endl;
    cout << "5)Edit man" << endl;
    cout << "6)Bithday of the month" << endl;
    cout << "7)Sort Mans by surname" << endl;
    cout << "8)Sort Mans by name" << endl;
    cout << "9)Exit" << endl;
    cin >> num;
    cin.get();

    while (num != 9)
    {
        switch (num)
        {
            case 1:
                addMan(mans, size);
                cout << "Choose option: " << endl;
                cout << "1)Add man" << endl;
                cout << "2)Delete man" << endl;
                cout << "3)Show all man" << endl;
                cout << "4)Search Man" << endl;
                cout << "5)Edit man" << endl;
                cout << "6)Bithday of the month" << endl;
                cout << "7)Sort Man by surname" << endl;
                cout << "8)Sort Mans by name" << endl;
                cout << "9)Exit" << endl;
                cin >> num;
                cin.get();
                break;
            case 2:
                cout << "Enter number of man who want delete: ";
                cin >> index;
                index--;
                deleteMan(mans, size, index);
                cout << "Choose option: " << endl;
                cout << "1)Add man" << endl;
                cout << "2)Delete man" << endl;
                cout << "3)Show all man" << endl;
                cout << "4)Search Man" << endl;
                cout << "5)Edit man" << endl;
                cout << "6)Bithday of the month" << endl;
                cout << "7)Sort Man by surname" << endl;
                cout << "8)Sort Mans by name" << endl;
                cout << "9)Exit" << endl;
                cin >> num;
                cin.get();
                break;
            case 3:
                showMan(mans, size);
                cout << "Choose option: " << endl;
                cout << "1)Add man" << endl;
                cout << "2)Delete man" << endl;
                cout << "3)Show all man" << endl;
                cout << "4)Search Man" << endl;
                cout << "5)Edit man" << endl;
                cout << "6)Bithday of the month" << endl;
                cout << "7)Sort Man by surname" << endl;
                cout << "8)Sort Mans by name" << endl;
                cout << "9)Exit" << endl;
                cin >> num;
                cin.get();
                break;
            case 4:
                cout << "Enter surname a man who want search: ";
                cin.getline(strSurname, 50);
                cout << "Enter name a man who want search: ";
                cin.getline(strName, 50);
                searchMan(mans, size, strSurname, strName);
                cout << "Choose option: " << endl;
                cout << "1)Add man" << endl;
                cout << "2)Delete man" << endl;
                cout << "3)Show all man" << endl;
                cout << "4)Search Man" << endl;
                cout << "5)Edit man" << endl;
                cout << "6)Bithday of the month" << endl;
                cout << "7)Sort Man by surname" << endl;
                cout << "8)Sort Mans by name" << endl;
                cout << "9)Exit" << endl;
                cin >> num;
                cin.get();
                break;
            case 5:
                cout << "Enter number of man who want edit: ";
                cin >> index;
                cin.get();
                index--;
                editMan(mans, index, size);
                cout << "Choose option: " << endl;
                cout << "1)Add man" << endl;
                cout << "2)Delete man" << endl;
                cout << "3)Show all man" << endl;
                cout << "4)Search Man" << endl;
                cout << "5)Edit man" << endl;
                cout << "6)Bithday of the month" << endl;
                cout << "7)Sort Man by surname" << endl;
                cout << "8)Sort Mans by name" << endl;
                cout << "9)Exit" << endl;
                cin >> num;
                cin.get();
                break;
            case 6:
                cout << "Enter number of month: ";
                cin >> month;
                bithday(mans, size, month);
                cout << "Choose option: " << endl;
                cout << "1)Add man" << endl;
                cout << "2)Delete man" << endl;
                cout << "3)Show all man" << endl;
                cout << "4)Search Man" << endl;
                cout << "5)Edit man" << endl;
                cout << "6)Bithday of the month" << endl;
                cout << "7)Sort Man by surname" << endl;
                cout << "8)Sort Mans by name" << endl;
                cout << "9)Exit" << endl;
                cin >> num;
                cin.get();
                break;
            case 7:
                sortSurname(mans, size);
                cout << "Choose option: " << endl;
                cout << "1)Add man" << endl;
                cout << "2)Delete man" << endl;
                cout << "3)Show all man" << endl;
                cout << "4)Search Man" << endl;
                cout << "5)Edit man" << endl;
                cout << "6)Bithday of the month" << endl;
                cout << "7)Sort Man by surname" << endl;
                cout << "8)Sort Mans by name" << endl;
                cout << "9)Exit" << endl;
                cin >> num;
                cin.get();
                break;
            case 8:
                sortName(mans, size);
                cout << "Choose option: " << endl;
                cout << "1)Add man" << endl;
                cout << "2)Delete man" << endl;
                cout << "3)Show all man" << endl;
                cout << "4)Search Man" << endl;
                cout << "5)Edit man" << endl;
                cout << "6)Bithday of the month" << endl;
                cout << "7)Sort Man by surname" << endl;
                cout << "8)Sort Mans by name" << endl;
                cout << "9)Exit" << endl;
                cin >> num;
                cin.get();
                break;
            default:
                cout << "You chose wrong option" << endl;
                cout << "Choose option again:" << endl;
                cout << "1)Add man" << endl;
                cout << "2)Delete man" << endl;
                cout << "3)Show all man" << endl;
                cout << "4)Search Man" << endl;
                cout << "5)Edit man" << endl;
                cout << "6)Bithday of the month" << endl;
                cout << "7)Sort Man by surname" << endl;
                cout << "8)Sort Mans by name" << endl;
                cout << "9)Exit" << endl;
                cin >> num;
                cin.get();
                break;
        }
    }

    return 0;
}
