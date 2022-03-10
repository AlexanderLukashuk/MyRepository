#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pet
{
//private:
public:
    string name;
    int age;
    
    void show()
    {
        cout << name << " " << age << endl;
    }
};

class Cat : public Pet
{
public:
    void clean()
    {
        cout << "Cat " << name << " cleans itself" << endl;
    }
};

class Dog : public Pet
{
public:
    int kmOfChuika;
    int age;
    void show()
    {
        cout << name << " " << age << " " << kmOfChuika << endl;
    }
};

class Wolf
{
};

int main()
{
    Cat cat;
    cat.name = "Cleo";
    cat.age = 4;
    cat.show();
    cat.clean();

    Dog dog;
    dog.name = "Rax";

    dog.age = 5;
    dog.Pet::age = 7;

    dog.kmOfChuika = 5;
    dog.show();

    dog.Pet::show(); //не часто используется

}