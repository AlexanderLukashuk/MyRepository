#include <sstream>
#include "../include/decimal.hpp"

Decimal::Decimal() : integer(0), numerator(0), denominator(1) {}
Decimal::Decimal(int integer, int numerator, int denominator) : integer(integer), numerator(numerator), denominator(1)
{
    if (denominator != 0)
    {
        this->denominator = denominator;
    }

    simplify();
}

std::string Decimal::toString() const
{
    using std::endl;
    std::stringstream ss;
    if (numerator == 0)
    {
        ss << 0 << endl;
    }
    else if (integer == 0)
    {
        ss << "(" << numerator << "/" << denominator << ")" << endl;
    }
    else
    {
        ss << integer << "(" << numerator << "/" << denominator << ")" << endl;
    }

    return ss.str();
}

void Decimal::setNumerator(int numerator)
{
    this->numerator = numerator;
}

void Decimal::setDenominator(int denominator)
{
    if (denominator != 0)
    {
        this->denominator = denominator;
    }
}

void Decimal::simplify()
{
    int devider = numerator >= denominator ? denominator : numerator;

    for (int i = devider; true; i--)
    {
        if (numerator % i == 0 && denominator % i == 0)
        {
            devider = i;
            break;
        }
    }

    numerator /= devider;
    denominator /= devider;
}

int Decimal::getNumerator() const
{
    return numerator;
}

int Decimal::getDenominator() const
{
    return denominator;
}

Decimal Decimal::operator+(int number)
{
    Decimal res = *this;
    res.integer += number;
    res.simplify();
    if (res.numerator > res.denominator)
    {
        while (res.numerator > res.denominator)
        {
            res.numerator = res.numerator - res.denominator;
            res.integer++;
        }
    }
    return res;
}

Decimal Decimal::operator-(int number)
{
    Decimal res = *this;
    res.integer -= number;
    res.simplify();
    if (res.numerator > res.denominator)
    {
        while (res.numerator > res.denominator)
        {
            res.numerator = res.numerator - res.denominator;
            res.integer++;
        }
    }
    return res;
}

Decimal Decimal::operator*(int number)
{
    Decimal res;
    res.integer = 0;
    res.numerator = (integer * denominator + numerator) * number;
    res.denominator = denominator;
    res.simplify();
    if (res.numerator > res.denominator)
    {
        while (res.numerator > res.denominator)
        {
            res.numerator = res.numerator - res.denominator;
            res.integer++;
        }
    }
    return res;
}

Decimal Decimal::operator/(int number)
{
    Decimal res;
    res.integer = 0;
    res.numerator = (integer * denominator + numerator);
    res.denominator = denominator * number;
    res.simplify();
    if (res.numerator > res.denominator)
    {
        while (res.numerator > res.denominator)
        {
            res.numerator = res.numerator - res.denominator;
            res.integer++;
        }
    }
    return res;
}

Decimal Decimal::operator+(const Decimal &obj)
{
    Decimal res;
    res.integer = integer + obj.integer;
    if (denominator == obj.denominator)
    {
        res.numerator = numerator + obj.numerator;
        res.denominator = denominator;
    }
    else
    {
        res.numerator = numerator * obj.denominator + obj.numerator * denominator;
        res.denominator = denominator * obj.denominator;
    }
    res.simplify();
    if (res.numerator > res.denominator)
    {
        while (res.numerator > res.denominator)
        {
            res.numerator = res.numerator - res.denominator;
            res.integer++;
        }
    }
    return res;
}

Decimal Decimal::operator-(const Decimal &obj)
{
    Decimal res;
    if (denominator != obj.denominator)
    {
        res.numerator = (integer * denominator + numerator * obj.denominator) - (obj.integer * obj.denominator + obj.numerator * denominator);
        res.denominator = denominator * obj.denominator;
    }
    else
    {
        res.numerator = (integer * denominator + numerator) - (obj.integer * obj.denominator + obj.numerator);
        res.denominator = denominator;
    }
    res.simplify();

    if (res.numerator > res.denominator)
    {
        while (res.numerator > res.denominator)
        {
            res.numerator = res.numerator - res.denominator;
            res.integer++;
        }
    }
    return res;
}

