#include <iostream>
int furlgtolb(int);
int main ()
{
using namespace std;
int furlg;
cout << "Enter the distance in furlong: ";
cin >> furlg;
int yard = furlgtolb(furlg);
cout << furlg << " furlong = " << yard << " yard." << endl;
return 0;
}
int furlgtolb(int fur)
{
return 220 * fur;
}
