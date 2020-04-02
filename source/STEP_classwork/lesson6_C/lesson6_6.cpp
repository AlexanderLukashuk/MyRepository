#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cout << (double)5 / 2 << endl;
    cout << static_cast<double>(5) / 2 << endl;

    //dynamic_cast
    
    //const_cast
    const int number = pow(2, 8);
    cout << number << endl;
    const_cast<int&>(number) = 10;
    cout << number << endl;

    //reinterpret_cast //калламбур-преобразование
    double dnum = 5.78;
    cout << dnum << ": ";
    for (int i = 63; i >= 0; i--)
    {
        cout << (reinterpret_cast<long long&>(dnum) >> i & 1);
        //cout << endl;
    }
    //cout << reinterpret_cast<long long&>(dnum) << endl;
    cout << endl;

    //Parse
    /*if (TryParse())
    {
        Parse();
    }*/
    
    //cout << (double)5 / 2 << endl;
    //const int num = pow(2, 2);
    //double num = 5.5;
    //long long num2 = num;
    //int* mas = new int[5]{ 1, 2, 3, 4, 5 };

    //int* mas2 = new int[5];
    //int* mas2 = mas;
    //mas = nullptr;
    /*for (int i = 0; i < 5; i++)
    {
        mas2[i] = mas[i];
    }*/

    //delete[] mas;

    return 0;
}
