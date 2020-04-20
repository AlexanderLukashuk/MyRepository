#include <iostream>
using namespace std;

class TEST
{
    private:
        int num;
    public:
        TEST() : num(0) {}
        //explicit TEST(int a) : a(a) {}
        TEST(int num) : num(num) {}
        TEST(char num) = delete;
        TEST(const char* str)
        {
            num = atoi(str);
        }

        int getNum()
        {
            return num;
        }
};

int main()
{
    //TEST obj('1');
    TEST obj2(1);
    TEST obj3("123");
    cout << obj2.getNum() << endl;
    cout << obj3.getNum() << endl;
    int num = 10;
    (TEST)num;
    //(TEST)'1';
}