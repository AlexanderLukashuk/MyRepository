#include <iostream>
#include "../include/student.h"
using namespace std;

Student::Student()
{
    {
        strcpy(name, "no name");
        b_day = 0;
        b_month = 0;
        b_year = 0;
        strcpy(phone, "00000000000");
        strcpy(town, "no name");
        strcpy(country, "no name");
        strcpy(educ_name, "no name");
        strcpy(educ_town, "no name");
        strcpy(educ_country, "no name");
        strcpy(group, "no group");
    }
}

void Student::setName(const char* _name)
{
    strcpy(name, _name);
}

void Student::setBithDate(int day, int month, int year)
{
    b_day = day;
    b_month = month;
    b_year = year;
}

void Student::setPhone(const char* _phone)
{
    strcpy(phone, _phone);
}

void Student::setTown(const char* _town)
{
    strcpy(town, _town);
}

void Student::setCountry(const char* _country)
{
    strcpy(country, _country);
}

void Student::setEducName(const char* _educ_name)
{
    strcpy(educ_name, _educ_name);
}

void Student::setEducTown(const char* _educ_town)
{
    strcpy(educ_town, _educ_town);
}

void Student::setEducCountry(const char* _educ_country)
{
    strcpy(educ_country, _educ_country);
}

void Student::setGroup(const char* _group)
{
    strcpy(group, _group);
}

char* Student::getName()
{
    return name;
}

char* Student::getPhone()
{
    return phone;
}

char* Student::getTown()
{
    return town;
}

char* Student::getCountry()
{
    return country;
}

char* Student::getEducName()
{
    return educ_name;
}

char* Student::getEducTown()
{
    return educ_town; 
}

char* Student::getEducCountry()
{
    return educ_country;
}

char* Student::getGroup()
{
    return group;
}

void Student::show()
{
    cout << "Name: " << name << endl;
    cout << "Bith Date: " << b_day << "." << b_month << "." << b_year << endl;
    //getBithDate();
    cout << "Phone number: " << phone << endl;
    cout << "Town: " << town << endl;
    cout << "Country: " << country << endl;
    cout << "Education name(institution): " << educ_name << endl;
    cout << "Education town: " << educ_town << endl;
    cout << "Edcation country: " << educ_country << endl;
    cout << "Group: " << group << endl;
}