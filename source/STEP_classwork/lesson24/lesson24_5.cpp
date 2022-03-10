#include <iostream>
using namespace std;

class Human
{
protected:
    string name;
    string DateOfBirth;
public:
    Human() {}
    Human(string name, string DateOfBirth) : name(name), DateOfBirth(DateOfBirth) {}
    
    void eat()
    {
        cout << name << " is eating" << endl;
    }

    void show()
    {
        cout << "Name: " << name << endl;
        cout << "Date of birth: " << DateOfBirth << endl;
    }
};

class Robot
{
protected:
    string model;
    string DateOfCreating;
public:
    Robot() {}
    Robot(string model, string DateOfCreating) : model(model), DateOfCreating(DateOfCreating) {}
    
    void charge()
    {
        cout << model << " is charging" << endl;
    }

    void show()
    {
        cout << "Model: " << model << endl;
        cout << "Data of creating: " << DateOfCreating << endl;
    }
};

class Cyborg : public Human, public Robot
{
public:
    Cyborg() {};
    Cyborg(string name, string DateOfBirth, string model, string DateOfCreating)
        : Human(name, DateOfBirth), Robot(model, DateOfCreating) {}

    void show()
    {
        //cout << "Name: " << name << endl;
        //cout << "Date of birth: " << DataOfBirth << endl;
        //cout << "Model: " << model << endl;
        //cout << "Data of creating: " << DataOfCreating << endl;
        Human::show();
        Robot::show();
    }
};

int main()
{
    Cyborg c("John", "13.10.1998", "XH-970", "04.07.2031");

    c.show();
    c.eat();
    c.charge();
}