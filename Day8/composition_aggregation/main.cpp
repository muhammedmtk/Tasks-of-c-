#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()
    {
        x=0;
        y=0;
    }
    Point(int _x,int _y)
    {
        x= _x;
        y= _y;
    }

    void setX(int _x)
    {
        x= _x;
    }
    void setY(int _y)
    {
        y= _y;
    }
    void setPoint(int _x,int _y)
    {
        x= _x;
        y= _y;
    }
    //destructor
    ~Point()
    {
        cout<<endl<<"point destructor call";
    }

};

class Rectangle
{
    Point ul;
    Point lr;
public:
    //default constructor
    Rectangle()
    {
        ul.setPoint(3,4);
        lr.setPoint(5,6);
    }
    //parameterized constructor
    Rectangle(int _x,int _y,int _z,int _z2):ul(_x,_y),lr(_z,_z2)
    {
    cout<<endl<<"parameterized constructor call in Rectangle";
    };
    ~Rectangle()
    {
        cout<<endl<<"Rectangle destructor call";
    }

};
class Circle
{
    int radius;
    Point p1;
public:
//constructor
    Circle()
    {
        radius=0;
        p1.setPoint(5,6);
    }
    //destructor
    ~Circle()
    {
        cout<<endl<<"circle destructor call";
    }

};

class Triangle
{
    Point pt;
    Point pr;
    Point pi;
public:
//constructor
    Triangle()
    {
        pt.setPoint(3,5);
        pr.setPoint(5,6);
        pi.setPoint(6,7);
    }
//destructor
    ~Triangle()
    {
        cout<<endl<<"Triangle destructor call";
    }
};

int main()
{
    Rectangle R1;
    Rectangle R2(5,6,7,8);
    Circle C1;
    Triangle T1;
    return 0;
}
