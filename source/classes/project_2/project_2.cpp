#include <iostream>
using namespace std;

class Children
{
    private:
    char name[50];
    char lastName[50];
    int age;
    public:
    void getData(char n[], char lastN[], int a)
    {
        strcpy(name, n);
        strcpy(lastName, lastN);
        age = a;
    }

    void show(Children obj)
    {
        cout << obj.name << endl;
        cout << obj.lastName << endl;
        cout << obj.age << endl;
        cout << endl;
    }
};

int main()
{
    Children first;
    Children second;
    char childName[50];
    char childLastName[50];
    int childAge;

    cout << "Enter children name: ";
    cin.getline(childName, 50);
    cout << "Enter children last name: ";
    cin.getline(childLastName, 50);
    cout << "Enter age of children: ";
    cin >> childAge;
    cin.get();

    first.getData(childName, childLastName, childAge);

    cout << "Enter children name: ";
    cin.getline(childName, 50);
    cout << "Enter children last name: ";
    cin.getline(childLastName, 50);
    cout << "Enter age of children: ";
    cin >> childAge;
    cin.get();

    second.getData(childName, childLastName, childAge);
    first.show(first);
    second.show(second);

}