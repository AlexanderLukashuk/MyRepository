#include <iostream>
using namespace std;

class Person
{
private:
protected:
    string name;
    int age;

public:
    Person() : age() {}
    Person(const string &name, const int age) : name(name), age(age) {}
    virtual ~Person() {}
};

//class Student final : public Person запрет на наследование от Student
class Student : public Person
{
    string spec;
public:
    Student() {}
    Student(const string &name, const int age, const string &spec) : Person(name, age), spec(spec) {}
    virtual ~Student() { cout << "DESTR Student\n"; }
};

int main()
{
    Person *p = new Student();

    delete p;

}