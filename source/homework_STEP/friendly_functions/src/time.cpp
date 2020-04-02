#include "../include/time.h"
#include <sstream>

/*void Time::initMap()
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

Time::Time(int hours, int minutes, int seconds) : seconds(seconds), minutes(minutes), hours(hours)
{
    if (hours >= 0)
    {
        if (hours > 24)
        {
            while (hours >= 24)
            {
                hours -= 24;
            }
            this->hours = hours;
        }
    }
    else
    {
        this->hours = 0;
    }

    if (minutes >= 0)
    {
        if (minutes >= 60)
        {
            while (minutes >= 60)
            {
                minutes -= 60;
            }
            this->minutes = minutes;
        }
    }
    else
    {
        this->minutes = 0;
    }

    if (seconds >= 0)
    {
        if (seconds >= 60)
        {
            while (seconds >= 60)
            {
                seconds -= 60;
            }
            this->seconds = seconds;
        }
    }
    else
    {
        this->seconds = 0;
    }
}

std::string Time::toString() const
{
    std::stringstream ss;
    ss << hours << ":" << minutes << ":" << seconds << std::endl;
    return ss.str();
}

void Time::setSec(int seconds)
{
    if (seconds >= 0)
    {
        if (seconds >= 60)
        {
            while (seconds >= 60)
            {
                seconds -= 60;
            }
            this->seconds = seconds;
        }
    }
    else
    {
        this->seconds = 0;
    }
}

void Time::setMin(int minutes)
{
    if (minutes >= 0)
    {
        if (minutes >= 60)
        {
            while (minutes >= 60)
            {
                minutes -= 60;
            }
            this->minutes = minutes;
        }
    }
    else
    {
        this->minutes = 0;
    }
}

void Time::setHr(int hours)
{
    if (hours >= 0)
    {
        if (hours >= 24)
        {
            while (hours >= 24)
            {
                hours -= 24;
            }
            this->hours = hours;
        }
    }
    else
    {
        this->hours = 0;
    }
}

int Time::getSec() const
{
    return seconds;
}

int Time::getMin() const
{
    return minutes;
}

int Time::getHr() const
{
    return hours;
}