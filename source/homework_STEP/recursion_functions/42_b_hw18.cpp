#include <iostream>
using namespace std;

int date(int year, int month, int day)
{
    int leap_year = year / 4;
    int year1 = leap_year * 366;
    int allDay = (((year - leap_year) * 365) + year1) + day;

    for (int i = 1; i <= month - 1; i++)
    {
        if (i == 2 && year % 4 != 0)
        {
            allDay += 28;
        }
        else
        {
        allDay += 29;
        }

        if (i == 8)
        {
            allDay += 31;
        }
        else if (i % 2 != 0 && i != 2)
        {
            allDay += 31;
        }
        else
        {
            allDay += 30;
        }
    }

    //allDay = allDay % 7;

    return allDay - 3;
}

int main()
{
    int year, month, day;

    cout << "Enter taday's date\n";
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    cout << date(year, month, day) << endl;

    return 0;
}
