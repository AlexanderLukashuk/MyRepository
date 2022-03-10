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

    virtual void show() const = 0;
};

void Person::show() const
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}

//class Student final : public Person запрет на наследование от Student
class Student : public Person
{
    string spec;

public:
    Student() {}
    Student(const string &name, const int age, const string &spec) : Person(name, age), spec(spec)
    {
        //cout << "ctor params student\n";
    }

    virtual ~Student()
    {
        //cout << "DESTR Student\n";
    }

    virtual void show() const override
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Spec: " << spec << endl;
    }
};

class Teacher : public Person
{
public:
    ~Teacher()
    {
        cout << "DESTR Teacher\n";
    }
    virtual void show() const override
    {
        Person::show();
    }
};

//void func(unique_ptr<Person> ptr)
void func(Person *ptr)
{

}

int main()
{
    unique_ptr<Person> p = make_unique<Student>("Alex", 20, "KsiPO");
    p->show();
    (*p).show();

    //p = make_unique<Student>("Milena", 16, "rabotaga");
    p = make_unique<Teacher>();
    p->show();

    //func(move(p));
    func(p.get());

    cin.get();

}