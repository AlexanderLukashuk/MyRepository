#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	const int N = 20;
	const int size = 12;
	srand(time(0));

	//int mas[size] = { 2, 5, 77, 12, 88 };
	/*int mas2[size];
	int mas3[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 9; i >= 0; i--)
	{
		cout << mas3[i] << endl;
	}*/

	//double mas[size];
	//double profit = 0;

	//for (int i = 0; i < size; i++)
	//{
	//	cout << "Enter profit for " << i + 1 << " month: ";
	//	cin >> mas[i];
	//}
	//for (int i = 0; i < size; i++)
	//{
	//	profit += mas[i];
	//	//cout << "Profit for " << i + 1 << " month = " << mas[i] << endl;
	//}
	//cout << "Profit for 6 month = " << profit << endl;

	//int mas[size];
	//int max = 0, min = 0;

	//for (int i = 0; i < size; i++)
	//{
	//	cout << "Enter profit for " << i + 1 << " month: ";
	//	cin >> mas[i];
	//	/*count++;
	//	if (max_prof < mas[i])
	//	{
	//		max_prof = mas[i];
	//		month_max = count;
	//	}
	//	if (mas[i] > min_prof)
	//	{
	//		min_prof = mas[i];
	//		month_min = count;
	//	}*/
	//	if (mas[i] > mas[max])
	//	{
	//		max = i;
	//	}
	//	if (mas[i] < mas[min])
	//	{
	//		min = i;
	//	}
	//}
	//for (int i = 0; i < size; i++)
	//{
	//	cout << mas[i] << " ";
	//}
	//cout << endl;
	////for (int i = 0; i < size; i++)
	////{
	////	//cout << "Profit for " << i + 1 << " month = " << mas[i] << endl;
	////}
	//cout << "minimum profit was in " << min + 1 << " month" << endl;
	//cout << "maximum profit was in " << max + 1<< " month" << endl;

    
	int mas[size];
	int max = 0, min = 0;

	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 100 + 1;

		if (mas[i] > mas[max])
		{
			max = i;
		}
		if (mas[i] < mas[min])
		{
			min = i;
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;

	cout << "minimum profit was in " << min + 1 << " month" << endl;
	cout << "maximum profit was in " << max + 1 << " month" << endl;
	cout << "minimum = " << mas[min] << endl;
	cout << "maximum = " << mas[max] << endl;

    //--------#6--------
	int mas1[size];
	int max1 = 0, min1 = 0;
	int month1, month2;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter profit for " << i + 1 << " month: ";
		cin >> mas1[i];

	}

	cout << "enter a range from one month to another: ";
	cin >> month1;
	cin >> month2;
	if (month1 > month2)
	{
		for (int i = month2; i < month1; i++)
		{
			if (mas1[i] > mas[max1])
			{
				max1 = i;
			}
			if (mas1[i] < mas[min1])
			{
				min1 = i;
			}
		}
	}
	else
	{
		for (int i = month1; i < month2; i++)
		{
			if (mas1[i] > mas1[max1])
			{
				max1 = i;
			}
			if (mas1[i] < mas1[min1])
			{
				min1 = i;
			}
		}
	}
	cout << "minimum = " << mas1[min1] << endl;
	cout << "maximum = " << mas1[max1] << endl;
	
	cout << endl;


    //--------#7.1--------
	int mas2[N];
	int sum_neg = 0;

	for (int i = 0; i < N; i++)
	{
		mas2[i] = rand() % 100 - 30;

		if (mas2[i] < 0)
		{
			sum_neg += mas2[i];
		}
		
	}
	for (int i = 0; i < N; i++)
	{
		cout << mas2[i] << " ";
	}
	cout << endl;
	cout << "The amount of negative number = " << sum_neg << endl;


    //--------#7.2--------
	int mas3[N];
	int max3 = 0, min3 = 0;
	int comp = 1;

	for (int i = 0; i < N; i++)
	{
		mas3[i] = rand() % 100 - 1;

		if (mas3[i] > mas3[max3])
		{
			max3 = i;
		}
		if (mas3[i] < mas3[min3])
		{
			min3 = i;
		}
	}
	if (min3 < max3)
	{
		for (int i = min3; i <= max3; i++)
		{
			comp *= mas3[i];
		}
	}
	else
	{
		for (int i = max3; i <= min3; i++)
		{
			comp *= mas3[i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << mas3[i] << " ";
	}
	cout << endl;
	cout << "The composition = " << comp << endl;

    //--------#7.3--------
	int mas4[N];
	int comp_ev = 1;

	for (int i = 0; i < N; i++)
	{
		mas4[i] = rand() % 10 - 1;

		if (i % 2 == 0)
		{
			comp_ev *= mas4[i];
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		cout << mas4[i] << " ";
	}
	cout << endl;
	cout << "The composition of even number = " << comp_ev << endl;


    //--------#7.4--------
	int mas5[N];
	int sum_neg5 = 0;
	int neg1, neg2;

    for (int i = 0; i < N; i++)
    {
		mas5[i] = rand() % 10 - 3;
    }
	for (int i = 0; i < N; i++)
	{

		if (mas5[i] < 0)
		{
			neg1 = i;
			break;
		}
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (mas5[i] < 0)
		{
			neg2 = i;
			break;
		}
	}
	for (int i = neg1; i <= neg2; i++)
	{
		sum_neg5 += mas5[i];
	}
	for (int i = 0; i < N; i++)
	{
		cout << mas5[i] << " ";
	}
	cout << endl;
	cout << "sum from the first negative number to the last negative number = " << sum_neg5;
	cout << endl;

	//mas[0] = 2;

	//cout << mas[0] << endl;
	/*for (int i = 0; i < 10; i++)
	{
		cout << mas[i] << endl;
	}
	for (int i = 0; i < size; i++)
	{
		cout << mas2[i] << endl;
	}*/

	/*for (int i = 0; i < size; i++)
	{
		mas2[i] = i + 1;
	}

	for (int i = 0; i <= size; i++)
	{
		cout << mas2[i] << endl;
	}*/
	//cout << mas[4] << endl;

	cin.get();
	cin.get();
}
