#include <iostream>
#include <ncurses.h>
using namespace std;

int main()
{
    while (true)
    {
        int key = getch();
        int c = key;
        cin.get();
        cout << c << endl;
    }

    return 0;
}
