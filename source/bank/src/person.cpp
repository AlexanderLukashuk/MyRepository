#include <string>
#include "../include/person.hpp"

Person::Person() : name(nullptr), lastName(nullptr), age(0) {}

Person::Person(std::string name, std::string lastName, int age)
{
    if (name.empty() != true)
    {
        this->name = name;
    }

    if (lastName.empty() != true)
    {
        this->lastName = lastName;
    }

    if (age > 0)
    {
        this->age = age;
    }
}

void Person::setName(std::string name)
{
    if (name.empty() != true)
    {
        this->name = name;
    }
}

void Person::setLastName(std::string lastName)
{
    if (lastName.empty() != true)
    {
        this->lastName = lastName;
    }
}

void Person::setAge(int age)
{
    if (age > 0)
    {
        this->age = age;
    }
}

std::string Person::getName()
{
    return name;
}

std::string Person::getLastName()
{
    return lastName;
}

int Person::getAge()
{
    return age;
}