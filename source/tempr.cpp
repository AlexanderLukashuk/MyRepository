#include <iostream>
int celtempr(int);
int main ()
{
using namespace std;
int cel;
cout << "Enter a Celsius value: ";
cin >> cel;
int fahr = celtempr(cel);
cout << cel << " degrees Celsius is " << fahr << " degrees Fahrenheit." << endl;
return 0;
}
int celtempr(int fr)
{
return 1.8 * fr + 32;
}
