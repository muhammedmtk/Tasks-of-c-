#include <iostream>

using namespace std;

int main()
{
    int num,fact=1;
    cout<<"enter the num:";
    cin>>num;
    if(num<0)
    {
        cout<<"this is not factorial for negative number";
    }
    else
    {
        for(int i=1; i<=num; i++)
        {
            fact*=i;
        }
        cout<<"the factorial of number "<<num<<" is "<<fact;
    }
    return 0;
}
