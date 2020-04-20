#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

int main()
{
    list<int> obj;
    forward_list<int> flist;

    forward_list<int> list1(5);
    forward_list<int> list2(5, 9);
    forward_list<int> list3(list2);

    /*for (auto i = list1.begin(); i != list1.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    for (auto elem : list2)
    {
        cout << elem << " ";
    }
    cout << endl;

    for (auto elem : list3)
    {
        cout << elem << " ";
    }
    cout << endl;*/

    /*cout << flist.empty() << endl;
    cout << flist.max_size() << endl;
    list2.resize(6, 4);
    for (auto elem : list2)
    {
        cout << elem << " ";
    }
    cout << endl;*/

    flist.push_front(126);
    //flist.emplace_front(43);
    flist.insert_after(flist.begin(), 10);
    //flist.emplace_after(3, 10);

    auto it = flist.begin();
    it++;

    flist.insert_after(it, 3, 20);
    flist.insert_after(it, 31);
    flist.insert_after(it, list2.begin(), list2.end());

    for (auto elem : flist)
    {
        cout << elem << " ";
    }
    cout << endl;

    //flist = list1;
    //flist.assign(5, 1);
    //flist.assign(list1.begin(), list1.end());

    /*for (auto elem : flist)
    {
        cout << elem << " ";
    }
    cout << endl;*/

    /*flist.pop_front();
    flist.erase_after(flist.begin());
    
    auto iter1 = flist.begin();
    //iter1++;
    auto iter2 = flist.begin();
    iter2++;
    iter2++;
    iter2++;
    iter2++;
    iter2++;

    flist.erase_after(iter1, iter2);

    for (auto elem : flist)
    {
        cout << elem << " ";
    }
    cout << endl;*/

    //flist.clear();
    cout << flist.empty() << endl;

    flist.insert_after(flist.before_begin(), 888);
    
    for (auto elem : flist)
    {
        cout << elem << " ";
    }
    cout << endl;

    cout << flist.front() << endl;
}