#include<iostream>
using namespace std;

template <typename T>
void input(T &data)
{
    while(!(cin >> data)) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() 
{
    //int num1, num2, num3;
    int num1, num2;
    double num3;
    //input("lid", &num1, &num2, &num3);


    /*while(!(cin >> num1)) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }*/
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    input(num1);
    cout << "num1 = " << num1 << endl;

    input(num2);
    cout << num2 << endl;
    //cin.clear();
    
    input(num3);
    cout << num3 << endl;
    //cin.clear();

    //cout << num1 << endl;
    //cout << num2 << endl;
    //cout << num3 << endl;
    //cout << numeric_limits<int>::max();
    //cout << numeric_limits<int>::min();
    //int num1, num2, num3;
    //cin >> num1;
    //cin >> num2;
    //cin >> num3;

    //cout << num1 << endl;
    //cout << num2 << endl;
    //cout << num3 << endl;
	//int num1; //объявление
	//num1 = 5; // иниц. присвоение
	
    //int num2 = 10; // определение
	
    //int num3(5); // иниц. конструктор
	//cout << num3 << endl;
	
    //int num4 = { 6 }; //иниц. oi
	//cout << num4 << endl;
	
    //cin.get();
	return 0;
}
