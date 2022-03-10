#include <iostream>
using namespace std;

class TEST
{
private:

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

void func(shared_ptr<TEST> p)
{

}

int main()
{
    auto ptr = make_shared<TEST>();
    ptr->show();
    (*ptr).show();

    func(ptr); // без move() не как в uniqie_ptr
    
}