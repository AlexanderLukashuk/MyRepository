#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    const int cnum = 1;
    int* ptr;
    ptr = &num1;
    ptr = &num2;
    //ptr = &cnum;
    *ptr = 10;
    cout << *ptr << endl;

    const int* ptr1;
    ptr1 = &num1;
    ptr1 = &num2;
    ptr1 = &cnum;
    //*ptr1 = 10;
    cout << *ptr1;

    int* const ptr2 = &num1;
    //ptr2 = &num2;
    //int* const ptr3 = &cnum;
    *ptr2 = 10;
    cout << *ptr2 << endl;

    const int* const ptr4 = &num1;
    //ptr4 = &num1;
    cout << *ptr4 << endl;
    const int* const ptr5 = &cnum;
    //*ptr5 = 10;
    cout << *ptr5 << endl;


    return 0;
}
