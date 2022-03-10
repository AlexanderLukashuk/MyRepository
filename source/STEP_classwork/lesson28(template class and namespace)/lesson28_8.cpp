#include <iostream>
using namespace std;

template<class T, int size>
class TEST
{
public:
    void show()
    {
        cout << 1111 << endl;
    }
};

template<int size>
class TEST<char, size>
{
public:
    void print()
    {
        cout << 22222 << endl;
    }
};

template<class T>
class TEST<T, 777>
{
public:
    void print()
    {
        cout << 33333 << endl;
    }
};

int main()
{
    TEST<int, 777> obj;
    //obj.show();
    obj.print();
}