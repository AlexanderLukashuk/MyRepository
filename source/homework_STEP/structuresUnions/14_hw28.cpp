#include <iostream>
#include <math.h>
using namespace std;

struct coordinateSystem
{
    int x;
    int y;

    void distance(coordinateSystem& point1, coordinateSystem& point2)
    {
        /*cout << "Enter coordinate for first point:\n";
        cout << "Enter x: ";
        cin >> point1.x;
        cout << "Enter y:";
        cin >> point2.y;
        cout << "Enter coordinate for second point\n";
        cout << "Enter x:";
        cin >> point2.x;
        cout << "Enter y: ";
        cin >> point2.y;*/

        cout << "Distance between point1 and point2 = "
            << sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2))
            << endl;
    }
};

int main()
{
    coordinateSystem point1;
    coordinateSystem point2;

    cout << "Enter coordinate for first point:\n";
    cout << "Enter x: ";
    cin >> point1.x;
    cout << "Enter y:";
    cin >> point2.y;
    cout << "Enter coordinate for second point\n";
    cout << "Enter x:";
    cin >> point2.x;
    cout << "Enter y: ";
    cin >> point2.y;

    return 0;
}
