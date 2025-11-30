using namespace std;
#include <iostream>

int recursive_fib(int x, int count = 0, int fib1 = 0, int fib2 = 1)
{

    if (count == x)

        return fib1;

int fib = fib1 + fib2;
cout<<fib1<<" ";
    return recursive_fib(x, count + 1, fib2, fib);
}

int main()
{
    int x=5;
   int result=recursive_fib(7);
   cout<< result;
return 0;
}
