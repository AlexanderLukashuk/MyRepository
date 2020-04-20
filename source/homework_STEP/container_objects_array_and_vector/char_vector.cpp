#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<char> > vec;
    char ch;
    int width, length;

    cout << "Enter rectangle length: ";
    cin >> length;
    cout << "Enter rectangle width: ";
    cin >> width;
    cout << "Enter symbol: ";
    cin >> ch;

    vec.resize(width);
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].resize(length);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            if ( i == 0 || i == vec.size() - 1)
            {
                vec[i][j] = ch;
            }
            else if (j == 0 || j == vec[i].size() - 1)
            {
                vec[i][j] = ch;
            }
            else
            {
                vec[i][j] = ' ';
            }
        }
    }

    for (auto el : vec)
    {
        for (auto el1 : el)
        {
            cout << el1;
        }
        cout << endl;
    }
}