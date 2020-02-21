#include <iostream>
using namespace std;

struct Rabotnik
{
    char surname[50];
    char position[50];
    int age;
    int day;
    int month;
    int year;
};

void initRabotnik(Rabotnik* workers, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter data of the " << i + 1 << " worker:" << endl;
        cout << "Enter surname: ";
        cin.getline(workers[i].surname, 50);
        cout << "Enter position: ";
        cin.getline(workers[i].position, 50);
        cout << "Enter age: ";
        cin >> workers[i].age;
        cout << "Enter date of employment: " << endl;
        cout << "Enter day: ";
        cin >> workers[i].day;
        cout << "Enter month: ";
        cin >> workers[i].month;
        cout << "Enter year: ";
        cin >> workers[i].year;
        cin.get();
    }
    cout << endl;
}

void pension(Rabotnik* worker, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (63 - worker[i].age < 0)
        {
            cout << "Rabotnik ";
            cout << worker[i].surname << ", ";
            cout << "Age: " << worker[i].age << ", ";
            cout << "Position: " << worker[i].position << endl;
            cout << "The worker must already be retired\n";
        }
        else
        {
            cout << "Rabotnik ";
            cout << worker[i].surname << ", ";
            cout << "Age: " << worker[i].age << ", ";
            cout << "Position: " << worker[i].position << endl;
            cout << "Worker will be retired in ";
            cout << 63 - worker[i].age << " years\n";
        }
    }
}

void workExperience(Rabotnik* worker, int size, int year)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (year - worker[j].year < year - worker[j + 1].year)
            {
                Rabotnik temp = worker[j];
                worker[j] = worker[j + 1];
                worker[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Rabotnik " << worker[i].surname << ", ";
        cout << "Work experience: " << year - worker[i].year << endl;
    }
}

int main()
{
    int size = 10, todayYear;
    Rabotnik* workers = new Rabotnik[size];
    
    initRabotnik(workers, size);
    pension(workers, size);
    cout << "Enter today's year: ";
    cin >> todayYear;
    workExperience(workers, size, todayYear);

    return 0;
}
