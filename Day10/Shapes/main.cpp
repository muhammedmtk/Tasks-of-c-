#include <iostream>
#include <cmath>
using namespace std;

class shape
{
protected:
    int dim1;
    int dim2;

public:
    // constructor
    shape()
    {
        dim1 = 1;
        dim2 = 1;
    }

    // constructor 2
    shape(int value)
    {
        dim1 = value;
        dim2 = value;
    }

    // constructor 3
    shape(int _dim1, int _dim2)
    {
        dim1 = _dim1;
        dim2 = _dim2;
    }

    // setters
    void set_dim1(int _dim1)
    {
        dim1 = _dim1;
    }

    void set_dim2(int _dim2)
    {
        dim2 = _dim2;
    }
    //calc the area
    virtual void calcArea()=0;

    // print to override it
    virtual void printArea() {}
};

//-----------------------------------

class square : public shape
{
public:
    // constructor for one value
    square(int value) : shape(value) {}

    // constructor for two values
    square(int Tall1, int Tall2)
    {
        if (Tall1 != Tall2)
        {
            cout << "The 2 dimensions must be equal! Using the first value.\n";
            set_dim1(Tall1);
            set_dim2(Tall1);
        }
        else
        {
            set_dim1(Tall1);
            set_dim2(Tall2);
        }
    }

    void calcArea()
    {
        double Size = dim1 * dim2;
        cout<< Size;
    }

    void printArea()
    {
        cout <<"Square";
    }
};

//-----------------------------------

class circle : public shape
{
public:
    // constructor for one value
    circle(int value) : shape(value) {}

    // constructor for two values
    circle(int Tall1, int Tall2)
    {
        if (Tall1 != Tall2)
        {
            cout << "The 2 dimensions must be equal! Using the first value.\n";
            set_dim1(Tall1);
            set_dim2(Tall1);
        }
        else
        {
            set_dim1(Tall1);
            set_dim2(Tall2);
        }
    }

    void calcArea()
    {
        double Size = M_PI * dim1 * dim2;
        cout<< Size;
    }

    void printArea()
    {
        cout <<"circle";
    }
};

//-----------------------------------

class rictangle : public shape
{
public:
    rictangle(int Tall, int width) : shape(Tall, width) {}

    void calcArea()
    {
        double Size = dim1 * dim2;
        cout<< Size;
    }
    void printArea()
    {
        cout << "rictangle";
    }
};

//-----------------------------------

class triangle : public shape
{
public:
    triangle(int Tall, int Tall2) : shape(Tall, Tall2) {}

    void calcArea()
    {
        double Size = 0.5 * dim1 * dim2;
        cout<< Size;
    }
    void printArea()
    {
        cout << "triangle";
    }
};

//-----------------------------------
void myfunc(shape*ptr)
{
    cout<< "The size of ";
    ptr->printArea();
    cout<< " and The is ";
    ptr->calcArea();
    cout<<endl<<"==============="<<endl;
}

int main()
{
    shape*t[3];
    t[0]=new circle(5,5);
    t[1]=new triangle(6,7);
    t[2]=new rictangle(7,8);
    for(int i=0; i<3; i++)
    {
        myfunc(t[i]);
    }

    return 0;
}
