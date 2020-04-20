#include <iostream>
double lightyer(double);
int main ()
{
using namespace std;
double ly;
cout << "Enter the number of light years: ";
cin >> ly;
double astun = lightyer(ly);
cout << ly << " light years = " << astun << " astronomical unit" << endl;
return 0;
}
double lightyer(double as)
{
return 63240 * as;
}
