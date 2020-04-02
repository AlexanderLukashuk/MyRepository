#include <iostream>
#include <sstream>
using namespace std;

class Decimal
{
private:
    int integer;
    int numerator;
    int denominator;

public:
    Decimal() : integer(0), numerator(0), denominator(1) {}
    Decimal(int integer, int numerator, int denominator) : integer(integer), numerator(numerator), denominator(1)
    {
        if (denominator != 0)
        {
            this->denominator = denominator;
        }

        simplify();
    }

    string toString() const
    {
        stringstream ss;
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

    void setNumerator(int numerator)
    {
        this->numerator = numerator;
    }

    void setDenominator(int denominator)
    {
        if (denominator != 0)
        {
            this->denominator = denominator;
        }
    }

    void simplify()
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

    int getNumerator() const
    {
        return numerator;
    }

    int getDenominator() const
    {
        return denominator;
    }

    Decimal operator+(int number)
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

    Decimal operator-(int number)
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

    Decimal operator*(int number)
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

    Decimal operator/(int number)
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

    Decimal operator+(const Decimal &obj)
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

    Decimal operator-(const Decimal &obj)
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

    Decimal operator*(const Decimal &obj)
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

    Decimal operator/(const Decimal &obj)
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

    void operator+=(int number)
    {
        integer += number;
        simplify();
    }

    void operator-=(int number)
    {
        integer -= number;
        simplify();
    }

    void operator*=(int number)
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

    void operator/=(int number)
    {
        denominator *= number;
        simplify();
    }

    void operator+=(const Decimal &obj)
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

    void operator-=(const Decimal &obj)
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

    void operator*=(const Decimal &obj)
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

    void operator/=(const Decimal &obj)
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

    bool operator==(int number)
    {
        return numerator == number && denominator == 1;
    }

    bool operator!=(int number)
    {
        return numerator != number;
    }

    bool operator>(int number)
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

    bool operator<(int number)
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

    bool operator>=(int number)
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

    bool operator<=(int number)
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

    bool operator>(const Decimal& obj)
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

    bool operator<(const Decimal& obj)
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

    bool operator>=(const Decimal& obj)
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

    bool operator<=(const Decimal& obj)
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

    Decimal operator-() const
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

    bool operator!()
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
};

/*Decimal operator+(const Decimal &obj, int number)
{
    Decimal res;
    res.setDenominator(obj.getDenominator());
    res.setNumerator(obj.getDenominator() * number + obj.getNumerator());
    res.simplify();
    return res;
}

Decimal operator+(const Decimal &obj1, const Decimal &obj2)
{
    Decimal res;
    res.setDenominator(obj1.getDenominator() * obj2.getDenominator());
    res.setNumerator(obj1.getNumerator() * obj2.getDenominator() + obj2.getNumerator() * obj1.getDenominator());
    res.simplify();
    return res;
}

Decimal operator-(const Decimal &obj, int number)
{
    Decimal res;
    res.setDenominator(obj.getDenominator());
    res.setNumerator(obj.getNumerator() - obj.getDenominator() * number);
    res.simplify();
    return res;
}

Decimal operator-(const Decimal &obj1, const Decimal &obj2)
{
    Decimal res;
    //res.getDenominator(obj1.getDenominator() * obj2.getDenominator());
    res.setDenominator(obj1.getDenominator() * obj2.getDenominator());
    res.setNumerator(obj1.getNumerator() * obj2.getDenominator() - obj2.getNumerator() * obj1.getNumerator());
    res.simplify();
    return res;
}

void operator+=(Decimal& obj, int number)
{
    obj.setNumerator(obj.getDenominator() * number + obj.getNumerator());
    obj.simplify();
}

void operator+=(Decimal& obj1, const Decimal& obj2)
{
    obj1 = obj1 + obj2;
}

bool operator!(const Decimal &obj)
{
    return obj.getNumerator() < obj.getDenominator();
}

Decimal operator-(const Decimal &obj)
{
    Decimal res;
    res = obj;
    res.setNumerator(obj.getNumerator() * (-1));
    return res;
}*/

int main()
{
    Decimal dr1(0, 3, 4);

    Decimal dr2(-1, 2, 4);
    Decimal dr3;
    dr3 = dr1 - dr2;
    cout << dr3.toString();
    dr1 != 3;
    cout << dr1.toString();
    Decimal dr(0, 3, 4);
    Decimal dr6;
    dr6 = dr + 2;
    cout << dr6.toString();

    Decimal dr7;
    dr7 = dr + dr1;
    cout << dr7.toString();

    Decimal dr8(0, 2, 4);
    dr8 += dr;
    cout << dr8.toString();
    dr8 += 2;
    cout << dr8.toString();

    Decimal dr4(0, 2, 7);
    cout << !dr4 << endl;
}