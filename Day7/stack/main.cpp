#include <iostream>

using namespace std;
enum STACKSTATUS
{
    STACK_FULL,
    STACK_EMPTY,
    STACK_DONE
};

template <typename T>

class Stack
{
private:
    int size;
    int tos;
    T *arr;
public:
    //constructor
    Stack(T _size)
    {
        tos=-1;
        size=_size;
        arr=new T[_size];
    }

    STACKSTATUS push(T num)
    {
        if(tos<size-1)
        {
            arr[++tos]=num;
            return STACK_DONE;
        }
        else
        {
            return STACK_FULL;
        }
    }

    STACKSTATUS pop(T*data)
    {
        if(tos>-1)
        {
            *data=arr[tos--];
            return STACK_DONE;
        }
        else
        {
            return STACK_EMPTY;
        }
    }

    stack(const Stack&st)
    {
    size=st.size;
    tos=st.tos;
    T*arr=new T[size];
    for(int i=0;i<size;i++)
        {
        arr[i]=st.arr[i];
        }
    }

    ~Stack()
    {
    delete[] arr;
    }
    friend STACKSTATUS STACKEMPTY(Stack<int>* stack_t);
};

STACKSTATUS STACKEMPTY(Stack<int>* stack_t)
{
stack_t->tos=-1;
return STACK_EMPTY;
}


int main()
{
    Stack<int> S(10);

STACKSTATUS st;
STACKSTATUS st1(st);
st = S.push(20);
if (st == STACK_DONE)
    cout << "Push done\n";

st = S.push(30);
if (st == STACK_DONE)
    cout << "Push done\n";

st = S.push(40);
if (st == STACK_DONE)
    cout << "Push done\n";


    int x;
st = S.pop(&x);
if (st == STACK_DONE)
    cout << "Popped: " << x << endl;
st = S.pop(&x);
if (st == STACK_DONE)
    cout << "Popped: " << x << endl;
st = S.pop(&x);
if (st == STACK_DONE)
    cout << "Popped: " << x << endl;
st = S.pop(&x);
if (st == STACK_DONE)
    cout << "Popped: " << x << endl;
st = S.pop(&x);
if (st == STACK_DONE)
    cout << "Popped: " << x << endl;
    st=STACKEMPTY(&S);
    cout<<st;



    return 0;
}
