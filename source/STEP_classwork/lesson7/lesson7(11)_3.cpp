#include <iostream>
using namespace std;

//extern int number;
//static int number;
extern int number;

double g;
double getG();

int main()
{
    cout << getG() << endl;
    //cout << g << endl;
    cout << number << endl;
}