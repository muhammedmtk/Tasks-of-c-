#include <iostream>

using namespace std;

int main()
{
    int num1,num2;
    int mul=1;
    cout<<"enter the first num:";
    cin>>num1;
    cout<<"enter the second num:";
    cin>>num2;
    for(int i=0; i<num2; i++)
    {
        mul *=num1;
    }
    cout << num1 << " raised to the power " << num2 << " is " << mul;
    return 0;
}
