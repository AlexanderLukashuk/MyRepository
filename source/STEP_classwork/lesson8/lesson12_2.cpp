#include <iostream>
using namespace std;

class Point3D;

class Point2D 
{
	int x;
	int y;
    //friend void show(const Point2D& obj);
    friend bool equals(const Point2D& pnt1, const Point3D& pnt2);
public:
    Point2D() : x(0), y(0) {}
    Point2D(int x, int y) : x(x), y(y) {}
};

class Point3D
{
	int x;
	int y;
    int z;
    friend bool equals(const Point2D& pnt1, const Point3D& pnt2);
public:
    Point3D() : x(0), y(0) {}
    Point3D(int x, int y, int z) : x(x), y(y), z(z) {}
};

bool equals(const Point2D& pnt1, const Point3D& pnt2)
{
    return (pnt1.x == pnt2.x && pnt1.y == pnt2.y ? true : false);
}

// void show(const Point2D& obj)
// {
//     cout << obj.x << " " << obj.y << endl;
// }

int main()
{
    Point2D p1(1, 3);
    Point2D p2(1, 5);
    Point3D p3(1, 3, 4);

    cout << equals(p1, p3) << endl;
    cout << equals(p2, p3) << endl;
    // Point2D pnt(1, 2);
    // show(pnt);
}