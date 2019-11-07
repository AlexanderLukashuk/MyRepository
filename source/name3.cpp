#include <iostream>
#include <cstdio>
int main ()
{
	using namespace std;
	string name, sname;
	int age;

	cin >> name;
	cin >> sname;
	cin >> age;

	printf("Name: %s \n ", &name);
//	scanf("%c", &name);
//	printf(" %c\n", name);

	printf("Second name: %s \n ", &sname);
//	scanf("%c", &sname);
//	printf(" %c\n", sname):

	printf("Age: %d \n ", &age);
//	scanf("%d", &age);
//	printf(" %d\n", age);
	return 0;
}
