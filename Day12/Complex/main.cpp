#include <iostream>

using namespace std;

class Complex {
    int real;
    int img;

public:
    //default constructor
    Complex()
    {
        real = 0;
        img = 0;
    }

    //parameterized constructor
    Complex(int _img, int _real)
    {
        img = _img;
        real = _real;
    }

    //setter
    void set_real(int _real)
    {
        real = _real;
    }
    void set_img(int _img)
    {
        img = _img;
    }

    //getter
    int get_img()
    {
        return img;
    }
    int get_real()
    {
        return real;
    }

    //operator overload
    Complex operator+(Complex c)
    {
        Complex result;
        result.real = real + c.real;
        result.img = img + c.img;
        return result;
    }

    //multiply
    Complex operator*(Complex c)
    {
        Complex result;
        result.real = (real * c.real) - (img * c.img);
        result.img = (real * c.img) + (img * c.real);
        return result;
    }

    //substract
    Complex operator-(Complex &c)
    {
        Complex result;
        result.real = real - c.real;
        result.img = img - c.img;
        return result;
    }

    //operator overload equal
    Complex operator=(const Complex &c)//we must not return anything from function by referencث
    {
        real = c.real;
        img = c.img;
        return *this;
    }

    //operator equal
    bool operator==(const Complex &c)
    {
        return (real == c.real && img == c.img);
    }

    //not equal operator
    bool operator!=(const Complex &c)
    {
        return !(*this == c);//call function bool operator ==
    }

    Complex operator+(int num)//complex c2=c1+5;
    {
        return Complex(real + num, img);
    }

    //explicit for int i+ complex
    explicit operator int()
    {
        return real;
    }

    //prefix
    Complex operator++()
    {
        real++;
        img++;
        return *this;
    }

    //postfix
    Complex operator++(int x)
    {
        Complex result = *this;//use the value and then increase it
        real++;
        img++;
        return result;
    }

    //print
    void print() {
        cout << real << " + " << img << "i" << endl;
    }

    friend Complex operator+(int num, const Complex &c);
};

// for c1=5+c2;
Complex operator+(int num, const Complex &c)
{
    return Complex(c.real + num, c.img);
}

int main()
{
    Complex c1(2, 3); // real=3, img=2
    Complex c2(4, 1); // real=1, img=4

    Complex c3 = c1 + c2;
    cout << "c1 + c2 = ";
    c3.print();

    Complex c4 = c1 + 5;
    cout << "c1 + 5 = ";
    c4.print();

    Complex c5 = 5 + c2;
    cout << "5 + c2 = ";
    c5.print();

    Complex c6;
    c6 = 5 + c1; // c1=5+c2;
    cout << "c6 = 5 + c1 => ";
    c6.print();

    return 0;
}
