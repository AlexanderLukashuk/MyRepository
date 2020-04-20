#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stk;

    cout << stk.empty() << endl;
    cout << stk.size() << endl;

    stk.push(10);
    stk.push(15);
    stk.push(20);
    stk.pop();
    cout << stk.top() << endl;

    cout << stk.empty() << endl;
    cout << stk.size() << endl;

    /*while (stk.size() != 0)
    {
        cout << stk.top() << endl;
        stk.pop();
    }*/

    stack<int> stk2;
    stk2.push(100);
    stk2.swap(stk);

    cout << stk2.top() << endl;
    cout << stk.top() << endl;

}