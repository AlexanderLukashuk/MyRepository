#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    int num = -1, sum, count;
    double average;

    while (true)
    {
        cout << "Enter number: ";
        cin >> num;

        if (num == 0)
        {
            break;
        }
        
        vec.push_back(num);
    }

    for (int el : vec)
    {
        sum += el;
        count++;
    }

    for (int el : vec)
    {
        cout << el << " ";
    }
    cout << endl;

    average = sum / count;

    cout << "The amount = " << sum << endl;
    cout << "Average = " << average << endl;
}