#include <iostream>
using namespace std;
int main ()
{
    int money, cost, count = 0;

    cout << "Enter the amount of money from Pety: ";
    cin >> money;
    cout << "Enter ice cream price: ";
    cin >> cost;

    while (money >= cost)
    {
        money -= cost;
        count++;
    }        
    cout << "Petya has left " << money << endl;
    cout << "Petya bought " << count << " ice cream\n";
    return 0;
}
