#include <iostream>
using namespace std;
int main ()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "\"" << num << "\"" << " = " << char(num) << endl;
    return 0;
}
