#include <iostream>
using namespace std;
int main ()
{
	char x[13] = "Hello World!";
	x[5] = '\0';
	
	cout << "x = " << x << endl;
	return 0;
}
