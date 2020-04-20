#include <iostream>
using namespace std;

class Employer;

class Student
{
private:
    char IIN[20];
    char name[100];
    char spec[100];
    friend void show(const Student& obj);
    friend bool equals(const Student& obj1, const Employer& obj2);
public:
    Student(const char IIN[], const char name[], const char spec[])
    {
        strcpy(this->IIN, IIN);
        strcpy(this->name, name);
        strcpy(this->spec, spec);
    }
};

class Employer
{
private:
    char IIN[20];
    char name[100];
    char dolzhnost[100];
    friend void show(const Employer& obj);
    friend bool equals(const Student& obj1, const Employer& obj2);
public:
    Employer(const char IIN[], const char name[], const char dolzhnost[])
    {
        strcpy(this->IIN, IIN);
        strcpy(this->name, name);
        strcpy(this->dolzhnost, dolzhnost);
    }
};

void show(const Student& obj)
{
    cout << "Name: " << obj.name << endl;
    cout << "IIN: " << obj.IIN << endl;
    cout << "Spec: " << obj.spec << endl;
}

void show(const Employer& obj)
{
    cout << "Name: " << obj.name << endl;
    cout << "IIN: " << obj.IIN << endl;
    cout << "Dolzhnost: " << obj.dolzhnost << endl;
}

bool equals(const Student& obj1, const Employer& obj2)
{
    if (strcmp(obj1.IIN, obj2.IIN) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Student st1("88417331", "Alex", "IT");
    Student st2("432532", "Oleg", "IT");
    Employer emp1("88417331", "Alex", "Worker");

    show(st1);
    cout << endl;
    show(st2);
    cout << endl;
    show(emp1);
    cout << endl;
    cout << equals(st1, emp1) << endl;
    cout << equals(st2, emp1) << endl;

}