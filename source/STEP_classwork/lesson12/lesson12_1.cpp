#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point();
    Point(int x, int y);

    void show() const;
};


int main()
{
    Point point(2, 5);
    point.show();
}

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y) {}

void Point::show() const
{
    cout << "(" << x << ";" << y << ")" << endl;
}
