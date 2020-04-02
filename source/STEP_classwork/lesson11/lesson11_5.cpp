#include <iostream>
using namespace std;

class TEST
{
    public:
        int num;
        static int count;
        TEST()
        {
            count++;
        }

        ~TEST()
        {
            count--;
        }
};

int TEST::count = 0;

int main()
{
    TEST a;
    TEST b;
    {
        TEST c;
        cout << TEST::count << endl;
    }
    cout << TEST::count << endl;

}