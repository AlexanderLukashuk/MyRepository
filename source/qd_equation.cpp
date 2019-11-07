#include <iostream>
#include <cmath>
int main ()
{
	using namespace std;
	double a, b, c, x1, x2, d;
	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter secint number: ";
	cin >> b;
	cout << "Enter third number: ";
	cin >> c;

	d = pow(b, 2) -(4 * a * c);
	x1 = (-1 * b - sqrt(d)) / (2 * a);
	x2 = (-1 * b + sqrt(d)) / (2 * a);

	cout << "Discriminant = " << d << endl;
	cout << "First root ot the equation(x1) = " << x1 << endl;
	cout << "Second root ot the equation(x2) = " << x2 << endl;
	return 0;
}
