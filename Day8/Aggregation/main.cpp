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
    Point* ul;
    Point* lr;
public:
    //default constructor
    Rectangle(Point*R,Point*R2)
    {
        ul=new Point(*R);
        lr=new Point(*R2);
        cout<<endl<<"rectangle constructor call";
    }
    ~Rectangle()
    {
        delete ul;
        delete lr;
        cout<<endl<<"Rectangle destructor call";
    }

};
class Circle
{
    int radius;
    Point* p1;
public:
//constructor
    Circle(Point*C1)
    {
        cout<<endl<<"circle constructor call";
        radius=0;
        p1=new Point(C1);
    }
    //destructor
    ~Circle()
    {
        delete p1;
        cout<<endl<<"circle destructor call";
    }

};

class Triangle
{
    Point* pt;
    Point* pr;
    Point* pi;
public:
//constructor
    Triangle(Point *P,Point *p2,Point *p3)
    {
        pt=new point(*p);
        pr=new point(*p2);
        pi=new point(*p3);
        cout<<endl<<"Triangle constructor call";
    }
//destructor
    ~Triangle()
    {
        delete pt;
        delete pr;
        delete pi;
        cout<<endl<<"Triangle destructor call";
    }
};

int main()
{
    Point P1(10,3);
    Point P2(11,12);
    point p3 (13,14);
    Rectangle R1(&p1);
    Rectangle R2(&p2);
    Circle C1(P1);
    Triangle T1(&P1,&p2,&p3);
    return 0;
}
