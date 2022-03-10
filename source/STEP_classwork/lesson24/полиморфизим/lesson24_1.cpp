#include <iostream>
using namespace std;

class Pet
{
protected:
    string name;

public:
    Pet(string name) : name(name) {}
    void speak()
    {
        cout << name << " says "
             << "*%$#)&" << endl;
    }
};

class Cat : public Pet
{
public:
    Cat() : Pet("cat") {}
    void speak()
    {
        cout << name << " says meow" << endl;
    }
};

class Dog : public Pet
{
public:
    Dog() : Pet("dog") {}
    void speak()
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
    //dog.speak();

    Cat cat;
    //cat.speak();

    //Pet p = dog;
    Pet *pptr = &dog;
    Pet& pref = dog;

    pptr->speak();
    pref.speak();

    /*Pet* array[10];
    array[0] = new Dog();
    array[1] = new Cat();
    array[2] = new Dog();
    array[3] = new Dog();
    array[4] = new Cat();
    array[5] = new Dog();*/

    //golos(dog);
    //golos(cat);
}