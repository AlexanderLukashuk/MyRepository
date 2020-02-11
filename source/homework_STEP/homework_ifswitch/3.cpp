#include <iostream>
using namespace std;
int main ()
{
    int num;
    cout << "Enter number:";
    cin >> num;

    if (num > 0)
    {
        cout << num << " is positive number" << endl;
    }
    else if (num == 0)
    {
        cout << num << " = 0" << endl;
    }
    else
    {
        cout << num << " is negative number" << endl;
    }
    return 0;
}
