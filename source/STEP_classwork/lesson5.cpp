#include <iostream>
using namespace std;

/*void func1()
{
    cout << "Hello" << endl;
}

void func2()
{
    cout << "Bye" << endl;
}*/

/*int sum(int a, int b)
{
    return a + b;
}*/

/*void func1()
{
    cout << "Hello" << endl;
}

void func2()
{
    cout << "HowAreYou" << endl;
}

void func3()
{
    cout << "Buy" << endl;
}*/

/*void func()
{
    cout << "Hello" << endl;
}

void func2(  void (*ptr)()  )
{
    ptr();
}*/

/*bool isEven(int num)
{
    return num % 2 == 0;
}

bool isOdd(int num)
{
    return num % 2;
}

bool isSimple(int num)
{
    int n = abs(num);
    for (int i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

//void show(int* mas, int size, bool (*condition(int)))
{
    for (int i = 0; i < size; i++)
    {
        if (condition(mas[i]))
        {
            cout << mas[i] << " ";
        }
    }
}*/

/*struct Student
{
    char name[30];
    int age;
    double weight;
};

void show(int* mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << mas[i] << " ";
    }
}



template<typename T>
void sort(T* mas, int size, bool (*condition)(T, T) )
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            //if (mas[j] < mas[j + 1])
            if (condition(mas[j], mas[j + 1]))
            {
                swap(mas[j], mas[j + 1]);
            }
        }
    }
}

bool cond_int(int n1, int n2)
{
    return n1 > n2;
}

bool cond_student_age(Student s1, Student s2)
{
    return s1.age > s2.age;
}

bool cond_student_weight(Student s1, Student s2)
{
    return s1.weight > s2.weight;
}

bool cond_student_name(Student s1, Student s2)
{
    char str1[30];
    char str2[30];
    strcpy(str1, s1.name);
    //strlwr(str1);
    strcpy(str2, s2.name);
    //strlwr(str2);

    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str2[i] == '\0')
        {
            return true;
        }

        if (str1[i] > str2[i])
        {
            return true;
        }
        else if (str1[i] < str2[i])
        {
            return false;
        }

    }
    return false;
}*/

void show(bool(*condition)(int), int* mas, int size) {
	for (int i = 0; i < size; i++) {
		if (condition(mas[i])) {
			cout << mas[i] << " ";
		}
	}
}
bool all(int num) {
	return true;
}
bool even(int num) {
	return num % 2 == 0;
}
bool odd(int num) {
	return num % 2;
}
bool positive(int num) {
	return num > 0;
}
bool negative(int num) {
	return num < 0;
}
bool simple(int num) {
	for (int i = 2; i < num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

/*void func()
{
    cout << "Hello" << endl;
}

void (* selector() ) ()
{
    return func;
}*/

bool (* selector() ) (int)
{
    bool(*ptr[6])(int) = {all, even, odd, positive, negative, simple};
    cout << "Choose what are you want to see:\n";
    cout << "0 - all\n";
    cout << "1 - even\n";
    cout << "2 - odd\n";
    cout << "3 - positive\n";
    cout << "4 - negative\n";
    cout << "5 - simple\n";
    int i;
    cin >> i;
    return ptr[i];
}

int main() 
{
    //void (*ptr)() = selector();
    //ptr();

	int mas[10] = { -3,-2,-1,0,1,2,3,4,5,6 };
	
    show(selector(), mas, 10); 
    cout << endl;
	//show(even, mas, 10); 
    //cout << endl;
	//show(odd, mas, 10); 
    //cout << endl;
	//show(positive, mas, 10); 
    //cout << endl;
	//show(negative, mas, 10); 
    //cout << endl;
	//show(simple, mas, 10); 
    //cout << endl;
	//cin.get(); cin.get();
	return 0;
}

//int main()
//{
    //int menu;

    /*while (true)
    {
        cout << "0 - init mas"\n";
        cout << "1 - show\n";
        cout << "2 - sort mas\n";
        cout << "3 - exit\n";
        cin >> menu;
    
        switch (menu)

    }*/
    /*const int size = 10;
    int mas1[size] = { 1, -5, 44, 86, 91, -51, -6, 9, 11, -24 };

    sort(mas1, size, cond_int);
    show(mas1, size);

    Student st[3] = { {"Alex", 20, 65.5}, {"Tom", 25, 70.2}, {"Nikita", 15, 45} };

    sort(st, 3, cond_student_age);
    //sort(st, 3, cond_student_name);

    for (int i = 0; i < 3; i++)
    {
        cout << st[i].name << " ";
        cout << st[i].age << " ";
        cout << st[i].weight << " ";
    }*/

   /* show(mas, size, isEven);
    cout << endl;
    show(mas, size, isOdd);
    cout << endl;
    show(mas, size, isSimple);
    cout << endl;*/

    //void (*ptr)() = func;
    //func2(ptr);
    //void (*ptr[3])() { func1, func2, func3 };
    //ptr[0] = func1;
    //ptr[1] = func2;
    //ptr[2] = func3;

    //int num;
    //cin >> num;
    //ptr[num]();


    //int mas[10];
    //int (*ptr)(int, int) = sum;
    //cout << ptr(5, 7) << endl;
    
    //void (*ptr)() = func1;
    //ptr = func;
    
    //ptr();
    //ptr = func2;
    //ptr();
//}
