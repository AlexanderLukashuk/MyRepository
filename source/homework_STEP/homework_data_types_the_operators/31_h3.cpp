#include <iostream>
using namespace std;
int main ()
{
    double students, pass_ex, debtors, doubles, norm_students;

    cout << "Enter number of students: ";
    cin >> students;
    cout << "Enter number of students who passed exam: ";
    cin >> pass_ex;
    cout << "And enter number of students who did not passed exam: ";
    cin >> debtors;

    doubles = debtors / students * 100;
    norm_students = pass_ex / students * 100;

    cout << (int)doubles << "\% doubles in group" << endl;
    cout << (int)norm_students << "\% excellent students in group" << endl;
    return 0;
}
