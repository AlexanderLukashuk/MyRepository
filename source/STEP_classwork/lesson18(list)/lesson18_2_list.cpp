#include <iostream>
#include <list>
using namespace std;

bool func(int l, int r)
{
    return l > r;
}

bool odd(int number)
{
    return number % 2;
}

int main()
{
    list<int> list1;
    list<int> list2(4);
    list<int> list3(3, 8);
    list<int> list4(list3);

    list<int> list6(3, 3);

    list1.push_front(4);
    list1.push_front(1);
    list1.push_front(8);
    list1.push_front(0);
    list1.push_front(41);
    list1.push_front(3);

    //list1.remove(41);
    //list1.remove_if(odd);

    list6.merge(list1);

    for (auto elem : list6)
    {
        cout << elem << " ";
    }
    cout << endl;

    for (auto elem : list1)
    {
        cout << elem << " ";
    }
    cout << endl;

    //list1.sort(func);

    /*for (auto elem : list1)
    {
        cout << elem << " ";
    }
    cout << endl;*/

    /*list1.unique();
    list2.unique();

    for (auto elem : list2)
    {
        cout << elem << " ";
    }
    cout << endl;*/

    /*cout << list4.front() << endl;
    cout << list4.back() << endl;

    cout << list4.empty() << endl;
    cout << list4.size() << endl;

    
    list1.resize(5);
    list1.resize(5, 4);
    list4.assign(5, 3);
    list4.assign(list1.begin(), list1.end());*/

    /*list4.push_front(0);
    list4.push_back(100);

    list4.pop_front();
    list4.pop_back();

    list4.insert(list4.begin(), 100);
    list4.insert(list4.begin(), 3, 100);
    list4.insert(list4.begin(), list2.begin(), list2.end());

    list4.erase(list4.begin(), list4.end());*/

    /*for (auto elem : list4)
    {
        //elem = elem + 1;
        cout << elem << " ";
    }
    cout << endl;*/
}