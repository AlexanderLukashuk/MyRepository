#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Person
{
private:
    string name;
    int age;
    friend ostream& operator<<(ostream& out, const Person& obj);
    //friend bool operator<(const Person& l, const Person& r);
public:
    Person() : age() {}
    Person(string name, int age) : name(name), age(age) {}

    const string& getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }
};

ostream& operator<<(ostream& out, const Person& obj)
{
    out << obj.name << " " << obj.age;
    return out;
}

/*bool operator<(const Person& l, const Person& r)
{
    return l.getName() < r.getName();
}*/

class ComparePersonByAge
{
public:
    bool operator()(const Person& l, const Person& r)
    {
        return l.getAge() < r.getAge();
    }
};

class ComparePersonByName
{
public:
    bool operator()(const Person& l, const Person& r)
    {
        return l.getName() < r.getName();
    }
};

int main()
{
    priority_queue<Person, vector<Person>, ComparePersonByAge> que;
    //priority_queue<Person, vector<Person>, ComparePersonByName> que;


    que.push(Person("Bob", 5));
    que.push(Person("Adam", 10));
    que.push(Person("Bagdan", 7));

    //cout << que.top() << endl;

    while (!que.empty())
    {
        cout << que.top() << endl;
        que.pop();
    }
}