#include <iostream>
using namespace std;

void sum(double num1, double num2)
{
    cout << num1 + num2 << endl;
}

void division(double num1, double num2)
{
    cout << num1 / num2 << endl;
}

void vichit(double num1, double num2)
{
    cout << num1 - num2 << endl;
}

void multiplication(double num1, double num2)
{
    cout << num1 * num2 << endl;
}

int main()
{
    void (*ptr[4])(double, double) = { sum, vichit, multiplication, division };
    int option = 0;
    double arg1, arg2;

    while (option != 4)
    {
        cout << "0 - sum" << endl;
        cout << "1 - vichitanie" << endl;
        cout << "2 - multiplication" << endl;
        cout << "3 - division" << endl;
        cin >> option;

        cout << "Enter first arg: ";
        cin >> arg1;
        cout << "Enter second arg: ";
        cin >> arg2;

        ptr[option](arg1, arg2);
    }
}
