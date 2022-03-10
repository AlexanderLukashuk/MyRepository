#include <iostream>
#include <list>
#include <time.h>
using namespace std;

void func(int &num)
{
    num *= 2;
}

bool func2(int &num)
{
    return num % 2 == 0;
}

class Predicate
{
public:
    void operator()(int &num)
    {
        num *= 2;
    }
};

class Predicate2
{
public:
    bool operator()(int &num)
    {
        return num % 3 == 0;
    }
};

bool func3(int l, int r)
{
    return l < r;
}

class TEST
{
    public:
    int num;
    TEST() { num  = rand(); }
    TEST(int n) { num  = n; }
};

int main()
{
    srand(time(0));
    TEST t(-999999);

    list<TEST> l;
    l.push_back(TEST());
    l.push_back(TEST());
    l.push_back(TEST());
    //int multiplier = 2;
    /*list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(9);
    l.push_back(4);
    l.push_back(7);
    l.push_back(6);
    l.push_back(8);*/

    for (auto el : l)
    {
        cout << el.num << " ";
    }
    cout << endl;

    for_each(l.begin(), l.end(), [&t](TEST obj) 
    {
        t = max(t, obj, [](TEST l, TEST r)
        {
            return l.num < r.num;
        });
    });

    cout << t.num << endl;

    //auto it = max(l.front(), l.back(), func3);
    /*auto it = max(l.front(), l.back(), [](int l, int r)
    {
        return l < r;
    } );
    cout << it << endl;*/


    //auto it = find_if(l.begin(), l.end(), func2);
    //auto it = find_if(l.begin(), l.end(), Predicate2());
    /*auto it = find_if(l.begin(), l.end(),
                      [](int &num) -> bool {
                          return num > 2 && num < 7;
                          return num;
                          return num * 0.5;
                      });

    if (it != l.end())
        cout << *it << endl;*/

    /*auto it = find(l.begin(), l.end(), 3);
    if (it != l.end())
    {
        cout << *it << endl;
    }
    cout << *it << endl;*/
    //for_each(l.begin(), l.end(), func);
    //for_each(l.begin(), l.end(), Predicate());
    /*for_each(l.begin(), l.end(), 
        [&multiplier](int &num)
        {
            //multiplier = 2;
            num *= multiplier;
        } );*/

    /*for (auto el : l)
    {
        cout << el << " ";
    }
    cout << endl;*/
}