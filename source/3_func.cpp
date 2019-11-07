#include <iostream>
using namespace std;
string blmice(string);
string see_run(string);
int main ()
{
//using namespace srd;
string a = "There blind mice";
string b = "See how they run";
string c = blmice(a);
cout << c << endl;
c = blmice(a);
cout << c << endl;
string d = see_run(b);
cout << d << endl;
d = see_run(b);
cout << d << endl;
return 0;
}
string blmice(string bl)
{
string c =  bl;
return c;
//return bl; 
}
string see_run(string sr)
{
string d = sr;
return d;
//return sr;
}
