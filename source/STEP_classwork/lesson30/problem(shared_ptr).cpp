#include <iostream>
using namespace std;

class TEST
{
private:

public:
    //shared_ptr<TEST> ptr;
    weak_ptr<TEST> ptr;
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
        //static_cast<shared_ptr<TEST>>(ptr)->show();
    }
};

int main()
{
    auto test = make_shared<TEST>();
    test->ptr = test;
    //weak_ptr 
}