Decimal Decimal::operator*(const Decimal &obj)
{
    Decimal res;
    res.numerator = (integer * denominator + numerator) * (obj.integer * obj.denominator + obj.numerator);
    res.denominator = denominator * obj.denominator;
    res.simplify();
    if (res.numerator > res.denominator)
    {
        while (res.numerator > res.denominator)
        {
            res.numerator = res.numerator - res.denominator;
            res.integer++;
        }
    }
    return res;
}

Decimal Decimal::operator/(const Decimal &obj)
{
    Decimal res;
    res.numerator = (integer * denominator + numerator) * obj.denominator;
    res.denominator = denominator * (obj.integer * obj.denominator + obj.numerator);
    res.simplify();
    if (res.numerator > res.denominator)
    {
        while (res.numerator > res.denominator)
        {
            res.numerator = res.numerator - res.denominator;
            res.integer++;
        }
    }
    return res;
}

void Decimal::operator+=(int number)
{
    integer += number;
    simplify();
}

void Decimal::operator-=(int number)
{
    integer -= number;
    simplify();
}

void Decimal::operator*=(int number)
{
    numerator = (integer * denominator + numerator) * number;
    integer = 0;
    simplify();
    if (numerator > denominator)
    {
        while (numerator > denominator)
        {
            numerator = numerator - denominator;
            integer++;
        }
    }
}

void Decimal::operator/=(int number)
{
    denominator *= number;
    simplify();
}

void Decimal::operator+=(const Decimal &obj)
{
    if (denominator != obj.denominator)
    {
        integer += obj.integer;
        numerator = numerator * obj.denominator + obj.numerator * denominator;
        denominator = denominator * obj.denominator;
    }
    else if (denominator == obj.denominator)
    {
        integer += obj.integer;
        numerator = numerator * obj.denominator + obj.numerator * denominator;
    }
    simplify();
    if (numerator > denominator)
    {
        while (numerator > denominator)
        {
            numerator = numerator - denominator;
            integer++;
        }
    }
}

void Decimal::operator-=(const Decimal &obj)
{
    if (denominator != obj.denominator)
    {
        numerator = numerator * obj.denominator - obj.numerator * denominator;
        //integer -= obj.integer;
        denominator *= obj.denominator;
    }
    else
    {
        numerator = numerator * obj.denominator - obj.numerator * denominator;
    }
    simplify();
    if (numerator > denominator)
    {
        while (numerator > denominator)
        {
            numerator = numerator - denominator;
            integer++;
        }
    }
}

void Decimal::operator*=(const Decimal &obj)
{
    numerator = (integer * denominator + numerator) * (obj.integer * obj.denominator + obj.numerator);
    denominator = denominator * obj.denominator;
    simplify();
    if (numerator > denominator)
    {
        while (numerator > denominator)
        {
            numerator = numerator - denominator;
            integer++;
        }
    }
}

void Decimal::operator/=(const Decimal &obj)
{
    numerator = (integer * denominator + numerator) * obj.denominator;
    denominator = denominator * (obj.integer * obj.denominator + obj.numerator);
    simplify();
    if (numerator > denominator)
    {
        while (numerator > denominator)
        {
            numerator = numerator - denominator;
            integer++;
        }
    }
}

bool Decimal::operator==(int number)
{
    return numerator == number && denominator == 1;
}

bool Decimal::operator!=(int number)
{
    return numerator != number;
}

bool Decimal::operator>(int number)
{
    if (integer * denominator + numerator > number * denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Decimal::operator<(int number)
{
    if (integer * denominator + numerator < number * denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Decimal::operator>=(int number)
{
    if (integer * denominator + numerator >= number * denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Decimal::operator<=(int number)
{
    if (integer * denominator + numerator <= number * denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Decimal::operator>(const Decimal &obj)
{
    if (integer * denominator + numerator > obj.integer * obj.denominator + obj.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Decimal::operator<(const Decimal &obj)
{
    if (integer * denominator + numerator < obj.integer * obj.denominator + obj.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Decimal::operator>=(const Decimal &obj)
{
    if (integer * denominator + numerator >= obj.integer * obj.denominator + obj.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Decimal::operator<=(const Decimal &obj)
{
    if (integer * denominator + numerator <= obj.integer * obj.denominator + obj.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Decimal Decimal::operator-() const
{
    Decimal res = *this;
    if (res.integer != 0)
    {
        res.integer *= -1;
    }
    else if (res.numerator != 0)
    {
        res.numerator *= -1;
    }

    return res;
}

bool Decimal::operator!()
{
    if (numerator != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}