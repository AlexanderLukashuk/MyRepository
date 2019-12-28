#include <iostream>
using namespace std;
int main ()
{
    int mark1, mark2, mark3, mark4, mark5, sum;

    cout << "Enter five assessments: ";
    cin >> mark1 >> mark2 >> mark3 >> mark4 >> mark5;

    sum = (mark1 + mark2 + mark3 + mark4 + mark5) / 5;

    if (sum >= 4)
    {
        cout << "Student admitted to exam" << endl;
    }
    else
    {
        cout << "Student do not admitted to exam" << endl;
    }
    return 0;
}
