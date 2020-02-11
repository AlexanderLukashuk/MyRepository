#include <iostream>
using namespace std;
int main ()
{
    int year, b_year, age;

    cout << "Enter current year: ";
    cin >> year;
    cout << "Enter the year of your birth: ";
    cin >> b_year;

    age = year - b_year;
    cout << "Your age is " << age << endl;
    return 0;
}
