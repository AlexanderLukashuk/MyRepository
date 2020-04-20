#include <iostream>
using namespace std;

class TEST
{
    private:
        int num;
        static int cnum;
    public:
        static int getCnum()
        {
            return cnum;
        }

        static void setCnum(int _cnum)
        {
            cnum = _cnum;
        }
};

int TEST::cnum = 10;

int main()
{
    TEST a;
    TEST b;
    a.setCnum(12);

    //cout << TEST::getCnum() << endl;
    //TEST::setCnum(123);    
    //cout << TEST::getCnum << endl;
}