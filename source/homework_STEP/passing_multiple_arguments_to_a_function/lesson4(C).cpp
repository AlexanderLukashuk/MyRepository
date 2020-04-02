#include <iostream>
#include <stdarg.h>
using namespace std;

void myprintf(const char * str, ...)
{
	va_list ptr;
	va_start(ptr, str);

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '%' && str[i + 1] == 'i')
		{
			i++;
			cout << va_arg(ptr, int);
			cout << ' ';
		}
		else if (str[i] == '%' && str[i + 1] == 'd')
		{
			i++;
			cout << va_arg(ptr, double);
			//cout << ' ';
			//i--;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			i++;
			cout << '%';
		}
		else
		{
			cout << str[i];
		}
	}
}

int main()
{
	//I am 17 years old. My GPA 3.68. (%) I am Sanya
	//myprintf("I am %i years old. My GPA %.2d. (%%)", 17, 3.88, "I am Sanya");
	myprintf("I am %i years old. My GPA %d(%%).", 17, 3.88);

	return 0;
}
