#include <iostream>
using namespace std;
int main ()
{
    const int work_time = 8;
    const int pereriv = 30;
    int count, minutes;

    cout << "Enter count of contacts and minutes ";
    cin >> count >> minutes;

    int work = work_time * 60 - pereriv - count * minutes;
    int work_hours = work / 60;
    int work_minutes = work % 60;

    cout << "work time = " << work_hours << ":" << work_minutes << endl;;
    return 0; 
}
