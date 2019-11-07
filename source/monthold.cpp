#include <iostream>
int oldmonth(int);
int main ()
{
using namespace std;
int yer;
cout << "Enter your age: ";
cin >> yer;
int month = oldmonth(yer);
cout << "Your age in month is " << month << endl;
return 0;
}
int oldmonth(int mn)
{
return 12 * mn;
}
