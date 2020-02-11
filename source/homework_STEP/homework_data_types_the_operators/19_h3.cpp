#include <iostream>
using namespace std;
int main () 
{
    char symbol;
    
    cout << "Enter a symbol: ";
    cin >> symbol;

    cout << "\"" << symbol << "\"" << " = " << (int)symbol << endl;
    return 0;
}
