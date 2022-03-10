#include <iostream>
using namespace std;

class Pet
{
protected:
    string name;
    int age;
public:
    Pet() : age() {}
    Pet(string name, int age) : age(age), name(name) {}
    virtual ~Pet() {}
    virtual void speak() = 0;

    virtual void show() = 0;
};

void Pet::show()
{
    cout << name << " " << age << endl; 
}

class Dog : public Pet
{
public:
    Dog() {}
    Dog(string name, int age) : Pet(name, age) {}

    virtual void speak() override
    {
        cout << name << " says bark\n";
    }

    virtual void show() override
    {
        Pet::show();
    }
};

int main()
{
    Pet* ptr = new Dog("Rax", 5);
    ptr->speak();
    ptr->show();
}