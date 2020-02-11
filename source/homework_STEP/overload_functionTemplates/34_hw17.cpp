#include <iostream>
#include <math.h>
using namespace std;

template <typename DB>
void roots(DB a, DB b, DB c, DB& x1, DB& x2)
{
    double D;
    D = b * b - (4 * a * c);

    if (D > 0)
    {
        x1 = ((-b) - sqrt(D)) / (2 * a);
        x2 = ((-b) + sqrt(D)) / (2 * a);
    }
    else if (D == 0)
    {
        x1 = (-b) / (2 * a);
        x2 = (-b) / (2 * a);
    }
    else if (D < 0)
    {
        cout << "no roots" << endl;
    }
}

int main()
{
    double a, b, c;
    double x1, x2;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;

    roots(a, b, c, x1, x2);
    if (x1 == x2)
    {
        cout << "x1 = x2 = " << x1 << endl;
    }
    else
    {
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    return 0;
}
