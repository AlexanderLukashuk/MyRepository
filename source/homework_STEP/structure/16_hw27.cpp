#include <iostream>
using namespace std;

struct Fraction
{
    int wholePart;
    int numerator;
    int denominator;
};

void sum(Fraction& fraction1, Fraction& fraction2, Fraction& fraction3)
{
    int num = 1;

    cout << "Enter second fraction: " << endl;
    cout << "Enter whole part of fraction(if there is no whole part, enter 0: ";
    cin >> fraction2.wholePart;
    cout << "Enter numerator of fraction: ";
    cin >> fraction2.numerator;
    cout << "Enter denominator of fraction: ";
    cin >> fraction2.denominator;

    if (fraction1.denominator == fraction2.denominator)
    {
        fraction3.denominator = fraction1.denominator;
        fraction3.numerator = fraction1.numerator + fraction2.numerator;
    }
    else
    {
        fraction3.denominator = fraction1.denominator * fraction2.denominator;
    }

    while (fraction3.numerator >= fraction3.denominator)
    {
        if (fraction3.numerator > fraction3.denominator)
        {
            fraction3.wholePart++;
        }
    }

    for (int i = 0; i < fraction3.numerator; i++)
    {
        if (fraction3.numerator % i == 0 && fraction3.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction3.numerator /= num;
    fraction3.denominator /= num;

    while (fraction2.numerator >= fraction2.denominator)
    {
        if (fraction2.numerator >= fraction2.denominator)
        {
            fraction2.wholePart++;
            fraction2.numerator -= fraction2.denominator;
        }
    }

    for (int i = 0; i <= fraction2.numerator; i++)
    {
        if (fraction2.numerator % i == 0 && fraction2.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction2.numerator /= num;
    fraction2.denominator /= num;

    while (fraction1.numerator >= fraction1.denominator)
    {
        if (fraction1.numerator >= fraction1.denominator)
        {
            fraction1.wholePart++;
            fraction1.numerator -= fraction1.denominator;
        }
    }

    for (int i = 0; i <= fraction1.numerator; i++)
    {
        if (fraction1.numerator % i == 0 && fraction1.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction1.numerator /= num;
    fraction1.denominator /= num;

    fraction3.numerator = fraction1.numerator + fraction2.numerator;
}

void subtraction(Fraction& fraction1, Fraction& fraction2, Fraction& fraction3)
{
    int num = 1;

    cout << "Enter second fraction: " << endl;
    cout << "Enter whole part of fraction(if there is no whole part, enter 0: ";
    cin >> fraction2.wholePart;
    cout << "Enter numerator of fraction: ";
    cin >> fraction2.numerator;
    cout << "Enter denominator of fraction: ";
    cin >> fraction2.denominator;

    if (fraction1.denominator == fraction2.denominator)
    {
        fraction3.denominator = fraction1.denominator;
    }
    else
    {
        fraction3.denominator = fraction1.denominator * fraction2.denominator;
    }

    while (fraction3.numerator >= fraction3.denominator)
    {
        if (fraction3.numerator >= fraction3.denominator)
        {
            fraction3.wholePart++;
            fraction3.numerator -= fraction3.denominator;
        }
    }

    for (int i = 0; i <= fraction3.numerator; i++)
    {
        if (fraction3.numerator % i == 0 && fraction3.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction3.numerator /= num;
    fraction3.denominator /= num;

    while (fraction2.numerator >= fraction2.denominator)
    {
        if (fraction2.numerator >= fraction2.denominator)
        {
            fraction2.wholePart++;
            fraction2.numerator -= fraction2.denominator;
        }
    }
    for (int i = 0; i <= fraction2.numerator; i++)
    {
        if (fraction2.numerator % i == 0 && fraction2.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction2.numerator /= num;
    fraction2.denominator /= num;

    while (fraction1.numerator >= fraction1.denominator)
    {
        if (fraction1.numerator >= fraction1.denominator)
        {
            fraction1.wholePart++;
            fraction1.numerator -= fraction1.denominator;
        }
    }

    for (int i = 0; i <= fraction1.numerator; i++)
    {
        if (fraction1.numerator % i == 0 && fraction1.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction1.numerator /= num;
    fraction1.denominator /= num;

    if (fraction2.numerator > fraction1.numerator && fraction1.wholePart > 0)
    {
        fraction1.wholePart--;
        fraction1.numerator += fraction1.denominator;
    }

    fraction3.numerator = fraction1.numerator - fraction2.numerator;
}

void multiplication(Fraction& fraction1, Fraction& fraction2, Fraction& fraction3)
{
    int num = 1;

    cout << "Enter second fraction: " << endl;
    cout << "Enter whole part of fraction(if there is no whole part, enter 0: ";
    cin >> fraction2.wholePart;
    cout << "Enter numerator of fraction: ";
    cin >> fraction2.numerator;
    cout << "Enter denominator of fraction: ";
    cin >> fraction2.denominator;

    fraction1.numerator += fraction1.wholePart * fraction1.denominator;
    fraction3.denominator = fraction1.denominator * fraction2.denominator;

    while (fraction3.numerator >= fraction3.denominator)
    {
        if (fraction3.numerator >= fraction3.denominator)
        {
            fraction3.wholePart++;
        }
    }

    for (int i = 0; i <= fraction3.numerator; i++)
    {
        if (fraction3.numerator % i == 0 && fraction3.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction3.numerator /= num;
    fraction3.denominator /= num;

    while (fraction2.numerator >= fraction2.denominator)
    {
        if (fraction2.numerator >= fraction2.denominator)
        {
            fraction2.wholePart++;
            fraction2.numerator -= fraction2.denominator;
        }
    }

    for (int i = 0; i <= fraction2.numerator; i++)
    {
        if (fraction2.numerator % i == 0 && fraction2.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction2.numerator /= num;
    fraction2.denominator /= num;

    while (fraction1.numerator >= fraction1.denominator)
    {
        if (fraction1.numerator >= fraction1.denominator)
        {
            fraction1.wholePart++;
            fraction1.numerator -= fraction1.denominator;
        }
    }

    for (int i = 0; i <= fraction1.numerator; i++)
    {
        if (fraction1.numerator % i == 0 && fraction1.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction1.numerator /= num;
    fraction1.denominator /= num;

    fraction3.numerator = fraction1.numerator + fraction2.numerator;
}

void division(Fraction& fraction1, Fraction& fraction2, Fraction& fraction3)
{
    int num = 1;

    cout << "Enter second fraction: " << endl;
    cout << "Enter whole part of fraction(if there is no whole part, enter 0: ";
    cin >> fraction2.wholePart;
    cout << "Enter numerator of fraction: ";
    cin >> fraction2.numerator;
    cout << "Enter denominator of fraction: ";
    cin >> fraction2.denominator;

    fraction1.numerator += fraction1.wholePart * fraction1.denominator;
    fraction2.numerator += fraction2.wholePart * fraction2.denominator;
    fraction3.numerator = fraction1.numerator * fraction2.numerator;
    fraction3.denominator = fraction1.denominator * fraction2.denominator;

    while (fraction3.numerator >= fraction3.denominator)
    {
        if (fraction3.numerator >= fraction3.denominator)
        {
            fraction3.wholePart++;
            fraction3.numerator -= fraction3.denominator;
        }

    }

    for (int i = 0; i <= fraction3.numerator; i++)
    {
        if (fraction3.numerator % i == 0 && fraction3.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction3.numerator /= num;
    fraction3.denominator /= num;

    while (fraction2.numerator >= fraction2.denominator)
    {
        if (fraction2.numerator >= fraction2.denominator)
        {
            fraction2.wholePart++;
            fraction2.numerator -= fraction2.denominator;
        }

    }

    for (int i = 0; i <= fraction2.numerator; i++)
    {
        if (fraction2.numerator % i == 0 && fraction2.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction2.numerator /= num;
    fraction2.denominator /= num;

    while (fraction1.numerator >= fraction1.denominator)
    {
        if (fraction1.numerator >= fraction1.denominator)
        {
            fraction1.wholePart++;
            fraction1.numerator -= fraction1.denominator;
        }

    }

    for (int i = 0; i <= fraction1.numerator; i++)
    {
        if (fraction1.numerator % i == 0 && fraction1.denominator % i == 0)
        {
            num = i;
        }
    }

    fraction1.numerator /= num;
    fraction1.denominator /= num;

    fraction3.numerator = fraction1.numerator + fraction2.numerator;
}

int main()
{
    int num = 0;
    Fraction fraction1;
    Fraction fraction2;
    Fraction fraction3;

    while (num != 5)
    {
        cout << "Enter first fraction: " << endl;
        cout << "Enter whole part of fraction(if there is no whole part, enter 0: ";
        cin >> fraction1.wholePart;
        cout << "Enter numerator of fraction: ";
        cin >> fraction1.numerator;
        cout << "Enter denominator of fraction: ";
        cin >> fraction1.denominator;

        cout << "Choose operation: " << endl;
        cout << "1)Addition" << endl;
        cout << "2)Subtraction" << endl;
        cout << "3)Multiplication" << endl;
        cout << "4)Division" << endl;
        cout << "5)Exit" << endl;
        cin >> num;

        switch (num)
        {
            case 1:
                sum(fraction1, fraction2, fraction3);
                cout << " " << fraction1.numerator << " " << " "
                    << fraction2.numerator << "    "
                    << fraction3.numerator << endl;
                cout << fraction1.wholePart << "-" << "+"
                    << fraction2.wholePart << "-"
                    << " " << "=" << " " 
                    << fraction3.wholePart << "-" << endl;
                cout << " " << fraction1.denominator << " " << " "
                    << fraction2.denominator << "    "
                    << fraction3.denominator << endl;
                break;
            case 2:
                subtraction(fraction1, fraction2, fraction3);
                cout << " " << fraction1.numerator << " " << " "
                    << fraction2.numerator << "    "
                    << fraction3.numerator << endl;
                cout << fraction1.wholePart << "-" << "-"
                    << fraction2.wholePart << "-"
                    << " " << "=" << " " 
                    << fraction3.wholePart << "-" << endl;
                cout << " " << fraction1.denominator << " " << " "
                    << fraction2.denominator << "    "
                    << fraction3.denominator << endl;
                break;
            case 3:
                multiplication(fraction1, fraction2, fraction3);
                cout << " " << fraction1.numerator << " " << " "
                    << fraction2.numerator << "    "
                    << fraction3.numerator << endl;
                cout << fraction1.wholePart << "-" << "-"
                    << fraction2.wholePart << "-"
                    << " " << "=" << " " 
                    << fraction3.wholePart << "-" << endl;
                cout << " " << fraction1.denominator << " " << " "
                    << fraction2.denominator << "    "
                    << fraction3.denominator << endl;
                break;
            case 4:
                division(fraction1, fraction2, fraction3);
                cout << " " << fraction1.numerator << " " << " "
                    << fraction2.numerator << "    "
                    << fraction3.numerator << endl;
                cout << fraction1.wholePart << "-" << "-"
                    << fraction2.wholePart << "-"
                    << " " << "=" << " " 
                    << fraction3.wholePart << "-" << endl;
                cout << " " << fraction1.denominator << " " << " "
                    << fraction2.denominator << "    "
                    << fraction3.denominator << endl;
                break;
            default:
                cout << "You chose wrong operation" << endl;
                cout << "Choose operation again: " << endl;
                break;
        }
    }

    return 0;
}
