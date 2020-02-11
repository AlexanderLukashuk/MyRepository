#include <iostream>
using namespace std;
int main ()
{
    int day;

    cout << "Enter the day number of week: ";
    cin >> day;

    while (day > 0 && day < 8)
    {
        switch (day)
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
        cout << "Enter again the day number of week: ";
        cin >> day;
    }
    cout << "You entered wrong day number of week\n";
    return 0;
}
