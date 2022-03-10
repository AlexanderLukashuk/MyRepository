#include <iostream>
using namespace std;

class TEST
{
public:
    TEST()
    {
        cout << "CTOR" << endl;
    }
    ~TEST()
    {
        cout << "DESTR" << endl;
    }

    void show()
    {
        cout << "Hello" << endl;
    }
};

//void function1(unique_ptr<TEST> obj)
void function1(TEST *ptr)
{

}

int main()
{
    //TEST *ptr = new TEST;
    //delete ptr;
    //auto ptr = make_unique<TEST>();
    //TEST* ptr = new TEST;
    auto ptr1 = make_unique<TEST>();
    //function1(move(ptr1));
    //function1(ptr1.get());
    //unique_ptr<TEST> ptr2(ptr);

    ptr1->show();
    (*ptr1).show();
    ptr1.get()->show();

}