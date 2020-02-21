#include <iostream>
using namespace std;

struct Student
{
	char fullname[50];
	int age;
	int * marks = nullptr;
	int MarksCount = 0;
};

struct Group
{
	char name[20];
	int count = 0;
	Student * Students = nullptr;
};


void addGroup(Group*& groups, int& size)
{
	if (groups == nullptr)
	{
		size++;
		groups = new Group[size];

		cout << "Enter group name: ";
		cin >> groups->name;
		cin.get();
	}
	else
	{
		size++;
		Group* newGroup = new Group[size];

		for (int i = 0; i < size - 1; i++)
		{
			newGroup[i] = groups[i];
		}

		cout << "Enter group name: ";
		cin >> newGroup[size - 1].name;
		cin.get();

		delete[]groups;
		groups = newGroup;
	}
}

void addStudent(Student*& students, int& count)
{
	if (students == nullptr)
	{
		count++;
		students = new Student[count];

		cout << "Enter fullname: ";
		cin.getline(students->fullname, 50);
		cout << "Enter age: ";
		cin >> students->age;
		cin.get();
	}
	else
	{
		count++;
		Student* newStudents = new Student[count];

		for (int i = 0; i < count - 1; i++)
		{
			newStudents[i] = students[i];
		}

		cout << "Enter fullname: ";
		cin.getline(newStudents[count - 1].fullname, 50);
		cout << "Enter age: ";
		cin >> newStudents[count - 1].age;
		cin.get();

		delete[]students;
		students = newStudents;
	}
}

void addMark(int*& marks, int& marksCount)
{
	if (marks == nullptr)
	{
		marksCount++;
		marks = new int[marksCount];

		cout << "Enter mark: ";
		cin >> marks[0];
		cin.get();
	}
	else
	{
		marksCount++;
		int* newMarks = new int[marksCount];

		for (int i = 0; i < marksCount - 1; i++)
		{
			newMarks[i] = marks[i];
		}

		cout << "Enter mark: ";
		cin >> newMarks[marksCount - 1];
		cin.get();

		delete[]marks;
		marks = newMarks;
	}
}

void showGroup(Group* groups, int size)
{
	if (groups == nullptr)
	{
		cout << "There are no any groups" << endl;
        return;
	}
	else
	{
        cout << "Groups:\n";
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ")" << groups[i].name << endl;
		}
	}
}

void showStudents(Student* students, int count)
{
	if (students == nullptr)
	{
		cout << "There are no any students" << endl;
        return;
	}
	else
	{
        cout << "Students list:\n";
		for (int i = 0; i < count; i++)
		{
			cout << i + 1 << ")" << students[i].fullname << endl;
		}
	}
}

void showMarks(int *marks, int marksCount)
{
	if (marks == NULL)
	{
		cout << "This student has not any marks" << endl;
        return;
	}
	else
	{
        cout << "Marks list: ";
		for (int i = 0; i < marksCount; i++)
		{
			cout << marks[i] << " ";
		}
        cout << endl;
	}
}

void deleteGroup(Group*& groups, int& size, int index)
{
    if (index < 0 || index >= size)
    {
        cout << "You choose wrong group\n";
        cout << "There are no group with this number\n";
        return;
    }

    if (groups == nullptr)
    {
        cout << "There are no any groups" << endl;
        return;
    }
    else
    {
        size--;
        Group* newGroups = new Group[size];
        for (int i = 0, j = 0; i < size + 1; i++)
        {
            if (i != index)
            {
                newGroups[j] = groups[i];
                j++;
            }
        }

        delete[]groups;
        groups = newGroups;
    }
}

