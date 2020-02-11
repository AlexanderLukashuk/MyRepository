#include <iostream>
using namespace std;

void triangle(int h)
{
    for (int i = 0; i <= h * 2; i += 2)
    {
        //if (i == 0)
        //{
            //cout << "                        ";
            //cout << "\b";
            //cout << "^";
        //}
        //else
        //{
            //cout << "                        ";
            //for (int m = 0; m <= i; m += 2)
            //{
            //cout << "\b";
            //}

            for (int j = 0; j < i + 1; j++)
            {
                cout << "^";
            }
        //}
            cout << endl;
    }
}

int main()
{
    int h;

    cout << "Enter height of triangle: ";
    cin >> h;

    triangle(h);

    return 0;
}
