#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    Person() : age() {}
    Person(string name, int age) : name(name), age(age) {}
};

class Employee : public Person
{
protected:
    double salary;
public:
    Employee() : salary() {}
    Employee(string name, int age, double salary) 
        : salary(salary), Person(name, age) {}

    void show()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Teacher : public Employee
{
protected:
    string subject;
public:
    Teacher() {}
    Teacher(string name, int age, double salary, string subject)
        : subject(subject), Employee(name, age, salary) {}

    void show()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main()
{
    //Employee empl("Igor", 20, 20000);
    //empl.show();

    Teacher teacher("Mihail", 43, 350000, "Python");
    teacher.show();
}