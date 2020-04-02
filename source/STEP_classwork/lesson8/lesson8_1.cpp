#include <iostream>
using namespace std;

class A
{
    public:
        A()
        {
            cout << "CTOR" << endl;
        }

        ~A()
        {
            cout << "DESTOR" << endl;
        }
};

int main()
{
    {
        A b;
    }

    cout << "-------" << endl;
    
    A a;

    return 0;
}