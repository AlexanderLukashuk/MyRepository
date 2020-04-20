#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> que;

    que.push(10);
    que.push(15);
    que.push(25);
    cout << que.front() << endl;
    cout << que.back() << endl;

    cout << que.size() << endl;
    cout << que.empty() << endl;

    //que.pop();
    //cout << que.front() << endl;
}