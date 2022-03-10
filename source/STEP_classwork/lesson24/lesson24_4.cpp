#include <iostream>
using namespace std;

class Entity
{
    int id;
};

class Cat : public Entity
{

};

class Dog : public Entity
{

};

class CatDog : public Cat, public Dog
{
public:
    CatDog()
    {
        id = 111;
    }
};

int main()
{

}