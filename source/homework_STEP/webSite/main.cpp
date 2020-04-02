#include "page.h"

int main()
{
    Page home;
    home.print();
    home.setName("Gdsfs");
    string s = home.getName();
    cout << home.getName() << endl;
    cout << s << endl;
}
