#include <iostream>
using namespace std;
int main ()
{
    int salary, temp_sal;
    double workT;

    cout << "Enter introduces an hourly rate: ";
    cin >> temp_sal;
    cout << "Enter salary which you want: ";
    cin >> salary;

    workT = salary / (double)temp_sal;
    cout << "The janitor must work " << workT << endl;
    return 0;
}
