#include <iostream>
using namespace std;

// class TEST
// {
//     private:
//         int a;
//         int b;
//     public:
//         TEST()
//         {
//             a = 0;
//             b = 0;
//         }
//         TEST(int _a, int _b)
//         {
//             a = _a;
//             b = _b;
//         }

//         void show()
//         {
//             cout << a << " " << b << endl;
//         }

//         void setA(int _a)
//         {
//             a = _a;
//         }

//         int getA()
//         {
//             return a;
//         }
// };

class TEST
{
    private:
        //int a;
        //int b;
        const int c;
        int d;
    public:
        TEST() : c(0), d(0) {}
        // TEST() : a( 0 ), b( 0 ) {}

        // TEST(int _a, int _b) : a( _a ), b( _b ) {}

        // void show()
        // {
        //     cout << a << " " << b << endl;
        // }

        void Show() const
        {
            cout << c << " " << d << endl;
        }

        void input()
        {
            cin >> d;
        }
};

int main()
{
    const TEST t;
    t.Show();
    // TEST t1;
    // t1.show();

    // TEST t2(12, 24);
    // t2.show();
    // int n1;
    // n1 = 10;

    // int n2(10);
    // int n3{ 10 };

    // TEST t1;
    // t1.setA(10);
    // t1.show();
}