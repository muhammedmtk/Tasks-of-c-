#include <iostream>

using namespace std;
int factorial(int num)
{
    int x=1;
for(int i=1;i<=num;i++)
    {
    x*=i;
    }
return x;
}

int main()
{
    int num,fact_num;
    cout<<"enter the number:";
    cin>>num;
    fact_num=factorial(num);
    cout<<"the factorial of "<<num<<" is "<<fact_num;
    return 0;
}
