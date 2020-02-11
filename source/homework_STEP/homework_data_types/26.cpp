#include <iostream>
using namespace std;
int main ()
{
    double num, num2;
    int num3;

    cout << "Enter a fractional number: ";
    cin >> num;

    num2 = num * 100;
    num2 = (int)num2;
    num2 /= 100;
    num2 = (double)num2;
    num3 = num * 1000;
    num3 = (int)num3;
    num3 = num3 % 10;

    if (num3 > 4)
    {
        num2 += 0.01;
    }
    cout << "Now number = " << num2 << endl;
    
    return 0; 
}
