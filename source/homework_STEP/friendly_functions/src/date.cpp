#include <iostream>
#include <sstream>
#include <map>
#include "../include/date.h"
#include "../include/dateManager.h"

/*void Date::initMap()
{
    dictionary.insert(std::pair<int, int>(1, 31));
    dictionary.insert(std::pair<int, int>(2, 28));
    dictionary.insert(std::pair<int, int>(3, 31));
    dictionary.insert(std::pair<int, int>(4, 30));
    dictionary.insert(std::pair<int, int>(5, 31));
    dictionary.insert(std::pair<int, int>(6, 30));
    dictionary.insert(std::pair<int, int>(7, 31));
    dictionary.insert(std::pair<int, int>(8, 31));
    dictionary.insert(std::pair<int, int>(9, 30));
    dictionary.insert(std::pair<int, int>(10, 31));
    dictionary.insert(std::pair<int, int>(11, 30));
    dictionary.insert(std::pair<int, int>(12, 31));
}*/

Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
    //initMap();
    if (month >= 12)
    {
        while (month > 12)
        {
            month -= 12;
        }
    }

    if (month >= 1 && month <= 12)
    {
        this->month = month;
    }
    else
    {
        this->month = 1;
    }

    auto dictionary = DateManager::InitMap();
    for (auto i = dictionary.begin(); i != dictionary.end(); ++i)
    {
        if (i->first == month)
        {
            if (day > i->second)
            {
                this->day = i->second;
            }
        }
    }

    /*for (auto i = dictionary.begin(); i != dictionary.end(); ++i)
    {

        if (i->first == month)
        {
            if (day > i->second)
            {
                this->day = i->second;
            }
        }
    }*/
}

void Date::setDay(int day)
{
    auto dictionary = DateManager::InitMap();
    for (auto i = dictionary.begin(); i != dictionary.end(); ++i)
    {
        if (i->first == month)
        {
            if (day > i->second)
            {
                this->day = i->second;
            }
        }
    }
}

void Date::setMonth(int month)
{
    if (month >= 12)
    {
        while (month > 12)
        {
            month -= 12;
        }
    }

    if (month >= 1 && month <= 12)
    {
        this->month = month;
    }
    else
    {
        this->month = 1;
    }
}

void Date::setYear(int year)
{
    this->year = year;
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

std::string Date::toString() const
{
    std::stringstream ss;
    ss << day << "." << month << "." << year << std::endl;
    return ss.str();
}

std::string showDateTime(const Date &date, const Time &time)
{
    std::stringstream ss;
    ss << date.getDay() << "." << date.getMonth() << "." << date.getYear();
    ss << "  " << time.getHr() << ":" << time.getMin() << ":" << time.getSec() << std::endl;
    return ss.str();
}