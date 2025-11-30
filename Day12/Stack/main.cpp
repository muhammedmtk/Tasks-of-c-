using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Stack
{
private:
    int size;
    int tos;
    int* arr;

public:
    // default constructor
    Stack()
    {
        size = 10;
        tos = -1;
        arr = new int[size];
    }

    // parameterized constructor
    Stack(int _size)
    {
        size = _size;
        tos = -1;
        arr = new int[size];
    }

    //copy constructor
    Stack(const Stack& other)
    {
        size = other.size;
        tos = other.tos;
        arr = new int[size];
        for (int i = 0; i < size; ++i)
            arr[i] = other.arr[i];
    }

    // function stack push
    void stack_push(int num)
    {
        if (tos < size - 1)
        {
            arr[++tos] = num;
            cout << "stack done\n";
        }
        else
        {
            cout << "stack is full\n";
        }
    }

    // function stack pop
    int* stack_pop(int* data)
    {
        if (tos > -1)
        {
            *data = arr[tos--];
            return data;
        }
        else
        {
            cout << "stack is empty\n";
            return nullptr;
        }
    }
//function operator stack = stack
    Stack& operator=(const Stack& c)
    {
        size = c.size;
        tos = c.tos;
        delete[]arr;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = c.arr[i];

        return *this;
    }

    // operator overload stack+stack
    Stack operator+(const Stack& c) const
    {
        Stack result;
        result.size = size + c.size;
        result.tos = -1;
        delete[] result.arr; // remove default allocation array
        result.arr = new int[result.size];

        // copy elements
        int i=0;
        for (i = 0; i <= this->tos; i++)
        {
                result.arr[i]=arr[i];
                }
        for(int j=0;j<= c.tos;j++,i++)
            {
            result.arr[i]=c.arr[j];
            }
        result.tos = this->tos + c.tos + 1;
        return result;
    }

    // is full
    bool isfull()
    {
        return tos == size - 1;
    }

    // is empty
    bool isempty()
    {
        return tos == -1;
    }

    void print_stack()
    {
        if (isempty())
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack contents (top to bottom): ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack s1;
    s1.stack_push(10);
    s1.stack_push(20);
    s1.stack_push(30);
    s1.stack_push(10);
    s1.stack_push(20);
    s1.stack_push(30);
    s1.stack_push(10);
    s1.stack_push(20);
    s1.stack_push(30);
    s1.stack_push(10);

    Stack s2;
    s2.stack_push(40);
    s2.stack_push(50);
    s2.stack_push(60);
    s2.stack_push(70);
    s2.stack_push(80);
    s2.stack_push(90);
    s2.stack_push(100);
    s2.stack_push(110);
    s2.stack_push(120);
    s2.stack_push(130);

    Stack s3 = s1 + s2;

    cout << "\nAfter merging s1 + s2 into s3:\n";
    s3.print_stack();

    Stack s4;
    s4 = s3;

    cout << "\nNow popping all elements from s4:\n";
    int num;
    while (!s4.isempty())
    {
        s4.stack_pop(&num);
        cout << num << " is popped\n";
    }

    return 0;
}
