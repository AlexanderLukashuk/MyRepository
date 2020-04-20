#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> que;

    que.push(10);
    que.push(5);
    que.push(15);
    cout << que.size() << endl;

    cout << que.top() << endl;
    que.pop();
    cout << que.top() << endl;
}