#include <iostream>
using namespace std;

class Person
{
private:
protected:
    string name;
    int age;

public:
    Person() { cout << "CTOR Person\n"; }
    virtual ~Person() { cout << "DESTR Person\n"; }

    virtual void show() const
    {
        cout << "Person's show\n";
    }
};

//class Student final : public Person запрет на наследование от Student
class Student : public Person
{
public:
    Student() { cout << "CTOR Student\n"; }
    virtual ~Student() { cout << "DESTR Student\n"; }

    virtual void show() const override
    {
        cout << "Student's show\n";
    }
};

class Teacher : public Person
{
};

int main()
{
    Person *p = new Student();
    p->show();
    //dynamic_cast<Student*>(p)->show();
    //Person &p = st;
    //dynamic_cast<Student*>(p)->show();

    delete p;

}