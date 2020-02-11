#include <iostream>
int main ()
{
    using namespace std;
    int a = 5;
    int *px = &a;
    int *px2 = &a;

    cout << "a\t " << a << endl;
    cout << "px = " << px << endl;
    cout << "*px = " << *px << endl;
    cout << "Address + 1 = " << px + 1 << endl;
    cout << "a = " << a << endl;
    cout << "now *px = " << *px << endl;

    *px2 = 2;

    cout << "now a\t" << a << endl;
    cout << "a = " << a << endl;
    return 0;
}
