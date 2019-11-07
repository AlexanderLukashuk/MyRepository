#include <iostream>
namespace some_shit
{
int sum(int a, int b)
{
return a+b;
}
}
int main ()
{
using namespace std;
using namespace some_shit;
int x = sum(2, 3);
cout << x << endl;
return 0;
}
