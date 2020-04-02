#include <iostream>
#include "../include/student.h"
using namespace std;

int main()
{
    Student first;
    Student second;

    first.setName("Alex");
    first.getName();
    first.setBithDate(8, 10, 2003);
    first.setPhone("85863710532");
    first.getPhone();
    first.setTown("Astana");
    first.getTown();
    first.setCountry("Kazakhstan");
    first.getCountry();
    first.setEducName("Shcool");
    first.getEducName();
    first.setEducTown("Moscow");
    first.getEducTown();
    first.setEducCountry("Russia");
    first.setGroup("SEP-192");
    first.getGroup();
    second.setName("Sanya");
    second.getName();
    second.setBithDate(10, 8, 2000);
    second.setPhone("85395635988");
    second.getPhone();
    second.setTown("New-York");
    second.getTown();
    second.setCountry("USA");
    second.getCountry();
    second.setEducName("college");
    second.getEducName();
    second.setEducTown("Alabama");
    second.getEducTown();
    second.setEducCountry("USA");
    second.setGroup("SEP-192/2");
    second.getGroup();

    first.show();
    second.show();

    return 0;
}