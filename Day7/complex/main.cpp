#include <iostream>

using namespace std;
class Complex
{
private:
    int Real;
    int Img;
    static int count;

public:
    //constructor
    Complex()
    {
        Real=0;
        Img=0;
        count++;
    }
    //copy constructor
    Complex(const Complex &C)
    {
    Img=C.Img;
    Real=C.Real;
    count++;
    }

    //setter
    void set_real(int r)
    {
        Real=r;
    }
    void set_img(int i)
    {
        Img=i;
    }

    //getter
    int getreal()
    {
        return Real;
    }
    int getimg()
    {
        return Img;
    }
   static int getcount()
    {
    return count;
    }
    //operator overload
//add
    Complex operator+(Complex c1)
    {
        Complex result;
        result.Real=Real+c1.Real;
        result.Img=Img+c1.Img;
        return result;
    }
//substract
    Complex operator-(Complex c)
    {
        Complex result;
        result.Real=Real-c.Real;
        result.Img=Img-c.Img;
        return result;
    }
//multiply
    Complex operator*(Complex c)
    {
        Complex result;
        result.Real = (Real * c.Real) - (Img * c.Img);
        result.Img = (Real * c.Img) + (Img * c.Real);
        return result;
    }


    void display()
    {
        cout<<"Real="<<Real<<"\tImg="<<Img<<endl;
    }
    ~Complex()
    {
    count--;
    }
};

Complex add(Complex c1,Complex c2)
{
   Complex result;
   result.set_real(c1.getreal()+c2.getreal());
   result.set_img(c1.getimg()+c2.getimg());
   return result;
}
 int Complex::count=0;

int main()
{
    Complex C1;
    C1.set_real(10);
    C1.set_img(20);
    C1.display();

    Complex C2;
    C2.set_real(10);
    C2.set_img(20);
    C2.display();


    //add
    Complex c3;
    c3=C1+C2;
    cout<<"the add of two complex is: ";
    c3.display();
    //substract
    Complex c4;
    c4=c3-C2;
    cout<<"the substract of two complex is: ";
    c4.display();

//multiply
    Complex c5;
    c5=c4*c3;
    cout<<"the multiply of two complex is: ";
    c5.display();

    Complex result2=add(C1,C2);
    cout<<"the result of standalone function :";
    result2.display();

    int x=Complex::getcount();
    cout<<"the count is "<<x<<endl;
    return 0;
}
