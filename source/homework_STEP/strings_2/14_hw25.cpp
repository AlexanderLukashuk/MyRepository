#include <iostream>
using namespace std;

void numToString(double num, char*& str1)
{
	int temp = num, num1, count = 0, count2 = 0, num4;
	double num2 = num;
	double num3 = (double)num - (int)num;
    int size, k = 0;
	num1 = temp % 10;

	while (num1 != 0)
	{
		count++;
		temp = (temp - num1) / 10;
		num1 = temp % 10;
	}

	temp = num;
	int* array1 = new int[count];

	for (int i = 0; i < count; i++)
	{
		num1 = temp % 10;
		array1[count - i - 1] = num1;
		temp = (temp - num1) / 10;
	}


	while ((int)num2 != num2)
	{
		if ((int)num2 < num2)
		{
			count2++;
			num2 *= 10;
		}
	}

	int* array2 = new int[count2];

	for (int i = 0; i < count2; i++)
	{
		num3 *= 10;
	}
    num4 = num3;
	temp = num;

	for (int i = count2 - 1; i >= 0; i--)
	{
		num1 = num4 % 10;
		array2[i] = num1;
	    num4 = (num4 - num1) / 10;
	}

    size = count + count + 2;
    char* str = new char[size];
    for (int i = 0; i < count; i++)
    {
        switch (array1[i])
        {
            case 1:
                str[k] = '1';
                k++;
                break;
            case 2:
                str[k] = '2';
                k++;
                break;
            case 3:
                str[k] = '3';
                k++;
                break;
            case 4:
                str[k] = '4';
                k++;
                break;
            case 5:
                str[k] = '5';
                k++;
                break;
            case 6:
                str[k] = '6';
                k++;
                break;
            case 7:
                str[k] = '7';
                k++;
                break;
            case 8:
                str[k] = '8';
                k++;
                break;
            case 9:
                str[k] = '9';
                k++;
                break;
            case 0:
                str[k] = '0';
                k++;
                break;
        }
    }
    k++;
    str[k - 1] = '.';

    for (int i = 0; i < count2; i++)
    {
        switch (array2[i])
        {
            case 1:
                str[k] = '1';
                k++;
                break;
            case 2:
                str[k] = '2';
                k++;
                break;
            case 3:
                str[k] = '3';
                k++;
                break;
            case 4:
                str[k] = '4';
                k++;
                break;
            case 5:
                str[k] = '5';
                k++;
                break;
            case 6:
                str[k] = '6';
                k++;
                break;
            case 7:
                str[k] = '7';
                k++;
                break;
            case 8:
                str[k] = '8';
                k++;
                break;
            case 9:
                str[k] = '9';
                k++;
                break;
            case 0:
                str[k] = '0';
                k++;
                break;
        }
    }
    k++;
    str[k - 1] = '\0';

    delete[]str1;
    str1 = str;
    delete[]array1;
    delete[]array2;
}

int main()
{
	double num;
    char* str = new char;

	cout << "Enter real number: ";
	cin >> num;

	numToString(num, str);
    cout << str << endl;

    return 0;
}