void deleteStudent(Student*& students, int& count, int index)
{
    if (index < 0 || index >= count)
    {
        cout << "You choose wrong student\n";
        cout << "There are no student with this number\n";
        return;
    }

    if (students == nullptr)
    {
        cout << "There are no students in this group" << endl;
        return;
    }
    else
    {
        count--;
        Student* newStudents = new Student[count];
        for (int i = 0, j = 0; i < count + 1; i++)
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

void deleteMark(int*& marks, int& marksCount, int indexMark)
{
    if (marks == nullptr)
    {
        cout << "This student has not marks" << endl;
    }
    else if (indexMark > marksCount || indexMark < 1)
    {
        cout << "You entered wrong number of mark" << endl;
    }
    else
    {
        marksCount--;
        int* newMarks = new int[marksCount];
        for (int i = 0, j = 0; i < marksCount + 1; i++)
        {
            if (i != indexMark)
            {
                newMarks[j] = marks[i];
                j++;
            }
        }

        delete[]marks;
        marks = newMarks;
    }
}

int main()
{
	int size = 0, num, indexGroup, indexStudent;
    int indexMark;
	Group* Groups = nullptr;

	cout << "Choose option: " << endl;
	cout << "1)Add group" << endl;
	cout << "2)Add student" << endl;
	cout << "3)Add mark" << endl;
    cout << "4)Show all groups" << endl;
    cout << "5)Show students" << endl;
    cout << "6)Show marks" << endl;
	cout << "7)Delete group" << endl;
	cout << "8)Delete studet" << endl;
	cout << "9)Delete mark" << endl;
	cout << "10)Exit" << endl;
	cin >> num;

	while (num != 10)
	{
		switch (num)
		{
		case 1:
			addGroup(Groups, size);
			cout << "Choose option: " << endl;
			cout << "1)Add group" << endl;
			cout << "2)Add student" << endl;
			cout << "3)Add mark" << endl;
            cout << "4)Show all groups" << endl;
            cout << "5)Show students" << endl;
            cout << "6)Show marks" << endl;
			cout << "7)Delete group" << endl;
			cout << "8)Delete student" << endl;
			cout << "9)Delete mark" << endl;
			cout << "10)Exit" << endl;
			cin >> num;
			cin.get();
			break;
		case 2:
			cout << "Enter number of group: ";
			cin >> indexGroup;
			cin.get();
			indexGroup--;
			
			if (indexGroup > size || indexGroup < 0)
			{
				cout << "There are no group witch you chose" << endl;
				cout << "Choose right group >:[" << endl;
			}
			else
			{
				addStudent(Groups[indexGroup].Students, Groups[indexGroup].count);
			    cout << "Choose option: " << endl;
			    cout << "1)Add group" << endl;
			    cout << "2)Add student" << endl;
			    cout << "3)Add mark" << endl;
                cout << "4)Show all groups" << endl;
                cout << "5)Show students" << endl;
                cout << "6)Show marks" << endl;
			    cout << "7)Delete group" << endl;
			    cout << "8)Delete student" << endl;
			    cout << "9)Delete mark" << endl;
			    cout << "10)Exit" << endl;
			    cin >> num;
			    cin.get();
			}
			break;
		case 3:
			cout << "Enter number of group: ";
			cin >> indexGroup;
			indexGroup--;
			cout << "Enter number of students: ";
			cin >> indexStudent;
			indexStudent--;
			cin.get();

			if (indexGroup > size || indexGroup < 0)
			{
				cout << "There are no group witch you chose" << endl;
				cout << "Choose right group >:[" << endl;
			}
			else if (indexStudent > Groups[indexGroup].count || indexStudent < 0)
			{
				cout << "There are no student who you chose" << endl;
				cout << "Choose right group >:[" << endl;
			}
			else
			{
				addMark(Groups[indexGroup].Students[indexStudent].marks, Groups[indexGroup].Students[indexStudent].MarksCount);
			    cout << "Choose option: " << endl;
			    cout << "1)Add group" << endl;
			    cout << "2)Add student" << endl;
			    cout << "3)Add mark" << endl;
                cout << "4)Show all groups" << endl;
                cout << "5)Show students" << endl;
                cout << "6)Show marks" << endl;
			    cout << "7)Delete group" << endl;
			    cout << "8)Delete student" << endl;
			    cout << "9)Delete mark" << endl;
			    cout << "10)Exit" << endl;
			    cin >> num;
			    cin.get();
			}
			break;
		case 4:
			showGroup(Groups, size);
			cout << "Choose option: " << endl;
			cout << "1)Add group" << endl;
			cout << "2)Add student" << endl;
			cout << "3)Add mark" << endl;
            cout << "4)Show all groups" << endl;
            cout << "5)Show students" << endl;
            cout << "6)Show marks" << endl;
			cout << "7)Delete group" << endl;
			cout << "8)Delete student" << endl;
			cout << "9)Delete mark" << endl;
			cout << "10)Exit" << endl;
			cin >> num;
			cin.get();
			break;
		case 5:
			cout << "Enter number of group: ";
			cin >> indexGroup;
			cin.get();
			indexGroup--;

			if (indexGroup > size || indexGroup < 0)
			{
				cout << "There are no group witch you chose" << endl;
				cout << "Choose right group >:[" << endl;
			}
			else
			{
				showStudents(Groups[indexGroup].Students, Groups[indexGroup].count);
			    cout << "Choose option: " << endl;
			    cout << "1)Add group" << endl;
			    cout << "2)Add student" << endl;
			    cout << "3)Add mark" << endl;
                cout << "4)Show all groups" << endl;
                cout << "5)Show students" << endl;
                cout << "6)Show marks" << endl;
			    cout << "7)Delete group" << endl;
			    cout << "8)Delete student" << endl;
			    cout << "9)Delete mark" << endl;
			    cout << "10)Exit" << endl;
			    cin >> num;
			    cin.get();
			}
			break;
		case 6:
			cout << "Enter number of group: ";
			cin >> indexGroup;
			cin.get();
			indexGroup--;
			cout << "Enter number of students: ";
			cin >> indexStudent;
			cin.get();
			indexStudent--;

			if (indexGroup > size || indexGroup < 0)
			{
				cout << "There are no group witch you chose" << endl;
				cout << "Choose right group >:[" << endl;
			}
			else if (indexStudent > Groups[indexGroup].count || indexStudent < 0)
			{
				cout << "There are no student who you chose" << endl;
				cout << "Choose right group >:[" << endl;
			}
			else
			{
				showMarks(Groups[indexGroup].Students[indexStudent].marks, Groups[indexGroup].Students[indexStudent].MarksCount);
			    cout << "Choose option: " << endl;
			    cout << "1)Add group" << endl;
			    cout << "2)Add student" << endl;
			    cout << "3)Add mark" << endl;
                cout << "4)Show all groups" << endl;
                cout << "5)Show students" << endl;
                cout << "6)Show marks" << endl;
			    cout << "7)Delete group" << endl;
			    cout << "8)Delete student" << endl;
			    cout << "9)Delete mark" << endl;
			    cout << "10)Exit" << endl;
			    cin >> num;
			    cin.get();
			}
			break;
        case 7:
            cout << "Enter number of group: ";
            cin >> indexGroup;
            indexGroup--;
            deleteGroup(Groups, size, indexGroup);
			cout << "Choose option: " << endl;
			cout << "1)Add group" << endl;
			cout << "2)Add student" << endl;
			cout << "3)Add mark" << endl;
            cout << "4)Show all groups" << endl;
            cout << "5)Show students" << endl;
            cout << "6)Show marks" << endl;
			cout << "7)Delete group" << endl;
			cout << "8)Delete student" << endl;
			cout << "9)Delete mark" << endl;
			cout << "10)Exit" << endl;
			cin >> num;
			cin.get();
			break;
        case 8:
            cout << "Enter number of group: ";
            cin >> indexGroup;
            indexGroup--;
            cout << "Enter number of student who want delete: ";
            cin >> indexStudent;
            indexStudent--;
			deleteStudent(Groups[indexGroup].Students, Groups[indexGroup].count, indexStudent);
			cout << "Choose option: " << endl;
			cout << "1)Add group" << endl;
			cout << "2)Add student" << endl;
			cout << "3)Add mark" << endl;
            cout << "4)Show all groups" << endl;
            cout << "5)Show students" << endl;
            cout << "6)Show marks" << endl;
			cout << "7)Delete group" << endl;
			cout << "8)Delete student" << endl;
			cout << "9)Delete mark" << endl;
			cout << "10)Exit" << endl;
			cin >> num;
			cin.get();
			break;
        case 9:
			cout << "Enter number of group: ";
			cin >> indexGroup;
			indexGroup--;
			cout << "Enter number of students: ";
			cin >> indexStudent;
			indexStudent--;
            cout << "Enter number of mark which want delete: ";
            cin >> indexMark;
			cin.get();
			deleteMark(Groups[indexGroup].Students[indexStudent].marks, Groups[indexGroup].Students[indexStudent].MarksCount, indexMark);
			cout << "Choose option: " << endl;
			cout << "1)Add group" << endl;
			cout << "2)Add student" << endl;
			cout << "3)Add mark" << endl;
            cout << "4)Show all groups" << endl;
            cout << "5)Show students" << endl;
            cout << "6)Show marks" << endl;
			cout << "7)Delete group" << endl;
			cout << "8)Delete student" << endl;
			cout << "9)Delete mark" << endl;
			cout << "10)Exit" << endl;
			cin >> num;
			cin.get();
			break;
		default:
			cout << "You chose wrong option" << endl;
			cout << "Choose option again:" << endl;
			cout << "1)Add group" << endl;
			cout << "2)Add student" << endl;
			cout << "3)Add mark" << endl;
            cout << "4)Show all groups" << endl;
            cout << "5)Show students" << endl;
            cout << "6)Show marks" << endl;
			cout << "7)Delete group" << endl;
			cout << "8)Delete student" << endl;
			cout << "9)Delete mark" << endl;
			cout << "10)Exit" << endl;
			cin >> num;
			cin.get();
			break;
		}
	}

    return 0;
}
