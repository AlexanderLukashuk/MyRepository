#include <iostream>
#include <time.h>
using namespace std;

// class Options
// {
//     public:
//         Options()
//         {
//             system("chcp 1251 > null");
//             srand(time(0));
//         }

//         ~Options()
//         {
            
//             //cout << "DESTR" << endl;
//         }
// } obj;

// //Options obj;

class TEST
{
    private:
        int number;
    public:
        // void func()
        // {
        //     cout << this;
        // }

        TEST() : number(0) {}
        TEST(int number)
        {
            //(*this).number = number;
            this->number = number;
        }
};

int main()
{
    //TEST test;
    //test.func(11, 22);
    // TEST test1;
    // TEST test2;
    // TEST test3;

    // cout << &test1 << " ";
    // test1.func();
    // cout << endl;

    // cout << &test2 << " ";
    // test2.func();
    // cout << endl;

    // cout << &test3 << " ";
    // test3.func();
    // cout << endl;
}
