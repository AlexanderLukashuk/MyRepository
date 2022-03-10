#include <iostream>
#include <list>
using namespace std;

class TEST
{
public:
    TEST()
    {
        //cout << "CTOR" << endl;
    }

    TEST(int num)
    {
        cout << num << endl;
    }

    ~TEST()
    {
        //cout << "DESTR" << endl;
    }

    void show()
    {
        cout << "You in object" << endl;
    }
};

template<class T>
T&& Move(T& t)
{
    return static_cast<T&&>(t);
}

int main()
{
    // Smart pointer
    // auto_ptr - устарел
    // unique_ptr - 90%
    // shares_ptr
    // weak_ptr

    //TEST* t = new TEST;

    //unique_ptr<TEST> ptr1(new TEST);
    //unique_ptr<int[]> ptr(new int[100]);
    //TEST* p = new TEST;
    unique_ptr<TEST> ptr = make_unique<TEST>(8);
    //unique_ptr<TEST> ptr1(p);
    //unique_ptr<TEST> ptr2;
    //ptr2 = Move(ptr1);
    //unique_ptr<TEST> ptr1(t);
    //unique_ptr<TEST> ptr2(t);
    
    //cout << (ptr1 == nullptr ? "null" : "not null") << endl;
    //cout << (ptr2 == nullptr ? "null" : "not null") << endl;

    /*(*ptr1).show();
    ptr1->show();
    ptr1.get()->show();*/

    // *ptr = 10;
    //cout << *ptr << endl;

    //list<unique_ptr<int>> listInt;

    /*ptr.get()[0] = 10;
    ptr.get()[1] = 562;
    ptr.get()[2] = 5;

    cout << ptr.get()[0] << endl;
    cout << ptr.get()[1] << endl;
    cout << ptr.get()[2] << endl;*/
    //cin.get();

    /*int num1 = 1;
    int num2 = 2;

    num2 = Move(num1);

    cout << num1 << " " << num2 << endl;*/
}