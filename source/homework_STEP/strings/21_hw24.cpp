#include <iostream>
using namespace std;

struct Student
{
    char name[100];
};

void addStudent(Student*& students, int& size)
{
    if (students == nullptr)
    {
        size++;
        students = new Student[size];

        cout << "Enter fullname student: ";
        cin.getline(students->name, 100);
        cin.get();
    }
    else
    {
        size++;
        Student* newStudents = new Student[size];

        for (int i = 0; i < size - 1; i++)
        {
            newStudents[i] = students[i];
        }

        cout << "Enter fullname student: ";
        cin.getline(newStudents[size - 1].name, 100);
        cin.get();

        delete[]students;
        students = newStudents;
    }
}

void deleteStudent(Student*& students, int& size, int index)
{
    if (students == nullptr)
    {
        cout << "Empty. There are no any students" << endl;
        return;
    }
    else
    {
        size--;
        Student* newStudents = new Student[size];

        for (int i = 0, j = 0; i < size + 1; i++)
        {
            if (i != index)
            {
                newStudents[j] = students[i];
                j++;
            }
        }

        delete[]students;
        students = newStudents;
    }
}

void showStudents(Student *students, int size)
{
    if (students == nullptr)
    {
        cout << "There are no any student" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << i + 1<< ")" << students[i].name << endl;
        }
    }
}

int main()
{
    int size = 0, index, num;
    Student* students = nullptr;

    cout << "Choose option: " << endl;
    cout << "1)Add student" << endl;
    cout << "2)Delete student" << endl;
    cout << "3)Show all stdents" << endl;
    cout << "4)Exit" << endl;
    cin >> num;
    cin.get();

    while (num != 4)
    {
        switch (num)
        {
            case 1:
                addStudent(students, size);
                cout << "Choose option: " << endl;
                cout << "1)Add student" << endl;
                cout << "2)Delete student" << endl;
                cout << "3)Show all stdents" << endl;
                cout << "4)Exit" << endl;
                cin >> num;
                cin.get();
                break;
            case 2:
                cout << "Enter number of student who want delete: ";
                cin >> index;
                index -= 1;

                if (index > size || index < 1)
                {
                    cout << "There are students with this number" << endl;
                }

                deleteStudent(students, size, index);
                cout << "Choose option: " << endl;
                cout << "1)Add student" << endl;
                cout << "2)Delete student" << endl;
                cout << "3)Show all stdents" << endl;
                cout << "4)Exit" << endl;
                cin >> num;
                cin.get();
                break;
            case 3:
                showStudents(students, size);
                cout << "Choose option: " << endl;
                cout << "1)Add student" << endl;
                cout << "2)Delete student" << endl;
                cout << "3)Show all stdents" << endl;
                cout << "4)Exit" << endl;
                cin >> num;
                cin.get();
                break;
            default:
                cout << "You chose wrong option" << endl;
                cout << "Choose option again:" << endl;
                cout << "1)Add student" << endl;
                cout << "2)Delete student" << endl;
                cout << "3)Show all stdents" << endl;
                cout << "4)Exit" << endl;
                cin >> num;
                cin.get();
                break;
        }
    }

    return 0;
}
