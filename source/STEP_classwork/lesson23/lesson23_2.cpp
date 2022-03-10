#include <iostream>
#include <vector>
#include <string>
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

class Child : public Parent 
{
public:
    void showParentsFields()
    {
        setNumber1(141);
        cout << getNumber1() << endl;
        number2 = 588;
        cout << "number2 = " << number2 << endl;
        number3 = 354;
        cout << "number3 = " << number3 << endl;
    }
};

int main()
{
    Child child;
    //child.number1; //error
    //child.number2;
    child.number3;

    child.showParentsFields();
}