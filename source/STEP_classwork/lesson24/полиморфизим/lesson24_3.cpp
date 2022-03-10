#include <iostream>
using namespace std;

class Pet
{
protected:
    string name;

public:
    Pet(string name) : name(name) {}
    virtual void speak()
    {
        cout << name << " says "
             << "*%$#)&" << endl;
    }
};

class Cat : public Pet
{
public:
    Cat() : Pet("cat") {}
    virtual void speak() override
    {
        cout << name << " says meow" << endl;
    }
};

class Dog : public Pet
{
public:
    Dog() : Pet("dog") {}
    virtual void speak() override
    {
        cout << name << " says bark" << endl;
    }
};

void golos(Pet& p)
{
    p.speak();
}

int main()
{
    Dog dog;

    Cat cat;

    Pet *pptr = &cat;
    Pet& pref = cat;

    pptr->speak();
    pref.speak();

    //golos(dog);
    //golos(cat);
}