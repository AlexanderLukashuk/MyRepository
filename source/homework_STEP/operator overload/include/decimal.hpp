#ifndef _DECIMAL_H_
#define _DECIMAL_H_
#include <sstream>

class Decimal
{
private:
    int integer;
    int numerator;
    int denominator;

public:
    Decimal();
    Decimal(int integer, int numerator, int denominator);

    std::string toString() const;

    void setNumerator(int numerator);

    void setDenominator(int denominator);

    void simplify();

    int getNumerator() const;

    int getDenominator() const;

    Decimal operator+(int number);

    Decimal operator-(int number);

    Decimal operator*(int number);

    Decimal operator/(int number);

    Decimal operator+(const Decimal &obj);

    Decimal operator-(const Decimal &obj);

    Decimal operator*(const Decimal &obj);

    Decimal operator/(const Decimal &obj);

    void operator+=(int number);

    void operator-=(int number);

    void operator*=(int number);

    void operator/=(int number);

    void operator+=(const Decimal &obj);

    void operator-=(const Decimal &obj);

    void operator*=(const Decimal &obj);

    void operator/=(const Decimal &obj);

    bool operator==(int number);

    bool operator!=(int number);

    bool operator>(int number);

    bool operator<(int number);

    bool operator>=(int number);

    bool operator<=(int number);

    bool operator>(const Decimal &obj);

    bool operator<(const Decimal &obj);

    bool operator>=(const Decimal &obj);

    bool operator<=(const Decimal &obj);

    Decimal operator-() const;

    bool operator!();
};
#endif