#include <iostream>
using namespace std;

void hexadecimal(int n)
{
    cout << hex << n << endl;
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    hexadecimal(num);

    return 0;
}
