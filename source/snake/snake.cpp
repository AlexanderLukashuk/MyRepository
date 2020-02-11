#include <iostream>
using namespace std;

enum Tea
{
    BLACK = 101,
    RED = 10010,
    GREEN = 100001
};
int main ()
{
    int number;
    Tea entered;
    cout << "Enter number 1-3:" << endl;
    cin >> number;
    switch(number)
    {
        case 1:
            entered = Tea::BLACK;
            break;
        case 2:
            entered = Tea::RED;
            break;
        case 3:
            entered = Tea::GREEN;
            break;
    }
    cout << entered << endl;
    return 0;
}
