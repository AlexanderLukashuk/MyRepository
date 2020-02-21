#include <iostream>
using namespace std;

struct Phonebook
{
    char name[100];
    char phone[100];
};

void addPhone(Phonebook*& phone, int& size)
{
    if (phone == nullptr)
    {
        size++;
        phone = new Phonebook[size];

        cout << "Enter surname: ";
        cin >> phone->name;
        cout << "Enter phone number: ";
        cin >> phone->phone;
    }
    else
    {
        size++;
        Phonebook* newPhone = new Phonebook[size];
        for (int i = 0; i < size - 1; i++)
        {
            newPhone[i] = phone[i];
        }

        cout << "Enter surname: ";
        cin >> newPhone[size - 1].name;
        cout << "Enter phone number: ";
        cin >> newPhone[size - 1].phone;

        delete[]phone;
        phone = newPhone;
    }
}

void deletePhone(Phonebook*& phone, int& size, int index)
{
    if (phone == nullptr)
    {
        cout << "Your phonebook is empty" << endl;
        return;
    }
    else
    {
        size--;
        Phonebook* newPhone = new Phonebook[size];
        for (int i = 0, j = 0; i < size + 1; i++)
        {
            if(i != index - 1)
            {
                newPhone[j] = phone[i];
                j++;
            }
        }

        delete[]phone;
        phone = newPhone;
    }
}

void show(Phonebook* phone, int size)
{
    if (phone == nullptr)
    {
        cout << "Phonebook is empry" << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Person " << i + 1 << ":" << endl;
            cout << "Surname = " << phone[i].name << endl;
            cout << "Phone number = " << phone[i].phone << endl;
        }
    }
}

int main()
{
    int size = 0, num, index;
    Phonebook* phonebook = nullptr;

    cout << "Choose option: " << endl;
    cout << "1)add user in phonebook" << endl;
    cout << "2)delete user from phonebook" << endl;
    cout << "3)show" << endl;
    cout << "4)exit" << endl;
    cin >> num;

    while (num != 4)
    {
        switch (num)
        {
            case 1:
                addPhone(phonebook, size);
                cout << "Choose option: " << endl;
                cout << "1)add user in phonebook" << endl;
                cout << "2)delete user from phonebook" << endl;
                cout << "3)show" << endl;
                cout << "4)exit" << endl;
                cin >> num;
                break;
            case 2:
                cout << "Enter number of user who want delete: ";
                cin >> index;
                deletePhone(phonebook, size, index);
                cout << "Choose option: " << endl;
                cout << "1)add user in phonebook" << endl;
                cout << "2)delete user from phonebook" << endl;
                cout << "3)show" << endl;
                cout << "4)exit" << endl;
                cin >> num;
                break;
            case 3:
                show(phonebook, size);
                cout << "Choose option: " << endl;
                cout << "1)add user in phonebook" << endl;
                cout << "2)delete user from phonebook" << endl;
                cout << "3)show" << endl;
                cout << "4)exit" << endl;
                cin >> num;
                break;
            default:
                cout << "You chose wrong option" << endl;
                cout << "Choose option again:" << endl;
                cout << "1)add user in phonebook" << endl;
                cout << "2)delete user from phonebook" << endl;
                cout << "3)show" << endl;
                cout << "4)exit" << endl;
                cin >> num;
                break;
        }
    }
}
