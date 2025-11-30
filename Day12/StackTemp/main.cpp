#include <iostream>

using namespace std;


template <class T> class Stack{
private:
    T size;
    int tos;
    T*arr;
public:
    //default constructor
    Stack()
    {
    T size=10;
    tos= -1;
    arr=new T[size];
    }
    //parameterized constructor
    Stack(T _size)
    {
    T size= _size;
    tos= -1;
    arr=new T[_size];
    }
//function stack push
    void stack_push(T num)
    {
    if(tos<size-1)
        {
        arr[++tos]=num;
        cout<<"stack done\n";
        }
    else
        {
            cout<<"stack is full\n"<<endl;;
        }
    }
//function stack pop
    T* stack_pop(T*data)
    {
    if(tos>-1)
        {
            *data=arr[tos--];
            return data;
        }
    else{
        cout<<"stack is empty\n";
    }
    }
//is full
    bool isfull()
    {
    return tos==size-1;
    }
    //is empty
    bool isempty()
    {
    return tos==-1;
    }

};
int main()
{
    Stack <int> s1;
    s1.stack_push(10);
    s1.stack_push(20);
    s1.stack_push(30);
    int num;
    s1.stack_pop(&num);
    cout<<num<<" is poped\n";
    s1.stack_pop(&num);
    cout<<num<<" is poped\n";
    s1.stack_pop(&num);
    cout<<num<<" is poped\n";
    return 0;
}
