#include <iostream>
#include <cmath>
int main ()
{
using namespace std;
int y, z;
double n;
//double x, y, z;
//double x = (int y);
double x;
cout << "Enter first number: ";
cin >>  y;
cout << "Enter second number: ";
cin >> z;
n = sqrt(31);
cout << n << endl;
x = y + z;
cout << y << " + " << z << " = " << x << endl;
x = y - z;
cout << y << " - " << z << " = " << x << endl;
x = y * z;
cout << y << " * " << z << " = " << x << endl;
x = (double) y / z;
cout << y << " / " << z << " = " << x << endl;
return 0;
}
