#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    int num = 10;

    while (num < 21)
    {
        cout << num << " in power 2 = " << pow(num, 2) << endl;
        num++;
    }
    return 0;
}
