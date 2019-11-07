#include <iostream>
void timee(int);
void timeee(int);
using namespace std;
int main ()
{
int hour, minute;
cout << "Enter the number of hours: ";
cin >> hour;
timee(hour);
cout << "Enter the number of minutes: ";
cin >> minute;
timee(minute);
//cout << "Time: " << hour << ":" << minute << endl;
return 0;
}
void timee(int h)
{
	cout << "Time: " << h << ":";
}
void timeee(int m)
{
	cout << m << endl;
}
