#include <iostream>
using namespace std;

class TEST
{
private:
    int num;

public:
    TEST() : num(100)
    {
        cout << "CTOR" << endl;
    }
    ~TEST()
    {
        cout << "DESTR" << endl;
    }

    void show()
    {
        cout << "Hello" << num << endl;
    }
};

void func(shared_ptr<TEST> ptr3)
{

}

int main()
{
    TEST *ptr = new TEST();

    shared_ptr<TEST> ptr1(ptr);
    shared_ptr<TEST> ptr2(ptr1);
    //func(move(ptr1));
    //ptr1->show();

    
}