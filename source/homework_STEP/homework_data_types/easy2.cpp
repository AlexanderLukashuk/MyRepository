#include <iostream>
using namespace std;
int main ()
{
    const long long count = 1024;
    const long long count2 = 8;
    int GB;
    long long bit;

    cout << "Enter amount of memory in GB: ";
    cin >> GB;

    bit = GB * count * count * count * count2;
    cout << "Bits = " << bit << endl;
    return 0;
}
