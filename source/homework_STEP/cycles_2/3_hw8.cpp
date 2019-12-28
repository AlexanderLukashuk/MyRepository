#include <iostream>
using namespace std;
int main ()
{
    int sred = 0;
    for (int i = 1; i <= 1000; i++)
    {
        sred += i;
    }
    cout << "Sred = " << sred / 1000 << endl;
    return 0;
}
