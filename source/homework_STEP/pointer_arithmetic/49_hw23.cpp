#include <iostream>
using namespace std;

void startGame(char str[], int size)
{
    cout << "Enter string: ";
    cin.getline(str, size);
}

void addLetter(char str[], char letter[])
{
    int size = strlen(str) + strlen(letter);
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (i < str[i])
        {
            str[i] = str[i];
        }
        else
        {
            str[i] = letter[j];
            j++;
        }
    }

}

void delLetter(char str[], int delLet)
{
    int size = strlen(str) - delLet - 1;
    for (int i = 0; i < size; i++)
    {
        str[i] = str[i];
    }
    str[size + 1] = '\0';
}

void statistic(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        cout << str[i];
    }
    cout << endl;
}

int main()
{
    int size = 1000;
    char* str = new char[size];
    char letter[100];
    int del;
    int choice = 1;

    while (choice != 5)
    {
        cout << "Choose option: " << endl;
        cout << "1)start game" << endl;
        cout << "2)add letter" << endl;
        cout << "3)delete letter" << endl;
        cout << "4)view statistics" << endl;
        cout << "5)finish the game" << endl;
        cin >> choice;
        cin.get();
        
        if (choice > 5 || choice < 1)
        {
            while (choice > 5 || choice < 1)
            {
                cout << "You enter wrong number" << endl;
                cout << "Choose option again: " << endl;
                cout << "1)start game" << endl;
                cout << "2)add letter" << endl;
                cout << "3)delete letter" << endl;
                cout << "4)view statistics" << endl;
                cout << "5)finish the game" << endl;
                cin >> choice;
                cin.get();
            }
        }

        switch (choice)
        {
            case 1:
                startGame(str, size);
                break;
            case 2:
                cout << "Enter letter or letters which want add: ";
                cin.getline(letter, 100);
                addLetter(str, letter);
                break;
            case 3:
                cout << "Enter the number of letters you want to delete: ";
                cin >> del;
                delLetter(str, del);
                break;
            case 4:
                statistic(str);
                break;
        }
    }

    delete[]str;

    return 0;
}
