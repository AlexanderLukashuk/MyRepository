#ifndef __TIME_H_
#define __TIME_H_
#include <sstream>
#include <map>
#include "date.h"

class Time
{
private:
    int seconds;
    int minutes;
    int hours;
    //std::map<int, int> dictionary;
    void initMap();
    //friend void showDateTime(const Date& date, const Time& time);
public:
    Time(int seconds, int minutes, int hours);
    std::string toString() const;

    void setSec(int seconds);
    void setMin(int minutes);
    void setHr(int hours);
    int getSec() const;
    int getMin() const;
    int getHr() const;
};
#endif