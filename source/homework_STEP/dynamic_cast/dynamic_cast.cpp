#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
class Coord
{
    int x;
    int y;

public:
    Coord() : x(), y() {} // если без него не получается раскоментируйте
    Coord(int x, int y) : x(x), y(y) {}
    int getX() { return x; }
    int getY() { return y; }
};

class Shape
{
public:
    virtual void print() = 0;
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    Coord center;
    int radius;

public:
    Circle() : center(), radius() {}
    Circle(int x, int y, int radius) : center(Coord(x, y)), radius(radius) {}
    virtual void print() override
    {
        cout << "Circle(Coord(" << center.getX() << "; " << center.getY() << "), R = " << radius << ");" << endl;
    }

    virtual double area() override
    {
        return (3.14 * (radius * radius));
    }

    int getRadius()
    {
        return radius;
    }

    ~Circle() {}
};

class Square : public Shape
{
private:
    Coord upperLeft;
    Coord upperRight;
    Coord lowerLeft;
    Coord lowerRight;
    int sideLenght;

public:
    Square() : upperLeft(), upperRight(), lowerLeft(), lowerRight(), sideLenght() {}
    Square(int x, int y, int sideLenght)
        : upperLeft(Coord(x, y)), sideLenght(sideLenght)
    {
        upperRight = Coord(x + sideLenght, y);
        lowerLeft = Coord(x, y - sideLenght);
        lowerRight = Coord(x - sideLenght, y - sideLenght);
    }

    virtual void print() override
    {
        cout << "Square(Upper left coord(" << upperLeft.getX() << "; " << upperLeft.getY() << ")" << ");" << endl;
        cout << "Square(Upper right coord(" << upperRight.getX() << "; " << upperRight.getY() << ")" << ");" << endl;
        cout << "Square(Lower left coord(" << lowerLeft.getX() << "; " << lowerLeft.getY() << ")" << ");" << endl;
        cout << "Square(Lower right coord(" << lowerRight.getX() << "; " << lowerRight.getY() << ")" << ");" << endl;
        cout << "Side lenght = " << sideLenght << endl;
    }

    virtual double area() override
    {
        return (sideLenght * sideLenght);
    }
    
    ~Square() {}
};
// *Базовый абстрактный класс Shape
//		чистая вирт функция print
//		чистая вирт функция area - возвращает площадь
//		пустой вирт деструктор
// Дочерний класс Circle
//		поля - координата центра и радиус
// Дочерний класс Square
//		поля - 4 координаты(но в конструкторе он получает только одну лев.верх. координату и длину стороны,
//		оставшиеся координаты просчитывает)
// пример Print для Circle => Circle(Coord(5,6), R = 7);
int main()
{
    srand(time(0));
    vector<Shape *> vec;

    // добавить в вектор несколько квадратов окружностей и треугольников
    vec.push_back(new Circle(5, 6, 7));
    vec.push_back(new Circle(1, 14, 3));
    vec.push_back(new Square(8, 3, 5));
    vec.push_back(new Circle(2, 0, 9));
    vec.push_back(new Square(6, 0, 11));
    vec.push_back(new Circle(1, 7, 4));
    vec.push_back(new Circle(2, 2, 2));
    vec.push_back(new Square(3, 8, 8));
    vec.push_back(new Circle(6, 6, 7));

    // вывести на консоль вектор
    for (auto el : vec)
    {
        el->print();
    }

    // Найти самый большой радиус
    int maxRadius = 0;
    for (auto el : vec)
    {
        Circle* tmp = dynamic_cast<Circle*>(el);
        if (tmp)
        {
            if (tmp->getRadius() > maxRadius)
            {
                maxRadius = tmp->getRadius();
            }
        }
    }

    cout << "Max Radius = " << maxRadius << endl;

    // вывести площади всех фигур
    for (auto el : vec)
    {
        Circle* tmpC = dynamic_cast<Circle*>(el);
        if (tmpC)
        {
            cout << "Circle area: " << tmpC->area() << endl;
        }

        Square* tmpQ = dynamic_cast<Square*>(el);
        if (tmpQ)
        {
            cout << "Square area: " << tmpQ->area() << endl;
        }
    }
    
    // Найти самую большую площадь
    double maxArea = 0.0;
    for (auto el : vec)
    {
        Circle* tmpC = dynamic_cast<Circle*>(el);
        if (tmpC)
        {
            if (tmpC->area() > maxArea)
            {
                maxArea = tmpC->area();
            }
        }

        Square* tmpQ = dynamic_cast<Square*>(el);
        if (tmpQ)
        {
            if (tmpQ->area() > maxArea)
            {
                maxArea = tmpQ->area();
            }
        }
    }

    cout << "Max area = " << maxArea << endl;

    cin.get();
    return 0;
}