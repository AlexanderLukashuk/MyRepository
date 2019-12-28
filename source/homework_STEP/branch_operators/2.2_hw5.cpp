#include <iostream>
using namespace std;
int main ()
{
    int day;

    cout << "Enter the day number of week: ";
    cin >> day;
    switch(day)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << "Working day\n";
            break;
        case 6:
            cout << "Saturday\n";
            break;
        case 7:
            cout << "Sunday\n";
            break;
    }
    return 0;
}
