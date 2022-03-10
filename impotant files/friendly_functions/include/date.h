#ifndef _DATE_H_
#define _DATE_H_
#include <string>
#include <sstream>
#include <map>
#include "time.h"

class Time;

class Date
{
private:
    int day;
    int month;
    int year;
    //void initMap();
    /*{
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
public:
    friend std::string showDateTime(const Date& date, const Time& time);
    Date(int day, int month, int year);
    std::string toString() const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
};
#endif