#include <iostream>
int main ()
{
	using namespace std;
	const double inch = 0.8;
	double heightFeet, heightInch;

	cout << "Enter your height inches: ";
	cin >> heightInch;
	heightFeet = heightInch * inch;
	
	cout << "Your height in feet = " << heightFeet;
	cout << ", inches = " << heightInch << endl;
	return 0;
}
