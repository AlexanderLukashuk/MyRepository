#include <iostream>
using namespace std;

class Microwave
{
protected:
    int power;
    string model;
    string food;
public:
    Microwave() : power() {}
    Microwave(int power, string model, string food) : power(power), model(model), food(food) {}
    
    void characteristics()
    {
        cout << "Power: " << power << endl;
        cout << "Model: " << model << endl;
    }
};

class Toaster
{
protected:
    string bread;
public:
    Toaster() {}
    Toaster(string bread) : bread(bread) {}

    void makeToast()
    {
        cout << bread << " is fried" << endl;
        cout << "It is very hot" << endl;
    }
};

class ToasterMicrowave : public Toaster, public Microwave
{
public:
    ToasterMicrowave() {}
    ToasterMicrowave(int power, string model, string bread, string food)
        : Microwave(power, model, food), Toaster(bread) {}

    void working()
    {
        cout << food << " was warmed under a capacity of " << power << " by " << model << endl;
        cout << bread << "was fried" << endl;
    }
};

int main()
{
    ToasterMicrowave tm(500, "FG-h710X", "toast", "pizza");

    tm.working();
}