#include <iostream>
#include <math.h>
using namespace std;

struct coordinateSystem
{
    int x;
    int y;

    void distance(coordinateSystem point1, coordinateSystem point2)
    {
        double distance;
        distance = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));

        cout << "Distance between point 1(" << point1.x << "; " << point1.y << ") and "
            << "point 2(" << point2.x << "; " << point2.y << ") = " << distance << endl;
    }
};

int main()
{
    coordinateSystem point1;
    coordinateSystem point2;
    coordinateSystem Distance;

    cout << "Enter coordinate for first point:\n";
    cout << "Enter x: ";
    cin >> point1.x;
    cout << "Enter y:";
    cin >> point1.y;
    cout << "Enter coordinate for second point\n";
    cout << "Enter x:";
    cin >> point2.x;
    cout << "Enter y: ";
    cin >> point2.y;

    Distance.distance(point1, point2);

    return 0;
}
