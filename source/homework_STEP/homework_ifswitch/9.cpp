#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    int num3, pow_of_num, result2;

    cout << "Enter any number:";
    cin >> num3;
    cout << "Choose power of number:";
    cout << "1)^0 2)^1 3)^2 4)^3 5)^4 6)^5 7)^6 8)^7" << endl;
    cin >> pow_of_num;

    if (pow_of_num == 1)
    {
        result2 = pow(num3, 0);
        cout << "Your number in power 0 = " << result2 << endl;
    }
else if (pow_of_num == 2)
    {
        result2 = pow(num3, 1);
        cout << "Your number in power 1 = " << result2 << endl;
    }
    else if (pow_of_num == 3)
    {
        result2 = pow(num3, 2);
        cout << "Your number in power 2 = " << result2 << endl;
    }
    else if (pow_of_num == 4)
    {
        result2 = pow(num3, 3);
        cout << "Your number in power 3 = " << result2 << endl;
    }
    else if (pow_of_num == 5)
    {
        result2 = pow(num3, 4);
        cout << "Your number in power 4 = " << result2 << endl;
    }
    else if (pow_of_num == 6)
    {
        result2 = pow(num3, 5);
        cout << "Your number in power 5 = " << result2 << endl;
    }
else if (pow_of_num == 7)
    {
        result2 = pow(num3, 6);
        cout << "Your number in power 6 = " << result2 << endl;
    }
    else if (pow_of_num == 8)
    {
        result2 = pow(num3, 7);
        cout << "Your number in power 7 = " << result2 << endl;
    }
    else
    {
        cout << "You entered wrong number" << endl;
    }
    return 0;
}
