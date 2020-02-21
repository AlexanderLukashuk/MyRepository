#include <iostream>
using namespace std;

struct Phonebook
{
    char name[50];
    int phone;
};

void addPhone(Phonebook*& phone, int& size)
{
    if (phone == nullptr)
    {
        size++;
        phone = new Phonebook[size];

        cout << "Enter name: ";
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

        cout << "Enter name: ";
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
            cout << "Name = " << phone[i].name << endl;
            cout << "Phone number = " << phone[i].phone << endl;
        }
    }
}

void sortPhone(Phonebook* phones, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (phones[j].phone > phones[j + 1].phone)
            {
                Phonebook temp = phones[j];
                phones[j] = phones[j + 1];
                phones[j + 1] = temp;
            }
        }
    }
}

void sortName(Phonebook* phones, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (phones[j].name[0] > phones[j + 1].name[0])
            {
                Phonebook temp = phones[j];
                phones[j] = phones[j + 1];
                phones[j + 1] = temp;
            }
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
    cout << "4)Sort by phone numbers" << endl;
    cout << "5)Sort by name" << endl;
    cout << "6)exit" << endl;
    cin >> num;

    while (num != 6)
    {
        switch (num)
        {
            case 1:
                addPhone(phonebook, size);
                cout << "Choose option: " << endl;
                cout << "1)add user in phonebook" << endl;
                cout << "2)delete user from phonebook" << endl;
                cout << "3)show" << endl;
                cout << "4)Sort by phone numbers" << endl;
                cout << "5)Sort by name" << endl;
                cout << "6)exit" << endl;
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
                cout << "4)Sort by phone numbers" << endl;
                cout << "5)Sort by name" << endl;
                cout << "6)exit" << endl;
                cin >> num;
                break;
            case 3:
                show(phonebook, size);
                cout << "Choose option: " << endl;
                cout << "1)add user in phonebook" << endl;
                cout << "2)delete user from phonebook" << endl;
                cout << "3)show" << endl;
                cout << "4)Sort by phone numbers" << endl;
                cout << "5)Sort by name" << endl;
                cout << "6)exit" << endl;
                cin >> num;
                break;
            case 4:
                sortPhone(phonebook, size);
                cout << "Choose option: " << endl;
                cout << "1)add user in phonebook" << endl;
                cout << "2)delete user from phonebook" << endl;
                cout << "3)show" << endl;
                cout << "4)Sort by phone numbers" << endl;
                cout << "5)Sort by name" << endl;
                cout << "6)exit" << endl;
                cin >> num;
                break;
            case 5:
                sortName(phonebook, size);
                cout << "Choose option: " << endl;
                cout << "1)add user in phonebook" << endl;
                cout << "2)delete user from phonebook" << endl;
                cout << "3)show" << endl;
                cout << "4)Sort by phone numbers" << endl;
                cout << "5)Sort by name" << endl;
                cout << "6)exit" << endl;
                cin >> num;
                break;
            default:
                cout << "You chose wrong option" << endl;
                cout << "Choose option again:" << endl;
                cout << "1)add user in phonebook" << endl;
                cout << "2)delete user from phonebook" << endl;
                cout << "3)show" << endl;
                cout << "4)Sort by phone numbers" << endl;
                cout << "5)Sort by name" << endl;
                cout << "6)exit" << endl;
                cin >> num;
                break;
        }
    }
}
