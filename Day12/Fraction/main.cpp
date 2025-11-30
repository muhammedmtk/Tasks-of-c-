#include <iostream>
#include <algorithm>

using namespace std;
class Rational
{
    int num;
    int den;

public:
    Rational()
    {
        num = 0;
        den = 1;
    }

    Rational(float _num, float _dem)
    {
        num = _num;
        den = _dem;
    }

    //setter
    void setnumerator(int _num)
    {
        num = _num;
    }
    void setdenominator(int _den)
    {
        den = _den;
    }

    //getter
    int getnumerator()
    {
        return num;
    }
    int getdenominator()
    {
        return den;
    }

    //prefix
    Rational operator++()
    {
        num += den;
        return *this;
    }

    //postfix
    Rational operator++(int)
    {
        Rational result = *this; // store the old value
        num += den;              // add denominator to numerator
        return result;           // return the old value
    }

    //operator overload
    friend Rational operator+(int num, const Rational &R);

    // print function
    void print()
    {
        cout << num << "/" << den << endl;
    }
};

// int + Rational
Rational operator+(int num, const Rational &R)
{
    Rational result;
    result.num = (num * R.den) + R.num; // fixed formula
    result.den = R.den;
    return result;
}

int main()
{
    Rational c1;
    c1.setnumerator(2);
    c1.setdenominator(4);

    Rational c2;
    c2.setnumerator(3);
    c2.setdenominator(6);

    cout << "c1 = ";
    c1.print();

    cout << "c2 = ";
    c2.print();

    // ++ prefix
    cout << "\nAfter prefix ++c1:\n";
    ++c1;
    c1.print();

    // ++ postfix
    cout << "\nAfter postfix c2++:\n";
    Rational oldC2 = c2++;
    cout << "Returned old value: ";
    oldC2.print();
    cout << "New c2: ";
    c2.print();

    // int + Rational
    cout << "\n5 + c1 = ";
    Rational sum = 5 + c1;
    sum.print();

    return 0;
}
