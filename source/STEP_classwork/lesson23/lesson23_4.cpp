#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
};

class Employee : public Person
{
protected:
    double salary;
};

class Teacher : public Employee
{
protected:
    string subject;
public:
    void init()
    {
        name = "Sanya";
        age = 17;
        subject = "C++";
        salary = 0;
    }

    void show()
    {
        cout << name << " " << age << endl;
        cout << subject << endl;
        cout << salary << endl;
    }
};

int main()
{
    Teacher t;
    t.init();
    t.show();

}