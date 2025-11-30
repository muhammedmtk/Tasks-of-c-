#include <iostream>

using namespace std;

int main()
{
    int num1,num2=0,rem;
    cout<<"enter the number:";
    cin>>num1;
    while(num1!=0)
        {
        rem=num1%10;
        num2=rem+num2*10;
        num1=num1/10;
        }
    cout<<"the reversed number is "<<num2;
    return 0;
}
