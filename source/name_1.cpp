#include <iostream>
int main ()
{
using namespace std;
string name;
string adr;
using namespace std;
cout << "Enter your name: ";
cin >> name;
//cout << endl;
cout << "Enter your adress: ";
cin >> adr;
cout << "Hello, " << name << ". " << "Your house on the " << adr << endl;
cin.get();
return 0;
}
