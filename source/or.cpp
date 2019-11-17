#include <iostream>
int main ()
{
    using namespace std;
    cout << "This program may reformat your hard disk\n";
    cout << "and destroy all your data.\n";
    cout << "Do you wish to contunue? <y/n> ";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
        cout << "You were warned!\a\a\n";
    else if (ch == 'n' || ch == 'N')
        cout << "A wise choise ... bye\n";
    else 
        cout << "That wasn't a y or n! Apparently you "
            "can't follow\ninstructions, so "
            "I'll trash your disk anyway.\a\a\a\n";
    return 0;
}
