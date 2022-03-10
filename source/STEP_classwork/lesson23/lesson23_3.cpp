#include <iostream>
using namespace std;

class Parent
{
private:
    int number1;
protected:
    int number2;
public:
    int number3;

    void setNumber1(int n)
    {
        number1 = n;
    }

    const int& getNumber1() const
    {
        return number1;
    } 
};

//class Child : public Parent //открытое наследование
//class Child : protected Parent // все public методы и поля стали protected 
//class Child : private Parent // все методы и поля стали private
class Child : Parent // все методы и поля стали private
{

};

int main()
{
}