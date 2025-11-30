#include <iostream>

using namespace std;
class Parent{
protected:
    int x;
    int y;
public:
    //default constructor
    Parent()
    {
    x=0;
    y=0;
    }
    //parameterized constructor
    Parent(int _x,int _y)
    {
    x= _x;
    y= _y;
    }
    //setter
    void set_x(int _x)
    {
    x= _x;
    }
    void set_y(int _y)
    {
    y= _y;
    }
    //getter
    int get_x()
    {
    return x;
    }
    int get_y()
    {
    return y;
    }
    //virtual function
 int add()
    {
    return x+y;
    }
};
class Child:public Parent
{
    protected:
    int z;
    public:
    Child(int _x,int _y,int _z):Parent(_x,_y)
    {
    z= _z;
    }
    int add()
    {
    return x+y+z;
    }

};

int main()
{
    Parent p(10,20);
    Parent *ptr;
    Child c(3,4,5);
    ptr=&c;
    int sum=ptr->add();
    int sum2=p.add();
    cout<<"the sum of function add in child = "<<sum<<endl;
    cout<<"the sum of function add in parent = "<<sum2<<endl;
}
