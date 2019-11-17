#include <iostream>
using namespace std;
int main ()
{
	const int degsec = 60;
	const int degmin = 60;
	double deg, min, sec, arcMin, arcSec, arc;
	
	cout << "Enter a latitude in degrees, minutes, and seconds: " << endl;
	cout << "Firts, enter the degrees: ";
	cin >> deg;
	cout << "Next, enter the minute of arc: ";
	cin >> min;
	cout << "Finally, enter the second of arc: ";
	cin >> sec;
	
	arcMin = min / degmin;
	arcSec = (sec / degsec) / degmin;
	arc = deg + arcMin + arcSec;
	
	cout << deg << " degrees, " << min << " minutes , " << sec << " seconds = ";
	cout << arc << " degrees" << endl;
	return 0;
}
