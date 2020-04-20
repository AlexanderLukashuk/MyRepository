#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    stack<string> box;
    string str;

    cout << "put thing" << endl;
    while (true)
    {
        getline(cin, str);
        if (str == "exit")
        {
            break;
        }
        else
        {
            box.push(str);
        }
    }

    cout << "Things that you transpored: " << endl;
    while (box.size() != 0)
    {
        cout << box.top() << endl;
        box.pop();
    }
}