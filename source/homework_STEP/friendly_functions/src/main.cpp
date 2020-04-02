#include <iostream>
#include "../include/date.h"
#include "../include/time.h"
#include "../include/dateManager.h"
using namespace std;

int main()
{
    int d, m, y;
    int hr, min, sec;
    Date date(41, 1, 1990);
    Time time(12, 34, 45);
    date.toString();
    time.toString();
    cout << showDateTime(date, time);
    cout << "Enter day: ";
    cin >> d;
    cout << "Enter month: ";
    cin >> m;
    cout << "Enter year: ";
    cin >> y;
    date.setDay(d);
    date.setMonth(m);
    date.setYear(y);
    date.toString();
    cout << "Set time: " << endl;
    cout << "Hours: ";
    cin >> hr;
    cout << "Minutes: ";
    cin >> min;
    cout << "Seconds: ";
    cin >> sec;
    time.setHr(hr);
    time.setMin(min);
    time.setSec(sec);
    time.toString();
    cout << showDateTime(date, time);


}